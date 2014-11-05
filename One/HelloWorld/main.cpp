#include <Windows.h>
int main()
{
	typedef double(CALLBACK* MyAdd)(double, double);
	HINSTANCE hDLL;
	FARPROC pcci;
	//MyAdd Add;
	double uReturnVal;
	LPCWSTR file = L"HelloWorldDll";

	hDLL = LoadLibrary(file);
	if (hDLL != NULL)
	{
		//Add = (MyAdd)GetProcAddress(hDLL, "Subtract");
		pcci = GetProcAddress(hDLL, "kig");
		if (!pcci)
		{
			FreeLibrary(hDLL);
			return E_UNEXPECTED;
		}
		else
		{
			uReturnVal = pcci();
			if (uReturnVal > 0)
			{
				return ERROR_SUCCESS;
			}
		}
	}
      	return 0;
}