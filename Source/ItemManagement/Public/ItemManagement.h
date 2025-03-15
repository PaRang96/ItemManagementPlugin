// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

UENUM(BlueprintType)
enum class EItemType : uint8
{
	E_Consumable,
	E_Gear,
};

class FItemManagementModule : public IModuleInterface
{
public:

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
