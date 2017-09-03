#include "initialise.h"

#include <QtQml>

#include "ToolEvents.h"

#include "ProxyTool.h"
#include "Tool.h"
#include "ToolController.h"

namespace ToolboxML
{
  void initialise()
  {
    const char* uri = "ToolboxML";
    qmlRegisterUncreatableType<AbstractTool>(uri, 1, 0, "AbstractTool", "It is a virtual class");
    qmlRegisterUncreatableType<MouseToolEvent>(uri, 1, 0, "MouseToolEvent", "Not useful");
    qmlRegisterUncreatableType<WheelToolEvent>(uri, 1, 0, "WheelToolEvent", "Not useful");
    
    qmlRegisterType<Tool>               (uri, 1, 0, "Tool");
    qmlRegisterType<ToolController>     (uri, 1, 0, "ToolController");
    qmlRegisterType<ProxyTool>          (uri, 1, 0, "ProxyTool");
  }
}
