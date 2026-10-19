//------------------------------------------------------------------------------
//  poolloadingresource.cc
//  (C) 2010 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/render/resources/streaming/poolloadingresource.h"
#include "Nebuladevice/render/resources/streaming/resourceslot.h"

namespace Resources
{
    __ImplementClass(Resources::PoolLoadingResource, 'PLRS', Resources::LoadingResource);

//------------------------------------------------------------------------------
/**
*/
void
PoolLoadingResource::OnSuccessRequest()
{
    // perform some checks
    n_assert(this->newSlot.isvalid());
    n_assert(this->newSlot->GetResource().isvalid());
    n_assert(this->newSlot->GetResource()->GetLoader().isvalid());
    n_assert(this->newSlot->GetResource()->GetState() == Resource::Loaded);
    
    this->newSlot->SetCurrentManagedResource(this->managedResource);
    if(this->oldSlot.isvalid())
    {
        this->oldSlot->SetCurrentManagedResource(0);
        this->oldSlot->GetResource()->Unlock();
    }
    LoadingResource::OnSuccessRequest();
}

} // namespace Resources
//------------------------------------------------------------------------------