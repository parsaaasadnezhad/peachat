import QtQuick 2.12
import QtQuick.Controls 2.5

ApplicationWindow{
    width: 400
    height: 600
    visible: true
    title: qsTr("Hello World")

    Component.onCompleted: loader_Id.sourceComponent = loginSignupComponent_Id


    function qmlJsFunction(value)
    {
//        listmodel.append({"message":value})
        console.log(value)
        console.log("main")
        contactComponent_Id.message = value
    }

    Loader{
        id:loader_Id
        anchors.fill: parent
    }

    Component{
        id:contactComponent_Id
        Contact{
            id:contact_Id
        }
    }
    Component{
        id:loginSignupComponent_Id
        LoginSignup{
            onGoContact:{
                console.log(username)
                loader_Id.sourceComponent = contactComponent_Id
            }
        }
    }

//    TextField{
//        id:text_Id
//        x: 133
//        y: 380
//        anchors.bottom: button.top
//        anchors.bottomMargin: -40
//        placeholderText: "message"
//    }

//    Button{
//        id:button
//        anchors.verticalCenterOffset: 170
//        anchors.horizontalCenterOffset: 69
//        anchors.centerIn: parent
//        onClicked: {
//            Client.sendMessage(text_Id.text)
//        }
//    }

//    TextArea {
//        id: textArea
//        x: 139
//        y: 38
//        width: 292
//        height: 339
//        placeholderText: qsTr("Text Area")
//    }
}
