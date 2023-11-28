// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "State.h"
#include "Pesado.generated.h"
UCLASS()
class PVZ_USFX_LAB02_API APesado : public AActor, public IState
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APesado();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	class AZombieComun* Zombie_Comun;
	virtual void Liviano_St() override;
	virtual void Pesado_St() override;
	virtual FString ToString() override;
	virtual void DefinirZombie_Estados(class AZombieComun* _Zombie_Comun) override;
};
