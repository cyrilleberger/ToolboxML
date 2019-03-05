#include "ToolAction.h"

using namespace ToolboxML;

struct ToolAction::Private
{
  QString text, icon;
  bool checkable  = false;
  bool checked    = false;
  bool enabled    = true;
};

ToolAction::ToolAction(QObject* _parent) : QObject(_parent), d(new Private)
{
}

ToolAction::~ToolAction()
{
  delete d;
}

QString ToolAction::text() const
{
  return d->text;
}

void ToolAction::setText(const QString& _text)
{
  if(d->text != _text)
  {
    d->text = _text;
    emit(textChanged());
  }
}

QString ToolAction::icon() const
{
  return d->icon;
}

void ToolAction::setIcon(const QString& _icon)
{
  if(d->icon != _icon)
  {
    d->icon = _icon;
    emit(iconChanged());
  }
}

bool ToolAction::isCheckable() const
{
  return d->checkable;
}

void ToolAction::setCheckable(bool _checkable)
{
  if(d->checkable != _checkable)
  {
    d->checkable = _checkable;
    emit(checkableChanged());
  }
}

bool ToolAction::isChecked() const
{
  return d->checked;
}

void ToolAction::setChecked(bool _checked)
{
  if(d->checked != _checked)
  {
    d->checked = _checked;
    emit(checkedChanged());
  }
}

bool ToolAction::isEnabled() const
{
  return d->enabled;
}

void ToolAction::setEnabled(bool _enabled)
{
  if(d->enabled != _enabled)
  {
    d->enabled = _enabled;
    emit(enabledChanged());
  }
}

#include "moc_ToolAction.cpp"
