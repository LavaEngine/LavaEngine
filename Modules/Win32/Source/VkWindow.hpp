#ifndef __LavaEngine_VkWindow__
#define __LavaEngine_VkWindow__

#include <vulkan/vulkan.h>
#include <vulkan/vk_cpp.hpp>

namespace LavaEngine {

class VkWindow
{
public:
	virtual ~VkWindow()		{}

	virtual void Create(const char* title) = 0;
	virtual vk::SurfaceKHR CreateSurface(vk::Instance& instance) = 0;

	virtual Vector<String> RequiredExtensions()		{ return {}; }

	virtual operator bool () = 0;

protected:
	VkWindow()		{}

private:
};

} // namespace LavaEngine

#endif // __LavaEngine_VkWindow__
