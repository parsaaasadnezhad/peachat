import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.3

Item {
    anchors.fill: parent

    property string cppMessage: Client.mosage
    property bool onlineUser: Client.onlineUser
    property var onlineUserList:[]
    onCppMessageChanged: {
        listmodel.append({"message":cppMessage , "place":1})
    }
    onOnlineUserChanged: {
        onlineUserList = Client.getOnlineUserList()
        for(var i=0 ; i<onlineUserList.length ; i++)
            onlineUserListModel_Id.append({"username":onlineUserList[i]})

    }

    function readValues(anArray) {
        for (var i=0; i<anArray.length; i++)
            console.log("Array item:", anArray[i])
    }

    Item{
        id:contactItem_Id
        width: parent.width / 4
        height: parent.height
        Pane{
            id:contactPane_Id
            anchors.fill: parent
            Material.background: Material.DeepOrange
            Material.elevation: 6

            Button{
                id:onlineUserButton_Id
                anchors.horizontalCenter: parent.horizontalCenter
                text:"online users"
                onClicked: {
                    onlineUserListModel_Id.clear()
                    Client.onlineUsers();
                }
            }
            Item{
                anchors.centerIn: parent
                width: parent.width - 20
                height: parent.height - 120

                ListView{
                    id:contactListView_Id
                    anchors.fill: parent
                    spacing: 10
                    model: onlineUserListModel_Id
                    delegate: Pane{
                        width: parent.width
                        height: 50
                        Material.background: Material.Orange
                        Material.elevation: 8
                        Text{
                            anchors.verticalCenter: parent.verticalCenter
                            text: username
                        }
                    }
                }
            }
        }
    }

    Item{
        x:parent.width / 4
        width: parent.width * 3 / 4
        height: parent.height
        Item{
            anchors.centerIn: parent
            width: parent.width - 30
            height: parent.height - 30
            ListView{
                id:list
                spacing: 10
                anchors.fill:parent
                model: listmodel
                delegate: Pane{
//                    anchors.right: list.right
                    x:{
//                        console.log(place)
                        if(place === 1)
                            return 0;
                        else if(place === 2)
                            return 250/*(list.width-parent.width)/2*/
                        else
                            return 500
                    }
                    width: text.implicitWidth + 20
                    height: text.implicitHeight + 20
                    Material.background: Material.Grey
                    Material.elevation: 8

                    Text{
                        anchors.centerIn: parent
                        id: text
                        text: message
                    }
                }
            }
        }
        RowLayout{
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width - 20
            TextField {
                id: textField
                Layout.fillWidth: true
                placeholderText: "write messsage"
            }
            Button {
                id: button
                x: 549
                y: 414
                text: qsTr("send")
                onClicked: {
                    Client.sendMessage(textField.text)
                    textField.text = ""
                }
            }
        }
    }
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++
    ListModel{
        id:listmodel
        ListElement{message:"peacht" ; place:2}
    }

    ListModel{
        id:onlineUserListModel_Id
//        ListElement{username:"peacht"}
    }
}
