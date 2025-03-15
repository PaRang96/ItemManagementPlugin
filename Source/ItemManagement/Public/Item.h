// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

class UItemBase;
class UStaticMeshComponent;
class USphereComponent;
enum class EItemType : uint8;

UCLASS()
class ITEMMANAGEMENT_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

private:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Interaction",
		meta = (AllowPrivateAccess = true))
	TObjectPtr<USphereComponent> InteractionRange;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	EItemType Type;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Appearance",
		meta = (AllowPrivateAccess = true))
	TObjectPtr<UStaticMeshComponent> StaticMesh;

	UFUNCTION()
	virtual void OnBeginInteraction(UPrimitiveComponent* OverlappedComponent, 
		AActor* OtherActor, UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnEndInteraction(UPrimitiveComponent* OverlappedComponent, 
		AActor* OtherActor, UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex);
};
