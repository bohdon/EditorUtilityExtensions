// Copyright (c) 2020 Bohdon Sayre

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Factories/Factory.h"
#include "Styling/SlateBrush.h"
#include "AssetTemplateTypes.generated.h"


/**
 * A template for creating assets. Defines a type,
 * location, and naming format, such that the only required
 * information are arguments for formatting the name and path.
 */
USTRUCT(BlueprintType)
struct FAssetTemplate : public FTableRowBase
{
	GENERATED_BODY()

public:
	FAssetTemplate()
		: TemplateName(FText()),
		  TemplateIcon(FSlateBrush()),
		  PathFormat(FString()),
		  NameFormat(FString()),
		  bIsBlueprint(false),
		  AssetClass(nullptr),
		  FactoryClass(nullptr),
		  BlueprintParentClass(nullptr),
		  FormatArguments(TMap<FString, FString>())
	{
	}

	/** The display name of the template */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AssetTemplate")
	FText TemplateName;

	/** The display icon of the template */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AssetTemplate")
	FSlateBrush TemplateIcon;

	/** The format string for the path to the new asset */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AssetTemplate")
	FString PathFormat;

	/** The format string for the name of the new asset */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AssetTemplate")
	FString NameFormat;

	/** Is the new asset a blueprint? */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AssetTemplate")
	bool bIsBlueprint;

	/** The asset class to create */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "!bIsBlueprint"), Category = "AssetTemplate")
	UClass* AssetClass;

	/** The factory to use to create the asset */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "!bIsBlueprint"), Category = "AssetTemplate")
	TSubclassOf<UFactory> FactoryClass;

	/** The parent class of the blueprint to create */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bIsBlueprint"), Category = "AssetTemplate")
	UClass* BlueprintParentClass;

	/** The names of each format argument and their default values */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AssetTemplate")
	TMap<FString, FString> FormatArguments;
};
