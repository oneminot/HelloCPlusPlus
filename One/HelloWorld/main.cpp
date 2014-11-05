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
			const double firstVariable = (double)3.0;
			const double secondVariable = (double)4.0;
			uReturnVal = pcci();
		}
	}
	return 0;
}