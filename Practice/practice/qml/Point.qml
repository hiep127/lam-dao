import QtQuick 2.0

Item {
    height: 30
    width: 320
    property alias skill : txtSkill.text
    property alias point: txtPoint.text
    property alias srcImage: logo.source

    Image{
        id: logo
        width: 30
        height: 30
        anchors.left: parent.left
        anchors.leftMargin: 60
        anchors.verticalCenter: parent.verticalCenter
    }

    Text{
        id: txtSkill
        anchors.left: parent.left
        anchors.leftMargin: 100
        anchors.verticalCenter: parent.verticalCenter
    }

    Text {
        id: txtPoint
        anchors.left: parent.left
        anchors.leftMargin: 180
        anchors.verticalCenter: parent.verticalCenter
    }

    Text {
        id: max
        text: "/5"
        color: "blue"
        anchors.left: txtPoint.right
        anchors.verticalCenter: parent.verticalCenter
    }
    Image{
        width: 25
        height: 25
        anchors.left: max.right
        anchors.leftMargin: 20
        anchors.verticalCenter: parent.verticalCenter
        source: txtPoint.text*1 > 3 ?  "/images/check.png" : "/images/remove.png"
    }
}
