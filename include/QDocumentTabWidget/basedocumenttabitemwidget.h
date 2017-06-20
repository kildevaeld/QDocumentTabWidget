#pragma once
#include <QWidget>

class BaseTabItem : public QWidget {

  Q_OBJECT
public:
  BaseTabItem(QWidget *parent = 0);

  bool isFragile() const;
  void setFragile(bool preview);

  virtual QString name() const = 0;

  void setWidget(QWidget *widget);

  QWidget *widget() const;

signals:
  void nameChanged(const QString &name);
  void fragileChanged(bool fragile);

private:
  QWidget *m_widget = 0;
  bool m_fragile;

  // QWidget interface
protected:
  virtual void resizeEvent(QResizeEvent *event) override;
};