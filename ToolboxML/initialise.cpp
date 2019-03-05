#include "initialise.h"

#include <QtQml>

#include "ToolEvents.h"

#include "ProxyTool.h"
#include "ToolAction.h"
#include "Tool.h"
#include "ToolController.h"


void initialise_ToolboxML_qrc()
{
  Q_INIT_RESOURCE(ToolboxML);
}

namespace ToolboxML
{
  void initialise()
  {
    initialise_ToolboxML_qrc();
    const char* uri = "ToolboxML";
    qmlRegisterUncreatableType<AbstractTool>(uri, 1, 0, "AbstractTool", "It is a virtual class");
    qmlRegisterUncreatableType<MouseToolEvent>(uri, 1, 0, "MouseToolEvent", "Not useful");
    qmlRegisterUncreatableType<WheelToolEvent>(uri, 1, 0, "WheelToolEvent", "Not useful");
    
    qmlRegisterType<Tool>               (uri, 1, 0, "Tool");
    qmlRegisterType<ToolAction>         (uri, 1, 0, "ToolAction");
    qmlRegisterType<ToolController>     (uri, 1, 0, "ToolController");
    qmlRegisterType<ProxyTool>          (uri, 1, 0, "ProxyTool");
    
    const char* uri_controls = "ToolboxML.Controls";
    qmlRegisterType(QUrl("qrc:/qml/ToolboxML/Controls1/ToolAction.qml"), uri_controls, 1, 0, "ToolAction");
    qmlRegisterType(QUrl("qrc:/qml/ToolboxML/Controls1/ToolActionsGroup.qml"), uri_controls, 1, 0, "ToolActionsGroup");

    qmlRegisterType(QUrl("qrc:/qml/ToolboxML/Controls2/ToolAction.qml"), uri_controls, 2, 0, "ToolAction");
    qmlRegisterType(QUrl("qrc:/qml/ToolboxML/Controls2/ToolActionsGroup.qml"), uri_controls, 2, 0, "ToolActionsGroup");
  }
}
