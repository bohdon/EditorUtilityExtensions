// Copyright (c) 2020 Bohdon Sayre

#include "AssetTemplates/AssetTemplateStatics.h"

#include "EditorUtilityExtensionsLibrary.h"
#include "Internationalization/TextFormatter.h"


bool UAssetTemplateStatics::FormatString(FString Format, const TMap<FString, FString>& Arguments, FString& Result)
{
	// perform extremely basic case-insensitive search and replace of keys and values
	Result = Format;
	for (auto& Elem : Arguments)
	{
		FString SearchKey = FString::Printf(TEXT("{%s}"), *Elem.Key);
		Result = Result.Replace(*SearchKey, *Elem.Value, ESearchCase::IgnoreCase);
	}

	if (Result.Contains(FString("{")) || Result.Contains(FString("}")))
	{
		return false;
	}

	return true;
}

bool UAssetTemplateStatics::FormatTemplateNameAndPath(const FAssetTemplate& Template, TMap<FString, FString> Arguments, FString& AssetName, FString& PackagePath)
{
	bool bSuccess = FormatString(Template.PathFormat, Arguments, PackagePath);
	bSuccess &= FormatString(Template.NameFormat, Arguments, AssetName);
	return bSuccess;
}

UObject* UAssetTemplateStatics::CreateAssetFromTemplate(const FAssetTemplate& Template, TMap<FString, FString> Arguments)
{
	FString AssetName, PackagePath;
	bool bSuccess = FormatTemplateNameAndPath(Template, Arguments, AssetName, PackagePath);

	if (!bSuccess)
	{
		return nullptr;
	}

	const FName CallingContext("AssetTemplates");

	if (Template.bIsBlueprint)
	{
		return UEditorUtilityExtensionsLibrary::CreateBlueprintAsset(AssetName, PackagePath, Template.BlueprintParentClass, CallingContext);
	}
	else
	{
		return UEditorUtilityExtensionsLibrary::CreateAsset(AssetName, PackagePath, Template.AssetClass, Template.FactoryClass, CallingContext);
	}
}
