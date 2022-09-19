import QtQuick 2.15
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

GridLayout {
    id: grid
    property alias hour: hour
    property alias minute: minute
    property int minimumInputSize: 60

    rows: 1
    columns: 3

    TextField
    {
        id: hour
        Layout.fillWidth: true
        Layout.minimumWidth: grid.minimumInputSize
        Layout.alignment: Qt.AlignLeft | Qt.AlignBaseline
        placeholderText: qsTr("HH")
        maximumLength: 2
        validator: IntValidator {bottom: 1; top: 24;}
        focus: true
    }

    Label
    {
        text: qsTr(":")
        Layout.alignment: Qt.AlignCenter
    }

    TextField
    {
        id: minute
        Layout.fillWidth: true
        Layout.minimumWidth: grid.minimumInputSize
        Layout.alignment: Qt.AlignLeft | Qt.AlignBaseline
        placeholderText: qsTr("MM")
        maximumLength: 2
        validator: IntValidator {bottom: 0; top: 59;}
        focus: true
    }
}
