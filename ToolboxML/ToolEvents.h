#ifndef _TOOLEVENTS_H_
#define _TOOLEVENTS_H_

#include <QKeyEvent>
#include <QMouseEvent>

#include "AbstractViewInterface.h"

namespace ToolboxML
{

  class KeyToolEvent : public QObject
  {
      Q_OBJECT
      Q_PROPERTY(int key READ key)
      Q_PROPERTY(QString text READ text)
      Q_PROPERTY(int modifiers READ modifiers)
      Q_PROPERTY(bool isAutoRepeat READ isAutoRepeat)
      Q_PROPERTY(int count READ count)
      Q_PROPERTY(quint32 nativeScanCode READ nativeScanCode)
      Q_PROPERTY(bool accepted READ isAccepted WRITE setAccepted)
  public:
      KeyToolEvent() : event(QEvent::None, 0, Qt::NoModifier)
      {}
      void reset(const QKeyEvent &ke)
      {
          event = ke;
      }
      int key() const { return event.key(); }
      QString text() const { return event.text(); }
      int modifiers() const { return event.modifiers(); }
      bool isAutoRepeat() const { return event.isAutoRepeat(); }
      int count() const { return event.count(); }
      quint32 nativeScanCode() const { return event.nativeScanCode(); }
      bool isAccepted() { return event.isAccepted(); }
      void setAccepted(bool accepted) { event.setAccepted(accepted); }
      Q_INVOKABLE bool matches(QKeySequence::StandardKey key) const { return event.matches(key); }
  private:
      QKeyEvent event;
  };
  class MouseToolEvent : public QObject
  {
      Q_OBJECT
      Q_PROPERTY(qreal x READ x)
      Q_PROPERTY(qreal y READ y)
      Q_PROPERTY(int button READ button)
      Q_PROPERTY(int buttons READ buttons)
      Q_PROPERTY(int modifiers READ modifiers)
      Q_PROPERTY(bool accepted READ isAccepted WRITE setAccepted)
  public:
      MouseToolEvent() : m_pos(QPointF()), m_button(Qt::NoButton), m_buttons(Qt::NoButton), m_modifiers(Qt::NoModifier), m_accepted(false)
      {}
      ~MouseToolEvent() {}
      void reset(const QMouseEvent& me, const AbstractViewInterface* _interface)
      {
        if(_interface) m_pos = _interface->fromView(me.pos());
        else m_pos = me.pos();
        m_button = me.button();
        m_buttons = me.buttons();
        m_modifiers = me.modifiers();
        m_accepted = me.isAccepted();
      }
      void reset(const QHoverEvent& he, const AbstractViewInterface* _interface)
      {
        if(_interface) m_pos = _interface->fromView(he.pos());
        else m_pos = he.pos();
        m_button = Qt::NoButton;
        m_buttons = Qt::NoButton;
        m_modifiers = he.modifiers();
        m_accepted = he.isAccepted();
      }
      qreal x() const { return m_pos.x(); }
      qreal y() const { return m_pos.y(); }
      int button() const { return m_button; }
      int buttons() const { return m_buttons; }
      int modifiers() const { return m_modifiers; }
      bool isAccepted() { return m_accepted; }
      void setAccepted(bool accepted) { m_accepted = accepted; }
  private:
      QPointF m_pos;
      int m_button, m_buttons, m_modifiers;
      bool m_accepted;
  };
  class WheelToolEvent : public QObject
  {
      Q_OBJECT
      Q_PROPERTY(qreal x READ x)
      Q_PROPERTY(qreal y READ y)
      Q_PROPERTY(QPoint angleDelta READ angleDelta)
      Q_PROPERTY(QPoint pixelDelta READ pixelDelta)
      Q_PROPERTY(int buttons READ buttons)
      Q_PROPERTY(int modifiers READ modifiers)
      Q_PROPERTY(bool accepted READ isAccepted WRITE setAccepted)
  public:
      WheelToolEvent() : m_pos(QPointF()), m_angleDelta(QPoint()), m_pixelDelta(QPoint()), m_buttons(Qt::NoButton), m_modifiers(Qt::NoModifier), m_accepted(false)
      {}
      void reset(const QWheelEvent& we, const AbstractViewInterface* _interface)
      {
        if(_interface) m_pos = _interface->fromView(we.pos());
        else m_pos = we.pos();
        m_angleDelta = we.angleDelta();
        m_pixelDelta = we.pixelDelta();
        m_buttons = we.buttons();
        m_modifiers = we.modifiers();
        m_accepted = we.isAccepted();
      }
      qreal x() const { return m_pos.x(); }
      qreal y() const { return m_pos.y(); }
      QPoint angleDelta() const { return m_angleDelta; }
      QPoint pixelDelta() const { return m_pixelDelta; }
      int buttons() const { return m_buttons; }
      int modifiers() const { return m_modifiers; }
      bool isAccepted() { return m_accepted; }
      void setAccepted(bool accepted) { m_accepted = accepted; }
  private:
    QPointF m_pos;
    QPoint m_angleDelta, m_pixelDelta;
    int m_buttons, m_modifiers;
    bool m_accepted;
  };
}

#endif

