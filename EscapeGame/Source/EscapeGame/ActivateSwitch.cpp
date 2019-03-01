// Fill out your copyright notice in the Description page of Project Settings.

#include "ActivateSwitch.h"
#include "Runtime/Engine/Classes/Engine/TriggerVolume.h"
#include "GameFramework/Actor.h"
#include "Engine/SpotLight.h"

// Sets default values for this component's properties
UActivateSwitch::UActivateSwitch()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UActivateSwitch::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UActivateSwitch::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	SetLightWhenTriggered();
}

void UActivateSwitch::SetLightWhenTriggered()
{
	if (!Switch) 
	{
		UE_LOG(LogTemp, Error, TEXT("%s has no attached trigger volume"), *GetOwner()->GetName());
		return; 
	}

	if (!ActorThatTriggers)
	{
		UE_LOG(LogTemp, Error, TEXT("%s has no actor that will trigger it"), *GetOwner()->GetName());
		return;
	}

	if (Switch->IsOverlappingActor(ActorThatTriggers))
	{
		for (auto Light : LightArray)
		{
			Light->SetBrightness(0.f);
		}
	}
}

