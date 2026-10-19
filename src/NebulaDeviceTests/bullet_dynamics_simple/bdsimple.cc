//------------------------------------------------------------------------------
//  ps3test.cc
//  (C) 2009 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "NebulaDeviceTests/bullet_dynamics_simple/bdapplication.h"
#include "Nebuladevice/foundation/system/appentry.h"

ImplementNebulaApplication();

//------------------------------------------------------------------------------
/**
*/
void
NebulaMain(const Util::CommandLineArgs& args)
{
    Tools::BDApplication app;
    app.SetAppTitle("Bullet Dynamics Simple");
    app.SetAppID("BDSIMPLE");
    if (app.Open())
    {
        app.Run();
        app.Close();
    }    
}
