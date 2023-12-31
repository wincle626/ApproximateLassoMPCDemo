// Copyright (C) 2022 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "../qqmldom_global.h"
#ifndef QTQMLCOMPILEREXPORTS_P_H
#define QTQMLCOMPILEREXPORTS_P_H
#if QT_VERSION < QT_VERSION_CHECK(6, 4, 0)
#include <QtCore/qstring.h>
namespace Qt {
inline namespace Literals {
inline namespace StringLiterals {

constexpr inline QLatin1String operator"" _L1(const char *str, size_t size) noexcept
{
    return QLatin1String { str, qsizetype(size) };
}

inline QString operator"" _s(const char16_t *str, size_t size) noexcept
{
    return QString(QStringPrivate(nullptr, const_cast<char16_t *>(str), qsizetype(size)));
}

} // StringLiterals
} // Literals
} // Qt
#ifdef Q_QMLCOMPILER_PRIVATE_EXPORT // clashing declaration fixed in ce53e48504f
#undef Q_QMLCOMPILER_PRIVATE_EXPORT
#endif
#endif
#define Q_QMLCOMPILER_PRIVATE_EXPORT QMLDOM_EXPORT
#endif
