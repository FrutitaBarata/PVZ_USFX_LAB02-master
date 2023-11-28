																										
// Fill out your copyright notice in the Description page of Project Settings.


#include "EstrategiaMovimientoSaltar.h"
#include "Zombie.h"
#include "Plant.h"
#include <Kismet/GameplayStatics.h>
// Sets default values
AEstrategiaMovimientoSaltar::AEstrategiaMovimientoSaltar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstrategiaMovimientoSaltar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstrategiaMovimientoSaltar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstrategiaMovimientoSaltar::moverseA(AZombie* _zombieActual, FVector _ubicacionDestino)
{
	
    AZombie* Zombie;
    Zombie = _zombieActual;
    Zombie->MovementSpeed = 1000.0f;
    TArray<AActor*> Plantas;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlant::StaticClass(), Plantas);

    for (int32 i = 0; i < Plantas.Num(); i++)
    {
        // comparar la posicion x de la Planta con la del zombie
        if (FMath::IsNearlyEqual(Plantas[i]->GetActorLocation().X, Zombie->GetActorLocation().X, 0.1f))
        {
            // guardar la ubicacion inicial del zombie y la distancia inicial y no entrar más al if
            if (Zombie->DistanciaInicial == 0.0f)
            {
                Zombie->UbicacionInicial = Zombie->GetActorLocation();
                Zombie->DistanciaInicial = FVector::Dist(Zombie->UbicacionInicial, Plantas[i]->GetActorLocation());
            }

            // si la posicion x de la planta es igual a la del zombie, entonces la planta es el objetivo
            float AlturaSaltoInicial = Zombie->AlturaSalto; // Almacena la altura de salto inicial

            Zombie->LocalizacionObjetivo = Plantas[i]->GetActorLocation() + FVector(0.0f, 0.0f, Zombie->AlturaSalto);

            // Calcula la distancia recorrida en el salto
            float DistanciaRecorrida = FVector::Dist(Zombie->UbicacionInicial, Zombie->GetActorLocation());

            // Ajusta la altura del objetivo en función de la velocidad y la proporción recorrida

            Zombie->AlturaSalto = FMath::Max(AlturaSaltoInicial * (1.0f - DistanciaRecorrida / Zombie->DistanciaInicial) * Zombie->MovementSpeed / 200.0f, 0.0f);

            // calcula la direccion y distancia al objetivo
            Zombie->Direccion = (Zombie->LocalizacionObjetivo - Zombie->GetActorLocation()).GetSafeNormal();
            // calcula la distancia al objetivo
            Zombie->DistanciaAlObjetivo = FVector::Dist(Zombie->LocalizacionObjetivo, Zombie->GetActorLocation());

            float DeltaMove = _zombieActual->MovementSpeed * GetWorld()->DeltaTimeSeconds;

            if (DeltaMove > Zombie->DistanciaAlObjetivo)
            {
                // Si el desplazamiento excede la distancia al objetivo, mueve directamente al objetivo
                _zombieActual->SetActorLocation(_ubicacionDestino);

            }
            else
            {
                // Mueve el objeto en la direcci�n calculada
                _zombieActual->AddActorWorldOffset(Zombie->Direccion * DeltaMove);
            }
    
        }
    }
    Plantas.Empty();
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Zombie estrategia saltar"));
}

