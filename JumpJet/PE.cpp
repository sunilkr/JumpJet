#include <Windows.h>
#include "PE.h"

DWORD GetProcBytes(LPVOID lpProcAddress, DLLINFO DllInfo, PFUNCTIONDATA pFunction)
{
	LPVOID Address = (LPVOID)((DWORD)lpProcAddress - ((DWORD)DllInfo.DllBase + DllInfo.TextOffset));
	INT cbInstr = rand()%5 + 1;
	INT cbBytes = GetInstrSize(Address, cbInstr);
	pFunction->CodeSize = cbBytes;
	CopyMemory(pFunction->CodeBytes, Address, cbBytes);
	return cbBytes;
}

LPVOID MapDllToMemory(LPSTR Path)
{
	HANDLE Handle = CreateFile(Path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL| FILE_ATTRIBUTE_SYSTEM, NULL);
	LPVOID Map=NULL;

	if(Handle != INVALID_HANDLE_VALUE)
	{
		DWORD FileSize = GetFileSize(Handle,NULL);
		Handle = CreateFileMapping(Handle, NULL, PAGE_READONLY|SEC_IMAGE, 0, 0, NULL);
		Map = MapViewOfFile(Handle, FILE_MAP_READ, 0, 0, 0);
	}
	return Map;
}

DWORD GetDllTextOffset(LPVOID DllMapping)
{
	PIMAGE_DOS_HEADER DosHdr = (PIMAGE_DOS_HEADER)DllMapping;
	if(DosHdr->e_magic != IMAGE_DOS_SIGNATURE)
		return IMG_NO_DOS_HDR;

	PIMAGE_NT_HEADERS NtHdr = (PIMAGE_NT_HEADERS)((LONG)DosHdr + DosHdr->e_lfanew);
	DWORD dwSections = NtHdr->FileHeader.NumberOfSections;

	IMAGE_SECTION_HEADER FirstSection = 
}