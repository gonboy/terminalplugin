#ifndef TERMINALPLUGIN_H
#define TERMINALPLUGIN_H

#include "terminalplugin_global.h"

#include <extensionsystem/iplugin.h>

namespace TerminalPlugin {
namespace Internal {

class TerminalOptionsPage;

class TERMINALPLUGINSHARED_EXPORT TerminalPluginPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "TerminalPlugin.json")

public:
    TerminalPluginPlugin();
    ~TerminalPluginPlugin();

    bool initialize(const QStringList &arguments, QString *errorString);
    void extensionsInitialized();
    ShutdownFlag aboutToShutdown();

private:
    TerminalOptionsPage *m_optionsPage;
};

} // namespace Internal
} // namespace TerminalPlugin

#endif // TERMINALPLUGIN_H

