#ifndef TerminalWidget_H
#define TerminalWidget_H

#include <QKeyEvent>
#include <QPoint>
#include <QMap>
#include <qtermwidget5/qtermwidget.h>

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
/* vim: set sts=4 ts=4 sw=4 et : */
