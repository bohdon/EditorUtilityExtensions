// Copyright (c) 2020 Bohdon Sayre

#include "EditorUtilityExtensionsModule.h"

DEFINE_LOG_CATEGORY(LogEditorUtilityExtensions);


#define LOCTEXT_NAMESPACE "FEditorUtilityExtensionsModule"

void FEditorUtilityExtensionsModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FEditorUtilityExtensionsModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FEditorUtilityExtensionsModule, EditorUtilityExtensions)