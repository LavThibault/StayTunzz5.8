import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

   ListView{
       model:trackModel
       anchors.fill: parent
       id : lisTest
       delegate : Item{
           height:100
           width:100
           Label{
               anchors.fill: parent
               text:model.trackName
           }
       }

   }
}
