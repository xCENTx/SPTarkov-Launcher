#pragma once
#include <Windows.h>
#include <iostream>
namespace SPTarkov {

	class Process {
	public:

		/// PROCESS INFORMATION
		STARTUPINFO sINFO;
		PROCESS_INFORMATION pINFO;
		DWORD dwExit;

		///	PATH
		LPCWSTR PATHS[2]{ L"Aki.Server.exe", L"Aki.Launcher.exe" };

		///	PATH EXAMPLES
		//LPCWSTR SERVER_PATH = L"Aki.Server.exe";
		//LPCWSTR LAUNCHER_PATH = L"Aki.Launcher.exe";
		//LPCWSTR GAME_PATH = L"EscapeFromTarkov.exe";
		//LPCWSTR SERVER_CONFIG_PATH = L"Aki.Sever.Config.exe";		//	KMC SERVER VALUE MODIFIER 1.5.1 [https://hub.sp-tarkov.com/files/file/308-kmc-server-value-modifier/]

		void AllocZeroMem(PROCESS_INFORMATION pINFO, STARTUPINFO sINFO);
		void ClearZeroMem(PROCESS_INFORMATION pINFO, STARTUPINFO sINFO);
		void ProcessRunning(PROCESS_INFORMATION pINFO, STARTUPINFO sINFO, DWORD ExitCode);
		bool Execute();
	};

	void Process::AllocZeroMem(PROCESS_INFORMATION pINFO, STARTUPINFO sINFO)
	{
		ZeroMemory(&sINFO, sizeof(sINFO));
		sINFO.cb = sizeof(sINFO);
		ZeroMemory(&pINFO, sizeof(pINFO));
		Sleep(1000);
	}

	void Process::ClearZeroMem(PROCESS_INFORMATION pINFO, STARTUPINFO sINFO)
	{
		CloseHandle(&pINFO.hProcess);
		CloseHandle(&pINFO.hThread);
		memset(&sINFO, NULL, sizeof(sINFO));
		memset(&pINFO, NULL, sizeof(pINFO));
	}

	void Process::ProcessRunning(PROCESS_INFORMATION pINFO, STARTUPINFO sINFO, DWORD ExitCode)
	{
		Sleep(2000);
		if (!GetExitCodeProcess(pINFO.hProcess, &ExitCode))
			ClearZeroMem(pINFO, sINFO);
	}

	bool Process::Execute()
	{
		int dwSize = sizeof(PATHS) / sizeof(PATHS[0]);
		for (int i = 0; i < dwSize; i++)
		{
			AllocZeroMem(pINFO, sINFO);
			if (!CreateProcess(PATHS[i], NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &sINFO, &pINFO)) {
				ClearZeroMem(pINFO, sINFO);
				MessageBoxA(NULL, "LAUNCH PROCEDURE FAILED\n\nEXITING . . .", "LAUNCH ERROR", MB_ICONERROR);
				return EXIT_FAILURE;
			}
			ProcessRunning(pINFO, sINFO, dwExit);
		}
		return EXIT_SUCCESS;
	}
}