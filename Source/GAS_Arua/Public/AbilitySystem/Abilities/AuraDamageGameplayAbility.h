// Copyright Windpig

#pragma once

#include "CoreMinimal.h"
#include "AuraAbilityType.h"
#include "AbilitySystem/Abilities/AuraGameplayAbility.h"
#include "Interaction/CombatInterface.h"
#include "AuraDamageGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class GAS_ARUA_API UAuraDamageGameplayAbility : public UAuraGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void CauseDamage(AActor* TargetActor);

	UFUNCTION(BlueprintPure)
	FDamageEffectParams MakeDamageEffectParamFromClassDefault(
		AActor* TargetActor = nullptr,
		FVector InRadialDamageOrigin = FVector::ZeroVector,
		bool bOverrideKnockbackDirection = false,
		FVector KnockbackDirectionOverride = FVector::ZeroVector,
		bool bOverrideDeathImpulse = false,
		FVector DeathImpulseDirectionOverride = FVector::ZeroVector,
		bool bOverridePitch = false,
		float PitchOverride = 0.f) const;

	UFUNCTION(BlueprintPure)
	float GetDamageAtLevel() const;
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> DamageEffectClass;
	
	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	FGameplayTag DamageType;
	
	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	FScalableFloat Damage;

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	float DebuffChance = 20.f;

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	float DebuffDamage = 5.f;

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	float DebuffFrequency = 1.f;

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	float DebuffDuration = 5.f;
	
	UPROPERTY(EditDefaultsOnly, Category = "Impulse")
	float DeathImpulseMagnitude = 1000.f;

	UPROPERTY(EditDefaultsOnly, Category = "Knockback")
	float KnockbackForceMagnitude = 500.f;

	UPROPERTY(EditDefaultsOnly, Category = "Knockback")
	float KnockbackChance = 0.f;

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	bool bIsRadialDamage = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Damage")
	float RadialDamageInnerRadius = 0.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Damage")
	float RadialDamageOuterRadius = 0.f;

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	FScalableFloat RadialMinDamage = 0.f;

	UFUNCTION(BlueprintPure)
	FTaggedMontage GetRandomTaggedMontageFromArray(const TArray<FTaggedMontage>& TaggedMontages) const;
};
