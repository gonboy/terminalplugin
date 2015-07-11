#ifndef TERMINALPANE_H
#define TERMINALPANE_H

#include "terminalplugin_global.h"

#include <coreplugin/ioutputpane.h>
#include <coreplugin/editormanager/ieditor.h>


class QCheckBox;

namespace TerminalPlugin {
namespace Internal {
class ConsoleWidget;
class TERMINALPLUGINSHARED_EXPORT TerminalPane : public Core::IOutputPane
{
    Q_OBJECT
public:
    explicit TerminalPane(QObject *parent = 0);

    QWidget *outputWidget(QWidget *);
    QList<QWidget *> toolBarWidgets() const;
    QString displayName() const;
    int priorityInStatusBar() const;
    void clearContents();
    void visibilityChanged(bool);
    bool canFocus() const;
    bool hasFocus() const;
    void setFocus();

    bool canNext() const;
    bool canPrevious() const;
    void goToNext();
    void goToPrev();
    bool canNavigate() const;

signals:

public slots:
    void documentManagerCurrentFileChanged(Core::IEditor*);
    void applySettings();

private:
    ConsoleWidget *m_terminal;
    QCheckBox *m_followDocs;
};

} // namespace Internal
} // namespace TerminalPlugin

#endif // TERMINALPANE_H
