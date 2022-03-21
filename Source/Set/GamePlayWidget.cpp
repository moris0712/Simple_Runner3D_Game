// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlayWidget.h"

UGamePlayWidget::UGamePlayWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Score = 0;
	Text = FString(TEXT("Score: ") + FString::FromInt(Score));
}

void UGamePlayWidget::Update_Score(int num)
{
	Score += num;
	Text = FString(TEXT("Score: ") + FString::FromInt(Score));
}

void UGamePlayWidget::Update_Hp(int num)
{
	Hp += num;
}

void UGamePlayWidget::Update_Max_Hp(int num)
{
	Max_Hp += num;
}

int UGamePlayWidget::Get_Hp()
{
	return Hp;
}

int UGamePlayWidget::Get_Max_Hp()
{
	return Max_Hp;
}

int UGamePlayWidget::Get_Score()
{
	return Score;
}