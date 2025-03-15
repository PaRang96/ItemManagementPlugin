// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "ItemBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = false;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	if (StaticMesh)
	{
		SetRootComponent(StaticMesh);
	}

	InteractionRange = CreateDefaultSubobject<USphereComponent>(TEXT("Interaction Range"));
	if (InteractionRange)
	{
		InteractionRange->SetupAttachment(StaticMesh);
	}

	if (ItemData != NULL)
	{
		auto Data = Cast<UItemBase>(ItemData.Get())->AssetItems[0];
		Type = Data.ItemType;
		auto Mesh = Data.ItemMesh.Get();
		if (Mesh)
		{
			StaticMesh->SetStaticMesh(Mesh);
		}
	}
}

void AItem::BeginPlay()
{
	Super::BeginPlay();

	if (InteractionRange)
	{
		InteractionRange->OnComponentBeginOverlap.AddDynamic(
			this, &ThisClass::OnBeginInteraction);
		InteractionRange->OnComponentEndOverlap.AddDynamic(
			this, &ThisClass::OnEndInteraction);
	}

	switch (Type)
	{
	case EItemType::E_Consumable:
		break;
	case EItemType::E_Gear:
		break;
	default:
		checkNoEntry();
		break;
	}
}

void AItem::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (InteractionRange)
	{
		InteractionRange->OnComponentBeginOverlap.RemoveDynamic(
			this, &ThisClass::OnBeginInteraction);
		InteractionRange->OnComponentEndOverlap.RemoveDynamic(
			this, &ThisClass::OnEndInteraction);
	}
}

void AItem::OnBeginInteraction(UPrimitiveComponent* OverlappedComponent, 
	AActor* OtherActor, UPrimitiveComponent* OtherComp,  int32 OtherBodyIndex, 
	bool bFromSweep, const FHitResult& SweepResult)
{

}

void AItem::OnEndInteraction(UPrimitiveComponent* OverlappedComponent, 
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}
