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

	// Content Browser
	// ---------------
public:
	/** Return the folders that are selected in the primary content browser */
	UFUNCTION(BlueprintCallable, Category = "EditorExtensions|ContentBrowser")
	static TArray<FString> GetSelectedFolders();

	/** Return the folders that are selected in the path view */
	UFUNCTION(BlueprintCallable, Category = "EditorExtensions|ContentBrowser")
	static TArray<FString> GetSelectedPathViewFolders();


	// Asset Tools
	// -----------
public:
	/**
	 * Create an asset using the asset tools.
	 * Allows using a generic object class for the factory, which makes it blueprint compatible.
	 */
	UFUNCTION(BlueprintCallable, Category = "EditorExtensions|AssetTools")
	static UObject* CreateAsset(const FString& AssetName, const FString& PackagePath, UClass* AssetClass, UClass* FactoryClass, FName CallingContext = NAME_None);

	/**
	 * Create a blueprint asset using the asset tools.
	 */
	UFUNCTION(BlueprintCallable, Category = "EditorExtensions|AssetTools")
	static UObject* CreateBlueprintAsset(const FString& AssetName, const FString& PackagePath, UClass* ParentClass, FName CallingContext = NAME_None);
};
