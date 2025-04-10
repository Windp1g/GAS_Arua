// Copyright Windpig


#include "AbilitySystem/Passive/PassiveNiagaraComponent.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AuraGameplayTags.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "Interaction/CombatInterface.h"

UPassiveNiagaraComponent::UPassiveNiagaraComponent()
{
	bAutoActivate = false;
}

void UPassiveNiagaraComponent::BeginPlay()
{
	Super::BeginPlay();
	
	ICombatInterface* CombatInterface = Cast<ICombatInterface>(GetOwner());
	UAuraAbilitySystemComponent* AuraASC = Cast<UAuraAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwner()));
	if (AuraASC)
	{
		AuraASC->ActivatePassiveNiagara.AddUObject(this, &UPassiveNiagaraComponent::OnPassiveActivate);
		ActivateIfEquipped(AuraASC);
	}
	else if (CombatInterface)
	{
		CombatInterface->GetOnASCRegisteredDelegate().AddWeakLambda(this, [this](UAbilitySystemComponent* InASC)
		{
			if (UAuraAbilitySystemComponent* AuraASC = Cast<UAuraAbilitySystemComponent>(InASC))
			{
				AuraASC->ActivatePassiveNiagara.AddUObject(this, &UPassiveNiagaraComponent::OnPassiveActivate);
				ActivateIfEquipped(AuraASC);
			}
		});
	}
	if (CombatInterface)
	{
		CombatInterface->GetOnDeathDelegate().AddDynamic(this, &UPassiveNiagaraComponent::OnOwnerDeath);
	}
}

void UPassiveNiagaraComponent::ActivateIfEquipped(UAuraAbilitySystemComponent* AuraASC)
{
	const bool bStartUpABilitiesGiven = AuraASC->bStartupAbilitiesGiven;
	if (bStartUpABilitiesGiven)
	{
		if (AuraASC->GetStatusFromAbilityTag(PassiveSpellTag) == FAuraGameplayTags::Get().Abilities_Status_Equipped)
		{
			Activate();
		}
	}
}

void UPassiveNiagaraComponent::OnPassiveActivate(const FGameplayTag& AbilityTag, bool bActivate)
{
	if (AbilityTag.MatchesTagExact(PassiveSpellTag))
	{
		if (bActivate && !IsActive())
		{
			Activate();
		}
		else
		{
			Deactivate();
		}
	}
}

void UPassiveNiagaraComponent::OnOwnerDeath(AActor* DeadActor)
{
	Deactivate();
}
