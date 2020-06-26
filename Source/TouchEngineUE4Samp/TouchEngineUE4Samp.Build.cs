// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TouchEngineUE4Samp : ModuleRules
{
	public TouchEngineUE4Samp(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
