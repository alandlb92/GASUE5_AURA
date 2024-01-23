// Copyright Faya Games

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "../Interaction/Highlight.h"
#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AEnemyCharacter : public ABaseCharacter, public IHighlight
{
	GENERATED_BODY()
public:
	AEnemyCharacter();

	/** IHighlight Interface implementations* */
	virtual void HighlightActor() override;
	virtual void UnHighlightAction() override;

	/* Combat Interface */
	virtual int32 GetCharacterLevel() override;

protected:
	virtual void BeginPlay() override;
	void InitAbilityActorInfo() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 _level = 1;
};
