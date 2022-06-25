// Copyright Epic Games, Inc. All Rights Reserved.

#include "TouchEngineUESampGameMode.h"
#include "TouchEngineUESampHUD.h"
#include "TouchEngineUESampCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATouchEngineUESampGameMode::ATouchEngineUESampGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATouchEngineUESampHUD::StaticClass();
}
