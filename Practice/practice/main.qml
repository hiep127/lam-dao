import QtQuick 2.9
import QtQuick.Controls 2.2
import "qrc:/qml"
import "qml"
ApplicationWindow {
    id: win
    visible: true
    width: 320
    height: 480
    title: qsTr("Practice")

    property string personName: ""
    property int assemblyPoint: 0
    property int cppPoint: 0
    property int javaScriptPoint: 0
    property int qmlPoint: 0
    property int openGLPoint: 0
    property bool isSender: true

    function updateCurrentView(){
        if(listView.currentItem !== null){
            var data = listView.currentItem.myData
            personName = data.name
            assemblyPoint = data.assembly
            cppPoint = data.cpp
            javaScriptPoint = data.javaScript
            qmlPoint = data.qml
            openGLPoint = data.openGL
        }
    }

    Component{
        id: sender
        Column{
            PointEdit{
                skill: "Assembly:"
                point: assemblyPoint
                srcImage: "/images/ambulance.png"
                onPointChanged: {
                    listView.currentItem.myData.assembly = point
                }
            }
            PointEdit{
                skill: "C++:"
                point: cppPoint
                srcImage: "/images/bicycle.png"
                onPointChanged: {
                    listView.currentItem.myData.cpp = point
                }
            }
            PointEdit{
                skill: "Java Script:"
                point: javaScriptPoint
                srcImage: "/images/car.png"
                onPointChanged: {
                    listView.currentItem.myData.javaScript = point
                }
            }
            PointEdit{
                skill: "QML:"
                point: qmlPoint
                srcImage: "/images/electric-car.png"
                onPointChanged: {
                    listView.currentItem.myData.qml = point
                }
            }
            PointEdit{
                skill: "OpenGL:"
                point: openGLPoint
                srcImage: "/images/vehicle.png"
                onPointChanged: {
                    listView.currentItem.myData.openGL = point
                }
            }
        }

    }

    Component{
        id: receiver
        Column{
            Point{
                skill: "Assembly:"
                point: assemblyPoint
                srcImage: "/images/ambulance.png"
            }
            Point{
                skill: "C++:"
                point: cppPoint
                srcImage: "/images/bicycle.png"
            }
            Point{
                skill: "Java Script:"
                point: javaScriptPoint
                srcImage: "/images/car.png"
            }
            Point{
                skill: "QML:"
                point: qmlPoint
                srcImage: "/images/electric-car.png"
            }
            Point{
                skill: "OpenGL:"
                point: openGLPoint
                srcImage: "/images/vehicle.png"
            }
        }

    }

    Item{
        anchors.fill: parent
        Rectangle{
            id: display
            width: parent.width
            height: 200
            Text{
                id: pic
                text: personName
                font.pixelSize: 30
                font.bold: true
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Loader{
                anchors.top: pic.bottom
                anchors.topMargin: 10
                sourceComponent: isSender ? sender : receiver
            }


        }

        Timer {
            id: timer
            interval: 3000
            onTriggered: {
                busyind.visible = false
            }
        }

        Button{
            id: refreshBtn
            anchors.top: display.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Refresh"
            onClicked: {
                timer.restart()
                busyind.visible = true
            }
        }

        TextField{
            id: searrch
            width: parent.width
            height: 40
            placeholderText: qsTr("Enter name")
            y: parent.height*2/5 + refreshBtn.height
            onTextEdited: {
                listModel.setFilterFixedString(text)
            }
        }

        BusyIndicator{
            id: busyind
            visible: false
            width: 150
            height: 150
            anchors.top: searrch.bottom
            anchors.topMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: scrollView.verticalCenter
        }
        ScrollView {
            id: scrollView
            visible: !busyind.visible
            width: parent.width
            height: 200
            anchors.top: searrch.bottom
            ListView {
                id: listView
                visible: parent.visible
                width: parent.width
                model: listModel
                currentIndex: 0

                property var item: listView.currentItem
                onItemChanged: {
                    updateCurrentView()
                }
                header: Item {
                    id: hearder
                    z: 2
                    width: listView.width
                    height: 30
                    Text{
                        id: txtNameHeader
                        width: listView.width*2/3
                        text: "Name"
                        anchors.verticalCenter: parent.verticalCenter
                        leftPadding: 30
                        font.bold: true
                    }
                    Text{
                        anchors.left: txtNameHeader.right
                        width: listView.width/3
                        text: "Point"
                        anchors.verticalCenter: parent.verticalCenter
                        font.bold: true
                    }
                }
                delegate: Item {
                    property variant myData: model
                    width: listView.width
                    height: 30
                    Text{
                        id: txtName
                        width: listView.width*2/3
                        text: name
                        anchors.verticalCenter: parent.verticalCenter
                        leftPadding: 30
                    }
                    Text{
                        anchors.left: txtName.right
                        width: listView.width/3
                        text: (assembly + cpp + javaScript + qml + openGL)/5
                        anchors.verticalCenter: parent.verticalCenter

                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked:{
                            listView.currentIndex = index
                        }
                    }
                }
                highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
                clip: true
                highlightMoveDuration: 100
                Component.onCompleted: {
                    updateCurrentView()
                }
            }
        }
    }


}
