// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

DWORD WINAPI my_thread(void* hModule) {
    //Your code goes here
    //====================
    if (MH_Initialize() != MH_OK) {
        std::cout << "Unable to load MinHook";
        FreeLibraryAndExitThread(reinterpret_cast<HMODULE>(hModule), 0);
    }
    MH_CreateHook(reinterpret_cast<void*>(gd::base + 0x1FB780), PlayLayer::hook, reinterpret_cast<void**>(&PlayLayer::init));
    MH_EnableHook(MH_ALL_HOOKS);

    //This line will dettach your DLL when executed. Remove if needed
    //FreeLibraryAndExitThread(reinterpret_cast<HMODULE>(hModule), 0);
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0x1000, my_thread, hModule, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

