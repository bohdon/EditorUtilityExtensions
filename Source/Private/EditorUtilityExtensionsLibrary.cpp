// Copyright (c) 2019 Bohdon Sayre

#include "EditorUtilityExtensionsLibrary.h"

#include "ContentBrowserModule.h"
#include "IContentBrowserSingleton.h"


TArray<FString> UEditorUtilityExtensionsLibrary::GetSelectedFolders()
{
	FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
	TArray<FString> SelectedFolders;
	ContentBrowserModule.Get().GetSelectedFolders(SelectedFolders);

	return SelectedFolders;
}

TArray<FString> UEditorUtilityExtensionsLibrary::GetSelectedPathViewFolders()
{
	FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
	TArray<FString> SelectedFolders;
	ContentBrowserModule.Get().GetSelectedPathViewFolders(SelectedFolders);

	return SelectedFolders;
}
