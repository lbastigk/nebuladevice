//------------------------------------------------------------------------------
//  ps3test.cc
//  (C) 2009 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "NebulaDeviceTests/bullet_collision_simple/bcapplication.h"
#include "Nebuladevice/foundation/system/appentry.h"

ImplementNebulaApplication();

//------------------------------------------------------------------------------
/**
*/
void
NebulaMain(const Util::CommandLineArgs& args)
{
    Tools::BCApplication app;
    app.SetAppTitle("Bullet Collision Simple");
    app.SetAppID("BCSIMPLE");
    if (app.Open())
    {
        app.Run();
        app.Close();
    }    
}
