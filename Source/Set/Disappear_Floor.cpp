// Fill out your copyright notice in the Description page of Project Settings.


#include "Disappear_Floor.h"
#include "RunnerCharacter.h"


// Sets default values
ADisappear_Floor::ADisappear_Floor()
{
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = Root;
	
	Disappear_Floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Scale_Floor"));
	Disappear_Floor->SetupAttachment(RootComponent);

	Collision_Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Disappear_Trigger"));
	Collision_Box->SetupAttachment(Disappear_Floor);

	Disappear_Time = 1.0f;

	PrimaryActorTick.bCanEverTick = true; 
	PrimaryActorTick.bStartWithTickEnabled = false;  // 틱함수꺼놓음
}

// Called when the game starts or when spawned
void ADisappear_Floor::BeginPlay()
{
	Super::BeginPlay();

	Collision_Box->OnComponentBeginOverlap.
		AddDynamic(this, &ADisappear_Floor::OnOverlapBegin);
	
}

// Called every frame
void ADisappear_Floor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADisappear_Floor::Destroy_Floor()
{
	Destroy();
}

void ADisappear_Floor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (OtherActor != nullptr)
	{
		ARunnerCharacter* Pc = Cast<ARunnerCharacter>(OtherActor);
	
		if (Pc)
		{
			UBoxComponent* Trigger_box = Cast<UBoxComponent>(OverlappedComp);

			FTimerHandle DestroyHandle;

			GetWorld()->GetTimerManager().SetTimer(DestroyHandle,
				this,&ADisappear_Floor::Destroy_Floor, Disappear_Time, true);
		}
	}
}
