#pragma once
#include "basedocumenttabitemwidget.h"

class QDocumentTabItemWidget : public BaseTabItem {
  // BaseTabItem interface
public:
  explicit QDocumentTabItemWidget(QWidget *parent = 0);

  QString name() const;
  void setName(const QString &name);

private:
  QString m_name;
};
