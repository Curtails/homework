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
int p_num=0;	//运行进程数
unsigned long int temp1[MAX_PATH];
class process {
public:

	process();
	void open();
	void close(unsigned long int id);
	void seek_name(unsigned long int id);	//存储进程名与线程数
	unsigned long int p_id;				//进程id
	unsigned long int p_threadid;		//线程数
	wchar_t p_name[MAX_PATH];
	wchar_t test[MAX_PATH];
	

	void Wchar_tToString(std::string& szDst, wchar_t* wchar);
	void StringToWstring(std::wstring& szDst, std::string str);
};
process::process() {

}

void process::open()	//创建进程
{

	wchar_t proPath[MAX_PATH];	//定义大小MAX_PATH数组
	wcscpy_s(proPath, test);	//将test数组内容传给proPath代表路径
	//cout << proPath[MAX_PATH] << endl;

	STARTUPINFO si = { sizeof(si) };	// STARTUPINFO指定窗口特性 应用程序必须将cb初始化为sizeof(STARTUPINFO)
	PROCESS_INFORMATION pi;	//PROCESS_INFORMATION结构存储线程的相关信息

	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = TRUE;
	BOOL bRet = ::CreateProcess(NULL, proPath, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
	//创建进程

	p_id = pi.dwProcessId;
	//printf("进程id： %d\n",pi.dwProcessId);

	seek_name(p_id); //存储进程名及线程数
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

	hProcess = ::OpenProcess(PROCESS_TERMINATE, FALSE, pe.th32ProcessID); //根据进程ID返回对象句柄
	::TerminateProcess(hProcess, 0);  //根据对象句柄结束进程
	CloseHandle(hSnapshot);	//关闭句柄
	CloseHandle(hProcess);
	return;
}

void process::seek_name(unsigned long int id) {

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
			if (pe.th32ProcessID == id)
			{
				printf("%ls----%d\n", pe.szExeFile, pe.th32ProcessID);	//test
				break;
			}

			pe.dwSize = sizeof(PROCESSENTRY32);
			printf("%ls----%d\n", pe.szExeFile, pe.th32ProcessID);	//test
		} while (Process32Next(hSnapshot, &pe));

	}

	wcscpy_s(p_name, pe.szExeFile);	//存储进程名
	p_threadid = pe.cntThreads;		//存储线程数
}

// wchar 转 std::string
void process::Wchar_tToString(std::string& szDst, wchar_t* wchar)
{
	wchar_t* wText = wchar;
	DWORD dwNum = WideCharToMultiByte(CP_OEMCP, NULL, wText, -1, NULL, 0, NULL, FALSE);// WideCharToMultiByte的运用
	char* psText; // psText为char*的临时数组，作为赋值给std::string的中间变量
	psText = new char[dwNum];
	WideCharToMultiByte(CP_OEMCP, NULL, wText, -1, psText, dwNum, NULL, FALSE);// WideCharToMultiByte的再次运用
	szDst = psText;// std::string赋值
	delete[]psText;// psText的清除
}

//std::string 转 wchar
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

//System::String 转 std::string
void ConvertToString(System::String^ str, std::string& text)
{
	char* p = (char*)(int)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str);
	text = p;
	System::Runtime::InteropServices::Marshal::FreeHGlobal((System::IntPtr)p);
}