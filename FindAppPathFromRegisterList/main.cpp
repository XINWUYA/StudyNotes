#include <iostream>
#include <Windows.h>

#define BUFFER_SIZE 256

int main()
{
	HKEY ThisHKey;
	TCHAR ProductType[BUFFER_SIZE];
	memset(ProductType, 0, sizeof(ProductType));
	DWORD BufferLength = BUFFER_SIZE;
	char AppPath[BUFFER_SIZE];

	if (RegOpenKeyEx(HKEY_CURRENT_USER, TEXT("SOFTWARE\\Tencent\\WeChat"), 0, KEY_QUERY_VALUE, &ThisHKey) != ERROR_SUCCESS)
	{
		MessageBox(GetForegroundWindow(), TEXT("注册表打开失败！"), TEXT("错误"), MB_ICONEXCLAMATION);
		return 1;
	}

	if (RegQueryValueEx(ThisHKey, TEXT("InstallPath"), NULL, NULL, (LPBYTE)ProductType, &BufferLength) != ERROR_SUCCESS)
	{
		MessageBox(GetForegroundWindow(), TEXT("注册表找不到该路径！"), TEXT("错误"), MB_ICONEXCLAMATION);
		return 1;
	}

	RegCloseKey(ThisHKey);

	WideCharToMultiByte(CP_ACP, 0, ProductType, -1, AppPath, sizeof(AppPath), NULL, NULL);
	strcat_s(AppPath, "\\WeChat.exe");
	std::cout << AppPath << std::endl;
	WinExec(AppPath, SW_SHOW);
	//return 0;
}