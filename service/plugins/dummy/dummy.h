/*
 *   Copyright (C) 2008 Nick Shaforostoff <shaforostoff@kde.ru>
 *
 *   based on work by:
 *   Copyright (C) 2007 Thomas Georgiou <TAGeorgiou@gmail.com> and Jeff Cooper <weirdsox11@gmail.com>
 *
 *   This program is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU General Public License as
 *   published by the Free Software Foundation; either version 2 of
 *   the License, or (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PLUGINS_DUMMY_DUMMY_H
#define PLUGINS_DUMMY_DUMMY_H

#include "../../Plugin.h"

class DummyPlugin: public Plugin
{
    Q_OBJECT

public:
    DummyPlugin(QObject *parent, const QVariantList & args);
    ~DummyPlugin();
};

#endif // PLUGINS_DUMMY_DUMMY_H

