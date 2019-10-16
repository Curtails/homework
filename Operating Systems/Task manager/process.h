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
#define PROCESS_PATH2 L"C:\\Windows\\System32\\notepad.exe"
//D:\\Converter.exe
int p_num=0;	//���н�����
unsigned long int temp1[MAX_PATH];
class process {
public:

	process();
	void open();
	void close(unsigned long int id);
	void seek_name(unsigned long int id);	//�洢���������߳���
	unsigned long int p_id;				//����id
	unsigned long int p_threadid;		//�߳���
	wchar_t p_name[MAX_PATH];
	wchar_t test[MAX_PATH];
	

	void Wchar_tToString(std::string& szDst, wchar_t* wchar);
	void StringToWstring(std::wstring& szDst, std::string str);
};
process::process() {

}

void process::open()	//��������
{

	wchar_t proPath[MAX_PATH];	//�����СMAX_PATH����
	wcscpy_s(proPath, test);	//��test�������ݴ���proPath����·��
	//cout << proPath[MAX_PATH] << endl;

	STARTUPINFO si = { sizeof(si) };	// STARTUPINFOָ���������� Ӧ�ó�����뽫cb��ʼ��Ϊsizeof(STARTUPINFO)
	PROCESS_INFORMATION pi;	//PROCESS_INFORMATION�ṹ�洢�̵߳������Ϣ

	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = TRUE;
	BOOL bRet = ::CreateProcess(NULL, proPath, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
	//��������

	p_id = pi.dwProcessId;
	//printf("����id�� %d\n",pi.dwProcessId);

	seek_name(p_id); //�洢���������߳���
	return;
}
void process::close(unsigned long int id)
{
	PROCESSENTRY32 pe;	//��ſ��ս�����Ϣ��һ���ṹ��
	pe.dwSize = sizeof(PROCESSENTRY32);

	HANDLE hProcess;	//����һ����� ָ��Ҫ�����Ľ���
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);	//ָ��ϵͳ���̿���
	if (hSnapshot == INVALID_HANDLE_VALUE)
	{
		printf("CreateToolhelp32Snapshot error.\n");
		return;
	}
	BOOL bProcess = Process32First(hSnapshot, &pe);
	if (bProcess) {
		do
		{
			if (pe.th32ProcessID == id)
			{
				printf("%ls----%d\n", pe.szExeFile, pe.th32ProcessID);	//test
				break;
			}

			pe.dwSize = sizeof(PROCESSENTRY32);
			printf("%ls----%d\n", pe.szExeFile, pe.th32ProcessID);	//test
		} while (Process32Next(hSnapshot, &pe));

	}
	printf("%ls----%d\n", pe.szExeFile, pe.th32ProcessID);

	hProcess = ::OpenProcess(PROCESS_TERMINATE, FALSE, pe.th32ProcessID); //���ݽ���ID���ض�����
	::TerminateProcess(hProcess, 0);  //���ݶ�������������
	CloseHandle(hSnapshot);	//�رվ��
	CloseHandle(hProcess);
	return;
}

void process::seek_name(unsigned long int id) {

	PROCESSENTRY32 pe;	//��ſ��ս�����Ϣ��һ���ṹ��
	pe.dwSize = sizeof(PROCESSENTRY32);

	HANDLE hProcess;	//����һ����� ָ��Ҫ�����Ľ���
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);	//ָ��ϵͳ���̿���
	if (hSnapshot == INVALID_HANDLE_VALUE)
	{
		printf("CreateToolhelp32Snapshot error.\n");
		return;
	}
	BOOL bProcess = Process32First(hSnapshot, &pe);
	if (bProcess) {
		do
		{
			if (pe.th32ProcessID == id)
			{
				printf("%ls----%d\n", pe.szExeFile, pe.th32ProcessID);	//test
				break;
			}

			pe.dwSize = sizeof(PROCESSENTRY32);
			printf("%ls----%d\n", pe.szExeFile, pe.th32ProcessID);	//test
		} while (Process32Next(hSnapshot, &pe));

	}

	wcscpy_s(p_name, pe.szExeFile);	//�洢������
	p_threadid = pe.cntThreads;		//�洢�߳���
}

// wchar ת std::string
void process::Wchar_tToString(std::string& szDst, wchar_t* wchar)
{
	wchar_t* wText = wchar;
	DWORD dwNum = WideCharToMultiByte(CP_OEMCP, NULL, wText, -1, NULL, 0, NULL, FALSE);// WideCharToMultiByte������
	char* psText; // psTextΪchar*����ʱ���飬��Ϊ��ֵ��std::string���м����
	psText = new char[dwNum];
	WideCharToMultiByte(CP_OEMCP, NULL, wText, -1, psText, dwNum, NULL, FALSE);// WideCharToMultiByte���ٴ�����
	szDst = psText;// std::string��ֵ
	delete[]psText;// psText�����
}

//std::string ת wchar
void process::StringToWstring(std::wstring& szDst, std::string str)
{
	std::string temp = str;
	int len = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)temp.c_str(), -1, NULL, 0);
	wchar_t* wszUtf8 = new wchar_t[len + 1];
	memset(wszUtf8, 0, len * 2 + 2);
	MultiByteToWideChar(CP_ACP, 0, (LPCSTR)temp.c_str(), -1, (LPWSTR)wszUtf8, len);
	szDst = wszUtf8;
	std::wstring r = wszUtf8;
	delete[] wszUtf8;
}

//System::String ת std::string
void ConvertToString(System::String^ str, std::string& text)
{
	char* p = (char*)(int)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str);
	text = p;
	System::Runtime::InteropServices::Marshal::FreeHGlobal((System::IntPtr)p);
}