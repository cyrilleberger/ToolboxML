import QtQuick 2.0
import QtQuick.Controls 1.4
import ToolboxML 1.0


Action
{
  id: root
  property QtObject tool
  property QtObject group
  onTriggered: root.group.tool = tool
  checkable: true
}

