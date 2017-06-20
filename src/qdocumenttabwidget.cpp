
#include <QColor>
#include <QDocumentTabWidget/basedocumenttabitemwidget.h>
#include <QDocumentTabWidget/qdocumenttabbarwidget.h>
#include <QDocumentTabWidget/qdocumenttabwidget.h>
#include <QKeyEvent>
#include <QRgb>
//#include <codeeditor/codeeditorfactory.hpp>
//#include <coreplugin/document-manager.hpp>
//#include <coreplugin/idocument.hpp>

// using Core::DocumentManager;

// namespace Code {

QDocumentTabWidget::QDocumentTabWidget(QWidget *parent) : QTabWidget(parent) {
  TabWidgetBar *bar = new TabWidgetBar(this);
  setTabBar(bar);

  setTabsClosable(true);
  setElideMode(Qt::ElideRight);
  setMovable(true);
  setTabBarAutoHide(false);
  setDocumentMode(true);
  setUsesScrollButtons(true);

#ifdef Q_OS_MAC
  setDocumentMode(false);
  QFont font = bar->font();
  font.setPixelSize(12);
  bar->setFont(font);
  QString styles =
      QString("QTabWidget::pane { background-color: white; }" // This style
                                                              // disables
                                                              // default styling
                                                              // under Mac
              "QTabWidget::tab-bar {"
              "alignment: left;"
              "}"
              "QTabBar::tab:selected { "
              "background: white;"
              "color: #282828;"
              "} "
              "QTabBar::tab {"
              "color: #505050;"
              "font-size: 11px;"
              "background: %1;"
              "border-right: 1px solid #aaaaaa;"
              "padding: 4px 5px 7px 5px;"
              "}")
          .arg(QWidget::palette()
                   .color(QWidget::backgroundRole())
                   .darker(114)
                   .name());
  setStyleSheet(styles);
#endif

  connect(bar, &TabWidgetBar::closeAllTabsRequested, this,
          &QDocumentTabWidget::closeAllTabs);
  connect(bar, &TabWidgetBar::closeOtherTabsRequested, this,
          &QDocumentTabWidget::closeOtherTabs);
  connect(this, &QDocumentTabWidget::tabCloseRequested, this,
          &QDocumentTabWidget::closeTab);

  // auto pal = Settings::instance().editor().palette(palette());
  // auto theme = Settings::instance().editor().theme();
  // auto color = theme.editorColor(Theme::BackgroundColor);
  // setPalette(pal);
  // setStyleSheet(QString("background-color: %1").arg(QColor(color).name()));
}

QDocumentTabWidget::~QDocumentTabWidget() { closeAllTabs(); }
/*
bool TabWidget::openEditor(Core::IDocument *doc, bool preview) {
  TabWidgetItem *item = nullptr;
  // If already open
  item = find([doc](TabWidgetItem *a) { return doc == a->document(); });
  int index;
  if (item) {
    index = indexOf(item);
  } else if (preview) {
    item = find([doc](TabWidgetItem *a) { return a->preview(); });
    if (item) {
      index = indexOf(item);
      item->setDocument(doc);
    }
  }
  if (!item) {
    item = createTab(doc);
    item->setPreview(preview);
    index = indexOf(item);
  } else {
    setTabText(index, doc->name());
    if (item->preview())
      item->setPreview(preview);
  }
  setCurrentIndex(index);
  item->setFocus();
  return true;
}*/

/*bool TabWidget::openEditor(Core::IEditor *editor, bool fragile) {
  if (!editor) {
    return false;
    // editor = CodeEditor::CodeEditorFactory::instance().createEditor();
  }

  auto item = new EditorTabItem(editor, this);
  item->setFragile(fragile);
  // auto name = item->document()->isUntitled() ? tr("Untitled") : item->name();
  addTab(item);
}*/

void QDocumentTabWidget::addTab(QWidget *widget, const QString &name) {
  QTabWidget::addTab(widget, name);
  setCurrentIndex(count() - 1);
}

BaseTabItem *QDocumentTabWidget::find(std::function<bool(BaseTabItem *)> fn) {
  for (int i = 0; i < count(); i++) {
    BaseTabItem *item = qobject_cast<BaseTabItem *>(widget(i));
    if (item && fn(item))
      return item;
  }

  return nullptr;
}

BaseTabItem *QDocumentTabWidget::currentItem() const {
  return qobject_cast<BaseTabItem *>(currentWidget());
}

void QDocumentTabWidget::addTab(BaseTabItem *item) {

  if (item->isFragile()) {
    auto found = find([](BaseTabItem *i) { return i->isFragile(); });

    if (found) {
      int index = indexOf(found);
      closeTab(index);
      insertTab(index, item, item->name());
      setCurrentIndex(index);
    } else {
      addTab(item, item->name());
    }
  } else {
    addTab(item, item->name());
  }

  // auto name = item->name();

  connect(item, &BaseTabItem::nameChanged,
          [this, item](auto &name) { this->tabItemNameChanged(item, name); });
}

BaseTabItem *QDocumentTabWidget::itemWidget(int index) {
  return qobject_cast<BaseTabItem *>(widget(index));
}

void QDocumentTabWidget::closeTab(int index) {
  if (index >= 0) {
    auto w = widget(index);
    // QueryWidget *tabWidget = queryWidget(index);
    removeTab(index);

    // Editor *editor = w->widget<Editor>();

    delete w;
    // delete tabWidget;
  }
}

void QDocumentTabWidget::closeOtherTabs(int index) {
  tabBar()->moveTab(index, 0);
  while (count() > 1) {
    closeTab(1);
  }
}

void QDocumentTabWidget::closeAllTabs() {
  while (count() > 0) {
    closeTab(0);
  }
}

void QDocumentTabWidget::tabItemNameChanged(BaseTabItem *item,
                                            const QString &name) {
  int index = indexOf(item);
  if (index == -1)
    return;

  setTabText(index, name);
}
/*
TabWidgetItem *TabWidget::createTab(Core::IDocument *doc) {
  auto item = new TabWidgetItem(doc, this);
  addTab(item);
  return item;
}*/

void QDocumentTabWidget::keyPressEvent(QKeyEvent *event) {

  int index;
  switch (event->key()) {
  case Qt::Key_0:
    index = 0;
    break;
  case Qt::Key_1:
    index = 1;
    break;
  case Qt::Key_2:
    index = 2;
    break;
  case Qt::Key_3:
    index = 3;
    break;
  case Qt::Key_4:
    index = 4;
    break;
  case Qt::Key_5:
    index = 5;
    break;
  case Qt::Key_6:
    index = 6;
    break;
  case Qt::Key_7:
    index = 7;
    break;
  case Qt::Key_8:
    index = 8;
    break;
  case Qt::Key_9:
    index = 3;
    break;
  default:
    index = -1;
  }

  if (event->modifiers() & Qt::CTRL && index != -1) {
    setCurrentIndex(index - 1);
  }

  QTabWidget::keyPressEvent(event);
}
