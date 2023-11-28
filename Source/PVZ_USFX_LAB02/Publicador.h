// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Publicador.generated.h"

UCLASS()
class PVZ_USFX_LAB02_API APublicador : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APublicador();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY()
	TArray<AActor*> Suscriptores = TArray<AActor*>();
public:
	virtual void Suscribirse(AActor* Suscriptor);
	virtual void Desuscribirse(AActor* SuscriptorAQuitar);
	virtual void NotificarSuscriptores();
};
