#pragma once

#include "Core.h"

namespace aymara {

	class AYMARA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in client 
	Application* CreateApplication();

}

