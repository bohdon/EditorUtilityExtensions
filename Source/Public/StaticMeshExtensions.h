// Copyright (c) 2019 Bohdon Sayre

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "StaticMeshExtensions.generated.h"

class UFbxFactory;
class UFbxImportUI;
class UStaticMesh;


UCLASS()
class EDITORUTILITYEXTENSIONS_API UStaticMeshExtensions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Return the names of all material slots on a static mesh */
	UFUNCTION(BlueprintCallable, Category = "EditorExtensions|StaticMesh")
	static TArray<FName> GetMaterialSlotNames(UStaticMesh* StaticMesh);

	/** Set the material slot names on a static mesh */
	UFUNCTION(BlueprintCallable, Category = "EditorExtensions|StaticMesh")
	static void SetMaterialSlotNames(UStaticMesh* StaticMesh, const TArray<FName>& Names);

	/**
	 * Set the import UI object for an fbx factory. Enables setting
	 * automated import settings on the ImportUI instance and then
	 * applying them to the factory that can be used during import.
	 */
	UFUNCTION(BlueprintCallable, Category = "EditorExtensions|FbxFactory")
	static void SetFbxFactoryImportUI(UFbxFactory* FbxFactory, UFbxImportUI* ImportUI);
};
