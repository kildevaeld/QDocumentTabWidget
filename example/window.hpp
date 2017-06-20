#pragma once
#include <QMainWindow>

class QDocumentTabWidget;

class Window : public QMainWindow {

public:
  Window();

private:
  QDocumentTabWidget *tabWidget;
};
