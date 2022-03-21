// Fill out your copyright notice in the Description page of Project Settings.


#include "WallSpike.h"
#include "BaseLevel.h"

AWallSpike::AWallSpike()
{

	PrimaryActorTick.bCanEverTick = true; 
	PrimaryActorTick.bStartWithTickEnabled = false;



}

void AWallSpike::BeginPlay()
{
	Super::BeginPlay();

	this->GetRootComponent()->ComponentVelocity = FVector(0, 0, 0);

}

void AWallSpike::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetActorLocation(GetActorLocation() + FVector(350 * DeltaTime, 0, 0), true); // x축으로 벽 이동

}

