// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QDARWINMEDIADEVICES_H
#define QDARWINMEDIADEVICES_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API. It exists purely as an
// implementation detail. This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <private/qplatformmediadevices_p.h>
#include <qelapsedtimer.h>
#include <qcameradevice.h>

QT_BEGIN_NAMESPACE

class QCameraDevice;

class QDarwinMediaDevices : public QPlatformMediaDevices
{
public:
    QDarwinMediaDevices();
    ~QDarwinMediaDevices();

    QList<QAudioDevice> audioInputs() const override;
    QList<QAudioDevice> audioOutputs() const override;
    QPlatformAudioSource *createAudioSource(const QAudioDevice &info) override;
    QPlatformAudioSink *createAudioSink(const QAudioDevice &info) override;

    void updateAudioDevices();

private:
    QList<QAudioDevice> m_audioInputs;
    QList<QAudioDevice> m_audioOutputs;

#ifdef Q_OS_MACOS
    void *m_audioDevicesProperty;
#endif
};

QT_END_NAMESPACE

#endif
