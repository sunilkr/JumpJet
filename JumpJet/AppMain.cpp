#include <stdio.h>
#include <Windows.h>
#include <assert.h>


int main(int argc, char** argv)
{
	HMODULE hKernel = GetModuleHandle("kernel32.dll");
	assert(hKernel!=INVALID_HANDLE_VALUE);

}