#include "IL2CPP.hpp"
#include <Logger.hpp>

namespace IL2CPP
{
	HMODULE GameAssembly_handle = nullptr;

	Domain* CurrentDomain()
	{
		return (Domain*) IMPORT::il2cpp_domain_get();
	}

	void AttachCurrentThread()
	{
		IMPORT::il2cpp_thread_attach(
			IMPORT::il2cpp_domain_get()
		);
	}

	void INIT()
	{
		static bool il2cppInitialized = false;

		if (il2cppInitialized)
		{
			LOG_WARN("IL2CPP library is already initialized.");
			return;
		}

		GameAssembly_handle = GetModuleHandleA("GameAssembly.dll");

		INIT_API_FUNCTIONS(GameAssembly_handle);
		VM_FUNCTIONS::INIT();
		AttachCurrentThread();
		CommonCShrap::INIT();

		il2cppInitialized = true;

		LOG_INFO("IL2CPP library have been initialized.");
	}
}