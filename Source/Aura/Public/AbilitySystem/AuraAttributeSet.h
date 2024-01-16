// Copyright Faya Games

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AuraAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()
	
	FEffectProperties(){}


	FGameplayEffectContextHandle EffectContextHandle;
	
	UPROPERTY()
	UAbilitySystemComponent* SourceASC = nullptr;

	UPROPERTY()
	AActor* SourceAvatarActor = nullptr;

	UPROPERTY()
	AController* SourceController = nullptr;

	UPROPERTY()
	ACharacter* SourceCharacter = nullptr;

	UPROPERTY()
	UAbilitySystemComponent* TargetASC = nullptr;

	UPROPERTY()
	AActor* TargetAvatarActor = nullptr;

	UPROPERTY()
	AController* TargetController = nullptr;

	UPROPERTY()
	ACharacter* TargetCharacter = nullptr;
};

/**
 * 
 */
UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UAuraAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


	virtual void PreAttributeChange(const FGameplayAttribute& attribute, float& newValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& data) override;

	/// <summary>
	/// Primary Attributes
	/// </summary>

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Strength, Category = "Primary Attributes")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Strength)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Inteligence, Category = "Primary Attributes")
	FGameplayAttributeData Inteligence;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Inteligence)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Resilience, Category = "Primary Attributes")
	FGameplayAttributeData Resilience;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Resilience)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Vigor, Category = "Primary Attributes")
	FGameplayAttributeData Vigor;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Vigor)

	/// <summary>
	/// Secondary Attributes
	/// </summary>
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Armor, Category = "Secondary Attributes")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Armor)
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ArmorPenetration, Category = "Secondary Attributes")
	FGameplayAttributeData ArmorPenetration;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, ArmorPenetration)
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_BlockChance, Category = "Secondary Attributes")
	FGameplayAttributeData BlockChance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, BlockChance)
		
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitChance, Category = "Secondary Attributes")
	FGameplayAttributeData CriticalHitChance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalHitChance)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitDamage, Category = "Secondary Attributes")
	FGameplayAttributeData CriticalHitDamage;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalHitDamage)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitResistence, Category = "Secondary Attributes")
	FGameplayAttributeData CriticalHitResistence;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalHitResistence)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HealthRegeneration, Category = "Secondary Attributes")
	FGameplayAttributeData HealthRegeneration;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, HealthRegeneration)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ManaRegeneration, Category = "Secondary Attributes")
	FGameplayAttributeData ManaRegeneration;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, ManaRegeneration)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Secondary Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Secondary Attributes")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxMana)

	/// <summary>
	/// Vital Attributes
	/// </summary>
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Vital Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxHealth)

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& oldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& oldMaxHealth) const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& oldMana) const;

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& oldMaxMana) const;

	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& oldStrength) const;

	UFUNCTION()
	void OnRep_Inteligence(const FGameplayAttributeData& oldInteligence) const;

	UFUNCTION()
	void OnRep_Resilience(const FGameplayAttributeData& oldResilience) const;

	UFUNCTION()
	void OnRep_Vigor(const FGameplayAttributeData& oldVigor) const;
	
	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& oldArmor) const;
	
	UFUNCTION()
	void OnRep_ArmorPenetration(const FGameplayAttributeData& oldArmorPenetration) const;
	
	UFUNCTION()
	void OnRep_BlockChance(const FGameplayAttributeData& oldBlockChance) const;
	
	UFUNCTION()
	void OnRep_CriticalHitChance(const FGameplayAttributeData& oldCriticalHitChance) const;
	
	UFUNCTION()
	void OnRep_CriticalHitDamage(const FGameplayAttributeData& oldCriticalHitDamage) const;
	
	UFUNCTION()
	void OnRep_CriticalHitResistence(const FGameplayAttributeData& oldCriticalHitResistence) const;
	
	UFUNCTION()
	void OnRep_HealthRegeneration(const FGameplayAttributeData& oldHealthRegeneration) const;
	
	UFUNCTION()
	void OnRep_ManaRegeneration(const FGameplayAttributeData& oldManaRegeneration) const;

private:
	void SetEffectProperties(const FGameplayEffectModCallbackData& data, FEffectProperties& props) const;
};
