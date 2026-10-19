//------------------------------------------------------------------------------
//  n2tableconverterapp.cc
//  (C) 2009 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/toolkit/n2tableconverter/n2tableconverterapp.h"
#include "Nebuladevice/toolkit/n2tableconverter/n2xmltableconverter.h"
#include "Nebuladevice/foundation/timing/time.h"

namespace Toolkit
{
using namespace Util;
using namespace IO;

//------------------------------------------------------------------------------
/**
*/
void
N2TableConverterApp::ShowHelp()
{
    n_printf("Convert specific Nebula2/Mangalore Excel XML files to binary format.\n"
             "(C) Radon Labs GmbH 2009.\n"
             "-help       -- display this help\n");
}

//------------------------------------------------------------------------------
/**
*/
void
N2TableConverterApp::Run()
{
    // parse command line args
    if (!this->ParseCmdLineArgs())
    {
        return;
    }

    // setup the project info object
    if (!this->SetupProjectInfo())
    {
        return;
    }

    // perform anims.xml conversion
    N2XmlTableConverter animsXmlConverter;
    animsXmlConverter.ConvertAnimsXmlTable(this->logger);

    // wait for key press if requested
    if (this->waitForKey)
    {
        n_printf("Press <Enter> to continue!\n");
        while (!Console::Instance()->HasInput())
        {
            Timing::Sleep(0.01);
        }
    }
}

} // namespace Toolkit