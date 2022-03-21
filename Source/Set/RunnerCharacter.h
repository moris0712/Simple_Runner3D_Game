// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "SpawnLevel.h"
#include "WallSpike.h"
#include "TimerWidget.h"
#include "GamePlayWidget.h"
#include "Item.h"

#include "RunnerCharacter.generated.h"



UCLASS()
class SET_API ARunnerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARunnerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	//UPROPERTY(BlueprintReadWrite, EditAnywhere)
	//	class UBoxComponent* Box_Collision;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UCameraComponent* SideViewCamera;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class USpringArmComponent* OurCameraSpringArm;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;




protected:
	
	UFUNCTION()
		void MoveRight(float value);

	UFUNCTION()
		void MoveForward(float value);


		void StopJump();

		void StartJump();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int JumpCount;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool IsJump;


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float F_JumpHeight;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float S_JumpHeight;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Walk_Speed;

	UPROPERTY()
		UAnimInstance* AnimInstance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Double_Jump")
		UAnimMontage* Anim;


	virtual void Landed(const FHitResult& Hit) override;
	// 낙하 시 착지 시 호출되어 Hit결과에 따라 작업을 수행하는 함수

public:

	//class UCameraComponent* GetSideViewCameraComponent() 
	//{
	//	return SideViewCamera;
	//}

	UFUNCTION(BlueprintCallable)
		void RestartLevel();

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
			AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, 
			const FHitResult& SweepResult);

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp,
			AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);




	UFUNCTION(BlueprintCallable)
		void Start_Game(float timer);

	UFUNCTION(BlueprintCallable)
		void Setting_Game();

	UFUNCTION(BlueprintCallable)
		void End_Game();

	
protected:

	UPROPERTY(Instanced, BlueprintReadWrite, EditAnywhere, Category = "Widget")
	UUserWidget* GameOver_Widget;

	UPROPERTY(Instanced, BlueprintReadWrite, EditAnywhere, Category = "Widget")
		UTimerWidget* Timer_Widget;

	UPROPERTY(Instanced, BlueprintReadWrite, EditAnywhere, Category = "Widget")
		UGamePlayWidget* GamePlay_Widget;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		ASpawnLevel* SpawnLevel_Actor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		AWallSpike* Going_Wall;


	UPROPERTY()
	float Camera_distance;

	UFUNCTION()
		void Add_Score(int num);

	UFUNCTION(BlueprintCallable)
		int Get_Score();

	UPROPERTY()
		int Hp;

	UPROPERTY()
		int Max_Hp;

	UPROPERTY()
		int Set_Hp;

	UPROPERTY()
		int Score_Per_Second;

	UFUNCTION()
		void Attacked();

	UPROPERTY()
		bool IsAttacked;

	FTimerHandle Overlap_Timer;

	APlayerController* Pc;

private:

	float zPosition; // 카메라위치
	FVector tempPos = FVector();

	bool CanMove;
};
