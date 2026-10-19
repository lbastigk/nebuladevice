#pragma once
//------------------------------------------------------------------------------
/**
	@class DistributedTools::SharedDirCreator

    Small factory which creates SharedDirControl objects.

    (C) 2009 Radon Labs GmbH
*/
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/core/singleton.h"
#include "Nebuladevice/foundation/core/refcounted.h"
#include "Nebuladevice/toolkit/distributedtools/shareddircontrol.h"
#include "Nebuladevice/toolkit/toolkitutil/projectinfo.h"
#include "Nebuladevice/foundation/util/guid.h"

//------------------------------------------------------------------------------
namespace DistributedTools
{
class SharedDirCreator : public Core::RefCounted
{
    __DeclareClass(SharedDirCreator);
    __DeclareSingleton(SharedDirCreator);
public:
    /// constructor
    SharedDirCreator();
    /// destructor
    virtual ~SharedDirCreator();

    /// creates either a SharedDirFileSystem or a SharedDirFTP, depending on the given path.
    Ptr<SharedDirControl> CreateSharedControlObject(const Util::String & path);
    /// creates either a SharedDirFileSystem or a SharedDirFTP, depending on the given path.
    Ptr<SharedDirControl> CreateSharedControlObject(const Util::String & path, const Util::Guid & guid);
    /// set project info
    void SetProjectInfo(const ToolkitUtil::ProjectInfo & info);

private:
    ToolkitUtil::ProjectInfo projectInfo;
};

//------------------------------------------------------------------------------
/**
    set project info
*/
inline
void
SharedDirCreator::SetProjectInfo(const ToolkitUtil::ProjectInfo & info)
{
    this->projectInfo = info;
}

} // namespace DistributedTools
