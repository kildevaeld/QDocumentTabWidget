#pragma once
#include <QTabWidget>
#include <functional>

class BaseTabItem;

class QDocumentTabWidget : public QTabWidget {
  Q_OBJECT
public:
  explicit QDocumentTabWidget(QWidget *parent = 0);
  ~QDocumentTabWidget();

  // bool openEditor(Core::IDocument *doc, bool preview = true);
  // bool openEditor(Core::IEditor *editor = 0, bool fragile = true);
  void addTab(QWidget *widget, const QString &name);

  BaseTabItem *find(std::function<bool(BaseTabItem *)> fn);
  BaseTabItem *currentItem() const;

  void closeTab(int index);
  void closeOtherTabs(int index);
  void closeAllTabs();

  void addTab(BaseTabItem *item);
  BaseTabItem *itemWidget(int index);
private slots:
  void tabItemNameChanged(BaseTabItem *item, const QString &name);

  // private:
  //  TabWidgetItem *createTab(Core::IDocument *doc);

  // QWidget interface
protected:
  virtual void keyPressEvent(QKeyEvent *event) override;
};
