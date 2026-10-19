//------------------------------------------------------------------------------
//  resourcesaver.cc
//  (C) 2007 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/render/resources/resourcesaver.h"
#include "Nebuladevice/render/resources/resource.h"
#include "Nebuladevice/render/resources/resourceloader.h"

namespace Resources
{
__ImplementClass(Resources::ResourceSaver, 'RSSR', Core::RefCounted);

//------------------------------------------------------------------------------
/**
*/
ResourceSaver::ResourceSaver()
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
ResourceSaver::~ResourceSaver()
{
    n_assert(!this->IsAttachedToResource());
}

//------------------------------------------------------------------------------
/**
*/
void
ResourceSaver::OnAttachToResource(const Ptr<Resource>& res)
{
    n_assert(!this->IsAttachedToResource());
    this->resource = res;
}

//------------------------------------------------------------------------------
/**
*/
void
ResourceSaver::OnRemoveFromResource()
{
    n_assert(this->IsAttachedToResource());
    this->resource = 0;
}

//------------------------------------------------------------------------------
/**
*/
bool
ResourceSaver::IsAttachedToResource() const
{
    return this->resource.isvalid();
}

//------------------------------------------------------------------------------
/**
*/
const Ptr<Resource>&
ResourceSaver::GetResource() const
{
    return this->resource;
}

//------------------------------------------------------------------------------
/**
*/
bool
ResourceSaver::OnSave()
{
    n_assert(this->IsAttachedToResource());
    return true;
}

} // namespace Resources