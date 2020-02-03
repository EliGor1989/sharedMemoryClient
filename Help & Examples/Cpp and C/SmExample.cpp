// SmExample.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>

/* Library use on 32-bit systems:
 * If you want to use a dll with calling convention of type stdcall,
 * you must add WINAPI in all functions, example:
 * typedef int (WINAPI *FN1PTR) (char *, int);
 *
 * If you want to use a dll with calling convention of type fastcall, 
 * you must add __fastcall in all functions, example:
 * typedef int(__fastcall *FN1PTR)(char *, int);
 *
 * For the calling convention of type cdecl it is not necessary to add anything 
 * since it is the default calling convention in programming language C and C ++
 * 
 * To use the library on 64-bit systems it is not necessary to add anything
*/


typedef int(*FN1PTR)(char *, int); // We create a new structure that will point to the following functions:
								   // int openMemory(char *memoryName, int typeCode);
								   // int getInt(char *memoryName, int valuePosition);

typedef void(*FNWINTPTR)(char *, int, int); // We create a new structure that will point to the following functions:
										    // void setInt(char *memoryName, int valuePosition,int dValue);

typedef void(*FNWFLOATPTR)(char *, int, float); // We create a new structure that will point to the following functions:
												// void setFloat(char *memoryName, int valuePosition, float fValue);

typedef float(*FNRFLOATPTR)(char *, int);   // We create a new structure that will point to the following functions:
											// float getFloat(char *memoryName, int valuePosition);

typedef void(*FNWDOUBLEPTR)(char *, int, double); // We create a new structure that will point to the following functions:
												  // void setDouble(char *memoryName, int valuePosition, double lfValue);

typedef double(*FNRDOUBLEPTR)(char *, int); // We create a new structure that will point to the following functions:
											// double getDouble(char *memoryName, int valuePosition);

typedef void(*FNRWSTRINGPTR)(char *, int, char *); // We create a new structure that will point to the following functions:
												   // void setString(char *memoryName, int valuePosition, char *strValue);
												   // void getString(char *memoryName, int valuePosition, char *strRetValue);

typedef int(*FNCMEMPTR)(char *, int, int); // We create a new structure that will point to the following functions:
										   // int createMemory(char *memoryName, int quantity, int typeCode);

typedef void(*FNFREEMPTR)(void); // We create a new structure that will point to the following functions:
								 // void freeMemories();
								 // void freeViews();


/*
 * Use this path if the dll is 32 bits and is located in the 'System32' folder on a 64-bit system,
 * const string dllPath = "C:\\Windows\\SysNative\\smClient.dll";
*/

//static HINSTANCE hInst = LoadLibrary(L"C:\\Windows\\SysNative\\smClient.dll");

static HINSTANCE hInst = LoadLibrary(L"smClient64.dll");

/*
 * Pointers that we will use to call each function found in the library
*/
FN1PTR fnOpenMemory;
FNWINTPTR fnWriteInt;
FN1PTR fnReadInt;
FNWFLOATPTR fnWriteFloat;
FNRFLOATPTR fnReadFloat;
FNWDOUBLEPTR fnWriteDouble;
FNRDOUBLEPTR fnReadDouble;
FNRWSTRINGPTR fnWriteString;
FNRWSTRINGPTR fnReadString;
FNCMEMPTR fnCreateMem;
FNFREEMPTR fnFreeMem;
FNFREEMPTR fnFreeViews;


