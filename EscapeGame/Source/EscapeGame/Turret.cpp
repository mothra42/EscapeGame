// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret.h"

void UTurret::Rotate(float RelativeSpeed)
{
	//use the yaw to turn the turret
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0, 1.0);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, Rotation, 0));
}