// Copyright Faya Games


#include "AuraAssetManager.h"
#include "AuraGameplayTags.h"

UAuraAssetManager& UAuraAssetManager::Get()
{
	check(GEngine);
	UAuraAssetManager* auraAssetMaanger = Cast<UAuraAssetManager>(GEngine->AssetManager);
	return *auraAssetMaanger;
}

void UAuraAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FAuraGameplayTags::InitializeNativeGameplayTags();

}
