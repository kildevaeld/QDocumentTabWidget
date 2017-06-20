#include <QDocumentTabWidget/basedocumenttabitemwidget.h>

BaseTabItem::BaseTabItem(QWidget *parent) : QWidget(parent) {}

bool BaseTabItem::isFragile() const { return m_fragile; }

void BaseTabItem::setFragile(bool fragile) {
  if (m_fragile == fragile)
    return;

  m_fragile = fragile;
  emit fragileChanged(fragile);
}

void BaseTabItem::setWidget(QWidget *widget) {
  if (m_widget) {
    delete m_widget;
  }
  m_widget = widget;

  widget->setParent(this);
}

QWidget *BaseTabItem::widget() const { return m_widget; }

void BaseTabItem::resizeEvent(QResizeEvent *event) {

  QWidget::resizeEvent(event);

  if (m_widget)
    m_widget->setGeometry(this->geometry());
}
