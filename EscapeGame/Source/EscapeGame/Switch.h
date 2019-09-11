// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Switch.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSwitchDoorEvent);

class ATriggerBox;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEGAME_API USwitch : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USwitch();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
	FSwitchDoorEvent OnOpen;

private:
	UPROPERTY(EditAnywhere)
	TArray<ATriggerBox*> SwitchArray;

	bool bIsAllSwitchTriggered();
};
