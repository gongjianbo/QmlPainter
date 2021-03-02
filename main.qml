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
        backgroundColor: Qt.rgba(0.9,0.9,0.9,0.8)
        onPaint: {
            let center=height/2;
            let wave=20;
            painter.setAntialiasing(true);
            painter.setPen(Qt.rgba(0,0,0,1));

            let path=painter.createPath();
            path.addEllipse(width/2,height/2,height/2,height/2);
            painter.setClipPath(path);

            //第一个波浪
            //可以减小步进，如0.5，绘制更圆滑
            path.clearPath();
            path.moveTo(0,center+wave*Math.sin((begin)*Math.PI/180));
            for(let i=1;i<width+1;i++)
            {
                //sin值域为[-1,1]，这里相当于把y值下移并放大
                path.lineTo(i,center+wave*Math.sin((begin+i*2)*Math.PI/180));
            }
            path.lineTo(width,height);
            path.lineTo(0,height);
            path.closeSubpath();
            painter.fillPath(path,Qt.rgba(1,0,0,0.7));

            //第二个波浪
            path.clearPath();
            path.moveTo(0,center+wave*Math.sin((begin-60)*Math.PI/180));
            for(let i2=1;i2<width+1;i2++)
            {
                path.lineTo(i2,center+wave*Math.sin((begin-60+i2*2)*Math.PI/180));
            }
            path.lineTo(width,height);
            path.lineTo(0,height);
            path.closeSubpath();
            painter.fillPath(path,Qt.rgba(1,0,0,0.5));

            //圆圈
            path.clearPath();
            path.addEllipse(width/2,height/2,height/2,height/2);
            painter.setPen(Qt.rgba(0.6,0,0,1));
            painter.drawPath(path)
        }

        Timer{
            running: true
            repeat: true
            interval: 20
            onTriggered: {
                canvas.begin+=3;
                if(canvas.begin>360)
                    canvas.begin=0;
                canvas.repaint();
            }
        }
    }
}
