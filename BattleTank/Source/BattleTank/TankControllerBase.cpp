// Fill out your copyright notice in the Description page of Project Settings.


#include "TankControllerBase.h"


ATank* ATankControllerBase::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankControllerBase::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Controller Possessed tank %s"), *(ControlledTank->GetName()));
	}
}