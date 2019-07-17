// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Tank.generated.h"

class UTankBarrle;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
	void Fire();

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrleReference(UTankBarrle* BarrleToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 4000;
	UPROPERTY(EditAnywhere, Category = Firing)
		float ReloadTimeInSeconds = 3.f;
	UPROPERTY(EditAnywhere, Category = Firing)
		double LastFireTime = 0;
	UPROPERTY(EditAnywhere, Category = Setup)
		//UClass* ProjectileBlueprint;
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UTankBarrle* Barrle = nullptr;
	
};
