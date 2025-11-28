// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class TouchEngineUESampTarget : TargetRules
{
	public TouchEngineUESampTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		ExtraModuleNames.Add("TouchEngineUESamp");
	}
}
