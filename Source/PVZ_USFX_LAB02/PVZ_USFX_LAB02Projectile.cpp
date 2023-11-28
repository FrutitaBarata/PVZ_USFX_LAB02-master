// Copyright Epic Games, Inc. All Rights Reserve

#include "PVZ_USFX_LAB02Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Engine/StaticMesh.h"
#include "ZombieComun.h"

APVZ_USFX_LAB02Projectile::APVZ_USFX_LAB02Projectile() 
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Static reference to the mesh to use for the projectile
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile"));
	// Create mesh component for the projectile sphere
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh0"));
	ProjectileMesh->SetStaticMesh(ProjectileMeshAsset.Object);
	ProjectileMesh->SetupAttachment(RootComponent);
	ProjectileMesh->BodyInstance.SetCollisionProfileName("Projectile");
	ProjectileMesh->OnComponentHit.AddDynamic(this, &APVZ_USFX_LAB02Projectile::OnHit);		// set up a notification for when this component hits something
	RootComponent = ProjectileMesh;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement0"));
	ProjectileMovement->UpdatedComponent = ProjectileMesh;
	ProjectileMovement->InitialSpeed = 250.0f;
	ProjectileMovement->MaxSpeed = 250.0f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->ProjectileGravityScale = 0.f; // No gravity

	// Die after 3 seconds by default
	MaxDistance = 1000.0f;
	//InitialLifeSpan = 10.0f;
	InitialLifeSpan = MaxDistance / ProjectileMovement->InitialSpeed;
	DamageGenerates = 10.0f;
}

void APVZ_USFX_LAB02Projectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Muestra un mensaje indicando que la función NotifyHit se ha llamado
	/*GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("NotifyHit se ha llamado"));*/

	// Verifica si el proyectil chocó con un objeto de clase AZombieComun
	AZombieComun* Zombie = Cast<AZombieComun>(OtherActor);
	if (Zombie)
	{
		if (OtherActor == Zombie) {
			Zombie->Health -= 10;
			//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Este es un mensaje %i"), Zombie->energia));
			if (Zombie->Health <= 0) {
				Zombie->Destroy();
			};
		}
	}
	
	Destroy();
}

void APVZ_USFX_LAB02Projectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
