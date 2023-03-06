#pragma once

//#include "aymara.h"  
//TODO: Check why VS redlines "aymara::" without this incl 

#ifdef AYM_PLATFORM_WINDOWS

extern aymara::Application* aymara::CreateApplication();

int main(int argc, char** argv) {

	aymara::Log::Init();
	AYM_CORE_WARN("Initialized Log!");
	AYM_CORE_INFO("Hello!");

	auto app = aymara::CreateApplication();
	app->Run();
	delete app;

}

#endif