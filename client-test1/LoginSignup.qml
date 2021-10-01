import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.3
import QtGraphicalEffects 1.15

Item {
    id:root
    property string language:"English"
    signal goContact(string username);

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    Item{
        id:topItem_Id
        width: parent.width
        height: 40
        z:2
        Rectangle{
            anchors.fill: parent
            color: Material.color(Material.Pink)
            Material.elevation: 6
            Rectangle{
                x:(parent.width-width) / 2
                y:parent.height - height/2
                width: 50
                height: width
                radius: width
                color: "white"

                Rectangle{
                    anchors.centerIn: parent
                    width: 40
                    height: width
                    radius: width
                    color: Material.color(Material.Pink)
                    MouseArea{
                        anchors.fill: parent
                        cursorShape: "PointingHandCursor"
                        hoverEnabled: true
                        onClicked: {
                            if(topItem_Id.height === 40)
                            {
                                topItem_Id.height = 100
                                languageComboBox_Id.opacity = 1
                            }
                            else
                            {
                                topItem_Id.height = 40
                                languageComboBox_Id.opacity = 0
                            }
                        }
                    }
                }
            }
            ComboBox{
                id:languageComboBox_Id
                height: 40
                opacity: 0
                //                width: 80
                model: ["English", "Persian"]
                onCurrentTextChanged: {
                    language = currentText
                }
                Behavior on opacity {NumberAnimation{duration:600 ; easing.type:Easing.OutQuint}}
            }
        }
        Behavior on height {NumberAnimation{duration:500 ; easing.type:Easing.OutQuint}}
    }

    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    Image {
        id: image_Id
        source: "qrc:/image/image/login.jpg"
        x:parent.width/2
        width: parent.width/2
        height: parent.height
        Behavior on x{NumberAnimation{duration:600; easing.type:Easing.InOutQuint}}
    }

    Item{
        id:loginItem_Id
        height: parent.height
        width: parent.width/2

        Item{
            anchors.centerIn: parent
            width: parent.width/2
            height: parent.height/2


            ColumnLayout{
                //            width: 214
                //            height: 255
                anchors.fill: parent
                spacing: 15

                //1
                Label{
                    id:loginWelcomLabel_Id
                    Layout.alignment: Layout.Center
                    text: (Configure) ? Configure.translate("main.qml","loginWelcomLabel_Id",language) : ""
                    font{pointSize: 10}
                }
                //2
                Label{
                    id:loginTitleLabel_Id
                    Layout.alignment: Layout.Center
                    text: (Configure) ? Configure.translate("main.qml","loginTitleLabel_Id",language) : null
                    font{bold: true ; pointSize: 17}
                }
                //3
                TextField{
                    id:loginUsernameTextField_Id
                    Layout.fillWidth: true
                    height: 40
                    Label{
                        id:loginUsernameLabel_Id
                        text: (Configure) ? Configure.translate("main.qml","loginUsernameLabel_Id",language) : ""
                        color: "gray"
                        y:(loginUsernameTextField_Id.height - implicitHeight) / 2
                        x:0
                        scale: 1
                        Behavior on y{NumberAnimation{duration:200}}
                        Behavior on x{NumberAnimation{duration:200}}
                        Behavior on scale {NumberAnimation{duration:300}}
                    }
                    onFocusChanged: {
                        if(focus){
                            loginUsernameLabel_Id.y = (loginUsernameTextField_Id.height - loginUsernameLabel_Id.implicitHeight) / 2 - 20
                            loginUsernameLabel_Id.x = -10
                            loginUsernameLabel_Id.scale = 0.8
                        }
                        else{
                            if(loginUsernameTextField_Id.text === "")
                            {
                                loginUsernameLabel_Id.y = (loginUsernameTextField_Id.height - loginUsernameLabel_Id.implicitHeight) / 2
                                loginUsernameLabel_Id.x = 0
                                loginUsernameLabel_Id.scale = 1
                            }
                        }
                    }

                }
                //4
                TextField{
                    id:loginPasswordTextField_Id
                    Layout.fillWidth: true
                    height: 40
                    echoMode: TextInput.Password
                    Label{
                        id:loginPasswordLabel_Id
                        text: (Configure) ? Configure.translate("main.qml","loginPasswordLabel_Id",language) : null
                        color: "gray"
                        y:(loginPasswordTextField_Id.height - implicitHeight) / 2
                        x:0
                        scale: 1
                        Behavior on y{NumberAnimation{duration:200}}
                        Behavior on x{NumberAnimation{duration:200}}
                        Behavior on scale {NumberAnimation{duration:300}}
                    }
                    onFocusChanged: {
                        if(focus){
                            loginPasswordLabel_Id.y = (loginPasswordTextField_Id.height - loginPasswordLabel_Id.implicitHeight) / 2 - 20
                            loginPasswordLabel_Id.x = -10
                            loginPasswordLabel_Id.scale = 0.8
                        }
                        else{
                            if(loginPasswordTextField_Id.text === "")
                            {
                                loginPasswordLabel_Id.y = (loginPasswordTextField_Id.height - loginPasswordLabel_Id.implicitHeight) / 2
                                loginPasswordLabel_Id.x = 0
                                loginPasswordLabel_Id.scale = 1
                            }
                        }
                    }

                }
                //5
                Rectangle {
                    id: rectButton_Id
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Layout.fillWidth: true
                    height: 40
                    radius: 20
                    color: "#2cd8d5"
                    scale:1

                    gradient: Gradient {
                        GradientStop {position: 0;color: "#2cd8d5"}
                        GradientStop {position: 0.56;color: "#c5c1ff"}
                        GradientStop {position: 1;color: "#ffbac3"}
                    }
                    //                }

                    Label{
                        id:rectbuttonLabel_Id
                        anchors.centerIn: parent
                        text: (Configure) ? Configure.translate("main.qml","rectbuttonLabel_Id",language) : null
                    }
                    MouseArea{
                        id:rectButtonMouseArea_Id
                        anchors.fill: parent
                        cursorShape: "PointingHandCursor"
                        hoverEnabled: true
                        onClicked: {
                            if(loginUsernameTextField_Id.text !=="" && loginPasswordTextField_Id.text !== "")
                                if(Database.search(loginUsernameTextField_Id.text , loginPasswordTextField_Id.text))
                                {
                                    goContact(loginUsernameTextField_Id.text)
                                }


                            loginUsernameTextField_Id.text = ""
                            loginPasswordTextField_Id.text = ""
                        }
                        onEntered: {
                            rectButton_Id.scale = 1.1
                        }
                        onExited: {
                            rectButton_Id.scale = 1
                        }
                    }
                    Behavior on scale{NumberAnimation{duration:300}}
                }
                //6
                Label{
                    id:loginCreatAccountLabel_Id
                    text: (Configure) ?  Configure.translate("main.qml","loginCreatAccountLabel_Id",language) : null
                    Layout.alignment: Layout.Center
                    font{bold: true ; pointSize: 10}
                    MouseArea{
                        anchors.fill: parent
                        cursorShape: "PointingHandCursor"
                        hoverEnabled: true
                        onClicked: {
                            image_Id.x = 0;
                            signupItem_Id.x = root.width/2
                            loginItem_Id.x = -root.width/2

                        }
                    }
                }
            }
        }
        Behavior on x{NumberAnimation{duration:600;easing.type:Easing.InOutQuint}}
    }

    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++signup

    Item{
        id:signupItem_Id
        width:parent.width/2
        height: parent.height
        x:parent.width
        Item{
            anchors.centerIn: parent
            width: parent.width/2
            height: parent.height/2


            ColumnLayout{
                //            width: 214
                //            height: 255
                //            anchors.centerIn: parent
                anchors.fill: parent
                spacing: 15

                //1
                Label{
                    id:signupLabel_Id
                    Layout.alignment: Layout.Center
                    text:(Configure) ? Configure.translate("main.qml","signupLabel_Id",language) : null
                    font{pointSize: 10}
                }
                //2
                Label{
                    id:signupTitleLabel_Id
                    text: (Configure) ? Configure.translate("main.qml","signupTitleLabel_Id",language) : null
                    font{bold: true ; pointSize: 17}
                }
                //3
                TextField{
                    id:usernameSignupTextField_Id
                    Layout.fillWidth: true
                    height: 40
                    Label{
                        id:usernameSignupLabel_Id
                        text: (Configure) ? Configure.translate("main.qml","usernameSignupLabel_Id",language) : ""
                        color: "gray"
                        y:(usernameSignupTextField_Id.height - implicitHeight) / 2
                        x:0
                        scale: 1
                        Behavior on y{NumberAnimation{duration:200}}
                        Behavior on x{NumberAnimation{duration:200}}
                        Behavior on scale {NumberAnimation{duration:300}}
                    }
                    onFocusChanged: {
                        if(focus){
                            usernameSignupLabel_Id.y = (usernameSignupTextField_Id.height - usernameSignupLabel_Id.implicitHeight) / 2 - 20
                            usernameSignupLabel_Id.x = -10
                            usernameSignupLabel_Id.scale = 0.8
                        }
                        else{
                            if(usernameSignupTextField_Id.text === "")
                            {
                                usernameSignupLabel_Id.y = (usernameSignupTextField_Id.height - usernameSignupLabel_Id.implicitHeight) / 2
                                usernameSignupLabel_Id.x = 0
                                usernameSignupLabel_Id.scale = 1
                            }
                        }
                    }

                }
                //4
                TextField{
                    id:passwordSignupTextField_Id
                    Layout.fillWidth: true
                    height: 40
                    echoMode: TextInput.Password
                    Label{
                        id:passwordSignupLabel_Id
                        text: (Configure) ? Configure.translate("main.qml","passwordSignupLabel_Id",language) : null
                        color: "gray"
                        y:(passwordSignupTextField_Id.height - implicitHeight) / 2
                        x:0
                        scale: 1
                        Behavior on y{NumberAnimation{duration:200}}
                        Behavior on x{NumberAnimation{duration:200}}
                        Behavior on scale {NumberAnimation{duration:300}}
                    }
                    onFocusChanged: {
                        if(focus){
                            passwordSignupLabel_Id.y = (passwordSignupTextField_Id.height - passwordSignupLabel_Id.implicitHeight) / 2 - 20
                            passwordSignupLabel_Id.x = -10
                            passwordSignupLabel_Id.scale = 0.8
                        }
                        else{
                            if(passwordSignupTextField_Id.text === "")
                            {
                                passwordSignupLabel_Id.y = (passwordSignupTextField_Id.height - passwordSignupLabel_Id.implicitHeight) / 2
                                passwordSignupLabel_Id.x = 0
                                passwordSignupLabel_Id.scale = 1
                            }
                        }
                    }
                }
                //5
                TextField{
                    id:rePasswordSignupTextField_Id
                    Layout.fillWidth: true
                    height: 40
                    echoMode: TextInput.Password
                    Label{
                        id:rePasswordSignupLabel_Id
                        text:(Configure) ?  Configure.translate("main.qml","rePasswordSignupLabel_Id",language) : null
                        color: "gray"
                        y:(rePasswordSignupTextField_Id.height - implicitHeight) / 2
                        x:0
                        scale: 1
                        Behavior on y{NumberAnimation{duration:200}}
                        Behavior on x{NumberAnimation{duration:200}}
                        Behavior on scale {NumberAnimation{duration:300}}
                    }
                    onFocusChanged: {
                        if(focus){
                            rePasswordSignupLabel_Id.y = (rePasswordSignupTextField_Id.height - rePasswordSignupLabel_Id.implicitHeight) / 2 - 20
                            rePasswordSignupLabel_Id.x = -10
                            rePasswordSignupLabel_Id.scale = 0.8
                        }
                        else{
                            if(rePasswordSignupTextField_Id.text === "")
                            {
                                rePasswordSignupLabel_Id.y = (rePasswordSignupTextField_Id.height - rePasswordSignupLabel_Id.implicitHeight) / 2
                                rePasswordSignupLabel_Id.x = 0
                                rePasswordSignupLabel_Id.scale = 1
                            }
                        }
                    }
                }
                //6
                TextField{
                    id:emailSignupTextField_Id
                    Layout.fillWidth: true
                    height: 40
                    Label{
                        id:emailSignupLabel_Id
                        text: (Configure) ? Configure.translate("main.qml","emailSignupLabel_Id",language) : ""
                        color: "gray"
                        y:(emailSignupTextField_Id.height - implicitHeight) / 2
                        x:0
                        scale: 1
                        Behavior on y{NumberAnimation{duration:200}}
                        Behavior on x{NumberAnimation{duration:200}}
                        Behavior on scale {NumberAnimation{duration:300}}
                    }
                    onFocusChanged: {
                        if(focus){
                            emailSignupLabel_Id.y = (emailSignupTextField_Id.height - emailSignupLabel_Id.implicitHeight) / 2 - 20
                            emailSignupLabel_Id.x = -10
                            emailSignupLabel_Id.scale = 0.8
                        }
                        else{
                            if(emailSignupTextField_Id.text === "")
                            {
                                emailSignupLabel_Id.y = (emailSignupTextField_Id.height - emailSignupLabel_Id.implicitHeight) / 2
                                emailSignupLabel_Id.x = 0
                                emailSignupLabel_Id.scale = 1
                            }
                        }
                    }
                }
                //7
                Rectangle {
                    id: rectSignupButton_Id
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    width: usernameSignupTextField_Id.width
                    height: 40
                    radius: 20
                    color: "#2cd8d5"
                    scale:1

                    gradient: Gradient {
                        GradientStop {position: 0;color: "#2cd8d5"}
                        GradientStop {position: 0.56;color: "#c5c1ff"}
                        GradientStop {position: 1;color: "#ffbac3"}
                    }

                    Label{
                        anchors.centerIn: parent
                        text: (Configure) ? Configure.translate("main.qml","rectSignupButton_Id",language) : ""
                    }
                    MouseArea{
                        id:rectSignupButtonMouseArea_Id
                        anchors.fill: parent
                        hoverEnabled: true
                        onClicked: {
                            //                        if
//                            Database.insert(usernameSignupTextField_Id.text , passwordSignupTextField_Id.text)
                            usernameSignupTextField_Id.text = ""
                            passwordSignupTextField_Id.text = ""
                            rePasswordSignupTextField_Id.text = ""
                            emailSignupTextField_Id.text = ""
                        }
                        onEntered: {
                            rectSignupButton_Id.scale = 1.1
                        }
                        onExited: {
                            rectSignupButton_Id.scale = 1
                        }
                    }
                    Behavior on scale{NumberAnimation{duration:300}}
                }
                //6
                Label{
                    id:signupHaveAccountLabel_Id
                    text: (Configure) ? Configure.translate("main.qml","signupHaveAccountLabel_Id",language) : ""
                    Layout.alignment: Layout.Center
                    font{bold: true ; pointSize: 10}
                    MouseArea{
                        anchors.fill: parent
                        cursorShape: "PointingHandCursor"
                        hoverEnabled: true
                        onClicked: {
                            image_Id.x = root.width/2;
                            signupItem_Id.x = root.width
                            loginItem_Id.x = 0

                        }
                    }
                }
            }
        }
        Behavior on x{NumberAnimation{duration:600;easing.type:Easing.InOutQuint}}
    }

}
