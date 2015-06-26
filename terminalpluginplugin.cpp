#include "terminalpluginplugin.h"
#include "terminalpane.h"
#include "terminaloptionspage.h"

#include <coreplugin/icore.h>
#include <coreplugin/icontext.h>
#include <coreplugin/coreconstants.h>


using namespace TerminalPlugin::Internal;

TerminalPluginPlugin::TerminalPluginPlugin()
{
    m_optionsPage = new TerminalOptionsPage();
    addObject(m_optionsPage);
}

TerminalPluginPlugin::~TerminalPluginPlugin()
{
    removeObject(m_optionsPage);
    delete m_optionsPage;
    m_optionsPage = 0;
}

bool TerminalPluginPlugin::initialize(const QStringList &arguments, QString *errorString)
{
    Q_UNUSED(arguments)
    Q_UNUSED(errorString)

    addAutoReleasedObject(new TerminalPane());

    return true;
}

void TerminalPluginPlugin::extensionsInitialized()
{
}

ExtensionSystem::IPlugin::ShutdownFlag TerminalPluginPlugin::aboutToShutdown()
{
    return SynchronousShutdown;
}
