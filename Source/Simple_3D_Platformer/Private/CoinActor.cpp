// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinActor.h"

#include "GameFramework/RotatingMovementComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

#include "NiagaraFunctionLibrary.h"



// Sets default values
ACoinActor::ACoinActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ColliderComponent = CreateDefaultSubobject<USphereComponent>("ColliderComponent");
	ColliderComponent->SetGenerateOverlapEvents(true);
	SetRootComponent(ColliderComponent);
	ColliderComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	ColliderComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	ColliderComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	ColliderComponent->OnComponentBeginOverlap.AddDynamic(
		this, &ACoinActor::OnBeginOverlapComponentEvent
	);

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	MeshComponent->SetupAttachment(ColliderComponent);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	MeshComponent->SetGenerateOverlapEvents(false);

	RotatingMovementComponent = CreateDefaultSubobject<URotatingMovementComponent>("RotatingMovementComponent");
}
void ACoinActor::OnBeginOverlapComponentEvent(
	UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult
)
{
	if (!Cast<ACharacter>(OtherActor)) return;

	if (PickSound)
	{
		UGameplayStatics::PlaySoundAtLocation(
			this, PickSound, GetActorLocation(), VolumeMultiplier);
	}

	if (OnPickupEffect)
	{
		const FVector Offset = GetActorUpVector() * PickEffectSpawnOffset;
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(
			this, OnPickupEffect, OtherActor->GetActorLocation() + Offset);
	}

	IInteractInterface::Execute_AddScore(OtherActor, AddScore);

	Destroy();
}


