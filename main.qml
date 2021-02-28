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
        property int value: 0
        width: parent.width/2
        height: parent.height/2
        backgroundColor: Qt.rgba(1,0,0,0.8)
        onPaint: {
            painter.drawLine(10,10+200-value,width-10,10+value);
        }

        Timer{
            running: true
            repeat: true
            interval: 20
            onTriggered: {
                canvas.value+=1;
                if(canvas.value>200)
                    canvas.value=0;
                canvas.repaint();
            }
        }
    }
}
