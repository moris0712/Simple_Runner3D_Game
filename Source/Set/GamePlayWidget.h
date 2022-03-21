// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GamePlayWidget.generated.h"

/**
 * 
 */
UCLASS()
class SET_API UGamePlayWidget : public UUserWidget
{
	GENERATED_BODY()
	
	UGamePlayWidget(const FObjectInitializer& ObjectInitializer);

public:

	UFUNCTION()
		void Update_Hp(int num);

	UFUNCTION()
		void Update_Score(int num);

	UFUNCTION()
		void Update_Max_Hp(int num);

	UFUNCTION()
		int Get_Score();

	UFUNCTION()
		int Get_Hp();

	UFUNCTION()
		int Get_Max_Hp();


protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	FString Text;
	
	FTimerHandle CountdownTimerHandle;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
		int Score;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
		int Hp;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
		int Max_Hp;


};
