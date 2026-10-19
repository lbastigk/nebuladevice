#pragma once
//------------------------------------------------------------------------------
/**
    @class Maya::MayaPlugin
    
    Front-end class of the Nebula3 Maya plugin.
    
    (C) 2009 Radon Labs GmbH
*/
#include "Nebuladevice/foundation/core/refcounted.h"
#include "Nebuladevice/foundation/core/singleton.h"
#include "Nebuladevice/mayaplugin/mayamain/mayanebula3runtime.h"
#include "Nebuladevice/mayaplugin/mayamain/mayalogger.h"
#include "Nebuladevice/mayaplugin/mayamain/mayadirectoryregistry.h"
#include "Nebuladevice/mayaplugin/mayamain/mayacommandregistry.h"
#include "Nebuladevice/mayaplugin/mayashaders/mayashaderregistry.h"
#include "Nebuladevice/mayaplugin/mayacore/mayavariableregistry.h"
#include "Nebuladevice/mayaplugin/mayacore/mayamaterialgroupregistry.h"
#include <maya/MObject.h>

//------------------------------------------------------------------------------
namespace Maya
{
class MayaPlugin : public Core::RefCounted
{
    __DeclareClass(MayaPlugin);
    __DeclareSingleton(MayaPlugin);
public:
    /// constructor
    MayaPlugin();
    /// destructor
    virtual ~MayaPlugin();
    
    /// setup the plugin
    bool Setup(MObject pluginObject);
    /// discard the plugin
    void Discard();
    /// return true if object is valid
    bool IsValid() const;

private:
    /// start the MEL environment
    bool MELStartup();
    /// shutdown the MEL environment
    void MELShutdown();

    MObject mayaPluginObject;
    Ptr<MayaNebula3Runtime> mayaNebula3Runtime;
    Ptr<MayaLogger> mayaLogger;
    Ptr<MayaDirectoryRegistry> mayaDirectoryRegistry;
    Ptr<MayaCommandRegistry> mayaCommandRegistry;
    Ptr<MayaShaderRegistry> mayaShaderRegistry;
    Ptr<MayaVariableRegistry> mayaVariableRegistry;
    Ptr<MayaMaterialGroupRegistry> mayaMaterialGroupRegistry;
    bool isValid;
};

//------------------------------------------------------------------------------
/**
*/
inline bool
MayaPlugin::IsValid() const
{
    return this->isValid;
}

} // namespace Maya
//------------------------------------------------------------------------------

    