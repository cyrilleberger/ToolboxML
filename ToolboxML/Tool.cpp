#include "Tool.h"

#include <QMouseEvent>

#include "ToolEvents.h"

using namespace ToolboxML;

Tool::Tool(QObject* _parent): AbstractTool(_parent)
{

}

Tool::~Tool()
{

}

void Tool::mouseDoubleClickEvent(MouseToolEvent* event)
{
  emit(doubleClicked(event));
  event->setAccepted(not m_propagateEvents);
}

void Tool::mouseMoveEvent(MouseToolEvent* event)
{
  emit(positionChanged(event));
  event->setAccepted(not m_propagateEvents);
}

void Tool::mousePressEvent(MouseToolEvent* event)
{
  emit(pressed(event));
  event->setAccepted(not m_propagateEvents);
}

void Tool::mouseReleaseEvent(MouseToolEvent* event)
{
  emit(released(event));
  event->setAccepted(not m_propagateEvents);
}

void Tool::wheelEvent(WheelToolEvent* event)
{
  emit(wheel(event));
  event->setAccepted(not m_propagateEvents);
}

void Tool::toolActivated()
{
  emit(activated());
}

void Tool::toolDeactivated()
{
  emit(deactivated());
}

bool Tool::propagateEvents() const
{
  return m_propagateEvents;
}

void Tool::setPropagateEvents(bool _v)
{
  m_propagateEvents = _v;
  emit(propagateEventsChanged());
}

#include "moc_Tool.cpp"

