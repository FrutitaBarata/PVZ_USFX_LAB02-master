// Fill out your copyright notice in the Description page of Project Settings.


#include "Lanzaguisantes.h"

ALanzaguisantes::ALanzaguisantes()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlantMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	PlantMeshComponent->SetStaticMesh(PlantMesh.Object);

	Tags.Add(TEXT("Lanzaguisantes"));
}

void ALanzaguisantes::BeginPlay()
{
	Super::BeginPlay();
}

void ALanzaguisantes::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FireShot(FVector(0.0f, 1.0f, 0.0f));
}
