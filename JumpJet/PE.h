#include <Windows.h>
#include "DataDefs.h"

DWORD	GetProcBytes(LPVOID lpProcAddress, DLLINFO DllInfo);
LPVOID	MapDllToMemory(LPSTR Path);
INT		GetInstrSize( LPVOID Address, INT cbInstr);

PIMAGE_SECTION_HEADER	GetDllTextOffset(LPVOID DllMaping);