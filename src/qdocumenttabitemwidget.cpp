#include <QDocumentTabWidget/qdocumenttabitemwidget.h>

QDocumentTabItemWidget::QDocumentTabItemWidget(QWidget *parent)
    : BaseTabItem(parent) {}

QString QDocumentTabItemWidget::name() const { return m_name; }

void QDocumentTabItemWidget::setName(const QString &name) { m_name = name; }
