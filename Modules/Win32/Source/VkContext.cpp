#include "VkContext.hpp"

namespace LavaEngine {

VkContext::VkContext()
{

}

VkContext::~VkContext()
{

}

void VkContext::Init(const char* appName)
{
	_AppInfo = vk::ApplicationInfo(appName, 0, "LavaEngine", 0, 0);

	Vector<const char*> instanceExtensions;
	for (auto& ext : _RequiredInstanceExtensions) instanceExtensions.push_back(ext.c_str());

	vk::InstanceCreateInfo createInfo(vk::InstanceCreateFlags(), &_AppInfo, 0, nullptr, (uint32_t) instanceExtensions.size(), instanceExtensions.data());

	_Instance = vk::createInstance(createInfo);
	if (_Instance == nullptr)
	{
		fprintf(stderr, "Failed to create instance.\n");
		abort();
	}

	auto physicalDevices = _Instance.enumeratePhysicalDevices();
	auto formatProperties = physicalDevices[0].getFormatProperties(vk::Format::eR8G8B8A8Unorm);

	float queuePriorities[] = { 1.0f };
	auto deviceQueueCreateInfo = vk::DeviceQueueCreateInfo()
		.setQueueCount(1)
		.setPQueuePriorities(queuePriorities);

	Vector<const char*> extensions;
	for (auto& ext : _RequiredExtensions) extensions.push_back(ext.c_str());

	auto deviceCreateInfo = vk::DeviceCreateInfo()
		.setQueueCreateInfoCount(1)
		.setPQueueCreateInfos(&deviceQueueCreateInfo)
		.setEnabledExtensionCount((uint32_t) _RequiredExtensions.size())
		.setPpEnabledExtensionNames(extensions.data());

	_Device = physicalDevices[0].createDevice(deviceCreateInfo);
	if (_Device == nullptr)
	{
		fprintf(stderr, "Failed creating logical device.\n");
		abort();
	}
}

} // namespace LavaEngine
