// Copyright (c) 2019 Bohdon Sayre

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityExtensionsModule.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EditorUtilityExtensionsLibrary.generated.h"


UCLASS()
class EDITORUTILITYEXTENSIONS_API UEditorUtilityExtensionsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


	// General Utils
	// -------------
public:
	/**
	 * Format a string using a dictionary of key and value strings
	 *
	 * @param Format The format string, using braces to indicate keys, e.g. "{MyKey}"
	 * @param Values The values for each key in the format string
	 * @return True if the format string was fully formatted, false if values were missing
	 */
	UFUNCTION(BlueprintCallable, Category = "EditorExtensions")
	static bool FormatString(FString Format, const TMap<FString, FString>& Values, FString& Result);


	// Content Browser
	// ---------------
public:
	/** Return the folders that are selected in the primary content browser */
	UFUNCTION(BlueprintCallable, Category = "EditorExtensions|ContentBrowser")
	static TArray<FString> GetSelectedFolders();

	/** Return the folders that are selected in the path view */
	UFUNCTION(BlueprintCallable, Category = "EditorExtensions|ContentBrowser")
	static TArray<FString> GetSelectedPathViewFolders();

	/**
	 * Select assets in the content browser
	 *
	 * @param AssetList An array of UObject assets to select
	 * @param bAllowLockedBrowsers When true, even locked browsers may handle the sync. Only set to true if the sync doesn't seem external to the content browser
	 * @param bFocusContentBrowser When true, brings the ContentBrowser into the foreground.
	 * @param InstanceName When supplied, will only sync the Content Browser with the matching InstanceName.  bAllowLockedBrowsers is ignored.
	 */
	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = 1), Category = "EditorExtensions|ContentBrowser")
	static void SyncBrowserToAssets(const TArray<UObject*>& AssetList, bool bAllowLockedBrowsers = false, bool bFocusContentBrowser = true, FName InstanceName = NAME_None, bool bNewSpawnBrowser = false);

	/**
	 * Select folders in the content browser
	 *
	 * @param FolderList An array of folders to select
	 * @param bAllowLockedBrowsers When true, even locked browsers may handle the sync. Only set to true if the sync doesn't seem external to the content browser
	 * @param bFocusContentBrowser When true, brings the ContentBrowser into the foreground.
	 * @param InstanceName When supplied, will only sync the Content Browser with the matching InstanceName.  bAllowLockedBrowsers is ignored.
	 */
	UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = 1), Category = "EditorExtensions|ContentBrowser")
	static void SyncBrowserToFolders(const TArray<FString>& FolderList, bool bAllowLockedBrowsers = false, bool bFocusContentBrowser = true, FName InstanceName = NAME_None, bool bNewSpawnBrowser = false);


	// Asset Tools
	// -----------
public:
	/**
	 * Create an asset using the asset tools.
	 * Allows using a generic object class for the factory, which makes it blueprint compatible.
	 *
	 * @param AssetName The name of the new asset
	 * @param PackagePath The package that will contain the new asset
	 * @param AssetClass The class of the new asset
	 * @param FactoryClass The class of the factory that will build the new asset
	 * @param CallingContext Optional name of the module or method calling CreateAsset() - this is passed to the factory
	 * @return The new asset or nullptr if it fails
	 */
	UFUNCTION(BlueprintCallable, Category = "EditorExtensions|AssetTools")
	static UObject* CreateAsset(const FString& AssetName, const FString& PackagePath, UClass* AssetClass, UClass* FactoryClass, FName CallingContext = NAME_None);

	/**
	 * Create a blueprint asset using the asset tools.
	 *
	 * @param AssetName The name of the new asset
	 * @param PackagePath The package that will contain the new asset
	 * @param ParentClass The parent class of the new blueprint
	 * @param CallingContext Optional name of the module or method calling CreateAsset() - this is passed to the factory
	 * @return The new asset or nullptr if it fails
	 */
	UFUNCTION(BlueprintCallable, Category = "EditorExtensions|AssetTools")
	static UObject* CreateBlueprintAsset(const FString& AssetName, const FString& PackagePath, UClass* ParentClass, FName CallingContext = NAME_None);
};
