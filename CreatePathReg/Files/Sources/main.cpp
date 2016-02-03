#define _X86_

#include <stdio.h>
#include <iostream>
#include <Winreg.h>

#include <tchar.h>
#include <windows.h>

#pragma comment (lib, "Advapi32.lib")


LONG GetStringRegKey(HKEY hKey, const std::wstring &strValueName, std::wstring &strValue, const std::wstring &strDefaultValue);
LONG GetDWORDRegKey(HKEY hKey, const std::wstring &strValueName, DWORD &nValue, DWORD nDefaultValue);
LONG GetBoolRegKey(HKEY hKey, const std::wstring &strValueName, bool &bValue, bool bDefaultValue);

#define BUFSIZE MAX_PATH
#define RESPONSE_32_BIT "32"
#define RESPONSE_64_BIT "64"

typedef BOOL(WINAPI *IW64PFP)(HANDLE, BOOL *);

int main()
{
	HKEY hKey;
	printf("Let set the key to the registry for dll path");
	DWORD dwDisposition;
	RegCreateKeyEx(HKEY_LOCAL_MACHINE,
		TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\Muse.exe"),
		0, NULL, 0,
		KEY_WRITE, NULL,
		&hKey, &dwDisposition);
	
		printf("create key");
		TCHAR Buffer[BUFSIZE];
		DWORD dwRet;
		dwRet = GetCurrentDirectory(BUFSIZE, Buffer);

		typedef std::basic_string<TCHAR> tstring;

		tstring value = tstring(Buffer) + tstring(L"\\libs");

		if (RegSetValueEx(hKey, _T("path"), 0, REG_SZ,
			(const BYTE *)value.c_str(), sizeof(TCHAR) * (_tcslen(value.c_str()) + 1)) != ERROR_SUCCESS) {
			printf("set value failed!\n");
		}
		else
		{
			printf("CurrentDir : %s", Buffer);
			printf("set value succeeded!\n");
		}
	
	
	std::getchar();
}


LONG GetDWORDRegKey(HKEY hKey, const std::wstring &strValueName, DWORD &nValue, DWORD nDefaultValue)
{
	nValue = nDefaultValue;
	DWORD dwBufferSize(sizeof(DWORD));
	DWORD nResult(0);
	LONG nError = ::RegQueryValueExW(hKey,
		strValueName.c_str(),
		0,
		NULL,
		reinterpret_cast<LPBYTE>(&nResult),
		&dwBufferSize);
	if (ERROR_SUCCESS == nError)
	{
		nValue = nResult;
	}
	return nError;
}


LONG GetBoolRegKey(HKEY hKey, const std::wstring &strValueName, bool &bValue, bool bDefaultValue)
{
	DWORD nDefValue((bDefaultValue) ? 1 : 0);
	DWORD nResult(nDefValue);
	LONG nError = GetDWORDRegKey(hKey, strValueName.c_str(), nResult, nDefValue);
	if (ERROR_SUCCESS == nError)
	{
		bValue = (nResult != 0) ? true : false;
	}
	return nError;
}


LONG GetStringRegKey(HKEY hKey, const std::wstring &strValueName, std::wstring &strValue, const std::wstring &strDefaultValue)
{
	strValue = strDefaultValue;
	WCHAR szBuffer[512];
	DWORD dwBufferSize = sizeof(szBuffer);
	ULONG nError;
	nError = RegQueryValueExW(hKey, strValueName.c_str(), 0, NULL, (LPBYTE)szBuffer, &dwBufferSize);
	if (ERROR_SUCCESS == nError)
	{
		strValue = szBuffer;
	}
	return nError;
}