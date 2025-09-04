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

void UCPP_TargetManager::SpawnAndRegisterTargetActor(FVector SpawnLocation)
{

	//ターゲットアクターのクラスをロードする
	UClass* TargetClass = LoadClass<ACPP_Target>(nullptr, TEXT("/Game/Blueprints/BP_Target.BP_Target_C"));

	if (TargetClass)
	{
		GetWorld()->SpawnActor<ACPP_Target>(TargetClass, SpawnLocation, FRotator::ZeroRotator);

		UE_LOG(LogTemp, Log, TEXT("Spawn Target Actor"));

		TargetsArray.Add(Cast<ACPP_Target>(TargetClass));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Failed to load Target Class"));
	}
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