// Copyright (c) 2019 Bohdon Sayre

#include "EditorUtilityExtensionsLibrary.h"

#include "AssetRegistryModule.h"
#include "AssetToolsModule.h"
#include "ContentBrowserModule.h"
#include "IAssetTools.h"
#include "IContentBrowserSingleton.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "PackageTools.h"


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

UObject* UEditorUtilityExtensionsLibrary::CreateAsset(const FString& AssetName, const FString& PackagePath, UClass* AssetClass, UClass* FactoryClass, FName CallingContext /*= NAME_None*/)
{
	if (FactoryClass)
	{
		UFactory* Factory = FactoryClass->GetDefaultObject<UFactory>();
		if (Factory)
		{
			IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
			return AssetTools.CreateAsset(AssetName, PackagePath, AssetClass, Factory, CallingContext);
		}
	}
	return nullptr;
}

UObject* UEditorUtilityExtensionsLibrary::CreateBlueprintAsset(const FString& AssetName, const FString& PackagePath, UClass* ParentClass, FName CallingContext /*= NAME_None*/)
{
	if (!FKismetEditorUtilities::CanCreateBlueprintOfClass(ParentClass))
	{
		UE_LOG(LogEditorUtilityExtensions, Error, TEXT("%s: Cannot create a Blueprint from class: %s"), *CallingContext.ToString(), *GetNameSafe(ParentClass));
		return nullptr;
	}

	// partly taken from FKismetEditorUtilities::CreateBlueprintFromClass
	// but without a dialog since we already have all the info we need

	// build full package name
	const FString PackageName = UPackageTools::SanitizePackageName(PackagePath + TEXT("/") + AssetName);

	// Then find/create it.
	UPackage* Package = CreatePackage(NULL, *PackageName);
	check(Package);

	// Create and init a new Blueprint
	UBlueprint* Blueprint = FKismetEditorUtilities::CreateBlueprint(ParentClass, Package, FName(*AssetName), BPTYPE_Normal, UBlueprint::StaticClass(), UBlueprintGeneratedClass::StaticClass(), CallingContext);
	if (Blueprint)
	{
		// Notify the asset registry
		FAssetRegistryModule::AssetCreated(Blueprint);

		// Mark the package dirty...
		Package->MarkPackageDirty();

		return Blueprint;
	}
	return nullptr;
}
