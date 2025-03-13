// Copyright Windpig


#include "AbilitySystem/Abilities/AuraFireBolt.h"

#include "AuraGameplayTags.h"

FString UAuraFireBolt::GetDescription(int32 Level)
{
	const int32 Damage = GetDamageByDamageTag(Level, FAuraGameplayTags::Get().Damage_Fire);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	return FString::Printf(TEXT(
		"<Title>火球术</>\n\n"
		"<Small>等级：</><Level>%d</>\n"
		"<Small>耗蓝:</><ManaCost>%.1f</>\n"
		"<Small>冷却:</><Cooldown>%.1fs</>\n\n"
		"<Default>发射%d个火球， 爆炸时造成</>"
		"<Damage>%d</><Default>火焰伤害并有几率燃烧</>"
		), Level, ManaCost, Cooldown, FMath::Min(Level, NumProjectiles), Damage);
}

FString UAuraFireBolt::GetNextLevelDescription(int32 Level)
{
	const int32 Damage = GetDamageByDamageTag(Level, FAuraGameplayTags::Get().Damage_Fire);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	return FString::Printf(TEXT(
		"<Title>下一级：</>\n\n"
		"<Small>等级：</><Level>%d</>\n"
		"<Small>耗蓝:</><ManaCost>%.1f</>\n"
		"<Small>冷却:</><Cooldown>%.1fs</>\n\n"
		"<Default>发射%d个火球， 爆炸时造成</>"
		"<Damage>%d</><Default>火焰伤害并有几率燃烧</>"
		), Level, ManaCost, Cooldown, FMath::Min(Level, NumProjectiles), Damage);
}