// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	Camera->SetupAttachment(RootComponent);
	Camera->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

	PlayerInputComponent->BindAxis("TurnCamera", this, &APlayerCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::LookUp);

	//PlayerInputComponent->BindAxis("TurnRate", this, &APawn::AddControllerYawInput);
	//PlayerInputComponent->BindAxis("LookUpRate", this, &APawn::AddControllerPitchInput);



}

void APlayerCharacter::MoveForward(float InputValue)
{
	if ((Controller) && (InputValue != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, InputValue);
	}
}

void APlayerCharacter::MoveRight(float InputValue)
{
	if ((Controller) && (InputValue != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, InputValue);
	}
	//FVector RightDirection = GetActorRightVector();
	//AddMovementInput(RightDirection, InputValue);
}

void APlayerCharacter::Turn(float InputValue)
{
	AddControllerYawInput(InputValue * 45.0f * GetWorld() -> GetDeltaSeconds());
}

void APlayerCharacter::LookUp(float InputValue)
{
	AddControllerPitchInput(InputValue * 45.0f * GetWorld()->GetDeltaSeconds());
}

void APlayerCharacter::AddScore_Implementation(float AddScore)
{
	Score = Score + AddScore;
	UE_LOG(LogTemp, Warning, TEXT("Some warning message"), Score);
}

