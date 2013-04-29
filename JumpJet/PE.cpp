#include <Windows.h>
#include "PE.h"

PBYTE GetProcBytes(LPVOID lpProcAddress, DLLINFO DllInfo)
{
	
}

DWORD GetDllTextOffset(LPSTR Path)
{
	
	HANDLE hFile = CreateFile(Path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL| FILE_ATTRIBUTE_SYSTEM, NULL);
	
	if(hFile != INVALID_HANDLE_VALUE)
	{
		DWORD FileSize = GetFileSize(hFile,NULL);

	}
}