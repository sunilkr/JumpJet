#include <Windows.h>
#include <string.h>
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

PIMAGE_SECTION_HEADER GetDllTextOffset(LPVOID DllMapping)
{
	PIMAGE_DOS_HEADER DosHdr = (PIMAGE_DOS_HEADER)DllMapping;
	if(DosHdr->e_magic != IMAGE_DOS_SIGNATURE)
		return NULL;

	PIMAGE_NT_HEADERS NtHdr = (PIMAGE_NT_HEADERS)((LONG)DosHdr + DosHdr->e_lfanew);
	DWORD dwSections = NtHdr->FileHeader.NumberOfSections;

	PIMAGE_SECTION_HEADER FirstSection = (PIMAGE_SECTION_HEADER)((LONG)DllMapping + sizeof(IMAGE_NT_HEADERS)); // FIXIT:: Smells Bad

	PIMAGE_SECTION_HEADER ThisSection = FirstSection;
	DWORD i = 0;
	for(; i < dwSections; i++)
	{
		if(strnicmp((PCHAR)ThisSection->Name,".TEXT",8))
			break;
		else
			ThisSection++;
	}

	if( i < dwSections)
		return ThisSection;
	return NULL;
}