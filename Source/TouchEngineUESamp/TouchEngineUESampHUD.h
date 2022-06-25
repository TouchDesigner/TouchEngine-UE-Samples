// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TouchEngineUESampHUD.generated.h"

UCLASS()
class ATouchEngineUESampHUD : public AHUD
{
	GENERATED_BODY()

public:
	ATouchEngineUESampHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};
