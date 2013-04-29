#include <Windows.h>
#include <Psapi.h>
#include "DataDefs.h"
#include "NbDefs.h"
#include "PE.h"

extern DLLINFO DllInfo[2];

DWORD InitDllInfo()
{
	LPSTR DllNames[] = {"kernel32.dll", "ntdll.dll"};
	int DllCount = 2;
	HMODULE hModule = NULL;
	DLLINFO diTemp;
	MODULEINFO ModuleInfo;
	
	for( int i = 0; i < DllCount; i++)
	{
		hModule = GetModuleHandle("kernel32.dll");
		if( GetModuleInformation(NULL, hModule, &ModuleInfo, sizeof(MODULEINFO)))
		{
			diTemp.DllBase = ModuleInfo.lpBaseOfDll;
			int size = GetModuleFileName(hModule, diTemp.Path, MAX_PATH);
			diTemp.TextOffset = GetDllTextOffset(diTemp.Path);
		}

		DllInfo[i] = diTemp;
	}
}