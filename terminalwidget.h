#ifndef TerminalWidget_H
#define TerminalWidget_H
#include <QKeyEvent>
#include <qtermwidget5/qtermwidget.h>
#include <QPoint>
#include <QMap>
namespace TerminalPlugin {
namespace Internal {

class TerminalWidget : public QTermWidget
{
  Q_OBJECT
  enum MenuActions {
    COPY,
    PASTE
  };

public:
  TerminalWidget(QWidget* p = 0);
public slots:
  void customContextMenuCall(const QPoint& pos);
private:
  QMap<MenuActions, QAction*> m_actions;
};
} // namespace Internal
} // namespace TerminalPlugin

#endif // TerminalWidget_H
