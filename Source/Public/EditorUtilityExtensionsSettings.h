// Copyright (c) 2020 Bohdon Sayre

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "EditorUtilityExtensionsSettings.generated.h"


UCLASS(config = Editor, defaultconfig)
class EDITORUTILITYEXTENSIONS_API UEditorUtilityExtensionsSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UEditorUtilityExtensionsSettings();

	static UEditorUtilityExtensionsSettings* Get();

	/** The default data table to use for asset templates */
	UPROPERTY(config, EditAnywhere, meta = (AllowedClasses = "DataTable"), Category = "AssetTemplates")
	FSoftObjectPath DefaultAssetTemplates;
};
