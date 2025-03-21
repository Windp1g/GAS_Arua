// Copyright Windpig


#include "AbilitySystem/Abilities/AuraLifeSiphon.h"

FString UAuraLifeSiphon::GetDescription(int32 Level)
{
	const int32 HealthSiphon = 100 * GetSiphonMagnitude(Level);
	return FString::Printf(TEXT(
		"<Title>生命汲取</>\n\n"
		"<Small>等级：</><Level>%d</>\n\n"
		"<Default>造成伤害时回血，回血量为造成伤害的</>"
		"<Damage>%d%%</>"
		), Level, HealthSiphon);
}

FString UAuraLifeSiphon::GetNextLevelDescription(int32 Level)
{
	const int32 HealthSiphon = 100 * GetSiphonMagnitude(Level);
	return FString::Printf(TEXT(
		"<Title>下一级：</>\n\n"
		"<Small>等级：</><Level>%d</>\n\n"
		"<Default>造成伤害时回血，回血量为造成伤害的</>"
		"<Damage>%d%%</>"
		), Level, HealthSiphon);
}

float UAuraLifeSiphon::GetSiphonMagnitude(float InLevel) const
{
	return SiphonMagnitude.GetValueAtLevel(InLevel);
}
