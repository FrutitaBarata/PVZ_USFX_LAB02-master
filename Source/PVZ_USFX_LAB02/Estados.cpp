// Fill out your copyright notice in the Description page of Project Settings.


#include "Estados.h"

void AEstados::EstadoCambiado()
{
	NotificarSuscriptores();
}

void AEstados::DefinirEstado(FString myEstado)
{
	Estado = myEstado;
	EstadoCambiado();
}