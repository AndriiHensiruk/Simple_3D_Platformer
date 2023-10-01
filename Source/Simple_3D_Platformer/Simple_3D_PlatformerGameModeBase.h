// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Simple_3D_PlatformerGameModeBase.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGameOver);

UCLASS()
class SIMPLE_3D_PLATFORMER_API ASimple_3D_PlatformerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable, Category = "Test")
		FGameOver OnGameOver;
};
