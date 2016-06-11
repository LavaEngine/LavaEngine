#include "VkWindowGlfw.hpp"

#include <iostream>

namespace LavaEngine {

void GlfwErrorHandler(int errcode, const char* desc)
{
	fprintf(stderr, "Error: GLFW errcode(%d): %s\n", errcode, desc);
}

void VkWindowGlfw::Create(const char* title)
{
	glfwSetErrorCallback(GlfwErrorHandler);

	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	_Window.reset(glfwCreateWindow(640, 480, "LavaEngine", nullptr, nullptr));
}

vk::SurfaceKHR VkWindowGlfw::CreateSurface(vk::Instance& instance)
{
	VkSurfaceKHR surface = nullptr;
	VkResult result = glfwCreateWindowSurface(instance, _Window.get(), nullptr, &surface);
	if (result)
	{
		fprintf(stderr, "Error: Failed to create vk surface, err=%d .\n", result);
		return nullptr;
	}
	return surface;
}

Vector<String> VkWindowGlfw::RequiredExtensions()
{
	uint32_t count;
	const char** extensionsArray = glfwGetRequiredInstanceExtensions(&count);

	Vector<String> extensions;
	for (uint32_t i = 0; i < count; i++) extensions.push_back(extensionsArray[i]);
	return extensions;
}

} // namespace LavaEngine
