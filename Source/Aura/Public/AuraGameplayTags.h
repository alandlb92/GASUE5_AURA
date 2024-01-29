// Copyright Faya Games

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/// <summary>
/// Aura gamplay tag 
/// Singleton containing native Gameplay Tags
/// </summary>

struct FAuraGameplayTags
{
public:
	static const FAuraGameplayTags& Get() { return _instance; };
	static void InitializeNativeGameplayTags();

	FGameplayTag GetGameplayTagByName(const char* name);
protected:
private:
	static FAuraGameplayTags _instance;
	std::vector<std::pair<std::string, FGameplayTag>> gameplayTags;

	const std::vector<std::pair<std::string, std::string>> gameplayTagsNames =
	{
		{ "Attributes.Primary.Strength", ""},
		{ "Attributes.Primary.Inteligence", ""},
		{ "Attributes.Primary.Resilience", ""},
		{ "Attributes.Primary.Vigor", ""},
		{ "Attributes.Secondary.Armor", ""},
		{ "Attributes.Secondary.ArmorPenetration", ""},
		{ "Attributes.Secondary.BlockChance", ""},
		{ "Attributes.Secondary.CriticalHitChance", ""},
		{ "Attributes.Secondary.CriticalHitDamage", ""},
		{ "Attributes.Secondary.CriticalHitResistence", ""},
		{ "Attributes.Secondary.HealthRegeneration", ""},
		{ "Attributes.Secondary.ManaRegeneration", ""},
		{ "Attributes.Secondary.MaxHealth", ""},
		{ "Attributes.Secondary.MaxMana", ""},
		{ "Attributes.Vital.Health", ""},
		{ "Attributes.Vital.MaxHealth", ""}
	};


};