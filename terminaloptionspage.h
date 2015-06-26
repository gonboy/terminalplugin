#ifndef TERMINALOPTIONSPAGE_H
#define TERMINALOPTIONSPAGE_H

#include "terminalplugin_global.h"
#include "ui_terminaloptionspage.h"

#include <coreplugin/dialogs/ioptionspage.h>

#include <QPointer>


namespace TerminalPlugin {
namespace Internal {

class TERMINALPLUGINSHARED_EXPORT TerminalOptionsPage : public Core::IOptionsPage
{
    Q_OBJECT

public:
    TerminalOptionsPage();

    QWidget *widget();
    void apply();
    void finish();

private:
    QPointer<QWidget> m_widget;
    Ui::TerminalOptionsPage m_ui;

private slots:
    void fontButton_clicked();
};

} // namespace Internal
} // namespace TerminalPlugin

#endif // TERMINALOPTIONSPAGE_H
