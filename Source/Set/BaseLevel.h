// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseLevel.generated.h"

class UBoxComponent;

UCLASS()
class SET_API ABaseLevel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseLevel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "My Triggers")
		UBoxComponent* Create_Trigger;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "My Triggers")
		UBoxComponent* Destroy_Trigger;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "My Triggers")
		UBoxComponent* SpawnLocation;

	UBoxComponent* Get_Create_Trigger();
	UBoxComponent* Get_Destory_Trigger();
	UBoxComponent* Get_SpawnLocation();



};
