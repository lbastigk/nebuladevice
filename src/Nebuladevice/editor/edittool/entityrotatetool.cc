//------------------------------------------------------------------------------
//  rotateentitymanip.cc
//  (C) 2011 xiongyouyi
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "Nebuladevice/editor/edittool/entityrotatetool.h"
#include "Nebuladevice/render/input/inputserver.h"
#include "Nebuladevice/render/input/mouse.h"
#include "Nebuladevice/application/basegamefeature/managers/entitymanager.h"
#include "Nebuladevice/application/basegamefeature/managers/factorymanager.h"
#include "Nebuladevice/application/basegamefeature/managers/envquerymanager.h"
#include "Nebuladevice/application/basegamefeature/managers/focusmanager.h"
#include "Nebuladevice/application/basegamefeature/basegameattr/basegameattributes.h"
#include "Nebuladevice/application/graphicsfeature/graphicsattr/graphicsattributes.h"
#include "Nebuladevice/application/physicsfeature/physicsattr/physicsattributes.h"
#include "Nebuladevice/application/basegamefeature/basegameprotocol.h"



namespace Editor
{
__ImplementClass(Editor::EntityRotateTool, 'REMP', Editor::EditTool);


using namespace Input;
using namespace Game;
using namespace BaseGameFeature;

//------------------------------------------------------------------------------
/**
*/
EntityRotateTool::EntityRotateTool()
: entity(0)
{

}

//------------------------------------------------------------------------------
/**
*/
EntityRotateTool::~EntityRotateTool()
{

}

//------------------------------------------------------------------------------
/**
	操作被置为当前
*/
void 
EntityRotateTool::OnActivate()
{
	FocusManager::Instance()->SetInputFocusType(FocusManager::Rotate);
}

//------------------------------------------------------------------------------
/**
	操作被置换
*/
void 
EntityRotateTool::OnDeactivate()
{
	if (this->entity)
	{
		this->entity = 0;
	}
}

//------------------------------------------------------------------------------
/**
	帧渲染前调用
*/
void 
EntityRotateTool::OnUpdate()
{
	InputServer* inputServer = InputServer::Instance();
	const Ptr<Mouse>& mouse = inputServer->GetDefaultMouse();

	if (mouse->ButtonDown(MouseButton::LeftButton))
	{
		Entity* ent = EnvQueryManager::Instance()->GetEntityUnderMouse();

		if (ent != this->entity)
		{
			this->entity = ent;
			FocusManager::Instance()->SetInputFocusEntity(this->entity);
		}
	} 
}

} // namespace Editor