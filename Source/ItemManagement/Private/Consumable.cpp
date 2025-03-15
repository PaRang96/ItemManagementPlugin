// Fill out your copyright notice in the Description page of Project Settings.


#include "Consumable.h"
#include "ConsumableItemBase.h"

AConsumable::AConsumable()
{
}

void AConsumable::BeginPlay()
{
	Super::BeginPlay();

	if (ConsumableItemData != NULL)
	{
		auto Data = ConsumableItemData.Get()->AssetItems[0];
		auto Mesh = Data.ItemMesh;
		if (Mesh != NULL)
		{
			StaticMesh->SetStaticMesh(Mesh);
		}
	}
}

void AConsumable::OnBeginInteraction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnBeginInteraction(OverlappedComponent, OtherActor,
		OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	
}

void AConsumable::OnEndInteraction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnEndInteraction(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

}
