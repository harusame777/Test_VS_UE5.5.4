// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_TargetManager.h"

UCPP_TargetManager::UCPP_TargetManager()
{

}

void UCPP_TargetManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	FString _LeftStr;

	GetWorld()->GetFullName().Split(TEXT("."), &_LeftStr, &TestLevelName);

	UE_LOG(LogTemp, Log, TEXT("LevelName : %s"), *TestLevelName);
}

void UCPP_TargetManager::Deinitialize()
{
	Super::Deinitialize();
}