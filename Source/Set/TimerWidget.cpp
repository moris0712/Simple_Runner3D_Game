// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerWidget.h"

UTimerWidget::UTimerWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	TimerCount = 3;
	//if (GetWorld() != nullptr)
	//	GetWorld()->GetTimerManager().SetTimer(CountdownTimerHandle, this,
	//		&UTimerWidget::Start_Timer, 1.0f, true);
}


void UTimerWidget::Start_Timer()
{
	if (TimerCount < 1)
	{
		GetWorld()->GetTimerManager().ClearTimer(CountdownTimerHandle);
	}
	--TimerCount;

	GetWorld()->GetTimerManager().SetTimer(CountdownTimerHandle, this,
		&UTimerWidget::Start_Timer, 1.0f, true);
	

}