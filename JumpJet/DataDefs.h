#include <Windows.h>

#define IDX_VALLOC			0
#define IDX_VPROTECT		1
#define IDX_OPEN_PROCESS	2
#define IDX_CRT_RMT_THREAD	3
#define IDX_WRITE_PROC_MEM	4
#define IDX_CREATE_PROCESS	5

#define IDX_KERNEL32	0
#define	IDX_NTDLL		1


typedef struct __FUNCTIONDATA
{
	LPVOID	 ProcAddress;
	DWORD	 CodeSize;
	BYTE	 CodeBytes[25];
	PDLLINFO pDll;
} FUNCTIONDATA, *PFUNCTIONDATA;

typedef struct __DLLINFO
{
	LPVOID	DllBase;
	DWORD	TextOffset;
	LPVOID	DllMapping;
	CHAR	Path[MAX_PATH];	
} DLLINFO, *PDLLINFO;
