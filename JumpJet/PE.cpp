#include <Windows.h>
#include "PE.h"

PBYTE GetProcBytes(LPVOID lpProcAddress, DLLINFO DllInfo)
{
	
}

LPVOID MapDllToMemory(LPSTR Path)
{
	HANDLE Handle = CreateFile(Path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL| FILE_ATTRIBUTE_SYSTEM, NULL);
	LPVOID Map;

	if(Handle != INVALID_HANDLE_VALUE)
	{
		DWORD FileSize = GetFileSize(Handle,NULL);
		Handle = CreateFileMapping(Handle, NULL, PAGE_READONLY|SEC_IMAGE, 0, 0, NULL);
		Map = MapViewOfFile(Handle, FILE_MAP_READ, 0, 0, 0);
	}
	return Map;
}


