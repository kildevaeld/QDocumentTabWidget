

#include <QAction>
#include <QDocumentTabWidget/qdocumenttabbarwidget.h>
#include <QMenu>
#include <QMouseEvent>

TabWidgetBar::TabWidgetBar(QWidget *parent) : QTabBar(parent) {
  buildContextMenu();
}

void TabWidgetBar::mouseReleaseEvent(QMouseEvent *event) {
  if (event->button() == Qt::RightButton) {
    this->rightMouseReleaseEvent(event);
  }

  QTabBar::mouseReleaseEvent(event);
}

void TabWidgetBar::buildContextMenu() {
  m_menu = new QMenu(this);

  m_closeTabAction = new QAction("Close", m_menu);
  m_closeOtherAction = new QAction("Close Other", m_menu);
  m_closeAllAction = new QAction("Class All", m_menu);

  m_menu->addAction(m_closeTabAction);
  m_menu->addAction(m_closeOtherAction);
  m_menu->addAction(m_closeAllAction);
}

void TabWidgetBar::rightMouseReleaseEvent(QMouseEvent *event) {
  int tabindex = tabAt(event->pos());
  if (tabindex < 0) {
    emit barClicked(event);
    return;
  }

  QAction *selected = m_menu->exec(QCursor::pos());

  if (!selected)
    return;

  emitSignalForContextMenuAction(tabindex, selected);
}

void TabWidgetBar::emitSignalForContextMenuAction(int tabIndex,
                                                  QAction *action) {
  if (action == m_closeTabAction) {
    emit tabCloseRequested(tabIndex);
  } else if (action == m_closeAllAction) {
    emit closeAllTabsRequested();
  } else if (action == m_closeOtherAction) {
    emit closeOtherTabsRequested(tabIndex);
  }
}
