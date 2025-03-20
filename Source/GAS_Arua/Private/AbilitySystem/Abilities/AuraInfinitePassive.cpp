// Copyright Windpig


#include "AbilitySystem/Abilities/AuraInfinitePassive.h"

#include "AbilitySystemComponent.h"

void UAuraInfinitePassive::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                           const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                           const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	
	FGameplayEffectSpecHandle PassiveEffectSpec = MakeOutgoingGameplayEffectSpec(PassiveEffect, GetAbilityLevel());
	if (PassiveEffectSpec.IsValid()) {
		ApplyGameplayEffectSpecToOwner(Handle, ActorInfo, ActivationInfo, PassiveEffectSpec);
	}
}

void UAuraInfinitePassive::ReceiveDeactivate(const FGameplayTag& AbilityTag)
{
	if (AbilityTags.HasTagExact(AbilityTag))
	{
		FGameplayTagContainer PassiveTags;
		PassiveTags.AddTag(AbilityTag);
		GetAbilitySystemComponentFromActorInfo()->RemoveActiveEffectsWithTags(PassiveTags);
	}
	Super::ReceiveDeactivate(AbilityTag);
}
