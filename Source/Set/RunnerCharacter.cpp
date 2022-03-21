// Fill out your copyright notice in the Description page of Project Settings.


#include "RunnerCharacter.h"

#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Public/EngineUtils.h"
// Iterator과 Range클래스 사용

#include "Blueprint/UserWidget.h"

#include "Engine.h"


// Sets default values
ARunnerCharacter::ARunnerCharacter()
{
	Pc = Cast<APlayerController>(GetController());



 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);
	GetCapsuleComponent()->SetCollisionResponseToChannel 
	(ECC_GameTraceChannel1, ECR_Overlap);
	// 타겟 액터의 채널(클래스?)을 변경해 주는 역활??

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false; // 회전 부드럽게 하기위함

	SideViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Side View Camera"));
	SideViewCamera->bUsePawnControlRotation = false; // 카메라 회전 끄기

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
	// bOrientRotationToMovement 자동적으로 캐릭터의 이동방향을 움직이는 방향에 맞춰줌
	// RotationRate 캐릭터 회전하는 속도  Y값이 빠를수록 회전방향으로 빠르게 움직인다
	GetCharacterMovement()->bUseControllerDesiredRotation = true;

	Walk_Speed = 500.0f;   // 러너 속도 
	F_JumpHeight = 800.0f; // 일단 점프 높이
	S_JumpHeight = 800.0f; // 이단 점프 높이
	GetCharacterMovement()->GravityScale = 2.0f;
	GetCharacterMovement()->AirControl = 0.8f; // 공중에서 움직일수있게
	GetCharacterMovement()->JumpZVelocity = S_JumpHeight; // 점프 길이
	GetCharacterMovement()->GroundFriction = 3.0f;
	GetCharacterMovement()->MaxWalkSpeed = Walk_Speed;
	GetCharacterMovement()->MaxFlySpeed = 600.0f;
	
	OurCameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	OurCameraSpringArm->SetupAttachment((USceneComponent*)GetCapsuleComponent());
	OurCameraSpringArm->CameraLagSpeed = 3.0f;
	OurCameraSpringArm->bUsePawnControlRotation = true;

	SideViewCamera->SetupAttachment(OurCameraSpringArm, USpringArmComponent::SocketName);
	SideViewCamera->SetRelativeLocation(FVector(-100.0f, 0.0f, 150.0f));
	SideViewCamera->SetRelativeRotation(FRotator(-12.0f, 0.0f, 0.0f));


	Score_Per_Second = 50; // 초당 점수
	Set_Hp = 3;  // 설정할 Hp




}


// Called when the game starts or when spawned
void ARunnerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	GetCapsuleComponent()->OnComponentBeginOverlap.
		AddDynamic(this, &ARunnerCharacter::OnOverlapBegin);

	GetCapsuleComponent()->OnComponentEndOverlap.
		AddDynamic(this, &ARunnerCharacter::OnOverlapEnd);


	for (TActorIterator<ASpawnLevel> entity(GetWorld()); entity; ++entity)
	{
		SpawnLevel_Actor = *entity;
	}

	for (TActorIterator<AWallSpike> entity(GetWorld()); entity; ++entity)
	{
		Going_Wall = *entity;
	}

	if (IsValid(GamePlay_Widget))
	{
		GamePlay_Widget->Update_Max_Hp(Set_Hp);
		GamePlay_Widget->Update_Hp(Set_Hp);
	}
	AnimInstance = GetMesh()->GetAnimInstance();

	IsAttacked = false;
	IsJump = false;  // 점프 중인가
	CanMove = false;
}

// Called every frame
void ARunnerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	tempPos = GetActorLocation();
	
	if (tempPos.Z < -500)
		ARunnerCharacter::End_Game();
}


// 점프--------------------------------------------
void ARunnerCharacter::StartJump()
{
	if (CanMove) {
		IsJump = true;

		JumpCount++;

		UE_LOG(LogTemp, Log, TEXT("Character is Die :: %d"), JumpCount);


		if (JumpCount == 1)
		{
			ACharacter::LaunchCharacter(FVector(0, 0, F_JumpHeight), false, true);
		}
		else if (JumpCount == 2)
		{
			AnimInstance->Montage_Play(Anim);
			ACharacter::LaunchCharacter(FVector(0, 0, S_JumpHeight), false, true);
		}
	}
}

