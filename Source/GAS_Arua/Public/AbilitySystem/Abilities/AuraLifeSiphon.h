// Copyright Windpig

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/AuraPassiveAbility.h"
#include "AuraLifeSiphon.generated.h"

/**
 * 
 */
UCLASS()
class GAS_ARUA_API UAuraLifeSiphon : public UAuraPassiveAbility
{
	GENERATED_BODY()
public:

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FScalableFloat SiphonMagnitude;

	UFUNCTION(BlueprintCallable)
	float GetSiphonMagnitude();
};
