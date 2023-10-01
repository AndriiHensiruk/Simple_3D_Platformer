// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractInterface.h"
#include "CoinActor.generated.h"

class UStaticMeshComponent;
class URotatingMovementComponent;
class USphereComponent;
class UNiagaraSystem;
class USoundBase;
class USoundBase;

UCLASS()
class SIMPLE_3D_PLATFORMER_API ACoinActor : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoinActor();

	UFUNCTION()
		void OnBeginOverlapComponentEvent(
			UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult
		);

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Coin")
		TObjectPtr<UStaticMeshComponent> MeshComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Coin")
		TObjectPtr<URotatingMovementComponent> RotatingMovementComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Coin")
		TObjectPtr<USphereComponent> ColliderComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Coin")
		TObjectPtr<UNiagaraSystem> OnPickupEffect;

	UPROPERTY(EditDefaultsOnly, Category = "Coin")
		TObjectPtr<USoundBase> PickSound;

	UPROPERTY(EditDefaultsOnly, Category = "Coin")
		float VolumeMultiplier{ 0.5 };

	UPROPERTY(EditDefaultsOnly, Category = "Coin")
		float PickEffectSpawnOffset{ 90 };

public:

	UPROPERTY(EditDefaultsOnly, Category = "Coin")
		int32 AddScore{ 5 };

};
