// Copyright Faya Games


#include "Player/AuraPlayerState.h"
#include "AbilitySystem/AuraAbilitySystemComponentBase.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include <Net/UnrealNetwork.h>

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

void AAuraPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AAuraPlayerState, _level);
}

UAttributeSet* AAuraPlayerState::GetAttributeSet() const
{
	return _attributeSet;
}

void AAuraPlayerState::OnRep_Level(int32 oldLevel)
{
}
