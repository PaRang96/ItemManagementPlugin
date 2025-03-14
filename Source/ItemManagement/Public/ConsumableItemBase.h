// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemManagement.h"
#include "ConsumableItemBase.generated.h"

UENUM(BlueprintType)
enum class EDurationType : uint8
{
	E_None				UMETA(DisplayName = "None"),
	E_Instant			UMETA(DisplayName = "Instant"),
	E_Persistent		UMETA(DisplayName = "Persists over Time"),
	E_MAX				UMETA(DisplayName = "Max")
};

USTRUCT(Atomic, BlueprintType)
struct FConsumableItemInfo
{
	GENERATED_USTRUCT_BODY()

	FConsumableItemInfo() { ItemType = EItemType::E_Consumable; };

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Metadata")
	EItemType ItemType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Metadata")
	FText ItemName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Metadata")
	FText Description;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Metadata")
	TObjectPtr<UTexture2D> ItemIcon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Metadata")
	TObjectPtr<UStaticMesh> ItemMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Metadata")
	EDurationType DurationType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Metadata")
	float AffectAmount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Metadata")
	int32 ItemValue;
};

UCLASS(BlueprintType)
class ITEMMANAGEMENT_API UConsumableItemBase : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Consumable Item")
	TArray<FConsumableItemInfo> AssetItems;
};
