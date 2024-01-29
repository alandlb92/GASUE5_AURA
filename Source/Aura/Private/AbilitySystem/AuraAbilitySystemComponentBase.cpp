// Copyright Faya Games


#include "AbilitySystem/AuraAbilitySystemComponentBase.h"
#include "AuraGameplayTags.h"

void UAuraAbilitySystemComponentBase::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponentBase::EffectApplied);

	const FAuraGameplayTags& gameplayTags =  FAuraGameplayTags::Get();
	//gameplayTags.Attribute_Secondary_Armor.ToString();
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Orange, FString::Printf(TEXT("TAG: %s"), *gameplayTags.Attribute_Secondary_Armor.ToString()));
}

void UAuraAbilitySystemComponentBase::EffectApplied(UAbilitySystemComponent* abilitySystemComponent, const FGameplayEffectSpec& effectSpec, FActiveGameplayEffectHandle activeEffectHandle)
{
	FGameplayTagContainer tagContainer;
	effectSpec.GetAllAssetTags(tagContainer);
	EffectAssetTags.Broadcast(tagContainer);	
}
