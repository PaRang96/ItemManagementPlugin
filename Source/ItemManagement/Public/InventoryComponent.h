// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemBase.h"
#include "InventoryComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnInventoryItemAdded, TSubclassOf<UItemBase> AddedItem);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnInventoryItemRemoved, TSubclassOf<UItemBase> RemovedItem);

UCLASS( ClassGroup=(ItemControl), meta=(BlueprintSpawnableComponent), Blueprintable )
class ITEMMANAGEMENT_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInventoryComponent();

protected:
	// @todo: when save system implemented, Begin Play should be overriden
	virtual void BeginPlay();

private:
	// map consists of: item - quantity pair => for stackable items
	TMap<TSubclassOf<UItemBase>, int32> StackableItems;

	// for non-stackable items
	TArray<TObjectPtr<UItemBase>> UniqueItems;

public:
	UFUNCTION(BlueprintCallable)
	bool AcquireItem(TSubclassOf<UItemBase> NewItem, int32 Quantity = 1);

	UFUNCTION(BlueprintCallable)
	bool UseItem(TSubclassOf<UItemBase> TargetItem, int32 Quantity = 1);

private:
	bool AddItem_NonStackable(TSubclassOf<UItemBase> NewItem);
	bool AddItem_Stackable(TSubclassOf<UItemBase> NewItem, int32 Quantity = 1);

	bool RemoveItem_NonStackable(TSubclassOf<UItemBase> TargetItem);
	bool RemoveItem_Stackable(TSubclassOf<UItemBase> TargetItem, int32 Quantity = 1);

protected:
	FOnInventoryItemAdded OnInventoryItemAdded;
	FOnInventoryItemRemoved OnInventoryItemRemoved;
};
