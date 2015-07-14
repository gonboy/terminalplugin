#include "terminalpane.h"

#include <coreplugin/idocument.h>
#include <coreplugin/editormanager/editormanager.h>
#include <coreplugin/icore.h>
#include <utils/fileutils.h>

#include "terminalwidget.h"

#include <QCheckBox>
#include <QFileInfo>
#include <QDir>

namespace TerminalPlugin {
namespace Internal {

TerminalPane::TerminalPane(QObject *parent) : Core::IOutputPane(parent)
{
    m_terminal = new TerminalWidget();

    m_followDocs = new QCheckBox(tr("Follow Documents Path"));

    applySettings();

    connect(Core::EditorManager::instance(), SIGNAL(currentEditorChanged(Core::IEditor*)),
            this, SLOT(documentManagerCurrentFileChanged(Core::IEditor*)));
}

QWidget *TerminalPane::outputWidget(QWidget *)
{
    return m_terminal;
}

QList<QWidget*> TerminalPane::toolBarWidgets() const
{
    return QList<QWidget*>() << m_followDocs;
}

QString TerminalPane::displayName() const
{
    return tr("Terminal");
}

int TerminalPane::priorityInStatusBar() const
{
    return 1; // TODO/FIXME: what value to use?
}

void TerminalPane::clearContents()
{
    m_terminal->clear();
}

void TerminalPane::visibilityChanged(bool)
{
}

bool TerminalPane::canFocus() const
{
    return true;
}

bool TerminalPane::hasFocus() const
{
    return m_terminal->hasFocus();
}

void TerminalPane::setFocus()
{
    m_terminal->setFocus();
}

bool TerminalPane::canNext() const
{
    return false;
}

bool TerminalPane::canPrevious() const
{
    return false;
}

void TerminalPane::goToNext()
{
}

void TerminalPane::goToPrev()
{
}

bool TerminalPane::canNavigate() const
{
    return false;
}

void TerminalPane::documentManagerCurrentFileChanged(Core::IEditor* editor)
{
    if (!editor || !m_followDocs->isChecked())
        return;

    QFileInfo fi(editor->document()->filePath().toString());
    m_terminal->sendText(QString(QLatin1String("cd \"%1\"\n")).arg(fi.dir().absolutePath()));
}

void TerminalPane::applySettings()
{
    QSettings *s = Core::ICore::settings();
    s->beginGroup(QLatin1String("TerminalPlugin"));
    m_terminal->setColorScheme(s->value(QLatin1String("ColorScheme"), QLatin1String("Linux")).toString());

    QFont f(s->value(QLatin1String("FontName"), TERMINALPLUGINDEFAULTFONT).toString());
    f.setPointSize(s->value(QLatin1String("FontSize"), 10).toInt());
    m_terminal->setTerminalFont(f);

    s->endGroup();
}

} // namespace Internal
} // namespace TerminalPlugin
