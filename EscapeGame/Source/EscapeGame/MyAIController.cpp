// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"

void AMyAIController::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);

	auto ControlledTank = GetPawn();
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!ControlledTank && !PlayerPawn) { return; }
}
