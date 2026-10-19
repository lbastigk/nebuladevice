#pragma once
//------------------------------------------------------------------------------
/**
    @class MultiplayerFeature::MotionObjectView
    
    (C) 2009 Radon Labs GmbH
*/
#include "Nebuladevice/foundation/core/refcounted.h"
#include "Nebuladevice/application/game/entity.h"
#include "Nebuladevice/addons/network/multiplayerfeature/objectview.h"
#include "Nebuladevice/addons/network/multiplayerprotocol.h"

//------------------------------------------------------------------------------
namespace Tools
{
class MotionObjectView : public MultiplayerFeature::ObjectView
{
    __DeclareClass(MotionObjectView);
public:
    
    /// constructor
    MotionObjectView();
    /// destructor
    virtual ~MotionObjectView();       

protected:
    /// compute and apply attibute, overwrite in subclass if attr should not directly copied over 
    virtual void ComputeCurrentValue(const Ptr<MultiplayerFeature::NetworkAttribute>&  networkAttr);
};

}; // namespace MultiplayerFeature
//------------------------------------------------------------------------------