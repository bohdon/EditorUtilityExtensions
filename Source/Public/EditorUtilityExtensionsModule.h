// Copyright (c) 2019 Bohdon Sayre

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"


class FEditorUtilityExtensionsModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
