// Copyright (C) 2020 The Qt Company Ltd.
// Copyright (C) 2021 Intel Corporation.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QOFFSETSTRINGARRAY_P_H
#define QOFFSETSTRINGARRAY_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "private/qglobal_p.h"

#include <QByteArrayView>

#include <array>
#include <limits>
#include <string_view>
#include <tuple>

class tst_QOffsetStringArray;

QT_BEGIN_NAMESPACE

QT_WARNING_PUSH
#if defined(Q_CC_GNU_ONLY) && Q_CC_GNU >= 1100
// we usually don't overread, but GCC has a false positive
QT_WARNING_DISABLE_GCC("-Wstringop-overread")
#endif


template <typename StaticString, typename OffsetList>
class QOffsetStringArray
{
public:
    constexpr QOffsetStringArray(const StaticString &string, const OffsetList &offsets)
        : m_string(string), m_offsets(offsets)
    {}

    constexpr const char *operator[](const int index) const noexcept
    {
        return m_string.data() + m_offsets[qBound(int(0), index, count())];
    }

    constexpr const char *at(const int index) const noexcept
    {
        return m_string.data() + m_offsets[index];
    }

    constexpr QByteArrayView viewAt(qsizetype index) const noexcept
    {
        return { m_string.data() + m_offsets[index],
                    qsizetype(m_offsets[index + 1]) - qsizetype(m_offsets[index]) - 1 };
    }

    constexpr int count() const { return int(m_offsets.size()) - 1; }

private:
    StaticString m_string;
    OffsetList m_offsets;
    friend tst_QOffsetStringArray;
};

namespace QtPrivate {
// std::copy is not constexpr in C++17
template <typename II, typename OO>
static constexpr OO copyData(II input, qsizetype n, OO output)
{
    using E = decltype(+*output);
    for (qsizetype i = 0; i < n; ++i)
        output[i] = E(input[i]);
    return output + n;
}

template <size_t Highest> constexpr auto minifyValue()
{
    if constexpr (Highest <= (std::numeric_limits<quint8>::max)()) {
        return quint8(Highest);
    } else if constexpr (Highest <= (std::numeric_limits<quint16>::max)()) {
        return quint16(Highest);
    } else {
        // int is probably enough for everyone
        return int(Highest);
    }
}

template <size_t StringLength, typename Extractor, typename... T>
constexpr auto makeStaticString(Extractor extract, const T &... entries)
{
    std::array<char, StringLength> result = {};
    qptrdiff offset = 0;

    const char *strings[] = { extract(entries).operator const char *()... };
    size_t lengths[] = { sizeof(extract(T{}))... };
    for (size_t i = 0; i < std::size(strings); ++i) {
        copyData(strings[i], lengths[i], result.begin() + offset);
        offset += lengths[i];
    }
    return result;
}

template <size_t N> struct StaticString
{
    char value[N] = {};
    constexpr StaticString() = default;
    constexpr StaticString(const char (&s)[N])  { copyData(s, N, value); }
    constexpr operator const char *() const     { return value; }
};

template <size_t KL, size_t VL> struct StaticMapEntry
{
    StaticString<KL> key = {};
    StaticString<VL> value = {};
    constexpr StaticMapEntry() = default;
    constexpr StaticMapEntry(const char (&k)[KL], const char (&v)[VL])
        : key(k), value(v)
    {}
};

template <typename StringExtractor, typename... T>
constexpr auto qOffsetStringArray(StringExtractor extractString, const T &... entries)
{
    constexpr size_t Count = sizeof...(T);
    constexpr qsizetype StringLength = (sizeof(extractString(T{})) + ...);
    using MinifiedOffsetType = decltype(QtPrivate::minifyValue<StringLength>());

    size_t offset = 0;
    std::array fullOffsetList = { offset += sizeof(extractString(T{}))... };

    // prepend zero
    std::array<MinifiedOffsetType, Count + 1> minifiedOffsetList = {};
    QtPrivate::copyData(fullOffsetList.begin(), Count, minifiedOffsetList.begin() + 1);

    std::array staticString = QtPrivate::makeStaticString<StringLength>(extractString, entries...);
    return QOffsetStringArray(staticString, minifiedOffsetList);
}
}

template<int ... Nx>
constexpr auto qOffsetStringArray(const char (&...strings)[Nx]) noexcept
{
    auto extractString = [](const auto &s) -> decltype(auto) { return s; };
    return QtPrivate::qOffsetStringArray(extractString, QtPrivate::StaticString(strings)...);
}

QT_WARNING_POP
QT_END_NAMESPACE

#endif // QOFFSETSTRINGARRAY_P_H