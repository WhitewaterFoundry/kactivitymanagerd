/*
 *   Copyright (C) 2012 Ivan Cukic <ivan.cukic(at)kde.org>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License version 2,
 *   or (at your option) any later version, as published by the Free
 *   Software Foundation
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details
 *
 *   You should have received a copy of the GNU General Public
 *   License along with this program; if not, write to the
 *   Free Software Foundation, Inc.,
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef ENCFSINTERFACE_H_
#define ENCFSINTERFACE_H_

#include <QObject>
#include <QProcess>

/**
 * EncfsInterface
 */
class EncfsInterface: public QObject {
    Q_OBJECT

public:
    EncfsInterface();
    virtual ~EncfsInterface();

    void mount(const QString & what, const QString & mountPoint);
    void umount(const QString & mountPoint);

    bool isEncryptionInitialized(const QString & path);

Q_SIGNALS:
    void error();

private Q_SLOTS:
    void processFinished(int exitCode, QProcess::ExitStatus exitStatus);

private:
    class Private;
    Private * const d;
};

#endif // ENCFSINTERFACE_H_

