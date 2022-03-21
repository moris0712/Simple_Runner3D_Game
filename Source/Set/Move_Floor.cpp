// Fill out your copyright notice in the Description page of Project Settings.


#include "Move_Floor.h"

// Sets default values
AMove_Floor::AMove_Floor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = Root;

	Move_Floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Scale_Floor"));
	Move_Floor->AttachTo(RootComponent);

	Max_Move_x = 300.0f;
	Max_Move_y = 300.0f;
	Max_Move_z = 300.0f;
	Move_Speed = 200.0f;
}

// Called when the game starts or when spawned
void AMove_Floor::BeginPlay()
{
	Super::BeginPlay();

	Distance_x = 0;
	Distance_y = 0;
	Distance_z = 0;

	IsPlus_x = true;
	IsPlus_y = true;
	IsPlus_z = true;
}

// Called every frame
void AMove_Floor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float CL_X = Move_Floor->GetComponentLocation().X;
	float CL_Y = Move_Floor->GetComponentLocation().Y;
	float CL_Z = Move_Floor->GetComponentLocation().Z;

	//UE_LOG(LogTemp, Log, TEXT("x: %f  %f  %f"), CL_X, CL_Y, CL_Z );


	if (Max_Move_x != 0)
	{
		if (IsPlus_x)
		{
			CL_X += DeltaTime * Move_Speed;
			Distance_x += DeltaTime * Move_Speed;
		}
		else
		{
			CL_X -= DeltaTime * Move_Speed;
			Distance_x -= DeltaTime * Move_Speed;
		}

		if (Distance_x >= Max_Move_x)
			IsPlus_x = false;

		if (Distance_x <= 0)
			IsPlus_x = true;
	}
	if (Max_Move_y != 0)
	{
		if (IsPlus_y)
		{
			CL_Y += DeltaTime * Move_Speed;
			Distance_y += DeltaTime * Move_Speed;
		}
		else
		{
			CL_Y -= DeltaTime * Move_Speed;
			Distance_y -= DeltaTime * Move_Speed;
		}

		if (Distance_y >= Max_Move_y)
			IsPlus_y = false;

		if (Distance_y <= 0)
			IsPlus_y = true;
	}
	if (Max_Move_z != 0)
	{
		if (IsPlus_z)
		{
			CL_Z += DeltaTime * Move_Speed;
			Distance_z += DeltaTime * Move_Speed;
		}
		else
		{
			CL_Z -= DeltaTime * Move_Speed;
			Distance_z -= DeltaTime * Move_Speed;
		}

		if (Distance_z >= Max_Move_z)
			IsPlus_z = false;

		if (Distance_z <= 0)
			IsPlus_z = true;
	}
	Move_Floor->SetWorldLocation(FVector(CL_X, CL_Y, CL_Z));
}

