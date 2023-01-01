#pragma once

#include <ZHMModSDK/EventDispatcher.h>
#include <ZHMModSDK/Common.h>

class ZHMSDK_API Events
{
public:
	static EventDispatcher<void>* OnConsoleCommand;
};