int main()
{
	// We check if the dll was found and loaded correctly
	if (!hInst) {
		std::cout << "Unable to load library";
		return EXIT_FAILURE;
	}

	/*
	 * Import of the library according to your calling convention
	 * You can find all the names of the functions corresponding to
	 * the calling conventions Cdecl, StdCall and FastCall in the file 'conventions.pdf'
	 */
	
	//fnOpenMemory = (FN1PTR)GetProcAddress(hInst, "openMemory@8");  // Function name in stdcall calling convention type
	//fnOpenMemory = (FN1PTR)GetProcAddress(hInst, "@openMemory@8"); // Function name in fastcall calling convention type 
	fnOpenMemory = (FN1PTR)GetProcAddress(hInst, "openMemory"); // For 64 Bits system and cdecl calling convention type
	/*
	 * The following conditional can be used to check if any function 
	 * could not be accessed correctly
	*/	
	if (!fnOpenMemory) {
		std::cout << "Cannot find the function Open shared memory";
		return EXIT_FAILURE;
	}
	
	fnWriteInt = (FNWINTPTR)GetProcAddress(hInst, "setInt"); // Funcion name for:
															 // stdcall : setInt@12
															 // fastcall: @setInt@12

	fnReadInt = (FN1PTR)GetProcAddress(hInst, "getInt");     // Funcion name for:
															 // stdcall : getInt@8
															 // fastcall: @getInt@8

	fnWriteFloat = (FNWFLOATPTR)GetProcAddress(hInst, "setFloat"); // Funcion name for:
																   // stdcall : setFloat@12
																   // fastcall: @setFloat@12

	fnReadFloat = (FNRFLOATPTR)GetProcAddress(hInst, "getFloat");  // Funcion name for:
																   // stdcall : getFloat@8
																   // fastcall: @getFloat@8

	fnWriteDouble = (FNWDOUBLEPTR)GetProcAddress(hInst, "setDouble"); // Funcion name for:
																	  // stdcall : setDouble@16
																	  // fastcall: @setDouble@16

	fnReadDouble = (FNRDOUBLEPTR)GetProcAddress(hInst, "getDouble"); // Funcion name for:
																	 // stdcall : getDouble@8
																	 // fastcall: @getDouble@8

	fnWriteString = (FNRWSTRINGPTR)GetProcAddress(hInst, "setString"); // Funcion name for:
																	   // stdcall : setString@12
																	   // fastcall: @setString@12

	fnReadString = (FNRWSTRINGPTR)GetProcAddress(hInst, "getString"); // Funcion name for:
																	  // stdcall : getString@12
																	  // fastcall: @getString@12

	fnCreateMem = (FNCMEMPTR)GetProcAddress(hInst, "createMemory");  // Funcion name for:
																	 // stdcall : createMemory@12
																	 // fastcall: @createMemory@12

	fnFreeMem = (FNFREEMPTR)GetProcAddress(hInst, "freeMemories");   // Funcion name for:
																	 // stdcall : freeMemories@0
																	 // fastcall: @freeMemories@0

	fnFreeViews = (FNFREEMPTR)GetProcAddress(hInst, "freeViews");   // Funcion name for:
																	// stdcall : freeViews@0
																	// fastcall: @freeViews@0
	
		/////////////////////////////////////// Access integer shared memory //////////////////////

		char intMemory[10] = "Memory0";				// Name of shared memory to open
		int retOpenInt = fnOpenMemory(intMemory, 1);  // Memory Type: 1 means integer values

		// In the integer memory that we have opened, we will store the value 1542 in the position 2 of the memory
		fnWriteInt(intMemory, 2, 1542);

		// In the memory that we have opened, we will read the value stored in position 2
		int intValue = fnReadInt(intMemory, 0);

		std::cout << "Int value = " << intValue << "\nPress key to continue\n";
		getchar();

		/////////////////////////////////////// Access float shared memory /////////////////////

		char floatMemory[10] = "Memory1";				   // Name of shared memory to open
		int retOpenFloat = fnOpenMemory(floatMemory, 2); // Memory Type: 2 means float values

		// In the float memory that we have opened, we will store the value 12.1231 in 
		// the position 4 of the memory
		fnWriteFloat(floatMemory, 4, (float)12.1231);

		// In the memory that we have opened, we will read the float value stored in position 4
		float valorFloat = fnReadFloat(floatMemory, 4);

		std::cout << "Float value = " << valorFloat << "\nPress key to continue\n";
		getchar();

		/////////////////////////////////// Access Double shared memory //////////////////////////

		char doubleMemory[10] = "Memory2";				 // Name of shared memory to open
		int retOpenDouble = fnOpenMemory(doubleMemory, 3); // Memory Type: 3 means double values

		// In the double memory that we have opened, we will store the value -1.123123423 in 
		// the position 1 of the memory
		fnWriteDouble(doubleMemory, 1, (double)-1.123123423);

		// In the memory that we have opened, we will read the double value stored in position 1
		double doubleValue = fnReadDouble(doubleMemory, 1);
		std::cout << std::setprecision(9) << std::fixed;     // This line configures an output with more decimals
		std::cout << "Double value = " << doubleValue << "\nPress key to continue\n";
		getchar();

		////////////////////////////// Access String shared memory ///////////////////////////////

		char stringMemory[10] = "Memory3";	// Name of shared memory to open
		char message[13] = "Hello world!";				// Message to be stored
		int resAbrirString = fnOpenMemory(stringMemory, 4); // Memory Type: 4 means String values

		// In the string memory that we have opened, we will store the message "Hello world!"  in 
		// the position 3 of the memory
	    fnWriteString(stringMemory, 3, message);

		// In the memory that we have opened, we will read the string value stored in position 3
		char stringValue[13];		
		fnReadString(stringMemory, 3, stringValue);

		std::cout << "valor string = " << stringValue << "\nPress key to continue\n";
		getchar();

		fnFreeViews(); // Free the nodes used for both the excess memories and the view nodes.
	
	/////////////////////////////////////// Memory Administration ///////////////////////////////////////////////
	/*
	 * If the user wishes to manage the creation, management and deletion of shared memories instead 
	 * of using the administration panel, he can use the following functions
	/*
		char namMemory1[10] = "myMemory1";
		int retCreateMem = fnCreateMem(namMemory1, 10, 1); // memory name, number of spaces, type of memory (integer)

		char namMemory2[10] = "myMemory2";
		int retCreateMem2 = fnCreateMem(namMemory2, 7, 2); // memory name, number of spaces, type of memory (float)

		char namMemory3[10] = "myMemory1";
		int retCreateMem3 = fnCreateMem(namMemory3, 5, 3); // memory name, number of spaces, type of memory (double)

		fnFreeMem(); // When memory spaces are managed, at the end of using the memories they should be released.

	*/
}