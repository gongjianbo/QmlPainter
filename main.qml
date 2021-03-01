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
        property real begin: 0
        width: parent.width/2
        height: parent.height/2
        backgroundColor: Qt.rgba(1,0,0,0.8)
        onPaint: {
            painter.setAntialiasing(true);
            //可以减小步进，如0.5，绘制更圆滑
            for(let i=0;i<width;i++)
            {
                //sin值域为[-1,1]，这里相当于把y值下移并放大
                painter.drawLine(i,height/2+height/4*Math.sin((begin+i)*Math.PI/180),
                                 i+1,height/2+height/4*Math.sin((begin+i+1)*Math.PI/180));
            }
        }

        Timer{
            running: true
            repeat: true
            interval: 10
            onTriggered: {
                canvas.begin+=1;
                if(canvas.begin>360)
                    canvas.begin=0;
                canvas.repaint();
            }
        }
    }
}
