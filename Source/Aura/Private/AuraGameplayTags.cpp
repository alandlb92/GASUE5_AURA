// Copyright Faya Games


#include "AuraGameplayTags.h"
#include <GameplayTagsManager.h>

FAuraGameplayTags FAuraGameplayTags::_instance;

void FAuraGameplayTags::InitializeNativeGameplayTags()
{
	for (auto pair : _instance.gameplayTagsNames) {
		auto gameplayTag = UGameplayTagsManager::Get().AddNativeGameplayTag(FName(pair.first.c_str()), FString(pair.second.c_str()));
		_instance.gameplayTags.push_back(std::pair(pair.first, gameplayTag));
	}
}

FGameplayTag FAuraGameplayTags::GetGameplayTagByName(const char* name)
{
	for (auto pair : gameplayTags) {
		if (pair.first.compare(name))
			return pair.second;
	}
}
