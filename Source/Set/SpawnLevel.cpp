// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnLevel.h"
#include "BaseLevel.h"

#include "RunnerCharacter.h"
#include "WallSpike.h"

#include "Components/BoxComponent.h"


// Sets default values
ASpawnLevel::ASpawnLevel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnLevel::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnLevel(true);
	//SpawnLevel(false);
	//SpawnLevel(false);
	//SpawnLevel(false);
	//SpawnLevel(false);
}

// Called every frame
void ASpawnLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnLevel::SpawnLevel(bool IsFirst)
{
	SpawnLocation = FVector(0.0f, 0.0f, 0.0f); 
	SpawnRotation = FRotator(0, 0, 0);   // x축 방향으로 놓여지게

	if (!IsFirst)
	{
		ABaseLevel* LastLevel = LevelList.Last();
		SpawnLocation = LastLevel->Get_SpawnLocation()->GetComponentTransform().GetTranslation();
	}
	else
	{
		SpawnLocation = FVector(500.0f, 0.0f, 0.0f); // 처음 생성만
	}

	RandomLevel = FMath::RandRange(1, 9);
	ABaseLevel* NewLevel = nullptr;

	if (RandomLevel == 1)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(LevelA1,
			SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (RandomLevel == 2)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(LevelA2,
			SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (RandomLevel == 3)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(LevelA3,
			SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (RandomLevel == 4)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(LevelA4,
			SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (RandomLevel == 5)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(LevelA5,
			SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (RandomLevel == 6)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(LevelB1,
			SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (RandomLevel == 7)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(LevelB2,
			SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (RandomLevel == 8)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(LevelB3,
			SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (RandomLevel == 9)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(LevelB4,
			SpawnLocation, SpawnRotation, SpawnInfo);
	}
	//else if (RandomLevel == 10)
	//{
	//	NewLevel = GetWorld()->SpawnActor<ABaseLevel>(LevelC1,
	//		SpawnLocation, SpawnRotation, SpawnInfo);
	//}
	//else if (RandomLevel == 11)
	//{
	//	NewLevel = GetWorld()->SpawnActor<ABaseLevel>(LevelC2,
	//		SpawnLocation, SpawnRotation, SpawnInfo);
	//}

	if (NewLevel)
	{
		if (NewLevel->Get_Create_Trigger())
		{
			NewLevel->Get_Create_Trigger()->OnComponentBeginOverlap.
				AddDynamic(this, &ASpawnLevel::OnOverlapBegin);
		}

		if (NewLevel->Get_Destory_Trigger())
		{
			NewLevel->Get_Destory_Trigger()->OnComponentBeginOverlap.
				AddDynamic(this, &ASpawnLevel::OnOverlapBegin);
		}
	}

	LevelList.Add(NewLevel);

	//UE_LOG(LogTemp, Log, TEXT("listcount :: %d"), LevelList.Num());
	//if (LevelList.Num() > 4)
	//{
	//	LevelList.RemoveAt(0);
	//}
}



void ASpawnLevel::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, 
	AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != nullptr)
	{
		AWallSpike* WallSpike = Cast<AWallSpike>(OtherActor);
		ARunnerCharacter* Pc = Cast<ARunnerCharacter>(OtherActor);

		if (Pc)
		{
			UBoxComponent* Trigger = Cast<UBoxComponent>(OverlappedComp);
			

			FString T_Name = FString(*Trigger->GetName());
			
			if (T_Name.Equals(FString(TEXT("Create Trigger Box"))))
			{
				UE_LOG(LogTemp, Log, TEXT("aaa: 레벨 생성"));
				SpawnLevel(false);
				UE_LOG(LogTemp, Log, TEXT("bbb: 생성 트리거 삭제")); // 돌아와서 다시 밟을수있으므로
				Trigger->DestroyComponent();
			}

		}
		else if (WallSpike)
		{
			//UBoxComponent* Trigger = Cast<UBoxComponent>(OverlappedComp);
			//ABaseLevel* BaseLevel = Cast<ABaseLevel>(Trigger->GetOwner());
			//UE_LOG(LogTemp, Log, TEXT("www : %s"), *BaseLevel->GetName());
			//BaseLevel->Destroy();

			UBoxComponent* Trigger = Cast<UBoxComponent>(OverlappedComp);
			FString T_Name = FString(*Trigger->GetName());
			if (T_Name.Equals(FString(TEXT("Destroy Trigger Box"))))
			{
				ABaseLevel* BaseLevel = Cast<ABaseLevel>(Trigger->GetOwner());
				UE_LOG(LogTemp, Log, TEXT("ccc: 레벨 삭제"));
				BaseLevel->Destroy();
			}
		}
	}
	
}

