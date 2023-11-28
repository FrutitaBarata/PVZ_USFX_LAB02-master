// Fill out your copyright notice in the Description page of Project Settings.


#include "Pesado.h"
#include "ZombieComun.h"

// Sets default values
APesado::APesado()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APesado::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APesado::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APesado::Liviano_St()
{
}

void APesado::Pesado_St()
{
	
	Zombie_Comun->ZombieMeshComponent->SetRelativeScale3D(FVector(2.0f, 2.0f, 3.0f));
		/*GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Accion pesada")));*/
}

FString APesado::ToString()
{
	return "Pesado";
}

void APesado::DefinirZombie_Estados(AZombieComun* _Zombie_Comun)
{
	Zombie_Comun = _Zombie_Comun;
}

