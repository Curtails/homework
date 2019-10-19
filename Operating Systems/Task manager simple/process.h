/*
 * This file is part of the Task manager project.
 * Copyright (C) 2019 Curtails
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once
#include <windows.h>
#include <iostream>
#include <cstdio>
#include "Tlhelp32.h"
#include "tchar.h"
#include <stdio.h>
#include <string>
using namespace std;
#define PROCESS_PATH L"C:\\Program Files\\Windows NT\\Accessories\\wordpad.exe"

class process {
	public:


		void open();
		void close(unsigned long int id);
		void seek_name(unsigned long int id);
		unsigned long int p_id;
		wchar_t p_name[MAX_PATH];
		wchar_t test[MAX_PATH];

		void Wchar_tToString(std::string& szDst, wchar_t* wchar);
		void StringToWstring(std::wstring& szDst, std::string str);
};


void process::open()
{

	wchar_t proPath[MAX_PATH];			//定义大小MAX_PATH数组
	wcscpy_s(proPath, PROCESS_PATH);

	STARTUPINFO si = { sizeof(si) };	// STARTUPINFO指定窗口特性 应用程序必须将cb初始化为sizeof(STARTUPINFO)
	PROCESS_INFORMATION pi;				//PROCESS_INFORMATION结构存储线程的相关信息

	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = TRUE;
	BOOL bRet = ::CreateProcess(NULL, proPath, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);

	p_id = pi.dwProcessId;
	return;
}
void process::close(unsigned long int id)
{
	PROCESSENTRY32 pe;	//存放快照进程信息的一个结构体
	pe.dwSize = sizeof(PROCESSENTRY32);

	HANDLE hProcess;	//定义一个句柄 指向要结束的进程
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);	//指向系统进程快照
	if (hSnapshot == INVALID_HANDLE_VALUE)
	{
		printf("CreateToolhelp32Snapshot error.\n");
		return;
	}
	BOOL bProcess = Process32First(hSnapshot, &pe);
	if (bProcess) {
		do
		{
			if (!_tcsicmp(pe.szExeFile, _T("wordpad.exe")))
			{
				printf("%ls----%d\n", pe.szExeFile, pe.th32ProcessID);	//test
				break;
			}

			pe.dwSize = sizeof(PROCESSENTRY32);
			printf("%ls----%d\n", pe.szExeFile, pe.th32ProcessID);	//test
		} while (Process32Next(hSnapshot, &pe));

	}
	cout << endl << endl;
	printf("%ls----%d\n", pe.szExeFile, pe.th32ProcessID);

	hProcess = ::OpenProcess(PROCESS_TERMINATE, FALSE, pe.th32ProcessID); //根据进程ID返回对象句柄
	::TerminateProcess(hProcess, 0);  //根据对象句柄结束进程
	CloseHandle(hSnapshot);	//关闭句柄
	CloseHandle(hProcess);
	return;
}
