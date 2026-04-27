#pragma once

#ifdef FALLOUT4
#include "RE/Fallout.h"
#include "F4SE/F4SE.h"

#define SKSE F4SE
#define SKSEAPI F4SEAPI
#define SKSEPlugin_Load F4SEPlugin_Load
#define SKSEPlugin_Query F4SEPlugin_Query

/*
	Old-gen Fallout 4 used runtime 1.10.163.
	Anniversary / next-gen Fallout 4 uses newer 1.11.x runtimes.

	This fallback alias only matters if the old SKSEPlugin_Query-style
	version check is compiled. The AE-compatible path should instead use
	F4SEPlugin_Version in main.cpp.
*/
#if defined(FALLOUT4_AE)
#define RUNTIME_1_5_97 RUNTIME_1_11_191
#else
#define RUNTIME_1_5_97 RUNTIME_1_10_163
#endif

#else
#include "RE/Skyrim.h"
#include "SKSE/SKSE.h"
#endif

#pragma warning(push)
#ifdef NDEBUG
#	include <spdlog/sinks/basic_file_sink.h>
#else
#	include <spdlog/sinks/msvc_sink.h>
#endif
#pragma warning(pop)

using namespace std::literals;

namespace logger = SKSE::log;

#define DLLEXPORT __declspec(dllexport)

#include "Version.h"
