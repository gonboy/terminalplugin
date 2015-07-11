#ifndef CONSOLEWIDGET_H
#define CONSOLEWIDGET_H
#include <QKeyEvent>
#include <qtermwidget5/qtermwidget.h>
#include <QPoint>
#include <QMap>
namespace TerminalPlugin {
namespace Internal {

class ConsoleWidget : public QTermWidget
{
  Q_OBJECT
  enum MenuActions {
    COPY,
    PASTE
  };

public:
  ConsoleWidget(QWidget* p = 0);
public slots:
  void customContextMenuCall(const QPoint& pos);
private:
  QMap<MenuActions, QAction*> m_actions;
};
} // namespace Internal
} // namespace TerminalPlugin

#endif // CONSOLEWIDGET_H
