// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Scale_Floor.generated.h"

UCLASS()
class SET_API AScale_Floor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScale_Floor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Floor")
		USceneComponent* Root;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Floor")
		UStaticMeshComponent* Scale_Floor;

	//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Floor")
	//	UBoxComponent* Collision_Box;

	float Height;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Floor")
		float Mim_Size;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Floor")
		float Max_Size;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Floor")
		float Grow_Speed;

	bool IsGrowing;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
