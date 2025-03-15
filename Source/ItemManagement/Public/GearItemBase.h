// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AttributeSet.h"
#include "ItemBase.h"
#include "GearItemBase.generated.h"

UENUM(BlueprintType)
enum class EGearType : uint8
{
	E_None				UMETA(DisplayName = "None"),
	E_SingleHandMelee	UMETA(DisplayName = "Single Handed Melee Weapon"),
	E_TwoHandsMelee		UMETA(DisplayName = "Two Handed Melee Weapon"),
	E_Ranged			UMETA(DisplayName = "Ranged Weapon"),
	E_Max				UMETA(DisplayName = "Max"),
};

USTRUCT(BlueprintType)
struct FAttributeRequirement
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Requirement")
	float MinimumStatValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Requirement")
	FGameplayAttribute RequiredAttribute;
};

USTRUCT(Atomic, BlueprintType)
struct FGearItemInfo : public FItemBasicInfo
{
	GENERATED_USTRUCT_BODY()

	FGearItemInfo() { ItemType = EItemType::E_Gear; };

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MetaData")
	EGearType GearType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Requirements")
	TArray<FAttributeRequirement> RequiredStats;
};

UCLASS()
class ITEMMANAGEMENT_API UGearItemBase : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gear Item")
	TArray<FGearItemInfo> AssetItems;
};
