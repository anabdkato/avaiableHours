import QtQuick 2.12
import QtQuick.Controls 2.12
import FileIO 1.0

ApplicationWindow {
    id: window

    width: 360
    height: 900
    visible: true
    title: qsTr("Adicione um horário")

    Tela {
        id: contactDialog
        onFinished: {
            if(contactDialog.isValidTime())
            {
                myText.text = "";
                for(var i = 0; i < myFile.avaiableHours(myFile.source, hour, minute).length; i++)
                    myText.text +=  myFile.avaiableHours(myFile.source, hour, minute)[i] + "\n";
            }
        }
    }

    Text {
        id: myText
        text: "Veja os restaurantes abertos"
        anchors.centerIn: parent
    }

    FileIO {
        id: myFile
        source: ":/restaurant_hours.csv"
        onError: console.log(msg)
    }

    RoundButton {
        text: qsTr("Adicionar horarios")
        highlighted: true
        anchors.margins: 10
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        onClicked: {
            contactDialog.createTime()
        }
    }
}
