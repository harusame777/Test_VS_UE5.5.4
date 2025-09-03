// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_TargetManager.h"

UCPP_TargetManager::UCPP_TargetManager()
{

}

void UCPP_TargetManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	FString _LeftStr;

	//レベル名を取得
	//Splitで"."で区切って右側を取得
	GetWorld()->GetFullName().Split(TEXT("."), &_LeftStr, &TestLevelName);

	//ログ出力
	UE_LOG(LogTemp, Log, TEXT("LevelName : %s"), *TestLevelName);
}

void UCPP_TargetManager::Deinitialize()
{
	Super::Deinitialize();
}

void UCPP_TargetManager::RegisterTargetActor(ACPP_Target* NewTarget)
{
	if (NewTarget)
	{
		TargetsArray.Add(NewTarget);

		TargetNum++;

		UE_LOG(LogTemp, Log, TEXT("TargetNum : %d"), TargetNum);
	}
}

void UCPP_TargetManager::UnRegisterTargetActor(ACPP_Target* RemoveTarget)
{

}