#pragma once
//------------------------------------------------------------------------------
/**
    @class ZipTestApplication
    
    Multithreading test for zip file access.
    
    (C) 2009 Radon Labs GmbH
*/
#include "Nebuladevice/foundation/app/consoleapplication.h"
#include "Nebuladevice/foundation/core/coreserver.h"

//------------------------------------------------------------------------------
namespace App
{
class ZipTestApplication : public ConsoleApplication
{
public:
    /// run the application, return when user wants to exit
    virtual void Run();

private:
}; 

} // namespace App
//------------------------------------------------------------------------------

    