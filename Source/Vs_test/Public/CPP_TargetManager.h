// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "CPP_TargetManager.generated.h"

/**
 * 
 */
UCLASS()
class VS_TEST_API UCPP_TargetManager : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:
	UCPP_TargetManager();

	//初期化関数
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	//終了関数
	virtual void Deinitialize() override;

	//テスト用レベル名
	UPROPERTY(BlueprintReadWrite, Category = "Level")
	FString TestLevelName;
};
