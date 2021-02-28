import QtQuick 2.12
import QtQuick.Window 2.12
import Test 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Qml Painter (龚建波)")

    Rectangle{
        anchors.fill: parent
        anchors.margins: 20
        color: "darkCyan"
    }

    QmlCanvas{
        id: canvas
        width: parent.width/2
        height: parent.height/2

        Timer{
            //running: true
            repeat: true
            interval: 1000
            onTriggered: {
                canvas.update();
            }
        }
    }
}
