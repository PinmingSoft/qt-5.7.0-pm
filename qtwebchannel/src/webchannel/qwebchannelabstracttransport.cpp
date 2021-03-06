/****************************************************************************
**
** Copyright (C) 2016 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Milian Wolff <milian.wolff@kdab.com>
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtWebChannel module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qwebchannelabstracttransport.h"

QT_BEGIN_NAMESPACE

/*!
    \class QWebChannelAbstractTransport

    \inmodule QtWebChannel
    \brief Communication channel between the C++ QWebChannel server and a HTML/JS client.
    \since 5.4

    Users of the QWebChannel must implement this interface and connect instances of it
    to the QWebChannel server for every client that should be connected to the QWebChannel.
    The {Qt WebChannel Standalone Example}{Standalone Example} shows how this can be done
    using Qt WebSockets. Qt WebKit implements this interface internally and uses the native
    WebKit IPC mechanism to transmit messages to HTML clients.

    \note The JSON message protocol is considered internal and might change over time.

    \sa {Qt WebChannel Standalone Example}
*/

/*!
    \fn QWebChannelAbstractTransport::messageReceived(const QJsonObject &message, QWebChannelAbstractTransport *transport)

    This signal must be emitted when a new JSON \a message was received from the remote client. The
    \a transport argument should be set to this transport object.
*/

/*!
    \fn QWebChannelAbstractTransport::sendMessage(const QJsonObject &message)

    Send a JSON \a message to the remote client. An implementation would serialize the message and
    transmit it to the remote JavaScript client.
*/

/*!
    Constructs a transport object with the given \a parent.
*/
QWebChannelAbstractTransport::QWebChannelAbstractTransport(QObject *parent)
: QObject(parent)
{

}

/*!
    Destroys the transport object.
*/
QWebChannelAbstractTransport::~QWebChannelAbstractTransport()
{

}

QT_END_NAMESPACE
