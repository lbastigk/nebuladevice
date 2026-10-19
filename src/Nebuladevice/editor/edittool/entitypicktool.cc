//------------------------------------------------------------------------------
//  selectentitymanip.cc
//  (C) 2011 xiongyouyi
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/editor/edittool/entitypicktool.h"
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
__ImplementClass(Editor::EntityPickTool, 'ESMP', Editor::EditTool);


using namespace Input;
using namespace Game;
using namespace BaseGameFeature;

//------------------------------------------------------------------------------
/**
*/
EntityPickTool::EntityPickTool()
: entity(0)
{

}

//------------------------------------------------------------------------------
/**
*/
EntityPickTool::~EntityPickTool()
{

}

//------------------------------------------------------------------------------
/**
*/
void 
EntityPickTool::OnActivate()
{
	FocusManager::Instance()->SetInputFocusType(FocusManager::Select);
}

//------------------------------------------------------------------------------
/**
*/
void 
EntityPickTool::OnDeactivate()
{
	if (this->entity)
	{
		this->entity = 0;
	}
}

//------------------------------------------------------------------------------
/**
*/
void 
EntityPickTool::OnUpdate()
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