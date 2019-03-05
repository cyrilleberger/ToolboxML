#include "AbstractTool.h"

#include "ToolAction.h"
#include "ToolEvents.h"

using namespace ToolboxML;

struct AbstractTool::Private
{
  QString name;
  bool hoverEnabled = false;
  QQmlComponent* optionsComponent = nullptr;
  QQmlComponent* overlayComponent = nullptr;
  QList<QObject*> children;
  QList<ToolAction*> actions;
};

AbstractTool::AbstractTool(QObject* _parent): QObject(_parent), d(new Private)
{
  d->name = QObject::tr("unnamed tool");
}

AbstractTool::~AbstractTool()
{

}

void AbstractTool::toolActivated()
{

}

void AbstractTool::toolDeactivated()
{

}

void AbstractTool::mouseDoubleClickEvent(MouseToolEvent* event)
{
  event->setAccepted(false);
}

void AbstractTool::mouseMoveEvent(MouseToolEvent* event)
{
  event->setAccepted(false);
}

void AbstractTool::mousePressEvent(MouseToolEvent* event)
{
  event->setAccepted(false);
}

void AbstractTool::mouseReleaseEvent(MouseToolEvent* event)
{
  event->setAccepted(false);
}

void AbstractTool::wheelEvent(WheelToolEvent* event)
{
  event->setAccepted(false);
}

QString AbstractTool::name() const
{
  return d->name;
}

void AbstractTool::setName(const QString& _name)
{
  if(d->name != _name)
  {
    d->name = _name;
    emit(nameChanged());
  }
}

bool AbstractTool::isHoverEnabled() const
{
  return d->hoverEnabled;
}

void AbstractTool::setHoveredEnabled(bool _v)
{
  if(d->hoverEnabled != _v)
  {
    d->hoverEnabled = _v;
    emit(hoverEnabledChanged());
  }
}

QQmlComponent* AbstractTool::optionsComponent() const
{
  return d->optionsComponent;
}

void AbstractTool::setOptionsComponent(QQmlComponent* _component)
{
  d->optionsComponent = _component;
  emit(optionsComponentChanged());
}

QQmlComponent* AbstractTool::overlayComponent() const
{
  return d->overlayComponent;
}

void AbstractTool::setOverlayComponent(QQmlComponent* _component)
{
  d->overlayComponent = _component;
  emit(overlayComponentChanged());
}

QQmlListProperty<ToolAction> AbstractTool::actionsList() const
{
  return QQmlListProperty<ToolAction>(const_cast<AbstractTool*>(this), 0, AbstractTool::actions_append, AbstractTool::actions_count, AbstractTool::actions_at, AbstractTool::actions_clear);
}

void AbstractTool::actions_append(QQmlListProperty<ToolAction>* _list, ToolAction* _layer)
{
  qobject_cast<AbstractTool*>(_list->object)->d->actions.append(_layer);
}

int AbstractTool::actions_count(QQmlListProperty<ToolAction>* _list)
{
  return qobject_cast<AbstractTool*>(_list->object)->d->actions.size();
}

ToolAction * AbstractTool::actions_at(QQmlListProperty<ToolAction>* _list, int _index)
{
  return qobject_cast<AbstractTool*>(_list->object)->d->actions.at(_index);
}

void AbstractTool::actions_clear(QQmlListProperty<ToolAction>* _list)
{
  qobject_cast<AbstractTool*>(_list->object)->d->actions.clear();
}

QQmlListProperty<QObject> AbstractTool::childrenList() const
{
  return QQmlListProperty<QObject>(const_cast<AbstractTool*>(this), 0, AbstractTool::children_append, AbstractTool::children_count, AbstractTool::children_at, AbstractTool::children_clear);
}

// static children_* functions

void AbstractTool::children_append(QQmlListProperty<QObject>* _tool, QObject* _child)
{
  _child->setParent(_tool->object);
}

int AbstractTool::children_count(QQmlListProperty<QObject>* _tool)
{
  return _tool->object->children().count();
}

QObject* AbstractTool::children_at(QQmlListProperty<QObject>* _tool, int _index)
{
  return _tool->object->children()[_index];
}

void AbstractTool::children_clear(QQmlListProperty<QObject>* _tool)
{
  for(QObject* obj : _tool->object->children())
  {
    obj->setParent(nullptr);
    obj->deleteLater();
  }
}


#include "moc_AbstractTool.cpp"

