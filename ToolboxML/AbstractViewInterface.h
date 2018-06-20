class QPointF;

namespace ToolboxML
{
  class AbstractViewInterface
  {
  public:
    AbstractViewInterface();
    virtual ~AbstractViewInterface();
    /**
     * Convert from document coordinate to view coordinate.
     */
    virtual QPointF toView(const QPointF& _point) const = 0;
    virtual QPointF fromView(const QPointF& _point) const = 0;
  };
}

#include <QtPlugin>

Q_DECLARE_INTERFACE(ToolboxML::AbstractViewInterface, "ToolBoxML.AbstractViewInterface")
