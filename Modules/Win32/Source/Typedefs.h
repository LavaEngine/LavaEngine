#ifndef __LavaEngine_Typedefs_HPP__
#define __LavaEngine_Typedefs_HPP__

#include <string>
#include <memory>
#include <vector>
#include <set>

namespace LavaEngine {

using String = std::string;
using WString = std::wstring;

template<typename... Args> using Ptr = std::shared_ptr<Args...>;
template<typename T, typename ...Args> auto MakeShared(Args&&... args) { return std::make_shared<T>(std::forward<Args>(args)...); }

template<typename... Args> using UniquePtr = std::unique_ptr<Args...>;
template<typename T, typename ...Args> auto MakeUnique(Args&&... args) { return std::make_unique<T>(std::forward<Args>(args)...); }

template<typename... Args> using Vector = std::vector<Args...>;
template<typename... Args> using Set = std::set<Args...>;

} // namespace LavaEngine

#endif // __LavaEngine_Typedefs_HPP__
