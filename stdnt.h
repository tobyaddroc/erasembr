#pragma once

#include <windows.h>
#include "lazyimp.h"

typedef long(__stdcall* pNtSuspendProcess)(void*);
typedef long(__stdcall* pNtResumeProcess)(void*);
typedef long(__stdcall* pNtRaiseHardError)(long, unsigned long, unsigned long,
	unsigned long*, unsigned long, unsigned long*);
typedef long(__stdcall* pRtlAdjustPrivilege)(unsigned long, unsigned char,
	unsigned char, unsigned char*);

__declspec(selectany) HMODULE NTDll = LI_FN(LoadLibrary)("ntdll.dll");
__declspec(selectany) pNtSuspendProcess NtSuspendProcess = pNtSuspendProcess(
	GetProcAddress(NTDll, "NtSuspendProcess")
);
__declspec(selectany) pNtResumeProcess NtResumeProcess = pNtResumeProcess(
	GetProcAddress(NTDll, "NtResumeProcess")
);
__declspec(selectany) pNtRaiseHardError NtRaiseHardError = pNtRaiseHardError(
	GetProcAddress(NTDll, "NtRaiseHardError")
);
__declspec(selectany) pRtlAdjustPrivilege RtlAdjustPrivilege = pRtlAdjustPrivilege(
	GetProcAddress(NTDll, "RtlAdjustPrivilege")
);