// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Publicador.h"
#include "Estados.generated.h"

/**
 * 
 */
UCLASS()
class PVZ_USFX_LAB02_API AEstados : public APublicador
{
	GENERATED_BODY()
	
private:
	
	FString Estado;
public:
	
	void EstadoCambiado();
	
	void DefinirEstado(FString myEstado);
	
	FORCEINLINE FString GetEstadoO() { return Estado; };



};
