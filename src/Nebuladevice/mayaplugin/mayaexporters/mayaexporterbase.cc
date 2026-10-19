//------------------------------------------------------------------------------
//  mayaexporterbase.cc
//  (C) 2009 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/mayaplugin/mayaexporters/mayaexporterbase.h"
#include "Nebuladevice/mayaplugin/mayautil/mayanodeutil.h"
#include "Nebuladevice/mayaplugin/mayautil/mayatype.h"

#include <maya/MDagPathArray.h>

namespace Maya
{
using namespace Util;

//------------------------------------------------------------------------------
/**
*/
MayaExporterBase::MayaExporterBase() :
    rootNode("|model")    
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
MayaExporterBase::~MayaExporterBase()
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
MayaStatus::Code
MayaExporterBase::Export()
{
    return MayaStatus::NothingTodo;
}    

//------------------------------------------------------------------------------
/**
*/
bool
MayaExporterBase::Save()
{
    return false;
}

//------------------------------------------------------------------------------
/**
    Updates the rootNodeDagPath object from the rootNode string.
*/
void
MayaExporterBase::UpdateRootNodeDagPath()
{
    MDagPathArray dagPathArray = MayaNodeUtil::LookupNode(MayaType::Cast<String,MString>(this->rootNode));
    if (dagPathArray.length() > 0)
    {
        this->rootNodeDagPath = dagPathArray[0];
    }
    else
    {
        this->rootNodeDagPath = MDagPath();
    }
}

} // namespace Maya