//------------------------------------------------------------------------------
//  resourcecreator.cc
//  (C) 2010 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/render/resources/streaming/resourcecreator.h"
#include "Nebuladevice/render/resources/resource.h"

namespace Resources
{
__ImplementClass(Resources::ResourceCreator, 'RSCR', Core::RefCounted);

//------------------------------------------------------------------------------
/**
*/
ResourceCreator::ResourceCreator()
{}

//------------------------------------------------------------------------------
/**
*/
ResourceCreator::~ResourceCreator()
{}

//------------------------------------------------------------------------------
/**
*/
Ptr<Resource>
ResourceCreator::CreateResource(const ResourceInfo* resourceInfo)
{
    n_error("ResourceCreator::CreateResource called. Overload this method in subclasses.");
    return 0;
}
} // namespace Resources
//------------------------------------------------------------------------------