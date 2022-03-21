// Fill out your copyright notice in the Description page of Project Settings.

#include "Scale_Floor.h"

// Sets default values
AScale_Floor::AScale_Floor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = Root;

	Scale_Floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Scale_Floor"));
	Scale_Floor->AttachTo(RootComponent);


	//Collision_Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision_Box"));
	//Collision_Box->AttachTo(RootComponent);

	Max_Size = 2.0f;    // 최대크기
	Mim_Size = 1.0f;    // 최소크기
	Grow_Speed = 0.7f;  // 성장?속도

}

// Called when the game starts or when spawned
void AScale_Floor::BeginPlay()
{
	Super::BeginPlay();
	
	IsGrowing = false;
	Height = Scale_Floor->GetComponentScale().Z;
}

// Called every frame
void AScale_Floor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float CurrentScale = Scale_Floor->GetComponentScale().X;

	if (CurrentScale == Mim_Size)
	{
		IsGrowing = true;
	}
	else if (CurrentScale == Max_Size)
	{
		IsGrowing = false;
	}

	if (IsGrowing)
	{
		CurrentScale += DeltaTime * Grow_Speed;
	}
	else
	{
		CurrentScale -= DeltaTime * Grow_Speed;
	}
	CurrentScale = FMath::Clamp(CurrentScale, Mim_Size, Max_Size);
	Scale_Floor->SetWorldScale3D(FVector(CurrentScale, CurrentScale, Height));
}

