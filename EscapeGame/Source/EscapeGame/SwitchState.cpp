// Fill out your copyright notice in the Description page of Project Settings.


#include "SwitchState.h"
#include "Runtime/Engine/Classes/Engine/TriggerBox.h"

// Sets default values for this component's properties
USwitchState::USwitchState()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called every frame
void USwitchState::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	ATriggerBox* TriggerVolume = Cast<ATriggerBox>(GetOwner());
	IsVolumeTriggered(TriggerVolume);
}

void USwitchState::IsVolumeTriggered(ATriggerBox* TriggerVolume)
{

	FString IsTriggeredValue = bIsTriggered ? "True" : "False";

	UE_LOG(LogTemp, Warning, TEXT("%s SwitchState Component is %s"), *GetOwner()->GetName(), *IsTriggeredValue)

	if (!ActorThatTriggers) { return; }
	if (bIsTriggered) { return; }

	if (TriggerVolume->IsOverlappingActor(ActorThatTriggers))
	{
		bIsTriggered = true;
	}

	
}
