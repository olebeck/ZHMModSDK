#pragma once

#include <random>
#include <unordered_map>

#include <ZHMModSDK/IPluginInterface.h>

class SkipIntro : public IPluginInterface
{
public:
	void Init() override;

private:
	DEFINE_PLUGIN_DETOUR(SkipIntro, void, OnLoadScene, ZEntitySceneContext*, ZSceneData&);
};

DEFINE_ZHM_PLUGIN(SkipIntro)
