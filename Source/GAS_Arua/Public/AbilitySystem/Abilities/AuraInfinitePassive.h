// Copyright Windpig

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/AuraPassiveAbility.h"
#include "AuraInfinitePassive.generated.h"

/**
 * 
 */
UCLASS()
class GAS_ARUA_API UAuraInfinitePassive : public UAuraPassiveAbility
{
	GENERATED_BODY()
public:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	virtual void ReceiveDeactivate(const FGameplayTag& AbilityTag) override;
};
