import QtQuick 2.0
import QtQuick.Controls 2.3
import ToolboxML 1.0

ActionGroup
{
  id: root
  exclusive: true
  property QtObject tool
  property list<ToolAction> toolsActions
  default property alias defaultActionsProperty: root.toolsActions
  Component.onCompleted: {
    for(var a in root.toolsActions)
    {
      var act = root.toolsActions[a]
      root.addGroup(act)
      act.group = root
      if(act.checked)
      {
        root.tool = act.tool
      }
    }
  }
}
