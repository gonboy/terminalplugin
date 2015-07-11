#include "consolewidget.h"
#include <QDebug>
#include <QMenu>
#include <QClipboard>
#include <QApplication>
namespace TerminalPlugin {
namespace Internal {

ConsoleWidget::ConsoleWidget(QWidget* p):QTermWidget(p)
{
  setContextMenuPolicy(Qt::CustomContextMenu);
  connect(this, SIGNAL(customContextMenuRequested(const QPoint&)),
          this, SLOT(customContextMenuCall(const QPoint&)));

  QAction* copy_action = new QAction(QString::fromUtf8("Copy"), this);
  connect(copy_action, SIGNAL(triggered()),
          this, SLOT(copyClipboard()));
  copy_action->setShortcut(Qt::CTRL + Qt::SHIFT + Qt::Key_C);
  m_actions[COPY] = copy_action;
  addAction(copy_action);

  QAction* paste_action = new QAction(QString::fromUtf8("Paste"), this);
  paste_action->setShortcut(Qt::CTRL + Qt::SHIFT + Qt::Key_V);
  connect(paste_action, SIGNAL(triggered()),
          this, SLOT(pasteClipboard()));
  m_actions[PASTE] = paste_action;
  addAction(paste_action);
}

void ConsoleWidget::customContextMenuCall(const QPoint& pos)
{
  QMenu menu;
  menu.addAction(m_actions[COPY]);
  menu.addAction(m_actions[PASTE]);
  menu.exec(mapToGlobal(pos));
}

} // namespace Internal
} // namespace TerminalPlugin
