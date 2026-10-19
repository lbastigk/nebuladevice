//------------------------------------------------------------------------------
//  ps3test.cc
//  (C) 2009 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "NebulaDeviceTests/audiotestsimple/simpleaudioapplication.h"
#include "Nebuladevice/foundation/system/appentry.h"

ImplementNebulaApplication();

//------------------------------------------------------------------------------
/**
*/
void
NebulaMain(const Util::CommandLineArgs& args)
{
    Test::SimpleAudioApplication app;
    if (app.Open())
    {
        app.Run();
        app.Close();
    }    
}
