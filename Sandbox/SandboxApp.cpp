#include "aymara.h"

class Sandbox : public aymara::Application 
{
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

aymara::Application* aymara::CreateApplication() {

	return new Sandbox();
}
