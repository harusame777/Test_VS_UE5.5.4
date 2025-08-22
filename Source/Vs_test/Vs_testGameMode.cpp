// Copyright Epic Games, Inc. All Rights Reserved.

#include "Vs_testGameMode.h"
#include "Vs_testCharacter.h"
#include "UObject/ConstructorHelpers.h"

AVs_testGameMode::AVs_testGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
