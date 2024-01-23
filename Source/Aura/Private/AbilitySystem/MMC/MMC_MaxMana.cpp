// Copyright Faya Games


#include "AbilitySystem/MMC/MMC_MaxMana.h"

#include "AbilitySystem/MMC/MMC_MaxHealth.h"
#include <AbilitySystem/AuraAttributeSet.h>
#include <Interaction/CombatInterface.h>

UMMC_MaxMana::UMMC_MaxMana()
{
	IntelligenceDef.AttributeToCapture = UAuraAttributeSet::GetInteligenceAttribute();
	IntelligenceDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	IntelligenceDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(IntelligenceDef);
}

float UMMC_MaxMana::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& spec) const
{
	// Gather tags from source and target
	const FGameplayTagContainer* sourceTags = spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* targetTags = spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters evaluationParameters;
	evaluationParameters.SourceTags = sourceTags;
	evaluationParameters.TargetTags = targetTags;

	float Intelligence = 0.0f;
	GetCapturedAttributeMagnitude(IntelligenceDef, spec, evaluationParameters, Intelligence);
	Intelligence = FMath::Max<float>(Intelligence, 0);

	ICombatInterface* combarInterface = Cast<ICombatInterface>(spec.GetContext().GetSourceObject());
	const int32 characterLevel = combarInterface->GetCharacterLevel();

	return 50.0f + (2.5f * Intelligence) + (15 * characterLevel);
}
