//------------------------------------------------------------------------------
//  zipstresstest.cc
//  (C) 2009 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "NebulaDeviceTests/zipstresstest/zipstresstestapplication.h"

//------------------------------------------------------------------------------
/**
*/
void
__cdecl main()
{
    App::ZipStressTestApplication app;
    app.SetCompanyName("Radon Labs GmbH");
    app.SetAppID("ZipStressTest");
    if (app.Open())
    {
        app.Run();
        app.Close();
    }
    app.Exit();
}
