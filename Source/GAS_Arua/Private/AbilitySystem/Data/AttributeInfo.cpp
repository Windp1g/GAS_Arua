// Copyright Windpig


#include "AbilitySystem/Data/AttributeInfo.h"

#include "GAS_Arua/AuraLogChannels.h"

FAuraAttributeInfo UAttributeInfo::FindAttributeInfoFormTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
	for (const FAuraAttributeInfo& Info : AttributeInformation)
	{
		if (Info.AttributeTag.MatchesTagExact(AttributeTag))
		{
			return Info;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogAura, Error, TEXT("Can't find attribute tag [%s] on AttributeInfo [%s]"), *AttributeTag.ToString(), *GetNameSafe(this));
	}

	return FAuraAttributeInfo();
}
