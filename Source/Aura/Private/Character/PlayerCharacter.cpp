// Copyright Faya Games


#include "Character/PlayerCharacter.h"
#include "Player/AuraPlayerState.h"
#include "AbilitySystem/AuraAbilitySystemComponentBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include <UI/HUD/AuraHUD.h>
#include <Player/AuraPlayerState.h>
#include <Player/AuraPlayerController.h>

APlayerCharacter::APlayerCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 400.0f, 0.0f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void APlayerCharacter::PossessedBy(AController* newController)
{
	Super::PossessedBy(newController);
	// Init ability action info for the server
	InitAbilityActorInfo();
}

void APlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	// Init ability action info for the clients
	InitAbilityActorInfo();
}

void APlayerCharacter::InitAbilityActorInfo()
{
	Super::InitAbilityActorInfo();

	AAuraPlayerState* auraPlayerState = GetPlayerState<AAuraPlayerState>();
	check(auraPlayerState);
	auraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(auraPlayerState, this);

	Cast<UAuraAbilitySystemComponentBase>(auraPlayerState->GetAbilitySystemComponent())->AbilityActorInfoSet();

	_abilitieSystemComponent = auraPlayerState->GetAbilitySystemComponent();
	_attributeSet = auraPlayerState->GetAttributeSet();

	if (AAuraPlayerController* playerController = Cast<AAuraPlayerController>(GetController()))
	{
		if (AAuraHUD* HUD = Cast<AAuraHUD>(playerController->GetHUD()))
		{
			HUD->InitOverlay(playerController, auraPlayerState, _abilitieSystemComponent, _attributeSet);
		}
	}

	InitializeDefaultAttributes();
}
