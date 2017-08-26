#ifndef _TOOLBOXML_TOOL_H_
#define _TOOLBOXML_TOOL_H_

#include "AbstractTool.h"

namespace ToolboxML
{
  class ToolController;
  class Tool : public AbstractTool
  {
    Q_OBJECT
  public:
    Tool(QObject* _parent = 0);
    ~Tool();
  protected:
    virtual void mouseDoubleClickEvent(MouseToolEvent* event);
    virtual void mouseMoveEvent(MouseToolEvent* event);
    virtual void mousePressEvent(MouseToolEvent* event);
    virtual void mouseReleaseEvent(MouseToolEvent* event);
    virtual void wheelEvent(WheelToolEvent* event);
    virtual void toolActivated();
    virtual void toolDeactivated();
  signals:
    void activated();
    void deactivated();
    void doubleClicked(ToolboxML::MouseToolEvent* mouse);
    void pressed(ToolboxML::MouseToolEvent* mouse);
    void positionChanged(ToolboxML::MouseToolEvent* mouse);
    void released(ToolboxML::MouseToolEvent* mouse);
    void wheel(ToolboxML::WheelToolEvent* wheel);
  };
}

#endif

