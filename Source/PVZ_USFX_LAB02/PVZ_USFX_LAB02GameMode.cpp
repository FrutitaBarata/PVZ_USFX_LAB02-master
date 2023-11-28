// Copyright Epic Games, Inc. All Rights Reserved.

#include "PVZ_USFX_LAB02GameMode.h"
#include "PVZ_USFX_LAB02Pawn.h"
#include "Zombie.h"
#include "Plant.h"

#include <Kismet/GameplayStatics.h>
#include "TimerManager.h"
#include "ZombieComun.h"
#include "ZombieCono.h"
#include "ZombieCubo.h"
#include "ZombieSenal.h"
#include "Lanzaguisantes.h"
#include "Repetidora.h"
#include "Girasol.h"
#include "Nuez.h"
#include "Estados.h"
#include "Hongo.h"
#include "EstrategiaMovimientoSaltar.h"
#include "State.h"


APVZ_USFX_LAB02GameMode::APVZ_USFX_LAB02GameMode()
{
	
	PrimaryActorTick.bCanEverTick = true;
	RangoAtaque = 1100.0f;
	/*ZombieComun = CreateDefaultSubobject<AZombieComun>(TEXT("ZombieComun"));*/
}


void APVZ_USFX_LAB02GameMode::BeginPlay()
{
	Super::BeginPlay();
	EstadosO = GetWorld()->SpawnActor<AEstados>(AEstados::StaticClass(), FVector(0, 0, 0), FRotator::ZeroRotator);

	float initialPositionX = -1500.0f;
	float initialPositionY = 1200.0f;

	for (int32 i = 0; i < 5; ++i)
	{
		AZombieComun* NewZombieComun = SpawnZombieComun(FVector(initialPositionX + i * 150.0f, initialPositionY, 200.0f));

		if (NewZombieComun)
		{
			NewZombieComun->SetSpawnAfter(FMath::RandRange(1, 10));
			NewZombieComun->SetActorHiddenInGame(false);
			NewZombieComun->SetActorEnableCollision(true);     // Habilita las colisiones si es necesario
			NewZombieComun->SetCanMove(true);
			ArrayZombies.Add(NewZombieComun);
			NewZombieComun->DefinirNotificarPlantas(EstadosO);
		}
	}

	

	initialPositionX = -1500.0f;
	initialPositionY = 100.0f;
	for (int i = 0; i < 5; i++)
	{
		ALanzaguisantes* NewLanzaguisantes = SpawnPlantLanzaguisantes(FVector(initialPositionX + i * 150.0f, initialPositionY, 200.0f));

		/*if (NewLanzaguisantes)*/
		NewLanzaguisantes->PlantMeshComponent->SetSimulatePhysics(false);
			/*NewLanzaguisantes->SetActorEnableCollision(true); */    // Habilita las colisiones si es necesario
			aPlantas.Add(NewLanzaguisantes);
		


		/*for (int j = 0; j < 2; j++) {
			APlant* NewLanzaguizantes = SpawnPlant(FVector(initialPositionX + i * 150.0f, initialPositionY + j * 350.0f, 200.0f));
			aPlantas.Add(NewLanzaguizantes);
		}*/
	} 

	

}

void APVZ_USFX_LAB02GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	for (AZombieComun* ZombieComun : ArrayZombies) {
		ZombieComunInstancia = ZombieComun;
		if (ZombieComunInstancia)
		{
			if (ZombieComunInstancia->GetEstadoActual())
			{
				FString EstadoActualString = ZombieComunInstancia->GetEstadoActual()->ToString();

				EstadosO->DefinirEstado(EstadoActualString);
			}
			
		}
		
	}

}


void APVZ_USFX_LAB02GameMode::VisualizarPotenciadores() {
	
}

void APVZ_USFX_LAB02GameMode::VisualizarTarjetasPlantas() {
	
}



AZombieComun* APVZ_USFX_LAB02GameMode::SpawnZombieComun(FVector _spawnPosition)
{
	FTransform SpawnLocation;
	SpawnLocation.SetLocation(_spawnPosition);
	return GetWorld()->SpawnActor<AZombieComun>(AZombieComun::StaticClass(), SpawnLocation);
}

AZombieCono* APVZ_USFX_LAB02GameMode::SpawnZombieCono(FVector _spawnPosition)
{
	FTransform SpawnLocation;
	SpawnLocation.SetLocation(_spawnPosition);
	return GetWorld()->SpawnActor<AZombieCono>(AZombieCono::StaticClass(), SpawnLocation);
}

AZombieCubo* APVZ_USFX_LAB02GameMode::SpawnZombieCubo(FVector _spawnPosition)
{
	FTransform SpawnLocation;
	SpawnLocation.SetLocation(_spawnPosition);
	return GetWorld()->SpawnActor<AZombieCubo>(AZombieCubo::StaticClass(), SpawnLocation);
}

AZombieSenal* APVZ_USFX_LAB02GameMode::SpawnZombieSenal(FVector _spawnPosition)
{
	FTransform SpawnLocation;
	SpawnLocation.SetLocation(_spawnPosition);
	return GetWorld()->SpawnActor<AZombieSenal>(AZombieSenal::StaticClass(), SpawnLocation);
}

APlant* APVZ_USFX_LAB02GameMode::SpawnPlant(FVector _spawnPosition)
{
	FTransform SpawnLocation;
	SpawnLocation.SetLocation(_spawnPosition);
	return GetWorld()->SpawnActor<APlant>(APlant::StaticClass(), SpawnLocation);
}


ALanzaguisantes* APVZ_USFX_LAB02GameMode::SpawnPlantLanzaguisantes(FVector _spawnPosition)
{
	FTransform SpawnLocation;
	SpawnLocation.SetLocation(_spawnPosition);
	return GetWorld()->SpawnActor<ALanzaguisantes>(ALanzaguisantes::StaticClass(), SpawnLocation);

}

void APVZ_USFX_LAB02GameMode::TimerCallBackPotenciadoresAgua()
{
	MapPotenciadores[TEXT("Agua")] += 1;
}

void APVZ_USFX_LAB02GameMode::TimerCallBackTarjetasPlantaNuez()
{
	MapTarjetasPlantas[TEXT("Nuez")] += 1;
}
