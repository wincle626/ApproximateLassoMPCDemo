// Copyright (C) 2017 Juan José Casafranca
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QT3DRENDER_QBUFFERCAPTURE_P_H
#define QT3DRENDER_QBUFFERCAPTURE_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists for the convenience
// of other Qt classes.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <Qt3DRender/qbuffercapture.h>
#include <Qt3DRender/private/qframegraphnode_p.h>

QT_BEGIN_NAMESPACE

namespace Qt3DRender
{

class QBufferCapturePrivate : public QFrameGraphNodePrivate
{
public:
    QBufferCapturePrivate();

    Q_DECLARE_PUBLIC(QBufferCapture)
};

} //Qt3DRender

QT_END_NAMESPACE

#endif // QT3DRENDER_QBUFFERCAPTURE_P_H