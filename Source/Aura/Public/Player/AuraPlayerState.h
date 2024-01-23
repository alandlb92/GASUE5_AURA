// Copyright Faya Games

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "AuraPlayerState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS()
class AURA_API AAuraPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	AAuraPlayerState();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	UAttributeSet* GetAttributeSet() const;

	FORCEINLINE int32 GetPlayerLevel() const { return _level; }
protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> _abilitieSystemComponent;

	UPROPERTY(transient)
	TObjectPtr<UAttributeSet> _attributeSet;

private:
	UPROPERTY(VisibleAnywhere, ReplicatedUsing= OnRep_Level)
	int32 _level = 1;

	UFUNCTION()
	void OnRep_Level(int32 oldLevel);
};