void ARunnerCharacter::StopJump()
{
	IsJump = false;
}

void ARunnerCharacter::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);

	JumpCount = 0;



}
// 점프---------------------------------------------


// Called to bind functionality to input
void ARunnerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ARunnerCharacter::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ARunnerCharacter::StopJump);

	PlayerInputComponent->BindAxis("MoveForward", this, &ARunnerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ARunnerCharacter::MoveRight);

}

void ARunnerCharacter::MoveRight(float value)
{
	if (CanMove)
	{
		AddMovementInput(FVector(0.0f, 1.0f, 0.0f), value);
	}
}

void ARunnerCharacter::MoveForward(float value)
{
	if (CanMove)
	{
		AddMovementInput(FVector(1.0f, 0.0f, 0.0f), value);
	}
}

void ARunnerCharacter::Add_Score(int num)
{
	GamePlay_Widget->Update_Score(num);
}


void ARunnerCharacter::Setting_Game()
{
	FTimerDelegate Delegate_func;

	FTimerHandle UnusedHandle;

	CanMove = true;
	SetActorTickEnabled(true);
	Going_Wall->SetActorTickEnabled(true);
	Timer_Widget->RemoveFromParent();

	Delegate_func.BindUFunction(this, FName("Add_Score"), Score_Per_Second);

	if (IsValid(GamePlay_Widget))
	{
		GamePlay_Widget->AddToViewport(); // 타이머 위젯 표시

		GetWorldTimerManager().SetTimer(UnusedHandle, 
			Delegate_func, 1.0f, true);
	}
}


void ARunnerCharacter::Start_Game(float timer) 
{

	FTimerHandle UnusedHandle;

	if (IsValid(Timer_Widget))
	{
		Timer_Widget->AddToViewport(); // 타이머 위젯 표시
	}
	Timer_Widget->Start_Timer();

	GetWorldTimerManager().SetTimer(UnusedHandle, this, 
		&ARunnerCharacter::Setting_Game, timer-1, false);
}

void ARunnerCharacter::End_Game()
{
	GetMesh()->Deactivate();
	GetMesh()->SetVisibility(false);
	SetActorTickEnabled(false);

	CanMove = false;
	Going_Wall->SetActorTickEnabled(false);

	if (IsValid(GamePlay_Widget))
	{
		GamePlay_Widget->RemoveFromParent();
	}


	if (IsValid(GameOver_Widget))
	{
		GameOver_Widget->AddToViewport(); // 게임오버 위젯 표시
	}

	UGameplayStatics::SetGamePaused(GetWorld(), true);
}

void ARunnerCharacter::RestartLevel()
{
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()));
	// 게임 다시 시작
}

int ARunnerCharacter::Get_Score()
{
	return GamePlay_Widget->Get_Score();
}



void ARunnerCharacter::Attacked()
{
	IsAttacked = false;
	GetWorldTimerManager().ClearTimer(Overlap_Timer);
}

void ARunnerCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, 
	AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != nullptr)
	{
		ASpike* WallSpike = Cast<AWallSpike>(OtherActor);
		ASpike* Spike = Cast<ASpike>(OtherActor);
		// 충돌한 물체가 다가오는 벽 이거나 함정일때

		AItem* Item = Cast<AItem>(OtherActor);
		// 아이템 

		if (WallSpike) 
		{
			ARunnerCharacter::End_Game();
			//ARunnerCharacter::RestartLevel();
		}

		else if (Spike)
		{
			if (!IsAttacked) {
				
				IsAttacked = true;
				GamePlay_Widget->Update_Hp(-1);

				if (GamePlay_Widget->Get_Hp() <= 0) {
					ARunnerCharacter::End_Game();
				}

				GetWorldTimerManager().SetTimer(Overlap_Timer, this,
					&ARunnerCharacter::Attacked, 2.0f, false);

			}
			
		}
		
		else if (Item)
		{
			Item->Active_Item(); // 아이템 효과
		}

		//else if (Item)
		//{

		//}
	}
}

void ARunnerCharacter::OnOverlapEnd(UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	//if (OtherActor != nullptr)
	//{
	//	ASpike* Spike = Cast<ASpike>(OtherActor);

	//	if (Spike)
	//	{
	//		
	//	}
	//}
}