// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Engine/TriggerVolume.h"
#include "Switch.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSwitchDoorEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEGAME_API USwitch : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USwitch();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
	FSwitchDoorEvent OnOpen;

private:
	UPROPERTY(EditAnywhere)
	TArray<ATriggerVolume*> SwitchArray;
	// Idea is to check if the trigger volume has been triggered, once all three have been triggered once the door will open
	
	UPROPERTY(EditAnywhere)
	AActor* TriggerActor = nullptr; //actor object used to throw at switches

	bool bIsAllSwitchTriggered();
};
