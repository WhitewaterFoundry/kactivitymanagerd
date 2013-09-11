/*
 *   Copyright (C) 2013 Ivan Cukic <ivan.cukic(at)kde.org>
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

#ifndef ACTIVITIES_CACHE_P_H
#define ACTIVITIES_CACHE_P_H

#include <QSharedPointer>
#include <QObject>

#include <common/dbus/org.kde.ActivityManager.Activities.h>

#include "activities_interface.h"

namespace KActivities {

class ActivitiesCache : public QObject {
    Q_OBJECT

public:
    static QSharedPointer<ActivitiesCache> self();

    bool isLoaded() const;

Q_SIGNALS:
    void activitiesLoaded();
    void activityAdded(const QString &id);
    void activityChanged(const QString &id);
    void activityRemoved(const QString &id);
    void activityStateChanged(const QString &id, int state);
    void currentActivityChanged(const QString &id);

private Q_SLOTS:
    void updateAllActivities();
    void updateActivity(const QString &id);
    void updateActivityState(const QString &id, int state);
    void removeActivity(const QString &id);

    void setActivityInfoFromReply(QDBusPendingCallWatcher *watcher);
    void setAllActivitiesFromReply(QDBusPendingCallWatcher *watcher);
    void setCurrentActivityFromReply(QDBusPendingCallWatcher *watcher);

    void setActivityInfo(const ActivityInfo &info);
    void setAllActivities(const ActivityInfoList &activities);
    void setCurrentActivity(const QString &activity);

private:
    template <typename _Result, typename _Functor>
    void passInfoFromReply(QDBusPendingCallWatcher *watcher, _Functor f);

    ActivitiesCache();
    static QWeakPointer<ActivitiesCache> s_instance;

    QList<ActivityInfo> m_activities;
    QString m_currentActivity;
    bool m_loaded;
};

} // namespace KActivities


#endif /* ACTIVITIES_CACHE_P_H */

