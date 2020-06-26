// Copyright Epic Games, Inc. All Rights Reserved.

#include "TouchEngineUE4SampGameMode.h"
#include "TouchEngineUE4SampHUD.h"
#include "TouchEngineUE4SampCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATouchEngineUE4SampGameMode::ATouchEngineUE4SampGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATouchEngineUE4SampHUD::StaticClass();
}
