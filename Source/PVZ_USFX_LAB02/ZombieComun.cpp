// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieComun.h"
#include "Estados.h"
#include "Plant.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Engine/StaticMesh.h"
#include "Engine/GameEngine.h"
#include "Liviano.h"
#include "Pesado.h"



AZombieComun::AZombieComun()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ZombieMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));
	ZombieMeshComponent->SetStaticMesh(ZombieMesh.Object);

	UPrimitiveComponent* CollisionComponent = CreateDefaultSubobject<UPrimitiveComponent>(TEXT("CollisionComponent"));
	SetRootComponent(CollisionComponent);


}

void AZombieComun::BeginPlay()
{
		Super::BeginPlay();
		//iniciando patron state
		Iniciar();
		
}

void AZombieComun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	
	//llamando a verificar health
	VerificarHealth();

	
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Patron Observer
void AZombieComun::DefinirNotificarPlantas(AEstados* myNotificarPlantas)
{
		estado = myNotificarPlantas;
		estado->Suscribirse(this);
}

void AZombieComun::Notificar_A(AActor* Publicador)
{
	Cambios();
}

void AZombieComun::Cambios()
{
	FString Estado = estado->GetEstadoO();
	if (!Estado.Compare("Liviano"))
	{
		MovementSpeed = 0.5f;
		
	}
	else if (!Estado.Compare("Pesado"))
	{
		MovementSpeed = 0.1f;
	
	}
	
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Patron State
void AZombieComun::Iniciar()
{
	Liviano = GetWorld()->SpawnActor<ALiviano>(ALiviano::StaticClass());
	Liviano->DefinirZombie_Estados(this);
	Pesado = GetWorld()->SpawnActor<APesado>(APesado::StaticClass());
	Pesado->DefinirZombie_Estados(this);
}

void AZombieComun::Liviano_St()
{
	EstadoActual->Liviano_St();
}

void AZombieComun::Pesado_St()
{
	EstadoActual->Pesado_St();
}

IState* AZombieComun::GetEstadoActual()
{
	return EstadoActual;
}

IState* AZombieComun::GetLiviano()
{
	return Liviano;
}

IState* AZombieComun::GetPesado()
{
	return Pesado;
}

FString AZombieComun::GetEstadoActual_ToString()
{
	return "Estado Actual de la Planta:" + EstadoActual->ToString();
}

void AZombieComun::DefinirEstado(IState* _State)
{
	EstadoActual = _State;
}

void AZombieComun::VerificarHealth()
{
	if (Health >= 50.0f)
	{
		
		DefinirEstado(Pesado);
		EstadoActual->Pesado_St();
		

	}
	else
	{
		DefinirEstado(Liviano);
		EstadoActual->Liviano_St();
	}
}




