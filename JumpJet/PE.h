#include <Windows.h>
#include "DataDefs.h"

DWORD	GetProcBytes(LPVOID lpProcAddress, DLLINFO DllInfo);
DWORD	GetDllTextOffset(LPVOID DllMaping);
LPVOID	MapDllToMemory(LPSTR Path);
INT		GetInstrSize( LPVOID Address, INT cbInstr);