// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spike.h"
#include "Components/BoxComponent.h"

#include "WallSpike.generated.h"

/**
 * 
 */
UCLASS()
class SET_API AWallSpike : public ASpike
{
	GENERATED_BODY()


public:

	AWallSpike();

	
protected:
	virtual void BeginPlay() override;


public:
	virtual void Tick(float DeltaTime) override;
	
};
