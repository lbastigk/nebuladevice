//------------------------------------------------------------------------------
//  properties/timeproperty.cc
//  (C) 2007 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/application/basegamefeature/properties/timeproperty.h"
//#include "Nebuladevice/application/basegamefeature/basegametiming/gametimesource.h"
#include "Nebuladevice/application/game/entity.h"
#include "Nebuladevice/application/basegamefeature/basegameattr/basegameattributes.h"

namespace BaseGameFeature
{
__ImplementClass(BaseGameFeature::TimeProperty, 'TIMP', Game::Property);

using namespace Game;

//------------------------------------------------------------------------------
/**
*/
TimeProperty::TimeProperty() :
    attachTime(0.0)
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
TimeProperty::~TimeProperty()
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
void
TimeProperty::SetupCallbacks()
{
    this->entity->RegisterPropertyCallback(this, BeginFrame);
}

//------------------------------------------------------------------------------
/**
*/
void
TimeProperty::SetupDefaultAttributes()
{
    Property::SetupDefaultAttributes();
    SetupAttr(Attr::Time);
}

//------------------------------------------------------------------------------
/**
*/
void
TimeProperty::OnActivate()
{
    Property::OnActivate();
    //this->attachTime = GameTimeSource::Instance()->GetTime();
}

//------------------------------------------------------------------------------
/**
*/
void
TimeProperty::OnBeginFrame()
{
    //Time absTime = GameTimeSource::Instance()->GetTime();
    //Time relTime = absTime - this->attachTime;
    //this->GetEntity()->SetFloat(Attr::Time, float(relTime));
}

}; // namespace Properties
