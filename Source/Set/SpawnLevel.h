// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"



#include "SpawnLevel.generated.h"

class ABaseLevel;

UCLASS()
class SET_API ASpawnLevel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnLevel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void SpawnLevel(bool IsFirst);

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
			AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& SweepResult);

protected:

	APawn* Player;

	UPROPERTY(EditAnywhere, Category = "A Level")
		TSubclassOf<ABaseLevel> LevelA1;

	UPROPERTY(EditAnywhere, Category = "A Level")
		TSubclassOf<ABaseLevel> LevelA2;

	UPROPERTY(EditAnywhere, Category = "A Level")
		TSubclassOf<ABaseLevel> LevelA3;

	UPROPERTY(EditAnywhere, Category = "A Level")
		TSubclassOf<ABaseLevel> LevelA4;

	UPROPERTY(EditAnywhere, Category = "A Level")
		TSubclassOf<ABaseLevel> LevelA5;

	UPROPERTY(EditAnywhere, Category = "B Level")
		TSubclassOf<ABaseLevel> LevelB1;

	UPROPERTY(EditAnywhere, Category = "B Level")
		TSubclassOf<ABaseLevel> LevelB2;

	UPROPERTY(EditAnywhere, Category = "B Level")
		TSubclassOf<ABaseLevel> LevelB3;

	UPROPERTY(EditAnywhere, Category = "B Level")
		TSubclassOf<ABaseLevel> LevelB4;

	//UPROPERTY(EditAnywhere, Category = "C Level")
	//	TSubclassOf<ABaseLevel> LevelC1;

	//UPROPERTY(EditAnywhere, Category = "C Level")
	//	TSubclassOf<ABaseLevel> LevelC2;


	TArray<ABaseLevel*> LevelList;

public:

	int RandomLevel;

	FVector SpawnLocation = FVector();
	FRotator SpawnRotation = FRotator();
	FActorSpawnParameters SpawnInfo = FActorSpawnParameters();
};
