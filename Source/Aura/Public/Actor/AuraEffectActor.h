// Copyright Faya Games

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <GameplayEffectTypes.h>
#include "AuraEffectActor.generated.h"

class UGameplayEffect;

UENUM(BlueprintType)
enum class EEfectApplicationPolicy 
{
	ApplyOnOverlap,
	ApplyOnEndOverlap,
	DoNotApply
};

UENUM(BlueprintType)
enum class EEfectRemovalPolicy
{
	RemoveOnEndOverlap,
	DoNotRemove
};

UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AAuraEffectActor();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* targetActor, TSubclassOf<UGameplayEffect> gameplayEffectClass);

	UFUNCTION(BlueprintCallable)
	void OnOverlap(AActor* targetActor);

	UFUNCTION(BlueprintCallable)
	void OnEndOverlap(AActor* targetActor);

	UPROPERTY(Editanywhere, BlueprintReadOnly, Category = "Applied Effects")
	bool bDestroyOnEffectRemoval = false;

	UPROPERTY(Editanywhere, BlueprintReadOnly, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> _instantGameplayEffectClass;
	UPROPERTY(Editanywhere, BlueprintReadOnly, Category = "Applied Effects")
	EEfectApplicationPolicy _instantEffectApplicationPolicy = EEfectApplicationPolicy::DoNotApply;


	UPROPERTY(Editanywhere, BlueprintReadOnly, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> _durationGameplayEffectClass;
	UPROPERTY(Editanywhere, BlueprintReadOnly, Category = "Applied Effects")
	EEfectApplicationPolicy _durationEffectApplicationPolicy = EEfectApplicationPolicy::DoNotApply;

	UPROPERTY(Editanywhere, BlueprintReadOnly, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> _infinityGameplayEffectClass;
	UPROPERTY(Editanywhere, BlueprintReadOnly, Category = "Applied Effects")
	EEfectApplicationPolicy _infinityEffectApplicationPolicy = EEfectApplicationPolicy::DoNotApply;
	UPROPERTY(Editanywhere, BlueprintReadOnly, Category = "Applied Effects")
	EEfectRemovalPolicy _infinityEffectRemovalPolicy = EEfectRemovalPolicy::RemoveOnEndOverlap;

	TMap<FActiveGameplayEffectHandle, UAbilitySystemComponent*> _activeEffectHandles;

	UPROPERTY(Editanywhere, BlueprintReadOnly, Category = "Applied Effects")
	float _actorLevel = 1.f;
};
