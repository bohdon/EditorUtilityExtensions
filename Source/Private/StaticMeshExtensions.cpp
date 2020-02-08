// Copyright (c) 2020 Bohdon Sayre

#include "StaticMeshExtensions.h"

#include "Engine/StaticMesh.h"
#include "Factories/FbxFactory.h"


TArray<FName> UStaticMeshExtensions::GetMaterialSlotNames(UStaticMesh* StaticMesh)
{
	TArray<FName> MaterialNames;
	if (StaticMesh)
	{
		for (int32 MaterialIndex = 0; MaterialIndex < StaticMesh->StaticMaterials.Num(); ++MaterialIndex)
		{
			const FStaticMaterial& StaticMaterial = StaticMesh->StaticMaterials[MaterialIndex];
			MaterialNames.Add(StaticMaterial.MaterialSlotName);
		}
	}
	return MaterialNames;
}

void UStaticMeshExtensions::SetMaterialSlotNames(UStaticMesh* StaticMesh, const TArray<FName>& Names)
{
	if (StaticMesh)
	{
		for (int32 MaterialIndex = 0; MaterialIndex < StaticMesh->StaticMaterials.Num(); ++MaterialIndex)
		{
			if (MaterialIndex >= Names.Num())
			{
				break;
			}

			FStaticMaterial& StaticMaterial = StaticMesh->StaticMaterials[MaterialIndex];
			StaticMaterial.MaterialSlotName = Names[MaterialIndex];
		}
	}
}

void UStaticMeshExtensions::SetFbxFactoryImportUI(UFbxFactory* FbxFactory, UFbxImportUI* ImportUI)
{
	if (FbxFactory)
	{
		FbxFactory->ImportUI = ImportUI;
	}
}
