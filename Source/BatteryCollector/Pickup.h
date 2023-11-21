// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API APickup : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APickup();

	// Return the mesh for the pick up
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickupMesh; }

	// return whether or not the pickup is active
	UFUNCTION(BlueprintPure, Category = "Pickup")
		bool IsActive();

	// allows other classes to safely change the active state of the pickup
	UFUNCTION(BlueprintCallable, Category = "Pickup")
		void SetActive(bool NewPickupState);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	// true when pickup can be used
	bool bIsActive;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Static mech to represent pickup in the level
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* PickupMesh;

};
