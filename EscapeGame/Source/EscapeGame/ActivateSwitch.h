// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActivateSwitch.generated.h"


class ATriggerBox;
class ASpotLight;
class AActor;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEGAME_API UActivateSwitch : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActivateSwitch();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
	ATriggerBox* Switch = nullptr;
	
	UPROPERTY(EditAnywhere)
	TArray<ASpotLight*> LightArray;

	UPROPERTY(EditAnywhere)
	AActor* ActorThatTriggers = nullptr;

	void SetLightWhenTriggered();
};
