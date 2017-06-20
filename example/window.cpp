#include "window.hpp"
#include <QDocumentTabWidget/QDocumentTabWidget>
#include <QVBoxLayout>

Window::Window() : QMainWindow() {

  // auto l = new QVBoxLayout(this);

  tabWidget = new QDocumentTabWidget(this);
  tabWidget->setTabBarAutoHide(false);
  // l->addWidget(tabWidget);

  // setLayout(l);
  setCentralWidget(tabWidget);

  auto item = new QDocumentTabItemWidget(tabWidget);
  item->setName("Hello");
  tabWidget->addTab(item);

  item = new QDocumentTabItemWidget(tabWidget);
  item->setName("World!");
  tabWidget->addTab(item);
  resize(800, 600);
}
