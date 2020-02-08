// Copyright (c) 2020 Bohdon Sayre

#pragma once

#include "AssetTemplateTypes.h"
#include "CoreMinimal.h"
#include "EditorUtilityExtensionsModule.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AssetTemplateStatics.generated.h"


UCLASS()
class EDITORUTILITYEXTENSIONS_API UAssetTemplateStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Format a string using a dictionary of key and value strings
	 *
	 * @param Format The format string, using braces to indicate keys, e.g. "{MyKey}"
	 * @param Arguments The values for each key in the format string
	 * @return True if the format string was fully formatted, false if values were missing
	 */
	UFUNCTION(BlueprintCallable, Category = "EditorExtensions")
	static bool FormatString(FString Format, const TMap<FString, FString>& Arguments, FString& Result);

	/**
	 * Create an asset from a template, using the given format values
	 * @return Whether both the path and name were formatted successfully
	 */
	UFUNCTION(BlueprintCallable)
	static bool FormatTemplateNameAndPath(const FAssetTemplate& Template, TMap<FString, FString> Arguments, FString& AssetName, FString& PackagePath);

	/**
	 * Create an asset from a template, using the given format values
	 */
	UFUNCTION(BlueprintCallable)
	static UObject* CreateAssetFromTemplate(const FAssetTemplate& Template, TMap<FString, FString> Arguments);
};
