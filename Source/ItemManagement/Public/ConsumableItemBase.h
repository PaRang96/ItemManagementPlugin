// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemBase.h"
#include "GameplayEffect.h"
#include "ConsumableItemBase.generated.h"

USTRUCT(BlueprintType)
struct FConsumeEffect
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Effect")
	float EffectMagnitude;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Effect")
	TSubclassOf<UGameplayEffect> EffectToApply;
};

USTRUCT(Atomic, BlueprintType)
struct FConsumableItemInfo : public FItemBasicInfo
{
	GENERATED_USTRUCT_BODY()

	FConsumableItemInfo() { ItemType = EItemType::E_Consumable; };

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Effect")
	TArray<FConsumeEffect> Effects;
};

UCLASS(BlueprintType)
class ITEMMANAGEMENT_API UConsumableItemBase : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Consumable Item")
	TArray<FConsumableItemInfo> AssetItems;
};
