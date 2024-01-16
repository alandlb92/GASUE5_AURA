// Copyright Faya Games


#include "UI/HUD/AuraHUD.h"
#include <UI/Widgets/AuraUserWidget.h>
#include <UI/WidigetController/OverlayWidgetController.h>

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (_overlayWidgetController == nullptr)
	{
		_overlayWidgetController = NewObject<UOverlayWidgetController>(this, _overlayWidgetControllerClass);
		_overlayWidgetController->SetWidgetControllerParam(WCParams);
		_overlayWidgetController->BindCallBacksToDependencies();
	}

	return _overlayWidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* playerController, APlayerState* playerState, UAbilitySystemComponent* abilitySystemComp, UAttributeSet* attributeSet)
{
	checkf(_overlayWidgetClass, TEXT("_overlayWidgetClass unitialize, please fill out BP_AuraHUD"));
	checkf(_overlayWidgetControllerClass, TEXT("_overlayWidgetControllerClass unitialize, please fill out BP_AuraHUD"));
	
	UUserWidget* widget = CreateWidget<UUserWidget>(GetWorld(), _overlayWidgetClass);
	OverlayWidget = Cast<UAuraUserWidget>(widget);

	const FWidgetControllerParams WidgetControllerParams(playerController, playerState, abilitySystemComp, attributeSet);
	UOverlayWidgetController* overlayWidgetController = GetOverlayWidgetController(WidgetControllerParams);

	OverlayWidget->SetWidgetController(overlayWidgetController);

	overlayWidgetController->BroadcastInitialValues();

	widget->AddToViewport();
}

