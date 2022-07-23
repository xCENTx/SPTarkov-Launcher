#pragma once
#include <Windows.h>
#include <iostream>
#include "atlstr.h"

///	OBTAIN PATH
LPCWSTR QUICK_PATHS[2]{ L"Aki.Server.exe", L"Aki.Launcher.exe" };
LPCWSTR SERVER_PATH = L"Aki.Server.exe";
LPCWSTR LAUNCHER_PATH = L"Aki.Launcher.exe";
LPCWSTR GAME_PATH = L"EscapeFromTarkov.exe";
LPCWSTR SERVER_CONFIG_PATH = L"Aki.Sever.Config.exe";

/// PROCESS INFORMATION
STARTUPINFO sINFO;
PROCESS_INFORMATION pINFO;
DWORD dwExit;

void AllocZeroMem(PROCESS_INFORMATION pINFO, STARTUPINFO sINFO)
{
	ZeroMemory(&sINFO, sizeof(sINFO));
	sINFO.cb = sizeof(sINFO);
	ZeroMemory(&pINFO, sizeof(pINFO));
}

void ClearZeroMem(PROCESS_INFORMATION pINFO, STARTUPINFO sINFO)
{
	CloseHandle(&pINFO.hProcess);
	CloseHandle(&pINFO.hThread);
	memset(&sINFO, NULL, sizeof(sINFO));
	memset(&pINFO, NULL, sizeof(pINFO));
}

void ProcessRunning(PROCESS_INFORMATION pINFO, STARTUPINFO sINFO, DWORD ExitCode)
{
	Sleep(1000);
	if (!GetExitCodeProcess(pINFO.hProcess, &ExitCode))
		ClearZeroMem(pINFO, sINFO);
}