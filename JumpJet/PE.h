#include <Windows.h>
#include "DataDefs.h"

PBYTE GetProcBytes(LPVOID lpProcAddress, DLLINFO DllInfo);
DWORD GetDllTextOffset(HANDLE DllMaping);
LPVOID MapDllToMemory(LPSTR Path);