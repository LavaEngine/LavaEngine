#ifndef __LavaEngine_VkContext__
#define __LavaEngine_VkContext__

#include <vulkan/vulkan.h>
#include <vulkan/vk_cpp.hpp>

#include "Typedefs.h"

namespace LavaEngine {

class VkContext
{
public:
	VkContext();
	virtual ~VkContext();

	void Init(const char* appName);

	template<typename Iterable> void RequireInstanceExtensions(const Iterable& extensions);
	template<typename Iterable> void RequireExtensions(const Iterable& extensions);

	operator vk::ApplicationInfo& ()	{ return _AppInfo; }
	operator vk::Instance& ()			{ return _Instance; }

private:
	vk::Instance _Instance;
	vk::Device _Device;

	vk::ApplicationInfo _AppInfo;

	Set<String> _RequiredInstanceExtensions;
	Set<String> _RequiredExtensions;
};

template<typename Iterable>
inline void VkContext::RequireInstanceExtensions(const Iterable & extensions)
{
	assert(_Instance == nullptr);
	for (auto& ext : extensions) _RequiredInstanceExtensions.insert(ext);
}

template<typename Iterable>
inline void VkContext::RequireExtensions(const Iterable& extensions)
{
	assert(_Device == nullptr);
	for (auto& ext : extensions) _RequiredExtensions.insert(ext);
}

} // namespace LavaEngine

#endif // __LavaEngine_VkContext__
