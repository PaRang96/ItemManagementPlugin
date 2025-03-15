// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "ItemBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Engine/StaticMesh.h"

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
