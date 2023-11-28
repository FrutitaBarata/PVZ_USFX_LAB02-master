// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EstrategiaMovimiento.h"
#include "EstrategiaMovimientoSaltar.generated.h"
class AZombie;
class APlant;
UCLASS()
class PVZ_USFX_LAB02_API AEstrategiaMovimientoSaltar : public AActor, public IEstrategiaMovimiento
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstrategiaMovimientoSaltar();

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void moverseA(AZombie* _zombieActual, FVector _ubicacionDestino) override;

};
