#include "Helper.h"

int main()
{
	///	LAUNCH SERVER CONFIG CLIENT (if requested)
			//	CLOSE HANDLE FOR AKI-SERVER-CONFIG CLIENT

	///	LAUNCH AKI-SERVER CLIENT
	AllocZeroMem(pINFO, sINFO);
	CreateProcess(SERVER_PATH, NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &sINFO, &pINFO);

	///	CHECK PROCESS RUNNING
	ProcessRunning(pINFO, sINFO, dwExit);

	///	SLEEP	(IDEALLY WE WOULD WANT TO CHECK IF THE SERVER IS ACTUALLY PRESENT)
	Sleep(10000);

	///	LAUNCH AKI-LAUNCHER
	AllocZeroMem(pINFO, sINFO);
	CreateProcess(LAUNCHER_PATH, NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &sINFO, &pINFO);
	ProcessRunning(pINFO, sINFO, dwExit);

	//	LAUNCH ESCAPE FROM TARKOV
	AllocZeroMem(pINFO, sINFO);
	CreateProcess(GAME_PATH, NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &sINFO, &pINFO);
	ProcessRunning(pINFO, sINFO, dwExit);

	///	EXIT
	return EXIT_SUCCESS;
}