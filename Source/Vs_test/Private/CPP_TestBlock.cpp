// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_TestBlock.h"

// Sets default values
ACPP_TestBlock::ACPP_TestBlock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_TestBlock::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_TestBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_TestBlock::TestFunction(int32 a)
{
	GEngine->AddOnScreenDebugMessage(
		-1,
		5.0f,
		FColor::Red,
		FString::Printf(TEXT("Test Ok! %d"),a)
	);
}

