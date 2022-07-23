#include "Helper.h"

int main()
{
	int dwSize = sizeof(QUICK_PATHS) / sizeof(QUICK_PATHS[0]);
	for (int i = 0; i < sizeof(QUICK_PATHS); i++)
	{
		AllocZeroMem(pINFO, sINFO);
		if (!CreateProcess(QUICK_PATHS[i], NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &sINFO, &pINFO)) {
			ClearZeroMem(pINFO, sINFO);
			MessageBoxA(NULL, "LAUNCH PROCEDURE FAILED\n\nEXITING . . .", "LAUNCH ERROR", MB_ICONERROR);
			return EXIT_FAILURE;
		}
		ProcessRunning(pINFO, sINFO, dwExit);
	}

	///	EXIT
	return EXIT_SUCCESS;
}