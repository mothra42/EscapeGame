// Fill out your copyright notice in the Description page of Project Settings.

#include "Switch.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "GameFramework//PlayerController.h"
#include "Components/PrimitiveComponent.h"

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
		UE_LOG(LogTemp, Warning, TEXT("All Switches Are Triggered!"));
		OnOpen.Broadcast();
	}
}

bool USwitch::bIsAllSwitchTriggered()
{
	if (SwitchArray.Num() == 0) { return true; }
	for (auto* TriggerVolume : SwitchArray)
	{
		if (!TriggerVolume) { return false; }

		if (TriggerVolume->IsOverlappingActor(TriggerActor))
		{
			UE_LOG(LogTemp, Warning, TEXT("The Rock is overlapping %s"), *TriggerVolume->GetName());
			SwitchArray.Remove(TriggerVolume); //This seems like a bad way to do it, but it also works.
		}
	}

	return false;
}