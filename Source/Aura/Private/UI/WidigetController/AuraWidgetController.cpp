// Copyright Faya Games


#include "UI/WidigetController/AuraWidgetController.h"

void UAuraWidgetController::SetWidgetControllerParam(FWidgetControllerParams WCParams)
{
	_playerController = WCParams.PlayerController;
	_playerState = WCParams.PlayerState;
	_abilitySystemComponent = WCParams.AbilitySystemComponent;
	_attributeSet = WCParams.AttributeSet;
}

void UAuraWidgetController::BroadcastInitialValues()
{
}

void UAuraWidgetController::BindCallBacksToDependencies()
{
}
