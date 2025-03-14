// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ConsumableItemBase.h"
#include "InventoryComponent.generated.h"

UCLASS( ClassGroup=(ItemControl), meta=(BlueprintSpawnableComponent), Blueprintable )
class ITEMMANAGEMENT_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInventoryComponent();

protected:
	virtual void BeginPlay() override;

private:
	TMap<UConsumableItemBase*, int32> Consumables;
};
