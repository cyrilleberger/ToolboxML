#include "ToolController.h"

#include "AbstractTool.h"
#include "ToolEvents.h"

using namespace ToolboxML;

struct ToolController::Private
{
  AbstractTool* tool = nullptr;
  MouseToolEvent mte;
  WheelToolEvent wte;
  AbstractViewInterface* viewInterface = nullptr;
};

ToolController::ToolController(QQuickItem* parent): QQuickItem(parent), d(new Private)
{
  setAcceptedMouseButtons(Qt::AllButtons);
}

ToolController::~ToolController()
{
  delete d;
}

AbstractTool* ToolController::tool() const
{
  return d->tool;
}

void ToolController::setTool(AbstractTool* _tool)
{
  if(d->tool)
  {
    disconnect(d->tool, SIGNAL(hoverEnabledChanged()), this, SLOT(toolHoverEnabledHasChanged()));
    d->tool->toolDeactivated();
  }
  d->tool = _tool;
  emit(toolChanged());
  if(d->tool)
  {
    connect(d->tool, SIGNAL(hoverEnabledChanged()), this, SLOT(toolHoverEnabledHasChanged()));
    d->tool->toolActivated();
  }
}

AbstractViewInterface * ToolController::viewInterface() const
{
  return d->viewInterface;
}

void ToolController::setViewInterface(AbstractViewInterface* _viewInterface)
{
  d->viewInterface = _viewInterface;
  emit(viewInterfaceChanged());
}

QObject* ToolController::viewInterfaceASQObject() const
{
  return dynamic_cast<QObject*>(d->viewInterface);
}

void ToolController::setViewInterface(QObject* _object)
{
  d->viewInterface = qobject_cast<AbstractViewInterface*>(_object);
  emit(viewInterfaceChanged());
}

void ToolController::mouseDoubleClickEvent(QMouseEvent* event)
{
  if(d->tool)
  {
    event->accept();
    d->mte.reset(*event, d->viewInterface);
    d->tool->mouseDoubleClickEvent(&d->mte);
    event->setAccepted(d->mte.isAccepted());
  } else {
    QQuickItem::mouseDoubleClickEvent(event);
  }
}

void ToolController::mouseMoveEvent(QMouseEvent* event)
{
  if(d->tool)
  {
    event->accept();
    d->mte.reset(*event, d->viewInterface);
    d->tool->mouseMoveEvent(&d->mte);
    event->setAccepted(d->mte.isAccepted());
  } else {
    QQuickItem::mouseMoveEvent(event);
  }
}

void ToolController::mousePressEvent(QMouseEvent* event)
{
  if(d->tool)
  {
    event->accept();
    d->mte.reset(*event, d->viewInterface);
    d->tool->mousePressEvent(&d->mte);
    event->setAccepted(d->mte.isAccepted());
  } else {
    QQuickItem::mousePressEvent(event);
  }
}

void ToolController::mouseReleaseEvent(QMouseEvent* event)
{
  if(d->tool)
  {
    event->accept();
    d->mte.reset(*event, d->viewInterface);
    d->tool->mouseReleaseEvent(&d->mte);
    event->setAccepted(d->mte.isAccepted());
  } else {
    QQuickItem::mouseReleaseEvent(event);
  }
}

void ToolController::wheelEvent(QWheelEvent* event)
{
  if(d->tool)
  {
    event->accept();
    d->wte.reset(*event, d->viewInterface);
    d->tool->wheelEvent(&d->wte);
    event->setAccepted(d->wte.isAccepted());
  } else {
    QQuickItem::wheelEvent(event);
  }
}

void ToolController::hoverEnterEvent(QHoverEvent* event)
{
  if(d->tool)
  {
    event->accept();
    d->mte.reset(*event, d->viewInterface);
    d->tool->mouseMoveEvent(&d->mte);
    event->setAccepted(d->mte.isAccepted());
  } else {
    QQuickItem::hoverEnterEvent(event);
  }
}

void ToolController::hoverLeaveEvent(QHoverEvent* event)
{
  if(d->tool)
  {
    event->accept();
    d->mte.reset(*event, d->viewInterface);
    d->tool->mouseMoveEvent(&d->mte);
    event->setAccepted(d->mte.isAccepted());
  } else {
    QQuickItem::hoverLeaveEvent(event);
  }
}

void ToolController::hoverMoveEvent(QHoverEvent* event)
{
  if(d->tool)
  {
    event->accept();
    d->mte.reset(*event, d->viewInterface);
    d->tool->mouseMoveEvent(&d->mte);
    event->setAccepted(d->mte.isAccepted());
  } else {
    QQuickItem::hoverMoveEvent(event);
  }
}

void ToolController::toolHoverEnabledHasChanged()
{
  setAcceptHoverEvents(d->tool->isHoverEnabled());
}

#include "moc_ToolController.cpp"

