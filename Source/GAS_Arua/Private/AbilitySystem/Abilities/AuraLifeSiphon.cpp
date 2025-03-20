// Copyright Windpig


#include "AbilitySystem/Abilities/AuraLifeSiphon.h"

float UAuraLifeSiphon::GetSiphonMagnitude()
{
	return SiphonMagnitude.GetValueAtLevel(GetAbilityLevel());
}
