#include <Windows.h>

#include "Typedefs.h"
#include "VkContext.hpp"
#include "VkWindow.hpp"
#include "VkWindowGlfw.hpp"

using namespace LavaEngine;

int main()
{
	auto window = LavaEngine::MakeUnique<VkWindowGlfw>();
	window->Create("LavaEngine");

	VkContext vkContext;
	vkContext.RequireInstanceExtensions(window->RequiredExtensions());
	vkContext.Init("Demo");

	auto surface = window->CreateSurface(vkContext);

}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	return main();
}
