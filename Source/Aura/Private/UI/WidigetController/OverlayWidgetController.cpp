// Copyright Faya Games


#include "UI/WidigetController/OverlayWidgetController.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include <AbilitySystem/AuraAbilitySystemComponentBase.h>

void UOverlayWidgetController::BroadcastInitialValues()
{
	Super::BroadcastInitialValues();

	if (_attributeSet == nullptr)
		return;

	const UAuraAttributeSet* auraAttributeSet = CastChecked<UAuraAttributeSet>(_attributeSet);

	OnHealthChanged.Broadcast(auraAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(auraAttributeSet->GetMaxHealth());

	OnManaChanged.Broadcast(auraAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(auraAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallBacksToDependencies()
{
	Super::BindCallBacksToDependencies();

	if (_attributeSet == nullptr)
		return;
	const UAuraAttributeSet* auraAttributeSet = CastChecked<UAuraAttributeSet>(_attributeSet);

	_abilitySystemComponent->GetGameplayAttributeValueChangeDelegate(auraAttributeSet->GetHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& data)
		{
			OnHealthChanged.Broadcast(data.NewValue);
		});

	_abilitySystemComponent->GetGameplayAttributeValueChangeDelegate(auraAttributeSet->GetMaxHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& data)
		{
			OnMaxHealthChanged.Broadcast(data.NewValue);
		});
	_abilitySystemComponent->GetGameplayAttributeValueChangeDelegate(auraAttributeSet->GetManaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& data)
		{
			OnManaChanged.Broadcast(data.NewValue);
		});
	_abilitySystemComponent->GetGameplayAttributeValueChangeDelegate(auraAttributeSet->GetMaxManaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& data)
		{
			OnMaxManaChanged.Broadcast(data.NewValue);
		});

	Cast<UAuraAbilitySystemComponentBase>(_abilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& tagContainer)
		{
			for (const FGameplayTag& tag : tagContainer)
			{
				FGameplayTag messageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
				if (tag.MatchesTag(messageTag))
				{
					const FUIWidgetRow* row = GetDatatableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, tag);
					MessageWidgetRowDelegate.Broadcast(*row);
				}
			}
		}
	);
}
