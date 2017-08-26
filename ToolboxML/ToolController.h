#ifndef _TOOLBOXML_TOOLCONTROLLER_H_
#define _TOOLBOXML_TOOLCONTROLLER_H_

#include <QQuickItem>

namespace ToolboxML
{
  class AbstractTool;
  class ToolController : public QQuickItem
  {
    Q_OBJECT
    Q_PROPERTY(ToolboxML::AbstractTool* tool READ tool WRITE setTool NOTIFY toolChanged)
  public:
    ToolController(QQuickItem* parent = 0);
    virtual ~ToolController();
    AbstractTool* tool() const;
    void setTool(AbstractTool* _tool);
  signals:
    void toolChanged();
    void currentFeaturesSourceChanged();
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

