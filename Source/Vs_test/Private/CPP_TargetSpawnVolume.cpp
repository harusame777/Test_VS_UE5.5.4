// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_TargetSpawnVolume.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ACPP_TargetSpawnVolume::ACPP_TargetSpawnVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SpawnArea = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnArea"));
	RootComponent = SpawnArea;

	//“–‚½‚è”»’èíœ
	SpawnArea->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SpawnArea->SetGenerateOverlapEvents(false);
}

FVector ACPP_TargetSpawnVolume::GetRandomPointInVolume() const
{
	return UKismetMathLibrary::RandomPointInBoundingBox(
		SpawnArea->GetComponentLocation(), 
		SpawnArea->GetScaledBoxExtent());
}

// Called when the game starts or when spawned
void ACPP_TargetSpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_TargetSpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

