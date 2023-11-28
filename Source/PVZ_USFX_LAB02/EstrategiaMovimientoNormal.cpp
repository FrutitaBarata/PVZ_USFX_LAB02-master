// Fill out your copyright notice in the Description page of Project Settings.


#include "EstrategiaMovimientoNormal.h"
#include "Zombie.h"

// Sets default values
AEstrategiaMovimientoNormal::AEstrategiaMovimientoNormal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstrategiaMovimientoNormal::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstrategiaMovimientoNormal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstrategiaMovimientoNormal::moverseA(AZombie* _zombieActual, FVector _ubicacionDestino)
{

	UE_LOG(LogTemp, Warning, TEXT("Dentro de MoverseA"));
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Dentro de moverseA"));


	FVector Direction = _ubicacionDestino - FVector(-800.0f, 400.0f, 160.0f);
	float DistanceToTarget = FVector::Dist(_ubicacionDestino, FVector(-800.0f, 400.0f, 160.0f));

	// Calcula el desplazamiento en este frame
	float DeltaMove = _zombieActual->MovementSpeed * GetWorld()->DeltaTimeSeconds;

	if (DeltaMove > DistanceToTarget)
	{
		// Si el desplazamiento excede la distancia al objetivo, mueve directamente al objetivo
		_zombieActual->SetActorLocation(_ubicacionDestino);

	}
	else
	{
		// Mueve el objeto en la direcci�n calculada
		_zombieActual->AddActorWorldOffset(Direction * DeltaMove);
	}
}

