// Copyright Windpig


#include "AuraAssetManager.h"
#include "AuraGameplayTags.h"
#include "AbilitySystemGlobals.h"

UAuraAssetManager& UAuraAssetManager::Get()
{
	check(GEngine);

	return *Cast<UAuraAssetManager>(GEngine->AssetManager);
}

void UAuraAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FAuraGameplayTags::Get().InitializeNativeGameplayTags();
	
	//UE5.4引擎自动调用
	//UAbilitySystemGlobals::Get().InitGlobalData();
}
