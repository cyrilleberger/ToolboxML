import QtQuick 2.0
import QtQuick.Controls 2.3
import ToolboxML 1.0

Action
{
  id: root
  property QtObject tool
  property QtObject group
  onTriggered: root.group.tool = tool
  checkable: true
}

