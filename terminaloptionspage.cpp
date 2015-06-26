#include "terminaloptionspage.h"

#include <coreplugin/icore.h>

#include <qtermwidget5/qtermwidget.h>

#include <QFontDialog>

namespace TerminalPlugin {
namespace Internal {

TerminalOptionsPage::TerminalOptionsPage()
    : m_widget(0)
{
    setId("A.General");
    setDisplayName(tr("General"));
    setCategory("D.Terminal");
    setDisplayCategory(tr("Terminal"));
    setCategoryIcon(QLatin1String(":/terminalplugin/utilities-terminal.png"));
}

QWidget* TerminalOptionsPage::widget()
{
    if (!m_widget) {
        m_widget = new QWidget;
        m_ui.setupUi(m_widget);
        m_ui.colorSchemeComboBox->addItems(QTermWidget::availableColorSchemes());

        connect(m_ui.fontButton, SIGNAL(clicked()),
                this, SLOT(fontButton_clicked()));
    }

    QSettings *s = Core::ICore::settings();
    s->beginGroup(QLatin1String("TerminalPlugin"));
    m_ui.colorSchemeComboBox->setCurrentText(s->value(QLatin1String("ColorScheme"), QLatin1String("Linux")).toString());
    QFont f(s->value(QLatin1String("FontName"), TERMINALPLUGINDEFAULTFONT).toString());
    f.setPointSize(s->value(QLatin1String("FontSize"), 10).toInt());
    m_ui.fontLabel->setFont(f);
    s->endGroup();

    return m_widget;
}

void TerminalOptionsPage::apply()
{
    QSettings *s = Core::ICore::settings();
    s->beginGroup(QLatin1String("TerminalPlugin"));
    s->setValue(QLatin1String("ColorScheme"), m_ui.colorSchemeComboBox->currentText());
    s->setValue(QLatin1String("FontName"), m_ui.fontLabel->font().family());
    s->setValue(QLatin1String("FontSize"), m_ui.fontLabel->font().pointSize());
    s->endGroup();

}

void TerminalOptionsPage::finish()
{
    delete m_widget;
    m_widget = 0;
}

void TerminalOptionsPage::fontButton_clicked()
{
    if (!m_widget)
        return;

    bool ok;
    QFont f = QFontDialog::getFont(&ok, m_ui.fontLabel->font());
    if (ok) {
        m_ui.fontLabel->setFont(f);
    }
}

} // namespace Internal
} // namespace TerminalPlugin
