//------------------------------------------------------------------------------
//  edittool.cc
//  (C) 2011 xiongyouyi
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/editor/edittool/edittool.h"



namespace Editor
{
__ImplementClass(Editor::EditTool, 'EACT', Core::RefCounted);

//------------------------------------------------------------------------------
/**
*/
EditTool::EditTool()
{

}

//------------------------------------------------------------------------------
/**
*/
EditTool::~EditTool()
{

}

//------------------------------------------------------------------------------
/**
*/
void 
EditTool::OnActivate()
{
	// overwrite in subclass if needed
}

//------------------------------------------------------------------------------
/**
*/
void 
EditTool::OnDeactivate()
{
	// overwrite in subclass if needed
}

//------------------------------------------------------------------------------
/**
*/
void 
EditTool::OnUpdate()
{
	// overwrite in subclass if needed
}


} // namespace Editor