// Copyright Faya Games


#include "Player/AuraPlayerState.h"
#include "AbilitySystem/AuraAbilitySystemComponentBase.h"
#include "AbilitySystem/AuraAttributeSet.h"

AAuraPlayerState::AAuraPlayerState()
{
	_abilitieSystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponentBase>("AbilitySystemComponent");
	_abilitieSystemComponent->SetIsReplicated(true);
	_abilitieSystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	_attributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");

	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return _abilitieSystemComponent;
}

UAttributeSet* AAuraPlayerState::GetAttributeSet() const
{
	return _attributeSet;
}
