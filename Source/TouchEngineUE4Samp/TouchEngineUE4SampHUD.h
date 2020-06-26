// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TouchEngineUE4SampHUD.generated.h"

UCLASS()
class ATouchEngineUE4SampHUD : public AHUD
{
	GENERATED_BODY()

public:
	ATouchEngineUE4SampHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

