// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Move_Floor.generated.h"

UCLASS()
class SET_API AMove_Floor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMove_Floor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Floor")
		USceneComponent* Root;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Floor")
		UStaticMeshComponent* Move_Floor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Floor")
		float Max_Move_x;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Floor")
		float Max_Move_y;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Floor")
		float Max_Move_z;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Floor")
		float Move_Speed;

	float Distance_x;
	float Distance_y;
	float Distance_z;

	bool IsPlus_x;
	bool IsPlus_y;
	bool IsPlus_z;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
