// Copyright Faya Games

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();

protected:
	virtual void PossessedBy(AController* newController) override; //Server
	virtual void OnRep_PlayerState() override; //Clients

private:
	void InitAbilityActorInfo() override;
};
