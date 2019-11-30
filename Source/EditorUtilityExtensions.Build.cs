// Copyright (c) 2019 Bohdon Sayre

using UnrealBuildTool;

public class EditorUtilityExtensions : ModuleRules
{
    public EditorUtilityExtensions(ReadOnlyTargetRules Target) : base(Target)
    {
        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "SlateCore",
				// ... add other public dependencies that you statically link with here ...
			}
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
        );
    }
}
