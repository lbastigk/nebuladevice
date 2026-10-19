//------------------------------------------------------------------------------
//  iointerface.cc
//  (C) 2006 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/foundation/io/iointerface.h"
#include "Nebuladevice/foundation/io/iointerfacehandler.h"
#include "Nebuladevice/foundation/messaging/blockinghandlerthread.h"

namespace IO
{
__ImplementClass(IO::IoInterface, 'IIOF', Interface::InterfaceBase);
__ImplementInterfaceSingleton(IO::IoInterface);

using namespace Messaging;
using namespace Interface;

//------------------------------------------------------------------------------
/**
*/
IoInterface::IoInterface()
{
    __ConstructInterfaceSingleton;
}

//------------------------------------------------------------------------------
/**
*/
IoInterface::~IoInterface()
{
    __DestructInterfaceSingleton;
}

//------------------------------------------------------------------------------
/**
*/
void
IoInterface::Open()
{
    // setup the message handler thread object
    Ptr<BlockingHandlerThread> handlerThread = BlockingHandlerThread::Create();
    handlerThread->SetName("IoInterface Thread");
    handlerThread->SetCoreId(System::Cpu::IoThreadCore);
#if __WII_
    handlerThread->SetPriority(Thread::NormalBoost);
#endif        
    handlerThread->AttachHandler(IoInterfaceHandler::Create());
    this->SetHandlerThread(handlerThread.cast<HandlerThreadBase>());

    InterfaceBase::Open();
}

} // namespace IO
