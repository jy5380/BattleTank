// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/Controller.h"
#include "TankControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankControllerBase : public AController
{
	GENERATED_BODY()
	
public:

	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;
};
