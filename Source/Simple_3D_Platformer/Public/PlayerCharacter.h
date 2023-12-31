// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InteractInterface.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class SIMPLE_3D_PLATFORMER_API APlayerCharacter : public ACharacter, public IInteractInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	UPROPERTY(EditAnywhere)
	class UCameraComponent* Camera;

	void MoveForward(float InputValue);
	void MoveRight(float InputValue);

	void Turn(float InputValue);
	void LookUp(float InputValue);

	virtual void AddScore_Implementation(float AddScore) override;

	UPROPERTY(EditDefaultsOnly)
		int32 Score = 0;
};
