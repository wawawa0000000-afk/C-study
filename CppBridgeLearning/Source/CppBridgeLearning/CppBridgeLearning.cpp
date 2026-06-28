// Copyright Epic Games, Inc. All Rights Reserved.
#include "CppBridgeLearning.h"
#include "Modules/ModuleManager.h"

class FCppBridgeLearningGameModule : public FDefaultGameModuleImpl
{
public:
	virtual void StartupModule() override
	{
		//Šm”F‚Å‚«‚Ä‚¢‚È‚¢
		UE_LOG(LogTemp, Warning, TEXT("Hello from CppBridgeLearning!"));

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello from CppBridgeLearning"));
		}
	}
};

IMPLEMENT_PRIMARY_GAME_MODULE(FCppBridgeLearningGameModule, CppBridgeLearning, "CppBridgeLearning");