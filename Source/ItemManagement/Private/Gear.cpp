// Fill out your copyright notice in the Description page of Project Settings.


#include "Gear.h"
#include "GearItemBase.h"

AGear::AGear()
{
}

void AGear::BeginPlay()
{
	Super::BeginPlay();

	if (GearItemData != NULL)
	{
		auto Data = GearItemData.Get()->AssetItems[0];
		auto Mesh = Data.ItemMesh;
		if (Mesh != NULL)
		{
			StaticMesh->SetStaticMesh(Mesh);
		}
	}
}

void AGear::OnBeginInteraction(UPrimitiveComponent* OverlappedComponent, 
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
	bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnBeginInteraction(OverlappedComponent, OtherActor,
		OtherComp, OtherBodyIndex, bFromSweep, SweepResult);


}

void AGear::OnEndInteraction(UPrimitiveComponent* OverlappedComponent, 
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnEndInteraction(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);


}
