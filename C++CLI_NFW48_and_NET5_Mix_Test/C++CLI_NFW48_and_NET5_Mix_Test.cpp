// C++CLI_NFW48_and_NET5_Mix_Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <exception>
#include "windows.h"
#include "ClassLibrary_NET5_Interop.h"
#include "ClassLibrary_NFW48_Interop.h"


typedef void(*GetUsersFunction)();

int main()
{
    HMODULE hLib = LoadLibrary("ClassLibrary_NFW48_Interop.dll");
	if (hLib)
	{
		GetUsersFunction GetUsersFunc = (GetUsersFunction)GetProcAddress(hLib, "GetAllUsers");
		if (GetUsersFunc)
		{
			GetUsersFunc();
		}
		FreeLibrary(hLib);
	}
	

	hLib = LoadLibrary("ClassLibrary_NET5_Interop.dll");
	if (hLib)
	{
		GetUsersFunction GetUsersFunc = (GetUsersFunction)GetProcAddress(hLib, "GetAllUsers");
		if (GetUsersFunc)
		{
			try
			{
				GetUsersFunc();
			}
			catch (const std::exception&)
			{

			}			
		}
		FreeLibrary(hLib);
	}
}
