#include "SkipIntro.h"

#include <ZHMModSDK/Hooks.h>
#include <ZHMModSDK/Logging.h>

#include <Glacier/ZScene.h>

void SkipIntro::Init()
{
	Hooks::ZEntitySceneContext_LoadScene->AddDetour(this, &SkipIntro::OnLoadScene);
}

DECLARE_PLUGIN_DETOUR(SkipIntro, void, OnLoadScene, ZEntitySceneContext* th, ZSceneData& p_SceneData)
{
	Logger::Debug("Loading scene: {}", p_SceneData.m_sceneName);

	for (auto& s_Brick : p_SceneData.m_sceneBricks)
		Logger::Debug("+ With brick: {}", s_Brick);

	if (p_SceneData.m_sceneName == "assembly:/_PRO/Scenes/Frontend/Boot.entity")
		p_SceneData.m_sceneName = "assembly:/_PRO/Scenes/Frontend/MainMenu.entity";

	return HookResult<void>(HookAction::Continue());
}

DECLARE_ZHM_PLUGIN(SkipIntro);
