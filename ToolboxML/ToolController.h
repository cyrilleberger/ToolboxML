#ifndef _TOOLBOXML_TOOLCONTROLLER_H_
#define _TOOLBOXML_TOOLCONTROLLER_H_

#include <QQuickItem>

namespace ToolboxML
{
  class AbstractTool;
  class AbstractViewInterface;
  class ToolController : public QQuickItem
  {
    Q_OBJECT
    Q_PROPERTY(ToolboxML::AbstractTool* tool READ tool WRITE setTool NOTIFY toolChanged)
    Q_PROPERTY(QObject* viewInterface READ viewInterfaceASQObject WRITE setViewInterface NOTIFY viewInterfaceChanged)
  public:
    ToolController(QQuickItem* parent = 0);
    virtual ~ToolController();
    AbstractTool* tool() const;
    void setTool(AbstractTool* _tool);
    AbstractViewInterface* viewInterface() const;
    void setViewInterface(AbstractViewInterface* _viewInterface);
  private:
    QObject* viewInterfaceASQObject() const;
    void setViewInterface(QObject* _object);
  signals:
    void toolChanged();
    void currentFeaturesSourceChanged();
    void viewInterfaceChanged();
  protected:
    virtual void mouseDoubleClickEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual void wheelEvent(QWheelEvent* event);
    virtual void hoverEnterEvent(QHoverEvent* event);
    virtual void hoverMoveEvent(QHoverEvent* event);
    virtual void hoverLeaveEvent(QHoverEvent* event);
  private slots:
    void toolHoverEnabledHasChanged();
  private:
    struct Private;
    Private* const d;
  };
}

#endif

