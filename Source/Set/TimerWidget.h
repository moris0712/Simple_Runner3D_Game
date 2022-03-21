// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TimerWidget.generated.h"

/**
 * 
 */
UCLASS()
class SET_API UTimerWidget : public UUserWidget
{
	GENERATED_BODY()

	
public:
	UTimerWidget(const FObjectInitializer &ObjectInitializer);

	UFUNCTION(BlueprintCallable)
		void Start_Timer();

protected:
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(BindWidget))
		int TimerCount;

	FTimerHandle CountdownTimerHandle;

};
