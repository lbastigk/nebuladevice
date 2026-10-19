//------------------------------------------------------------------------------
//  resourceinfo.cc
//  (C) 2010 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/render/resources/streaming/resourceinfo.h"

namespace Resources
{
//------------------------------------------------------------------------------
/**
*/
ResourceInfo::ResourceInfo() :
    estimatedSize(0)
{
}

//------------------------------------------------------------------------------
/**
*/
ResourceInfo::ResourceInfo(const ResourceInfo* info) :
    estimatedSize(info->estimatedSize)
{
}

//------------------------------------------------------------------------------
/**
*/
ResourceInfo::~ResourceInfo()
{
}
} // namespace Resources
//------------------------------------------------------------------------------