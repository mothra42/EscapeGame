// Fill out your copyright notice in the Description page of Project Settings.

#include "ActivateSwitch.h"
#include "Runtime/Engine/Classes/Engine/TriggerVolume.h"
#include "GameFramework/Actor.h"
#include "Engine/SpotLight.h"

// Sets default values for this component's properties
UActivateSwitch::UActivateSwitch()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called every frame
void UActivateSwitch::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	SetLightWhenTriggered();
}

void UActivateSwitch::SetLightWhenTriggered()
{
	if (!Switch) { return; }

	if (!ActorThatTriggers) { return; }

	if (Switch->IsOverlappingActor(ActorThatTriggers))
	{
		for (auto Light : LightArray)
		{
			Light->SetBrightness(0.f);
		}

		Switch->Destroy();
	}
}

