// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EstrategiaMovimiento.h"
#include "EstrategiaMovimientoNormal.generated.h"

class Zombie;

UCLASS()
class PVZ_USFX_LAB02_API AEstrategiaMovimientoNormal : public AActor, public IEstrategiaMovimiento
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstrategiaMovimientoNormal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	AZombie* d;
	virtual void moverseA(AZombie* _zombieActual, FVector _ubicacionDestino) override;
};
