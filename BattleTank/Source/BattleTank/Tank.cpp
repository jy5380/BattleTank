// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "TankBarrle.h"
#include "Projectile.h"

void ATank::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (Barrle && isReloaded)
	{
		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrle->GetSocketLocation(FName("Projectile")),
			Barrle->GetSocketRotation(FName("Projectile"))
			);

		Projectile->LauchProjectile(LaunchSpeed);

		LastFireTime = FPlatformTime::Seconds();
	}
	
}

void ATank::SetBarrleReference(UTankBarrle * BarrleToSet)
{
	TankAimingComponent->SetBarrleReference(BarrleToSet);
	Barrle = BarrleToSet;
}

void ATank::SetTurretReference(UTankTurret * TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

	//Barrle = GetComponentByClass()
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}
