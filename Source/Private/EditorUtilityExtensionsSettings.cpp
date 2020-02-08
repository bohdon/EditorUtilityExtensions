// Copyright (c) 2020 Bohdon Sayre

#include "EditorUtilityExtensionsSettings.h"


UEditorUtilityExtensionsSettings::UEditorUtilityExtensionsSettings()
{
}

UEditorUtilityExtensionsSettings* UEditorUtilityExtensionsSettings::Get()
{
	return UEditorUtilityExtensionsSettings::StaticClass()->GetDefaultObject<UEditorUtilityExtensionsSettings>();
}
