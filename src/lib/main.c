#include <windows.h>
#include <minhook.h>

PVOID __wrap_memcpy(PVOID dst, PVOID src, SIZE_T count)
{
    __movsb(dst, src, count);
    return dst;
}

PVOID __wrap_memset(PVOID dst, BYTE data, SIZE_T count)
{
    __stosb(dst, data, count);
    return dst;
}

BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, PVOID reserved)
{
    if (reason == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(instance);
        MH_Initialize();
    }
    return TRUE;
}