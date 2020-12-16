#include "pch.h"

#include <iostream>
#include <string>
#include <windows.h>


#pragma comment (lib, "winmm.lib")
#define MACR_STRNCPY(x) strncpy_s(output,outputSize,x,_TRUNCATE)

using namespace std;
const std::string version = "cmd extension for arma";

extern "C"
{
	__declspec (dllexport) void __stdcall RVExtensionVersion(char* output, int outputSize);
	__declspec (dllexport) void __stdcall RVExtension(char* output, int outputSize, const char* function);
}

void __stdcall
RVExtension(char* output, int outputsize, const char* function)
{
	setlocale(LC_ALL, "russian");
	std::string fnc = function;
	system(fnc.c_str());
};

void __stdcall
RVExtensionVersion(char* output, int outputSize)
{
	MACR_STRNCPY(version.c_str());
};
