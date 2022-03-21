// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseLevel.h"

#include "Components/BoxComponent.h"

// Sets default values
ABaseLevel::ABaseLevel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;  // 틱함수꺼놓음

}

// Called when the game starts or when spawned
void ABaseLevel::BeginPlay()
{
	Super::BeginPlay();

	if (Create_Trigger != nullptr)
		Create_Trigger->bHiddenInGame = true; // 가시성 비활성화

	if (Destroy_Trigger != nullptr)
		Destroy_Trigger->bHiddenInGame = true; // 가시성 비활성화
	
}

// Called every frame
void ABaseLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UBoxComponent* ABaseLevel::Get_Create_Trigger()
{
	return Create_Trigger;
}

UBoxComponent* ABaseLevel::Get_Destory_Trigger()
{
	return Destroy_Trigger;
}

UBoxComponent* ABaseLevel::Get_SpawnLocation()
{
	return SpawnLocation;
}

