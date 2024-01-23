// Copyright Faya Games


#include "Character/BaseCharacter.h"
#include "AbilitySystemComponent.h"

ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	_weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	_weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	_weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
	return _abilitieSystemComponent;
}

UAttributeSet* ABaseCharacter::GetAttributeSet() const
{
	return _attributeSet;
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();	
}

void ABaseCharacter::InitAbilityActorInfo()
{
}

void ABaseCharacter::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> gameplayEffectClass, float level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(gameplayEffectClass);
	FGameplayEffectContextHandle contextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	contextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle specHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(gameplayEffectClass, level, contextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*specHandle.Data.Get(), GetAbilitySystemComponent());
}

void ABaseCharacter::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(_defaultPimaryAttributes, 1);
	ApplyEffectToSelf(_defaultSecondaryAttributes, 1);
	ApplyEffectToSelf(_defaultVitalAttributes, 1);
}

