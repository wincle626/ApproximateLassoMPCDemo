// Copyright (C) 2016 Klaralvdalens Datakonsult AB (KDAB).
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QT3DINPUT_INPUT_INPUTCHORD_H
#define QT3DINPUT_INPUT_INPUTCHORD_H

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

#include <Qt3DCore/qnodeid.h>

#include <Qt3DInput/private/abstractactioninput_p.h>

QT_BEGIN_NAMESPACE

namespace Qt3DInput {

namespace Input {

class Q_AUTOTEST_EXPORT InputChord : public AbstractActionInput
{
public:
    InputChord();
    void cleanup();

    inline QList<Qt3DCore::QNodeId> chords() const { return m_chords; }
    inline qint64 timeout() const { return m_timeout; }
    inline qint64 startTime() const { return m_startTime; }
    void setStartTime(qint64 time);
    void reset();
    bool actionTriggered(Qt3DCore::QNodeId input);
    void syncFromFrontEnd(const Qt3DCore::QNode *frontEnd, bool firstTime) override;

    bool process(InputHandler *inputHandler, qint64 currentTime) override;

private:
    QList<Qt3DCore::QNodeId> m_chords;
    QList<Qt3DCore::QNodeId> m_inputsToTrigger;
    qint64 m_timeout;
    qint64 m_startTime;
};

} // namespace Input

} // namespace Qt3DInput

QT_END_NAMESPACE

#endif // QT3DINPUT_INPUT_INPUTCHORD_H
