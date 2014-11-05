#include <Windows.h>
int main()
{
	typedef UINT(CALLBACK* LPFNDLLFUNC1)(DWORD, UINT);
	HINSTANCE hDLL;               // Handle to DLL
	LPFNDLLFUNC1 lpfnDllFunc1;    // Function pointer
	DWORD dwParam1;
	UINT  uParam2, uReturnVal;
	LPCWSTR file = L"HelloWorldDll";

	hDLL = LoadLibrary(file);
	if (hDLL != NULL)
	{
		lpfnDllFunc1 = (LPFNDLLFUNC1)GetProcAddress(hDLL,
			"Add");
		if (!lpfnDllFunc1)
		{
			// handle the error
			FreeLibrary(hDLL);
			return ERROR_CALL_NOT_IMPLEMENTED;
		}
		else
		{
			// call the function
			uReturnVal = lpfnDllFunc1(2, 3);
		}
	}
	return 0;
}