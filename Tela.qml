import QtQuick 2.15
import QtQuick.Controls 2.12

Dialog {
    id: dialog

    signal finished(string hour, string minute)

    function createTime() {
        form.hour.clear();
        form.minute.clear();

        dialog.title = qsTr("Escolher horario");
        dialog.open();
    }

    function isValidTime():Boolean {
        if(false == form.hour.acceptableInput || false == form.minute.acceptableInput)
        {
            contactDialog.createTime();
            return false;
        }
        return true;
    }

    x: parent.width / 2 - width / 2
    y: parent.height / 2 - height / 2

    standardButtons: Dialog.Ok | Dialog.Cancel

    contentItem: Form {
        id: form
    }

    onAccepted: finished(form.hour.text, form.minute.text)
}
