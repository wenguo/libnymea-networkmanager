/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                         *
 * Copyright (C) 2018-2019 Simon Stürz <simon.stuerz@nymea.io>             *
 *                                                                         *
 * This file is part of libnymea-networkmanager.                           *
 *                                                                         *
 *  This library is free software; you can redistribute it and/or          *
 *  modify it under the terms of the GNU Lesser General Public             *
 *  License as published by the Free Software Foundation; either           *
 *  version 2.1 of the License, or (at your option) any later version.     *
 *                                                                         *
 *  This library is distributed in the hope that it will be useful,        *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU      *
 *  Lesser General Public License for more details.                        *
 *                                                                         *
 *  You should have received a copy of the GNU Lesser General Public       *
 *  License along with this library; If not, see                           *
 *  <http://www.gnu.org/licenses/>.                                        *
 *                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef WIREDNETWORKDEVICE_H
#define WIREDNETWORKDEVICE_H

#include <QObject>
#include <QDBusObjectPath>

#include "networkdevice.h"

class WiredNetworkDevice : public NetworkDevice
{
    Q_OBJECT
public:
    explicit WiredNetworkDevice(const QDBusObjectPath &objectPath, QObject *parent = nullptr);

    QString macAddress() const;
    int bitRate() const;
    bool pluggedIn() const;

private:
    QDBusInterface *m_wiredInterface = nullptr;

    QString m_macAddress;
    int m_bitRate = 0;
    bool m_pluggedIn = false;

    void setMacAddress(const QString &macAddress);
    void setBitRate(int bitRate);
    void setPluggedIn(bool pluggedIn);

private slots:
    void propertiesChanged(const QVariantMap &properties);

};

QDebug operator<<(QDebug debug, WiredNetworkDevice *networkDevice);

#endif // WIREDNETWORKDEVICE_H
