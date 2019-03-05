#ifndef _ABSTRACTOOL_H_
#define _ABSTRACTOOL_H_

#include <QObject>
#include <QQmlListProperty>

class QQmlComponent;

namespace ToolboxML
{
  class ToolAction;
  class MouseToolEvent;
  class ProxyTool;
  class ToolController;
  class WheelToolEvent;

  class AbstractTool : public QObject
  {
    friend class ToolController;
    friend class ProxyTool;
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(bool hoverEnabled READ isHoverEnabled WRITE setHoveredEnabled NOTIFY hoverEnabledChanged)
    Q_PROPERTY(QQmlComponent* optionsComponent READ optionsComponent WRITE setOptionsComponent NOTIFY optionsComponentChanged)
    Q_PROPERTY(QQmlComponent* overlayComponent READ overlayComponent WRITE setOverlayComponent NOTIFY overlayComponentChanged)
    Q_PROPERTY(QQmlListProperty<ToolboxML::ToolAction> actions READ actionsList NOTIFY actionsChanged)
    Q_PROPERTY(QQmlListProperty<QObject> children READ childrenList)
    Q_CLASSINFO("DefaultProperty", "children")
  public:
    AbstractTool(QObject* _parent = 0);
    ~AbstractTool();
    bool isHoverEnabled() const;
    void setHoveredEnabled(bool _v);
    QQmlComponent* optionsComponent() const;
    void setOptionsComponent(QQmlComponent* _component);
    QQmlComponent* overlayComponent() const;
    void setOverlayComponent(QQmlComponent* _component);
    QString name() const;
    void setName(const QString& _name);
  signals:
    void hoverEnabledChanged();
    void featuresSourceChanged();
    void optionsComponentChanged();
    void overlayComponentChanged();
    void mapViewChanged();
    void nameChanged();
    void actionsChanged();
  protected:
    virtual void toolActivated();
    virtual void toolDeactivated();
    virtual void mouseDoubleClickEvent(MouseToolEvent* event);
    virtual void mouseMoveEvent(MouseToolEvent* event);
    virtual void mousePressEvent(MouseToolEvent* event);
    virtual void mouseReleaseEvent(MouseToolEvent* event);
    virtual void wheelEvent(WheelToolEvent* event);
  private:
    QQmlListProperty<ToolAction> actionsList() const;
    static void actions_append(QQmlListProperty<ToolAction>* _list, ToolAction* _layer);
    static int actions_count(QQmlListProperty<ToolAction>* _list);
    static ToolAction* actions_at(QQmlListProperty<ToolAction>* _list, int _index);
    static void actions_clear(QQmlListProperty<ToolAction>* _list);
  private:
    QQmlListProperty<QObject> childrenList() const;
    static void children_append(QQmlListProperty<QObject>* _list, QObject* _layer);
    static int children_count(QQmlListProperty<QObject>* _list);
    static QObject* children_at(QQmlListProperty<QObject>* _list, int _index);
    static void children_clear(QQmlListProperty<QObject>* _list);
  private:
    struct Private;
    Private* const d;
  };
}

#endif

