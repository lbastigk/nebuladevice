//------------------------------------------------------------------------------
//  internalgraphicshandler.cc
//  (C) 2009 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/render/visibility/visibilityprotocol.h"
#include "Nebuladevice/foundation/messaging/staticmessagehandler.h"
#include "Nebuladevice/render/visibility/visibilitysystems/visibilitybox.h"
#include "Nebuladevice/render/visibility/visibilitychecker.h"
#include "Nebuladevice/render/internalgraphics/internalstage.h"
#include "Nebuladevice/render/internalgraphics/internalgraphicsserver.h"
                          
using namespace Util;
using namespace Visibility;
using namespace InternalGraphics;

namespace Messaging
{

//------------------------------------------------------------------------------
/**
*/
__StaticHandler(CreateVisibilityBoxes)
{
    const Ptr<InternalStage>& stage = InternalGraphicsServer::Instance()->GetStageByName(msg->GetStageName());
    Visibility::VisibilityChecker& visChecker = stage->GetVisibilityChecker();
                            
    visChecker.BeginAttachVisibilityContainer();
    SizeT numBoxes = msg->GetBoundingBoxes().Size();
    IndexT i;
    for (i = 0; i < numBoxes; ++i)
    {           
        Ptr<VisibilityBox> box = VisibilityBox::Create();    
        box->SetTransform(msg->GetBoundingBoxes()[i]);
        visChecker.AttachVisibilityContainer(box.cast<VisibilityContainer>());    	
    }
    visChecker.EndAttachVisibilityContainer();
}

} // namespace Messaging

