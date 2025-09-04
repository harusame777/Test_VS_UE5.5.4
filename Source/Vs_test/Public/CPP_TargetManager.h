// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "CPP_Target.h"
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

	//ターゲット生成
	UFUNCTION(BlueprintCallable, Category = "TargetManagerBP")
	void SpawnAndRegisterTargetActor(FVector SpawnLocation);

	//ターゲット削除
	UFUNCTION(BlueprintCallable, Category = "TargetManagerBP")
	void DestroyAndUnRegisterTargetActor(ACPP_Target* RemoveTarget);

	//ターゲットアクター解除関数
	UFUNCTION(BlueprintCallable, Category = "TargetManagerBP")
	void UnRegisterTargetActor(ACPP_Target* RemoveTarget);

	//ターゲット数取得関数
	UFUNCTION(BlueprintCallable, Category = "TargetManagerBP")
	int32 GetTargetsNum();

	//テスト用レベル名
	UPROPERTY(BlueprintReadWrite, Category = "Level")
	FString TestLevelName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TargetManagerBP")
	TArray<ACPP_Target*> TargetsArray;

private:

	int32 TargetNum = 0;

};
