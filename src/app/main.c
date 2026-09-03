#include <windows.h>
#include <MinHook.h>

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

VOID CDECL WinMainCRTStartup()
{
    MH_Initialize();
    ExitProcess(EXIT_SUCCESS);
}