//------------------------------------------------------------------------------
//  transition.cc
//  (C) 2006 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/application/scriptfeature/fsm/transition.h"
#include "Nebuladevice/foundation/messaging/message.h"
#include "Nebuladevice/application/scriptfeature/conditions/behaviour/fsmcondition.h"
#include "Nebuladevice/application/scriptfeature/actions/actionlist.h"
#include "Nebuladevice/application/scriptfeature/conditions/condition.h"
#include "Nebuladevice/application/scriptfeature/actions/sequenceaction.h"

namespace FSM
{
__ImplementClass(FSM::Transition, 'FSMR', Core::RefCounted);

//------------------------------------------------------------------------------
/**
*/
Transition::Transition()
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
Transition::~Transition()
{
    // empty
}

//------------------------------------------------------------------------------
/**
    This method gets called when the parent state becomes active.
*/
void
Transition::OnActivate()
{
    // empty
}

//------------------------------------------------------------------------------
/**
    This method gets called when the parent state becomes inactive.
*/
void
Transition::OnDeactivate()
{
    // empty 
}

//------------------------------------------------------------------------------
/**
    This method notifies FSMConditions about any incoming messages
    they are interested in.
*/
void
Transition::Notify(const Ptr<Messaging::Message>& msg)
{
    // empty
}

//------------------------------------------------------------------------------
/**
    This evaluates the state of all conditions and ANDs them together.
    If there are no Conditions, the transition is be true.
*/
bool
Transition::EvaluateConditions()
{
    //this->conditionBlock->Assert();
    return this->conditionBlock->Evaluate();
}

//------------------------------------------------------------------------------
/**
    This executes all actions added to the transition.
*/
void
Transition::ExecuteActions()
{
    this->actionList->Execute();
}

//------------------------------------------------------------------------------
/**
*/
void
Transition::SetTargetState(const Util::String& n)
{
    this->targetState = n;
}

//------------------------------------------------------------------------------
/**
*/
const Util::String&
Transition::GetTargetState() const
{
    return this->targetState;
}

//------------------------------------------------------------------------------
/**
*/
void
Transition::AddCondition(const Ptr<Conditions::Condition>& condition)
{
    n_assert(0 != condition);
    this->conditionBlock = condition;
}

//------------------------------------------------------------------------------
/**
*/
void
Transition::AddAction(const Ptr<Actions::ActionList>& action)
{
    n_assert(0 != action);
    this->actionList = Actions::SequenceAction::Create();
    this->actionList->FromList(action.cast<Actions::Action>());
}

}; // namespace FSM
