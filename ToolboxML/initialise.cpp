#include "initialise.h"

#include <QtQml>

#include "ProxyTool.h"
#include "Tool.h"
#include "ToolController.h"

namespace ToolboxML
{
  void initialise()
  {
    const char* uri = "ToolboxML";
    
    qmlRegisterType<Tool>               (uri, 1, 0, "Tool");
    qmlRegisterType<ToolController>     (uri, 1, 0, "ToolController");
    qmlRegisterType<ProxyTool>          (uri, 1, 0, "ProxyTool");
    
  }
}
