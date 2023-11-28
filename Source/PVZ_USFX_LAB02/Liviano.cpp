// Fill out your copyright notice in the Description page of Project Settings.


#include "Liviano.h"
#include "ZombieComun.h"

// Sets default values
ALiviano::ALiviano()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALiviano::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALiviano::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALiviano::Liviano_St()
{
	
	Zombie_Comun->ZombieMeshComponent->SetRelativeScale3D(FVector(0.5f, 0.5f, 1.0f));
	/*GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%i"), Zombie_Comun->Health));*/
	
}

void ALiviano::Pesado_St()
{
}

FString ALiviano::ToString()
{
	return "Liviano";
}

void ALiviano::DefinirZombie_Estados(AZombieComun* _Zombie_Comun)
{
	Zombie_Comun = _Zombie_Comun;
	
}

