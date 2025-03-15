// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UInventoryComponent::AcquireItem(TSubclassOf<UItemBase> NewItem, int32 Quantity)
{
	if (Cast<UItemBase>(NewItem.Get())->AssetItems[0].bAllowStack)
	{
		return AddItem_Stackable(NewItem, Quantity);
	}
	else
	{
		return AddItem_NonStackable(NewItem);
	}
}

bool UInventoryComponent::UseItem(TSubclassOf<UItemBase> TargetItem, int32 Quantity)
{
	if (Cast<UItemBase>(TargetItem.Get())->AssetItems[0].bAllowStack)
	{
		return RemoveItem_Stackable(TargetItem, Quantity);
	}
	else
	{
		return RemoveItem_NonStackable(TargetItem);
	}
}

bool UInventoryComponent::AddItem_NonStackable(TSubclassOf<UItemBase> NewItem)
{
	auto NewItemPtr = Cast<UItemBase>(NewItem.Get());
	UniqueItems.Add(NewItemPtr);
	if (UniqueItems.Find(NewItemPtr) != INDEX_NONE)
	{
		OnInventoryItemAdded.Broadcast(NewItem);
		return true;
	}
	return false;
}

bool UInventoryComponent::AddItem_Stackable(TSubclassOf<UItemBase> NewItem, int32 Quantity)
{
	if (StackableItems.Contains(NewItem))
	{
		StackableItems.Add(NewItem, *StackableItems.Find(NewItem) + Quantity);
		OnInventoryItemAdded.Broadcast(NewItem);
		return true;
	}
	else
	{
		StackableItems.Add(NewItem, Quantity);
		OnInventoryItemAdded.Broadcast(NewItem);
		return true;
	}
}

bool UInventoryComponent::RemoveItem_NonStackable(TSubclassOf<UItemBase> TargetItem)
{
	auto TargetItemPtr = Cast<UItemBase>(TargetItem.Get());
	if (UniqueItems.Find(TargetItemPtr) == INDEX_NONE)
	{
		return false;
	}
	OnInventoryItemRemoved.Broadcast(TargetItem);
	UniqueItems.Remove(TargetItemPtr);
	return true;
}

bool UInventoryComponent::RemoveItem_Stackable(TSubclassOf<UItemBase> TargetItem, int32 Quantity)
{
	if (!StackableItems.Contains(TargetItem))
	{
		return false;
	}
	int32 NewQuantity = *StackableItems.Find(TargetItem) - Quantity;
	OnInventoryItemRemoved.Broadcast(TargetItem);
	StackableItems.Add(TargetItem, NewQuantity);
	return true;
}

