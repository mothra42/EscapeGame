// Fill out your copyright notice in the Description page of Project Settings.

#include "Switch.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "GameFramework//PlayerController.h"
#include "Components/PrimitiveComponent.h"
#include "Runtime/Engine/Classes/Engine/TriggerBox.h"
#include "SwitchState.h"

// Sets default values for this component's properties
USwitch::USwitch()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called every frame
void USwitch::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Poll the Trigger Volume
	if (bIsAllSwitchTriggered())
	{
		UE_LOG(LogTemp, Warning, TEXT("Broadcasting Open Door"))
		OnOpen.Broadcast();
	}
}

bool USwitch::bIsAllSwitchTriggered()
{
	for (auto* TriggerVolume : SwitchArray)
	{
		
		if (!TriggerVolume) { return false; }

		USwitchState* SwitchState = TriggerVolume->FindComponentByClass<USwitchState>();
		if (!SwitchState->bIsTriggered)
		{
			return false;
		}
	}
	return true;
}