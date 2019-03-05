#pragma once

#include <QObject>

namespace ToolboxML
{
  class ToolAction : public QObject
  {
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QString icon READ icon WRITE setIcon NOTIFY iconChanged)
    Q_PROPERTY(bool checkable READ isCheckable WRITE setCheckable NOTIFY checkableChanged)
    Q_PROPERTY(bool checked READ isChecked WRITE setChecked NOTIFY checkedChanged)
  public:
    ToolAction(QObject* _parent = nullptr);
    ~ToolAction();
  public:
    QString text() const;
    void setText(const QString& _text);
    QString icon() const;
    void setIcon(const QString& _icon);
    bool isCheckable() const;
    void setCheckable(bool _v);
    bool isChecked() const;
    void setChecked(bool _v);
  signals:
    void textChanged();
    void iconChanged();
    void checkableChanged();
    void checkedChanged();
  private:
    struct Private;
    Private* const d;
  };
}
