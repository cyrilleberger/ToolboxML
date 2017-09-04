import QtQuick 2.0
import QtQuick.Controls 1.4
import ToolboxML 1.0

ExclusiveGroup
{
  id: root
  property QtObject tool
  property list<ToolAction> toolsActions
  default property alias defaultActionsProperty: root.toolsActions
  Component.onCompleted: {
    for(var a in root.toolsActions)
    {
      var act = root.toolsActions[a]
      act.group = root
      act.exclusiveGroup = root
      if(act.checked)
      {
        root.tool = act.tool
      }
    }
  }
}
