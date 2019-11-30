// Copyright (c) 2019 Bohdon Sayre

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EditorUtilityExtensionsLibrary.generated.h"


UCLASS()
class EDITORUTILITYEXTENSIONS_API UEditorUtilityExtensionsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Return the folders that are selected in the primary content browser */
	UFUNCTION(BlueprintCallable, Category = "Development|Editor")
	static TArray<FString> GetSelectedFolders();

	/** Return the folders that are selected in the path view */
	UFUNCTION(BlueprintCallable, Category = "Development|Editor")
	static TArray<FString> GetSelectedPathViewFolders();
};
