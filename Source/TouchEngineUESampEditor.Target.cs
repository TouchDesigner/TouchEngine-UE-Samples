// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class TouchEngineUESampEditorTarget : TargetRules
{
	public TouchEngineUESampEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
        ExtraModuleNames.Add("TouchEngineUESamp");

        // ~ IncludeOrderVersion ~
        // This flag was introduced by Epic for providing backward compatibility to a change in the way they process include orders
        // While setting IncludeOrderVersion to EngineIncludeOrderVersion.Latest will always use their latest setup, we are explicitly setting this to 5.1 below,
        // as this is in line with the default Target.cs generated for a new UE 5.1 project 
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;
    }
}
