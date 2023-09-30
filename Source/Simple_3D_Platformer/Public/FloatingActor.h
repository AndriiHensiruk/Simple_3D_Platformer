// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingActor.generated.h"

UCLASS()
class SIMPLE_3D_PLATFORMER_API AFloatingActor : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AFloatingActor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// declare our float variables 
	float RunningTime;

	UPROPERTY(EditAnywhere, Category = Movement)
		float XValue;

	UPROPERTY(EditAnywhere, Category = Movement)
		float YValue;

	UPROPERTY(EditAnywhere, Category = Movement)
		float ZValue;
};
