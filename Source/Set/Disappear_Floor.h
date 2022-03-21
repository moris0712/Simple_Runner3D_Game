// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Disappear_Floor.generated.h"

UCLASS()
class SET_API ADisappear_Floor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADisappear_Floor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Floor")
		USceneComponent* Root;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Floor")
		UStaticMeshComponent* Disappear_Floor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Floor")
		UBoxComponent* Collision_Box;

	UFUNCTION()
		void Destroy_Floor();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Floor")
		float Disappear_Time;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
			AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
