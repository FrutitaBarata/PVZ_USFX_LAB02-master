// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Suscriptor.h"
#include "Cambios.h"
#include "CoreMinimal.h"
#include "Zombie.h"
#include "ZombieComun.generated.h"
class IState;
class APlant;
class AEstados;
UCLASS()
class PVZ_USFX_LAB02_API AZombieComun : public AZombie, public ISuscriptor, public ICambios
{
	GENERATED_BODY()
	
public:
	AZombieComun();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public: 
	//-------------------------------------------------------------
	//Observer
	AEstados* estado;
	void DefinirNotificarPlantas(AEstados* myNotificarPlantas);
	void Notificar_A(AActor* Publicador) override;
	void Cambios() override;
	//-------------------------------------------------------------
	//State
	IState* Liviano;
	IState* Pesado;
	IState* EstadoActual;
	void Iniciar();
	void Liviano_St();
	void Pesado_St();
	IState* GetEstadoActual();
	IState* GetLiviano();
	IState* GetPesado();
	FString GetEstadoActual_ToString();
	void DefinirEstado(IState* _State);
	void VerificarHealth();

	
};
