// Copyright Faya Games


#include "Actor/AuraEffectActor.h"

#include <AbilitySystemBlueprintLibrary.h>
#include <AbilitySystemComponent.h>

AAuraEffectActor::AAuraEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}

void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraEffectActor::ApplyEffectToTarget(AActor* targetActor, TSubclassOf<UGameplayEffect> gameplayEffectClass)
{
	if (UAbilitySystemComponent* targetAbiltySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(targetActor))
	{
		check(gameplayEffectClass);
		FGameplayEffectContextHandle effectContenxtHandle = targetAbiltySystemComponent->MakeEffectContext();
		effectContenxtHandle.AddSourceObject(this);		
		const FGameplayEffectSpecHandle effectSpecHandle = targetAbiltySystemComponent->MakeOutgoingSpec(gameplayEffectClass, _actorLevel, effectContenxtHandle);
		const FActiveGameplayEffectHandle activeEffectHandle = targetAbiltySystemComponent->ApplyGameplayEffectSpecToSelf(*effectSpecHandle.Data.Get());

		const bool bIsInfinity = effectSpecHandle.Data.Get()->Def->DurationPolicy == EGameplayEffectDurationType::Infinite;
		if (bIsInfinity && _infinityEffectRemovalPolicy == EEfectRemovalPolicy::RemoveOnEndOverlap) 
		{
			_activeEffectHandles.Add(activeEffectHandle, targetAbiltySystemComponent);
		}
	}
}

void AAuraEffectActor::OnOverlap(AActor* targetActor)
{
	if (_instantEffectApplicationPolicy == EEfectApplicationPolicy::ApplyOnOverlap) 
	{
		ApplyEffectToTarget(targetActor, _instantGameplayEffectClass);
	}

	if (_durationEffectApplicationPolicy == EEfectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(targetActor, _durationGameplayEffectClass);
	}

	if(_infinityEffectApplicationPolicy == EEfectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(targetActor, _infinityGameplayEffectClass);
	}
}

void AAuraEffectActor::OnEndOverlap(AActor* targetActor)
{
	if (_instantEffectApplicationPolicy == EEfectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(targetActor, _instantGameplayEffectClass);
	}

	if (_durationEffectApplicationPolicy == EEfectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(targetActor, _durationGameplayEffectClass);
	}

	if (_infinityEffectApplicationPolicy == EEfectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(targetActor, _infinityGameplayEffectClass);
	}

	if (_infinityEffectRemovalPolicy == EEfectRemovalPolicy::RemoveOnEndOverlap)
	{
		if (UAbilitySystemComponent* targetAbiltySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(targetActor))
		{
			TArray<FActiveGameplayEffectHandle> handlesToRemove;
			for (auto handlePair : _activeEffectHandles) 
			{
				if (targetAbiltySystemComponent == handlePair.Value)
				{
					targetAbiltySystemComponent->RemoveActiveGameplayEffect(handlePair.Key, 1);
					handlesToRemove.Add(handlePair.Key);
				}
			}

			for (FActiveGameplayEffectHandle& handle : handlesToRemove) 
			{
				_activeEffectHandles.FindAndRemoveChecked(handle);
			}
		}
	}
}

