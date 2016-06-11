#ifndef __LavaEngine_VkWindowGlfw__
#define __LavaEngine_VkWindowGlfw__

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "Typedefs.h"
#include "VkWindow.hpp"

namespace LavaEngine {

class VkWindowGlfw : VkWindow
{
private:
	struct GLFWwindowDeleter {
		void operator() (GLFWwindow* window) { glfwDestroyWindow(window); }
	};

public:
	VkWindowGlfw()				{}
	virtual ~VkWindowGlfw()		{}

	void Create(const char* title) override;
	vk::SurfaceKHR CreateSurface(vk::Instance& instance) override;

	Vector<String> RequiredExtensions() override;

	operator bool() override	{ return (bool)_Window; };

protected:

private:
	UniquePtr<GLFWwindow, GLFWwindowDeleter> _Window;
};

} // namespace LavaEngine

#endif // __LavaEngine_VkWindowGlfw__
