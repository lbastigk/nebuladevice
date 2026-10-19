//------------------------------------------------------------------------------
//  defaultremoterequesthandler.cc
//  (C) 2008 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/foundation/core/coreserver.h"
#include "Nebuladevice/addons/remote/defaultremoterequesthandler.h"
#include "Nebuladevice/foundation/timing/calendartime.h"
#include "Nebuladevice/addons/remote/remotecontrol.h"

namespace Remote
{
__ImplementClass(Remote::DefaultRemoteRequestHandler, 'DRRH', Remote::RemoteRequestHandler);

using namespace Core;
using namespace Util;
using namespace Timing;

//------------------------------------------------------------------------------
/**
*/
void
DefaultRemoteRequestHandler::HandleRequest(const Ptr<RemoteRequest>& request)
{
    //
    // implement request handle here!!!
    //
}

} // namespace Remote