#pragma once
#include <QTabBar>

class QMenu;

class TabWidgetBar : public QTabBar {
  Q_OBJECT
public:
  explicit TabWidgetBar(QWidget *parent = 0);

signals:
  void closeOtherTabsRequested(int index);
  void closeAllTabsRequested();

protected:
  virtual void mouseReleaseEvent(QMouseEvent *event) override;

private:
  void buildContextMenu();
  void rightMouseReleaseEvent(QMouseEvent *event);
  void emitSignalForContextMenuAction(int tabIndex, QAction *action);

  QMenu *m_menu;
  QAction *m_closeTabAction;
  QAction *m_closeAllAction;
  QAction *m_closeOtherAction;
};
