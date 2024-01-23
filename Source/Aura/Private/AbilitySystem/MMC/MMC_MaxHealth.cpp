// Copyright Faya Games


#include "AbilitySystem/MMC/MMC_MaxHealth.h"
#include <AbilitySystem/AuraAttributeSet.h>
#include <Interaction/CombatInterface.h>

UMMC_MaxHealth::UMMC_MaxHealth()
{
	VigorDef.AttributeToCapture = UAuraAttributeSet::GetVigorAttribute();
	VigorDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	VigorDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(VigorDef);
}

float UMMC_MaxHealth::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& spec) const
{
	// Gather tags from source and target
	const FGameplayTagContainer* sourceTags = spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* targetTags = spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters evaluationParameters; 
	evaluationParameters.SourceTags = sourceTags;
	evaluationParameters.TargetTags = targetTags;

	float vigor = 0.0f;
	GetCapturedAttributeMagnitude(VigorDef, spec, evaluationParameters, vigor);
	vigor = FMath::Max<float>(vigor, 0);

	ICombatInterface* combarInterface = Cast<ICombatInterface>(spec.GetContext().GetSourceObject());
	const int32 characterLevel = combarInterface->GetCharacterLevel();

	return 80.0f + (2.5f * vigor) + (10 * characterLevel);
}
