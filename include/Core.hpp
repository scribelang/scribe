#pragma once

#include <array>
#include <cassert>
#include <cstring>
#include <deque>
#include <forward_list>
#include <fstream>
#include <initializer_list>
#include <iostream>
#include <mutex>
#include <regex>
#include <span>
#include <string>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <variant>
#include <vector>

#define _STRINGIFY(x) #x
#define STRINGIFY(x) _STRINGIFY(x)

#if defined(_WIN32) && defined(_MSC_VER)
#define SC_OS_WINDOWS
#if defined(_WIN64)
#define SC_OS_WINDOWS64
#endif
#elif defined(__linux__)
#define SC_OS_LINUX
#elif defined(__ANDROID__)
#define SC_OS_ANDROID
#elif defined(__FreeBSD__)
#define SC_OS_BSD
#define SC_OS_FREEBSD
#elif defined(__NetBSD__)
#define SC_OS_BSD
#define SC_OS_NETBSD
#elif defined(__OpenBSD__)
#define SC_OS_BSD
#define SC_OS_OPENBSD
#elif defined(__bsdi__)
#define SC_OS_BSD
#define SC_OS_BSDI
#elif defined(__DragonFly__)
#define SC_OS_BSD
#define SC_OS_DRAGONFLYBSD
#elif defined(__APPLE__)
#define SC_OS_APPLE
#endif

#if defined(SC_OS_WINDOWS)
#if defined(SC_OS_WINDOWS64)
using ssize_t = int64_t;
#else
using ssize_t = int;
#endif
#endif

namespace sc
{

// the primitives have lower case name
using u8	= unsigned char;
using Mutex	= std::mutex;
using Regex	= std::regex;
using String	= std::string;
using Thread	= std::thread;
using IStream	= std::istream;
using OStream	= std::ostream;
using FStream	= std::fstream;
using Nullptr	= std::nullptr_t;
using IOStream	= std::iostream;
using IFStream	= std::ifstream;
using OFStream	= std::ofstream;
using StringRef = std::string_view;

#if defined(SC_OS_WINDOWS)
using WString	 = std::wstring;
using WStringRef = std::wstring_view;
#endif

struct StringHash
{
	using HashType	     = std::hash<StringRef>;
	using is_transparent = void;

	size_t operator()(const char *str) const { return HashType{}(str); }
	size_t operator()(StringRef str) const { return HashType{}(str); }
	size_t operator()(const String &str) const { return HashType{}(str); }
};

template<typename T> using Set		   = std::unordered_set<T>;
template<typename T> using List		   = std::forward_list<T>; // singly linked list
template<typename T> using Span		   = std::span<T>;
template<typename T> using Deque	   = std::deque<T>;
template<typename T> using Vector	   = std::vector<T>;
template<typename T> using InitList	   = std::initializer_list<T>;
template<typename... Ts> using Variant	   = std::variant<Ts...>;
template<typename T, size_t N> using Array = std::array<T, N>;
template<typename K, typename V> using Map = std::unordered_map<K, V>;
template<typename V> using StringMap = std::unordered_map<String, V, StringHash, std::equal_to<>>;

} // namespace sc