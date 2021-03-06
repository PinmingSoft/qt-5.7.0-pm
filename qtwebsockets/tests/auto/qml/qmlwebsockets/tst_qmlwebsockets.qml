/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the test suite of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL-EXCEPT$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.5
import QtWebSockets 1.0
import QtTest 1.1

Rectangle {
    width: 360
    height: 360

    WebSocketServer {
        id: server
        port: 1337

        onClientConnected: {
            currentSocket = webSocket;
        }

        property var currentSocket
    }

    WebSocket {
        id: socket
        url: server.url
    }

    TestCase {
        function ensureConnected() {
            socket.active = true;
            server.listen = true;
            tryCompare(socket, 'status', WebSocket.Open);
            verify(server.currentSocket);
        }

        function ensureDisconnected() {
            socket.active = false;
            server.listen = false;
            tryCompare(socket, 'status', WebSocket.Closed);
            server.currentSocket = null;
        }

        function test_send_receive_text() {
            ensureConnected();

            var o = {};
            var sending = 'hello.';
            server.currentSocket.textMessageReceived.connect(function(received) {
                compare(received, sending);
                o.called = true;
            });

            socket.sendTextMessage(sending);
            tryCompare(o, 'called', true);
        }

        function test_send_text_error_closed() {
            ensureDisconnected();
            socket.sendTextMessage('hello');
            tryCompare(socket, 'status', WebSocket.Error);
        }
    }
}
