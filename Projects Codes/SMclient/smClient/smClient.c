/***
 * Code for dynamic link libraries generation.
 * For more information about functions you can find
 * all about these in:
 * README-Funtions.txt
 * functions.h
 * functions.c
 */

#include "functions.h"
#include "smClient.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <tchar.h>

EXPORT int CONVENTION  openMemory
  (char *memoryName, int typeCode){
    int errorCode = open_Memory(memoryName, typeCode);
    return errorCode;
}

EXPORT int CONVENTION  getInt
  (char *memoryName, int valuePosition){
    int dRetValue = get_Int(memoryName, valuePosition);
    return dRetValue;
}

EXPORT void CONVENTION  setInt
  (char *memoryName, int valuePosition,int dValue){
    set_Int(memoryName,valuePosition,dValue);
}

EXPORT void CONVENTION  setFloat
  (char *memoryName, int valuePosition, float fValue){
    set_Float(memoryName,valuePosition,fValue);

}

EXPORT float CONVENTION  getFloat
  (char *memoryName, int valuePosition){
    float fRetValue = get_Float(memoryName,valuePosition);
    return fRetValue;
}

EXPORT void CONVENTION  setDouble
  (char *memoryName, int valuePosition, double lfValue){
    set_Double(memoryName,valuePosition,lfValue);

}

EXPORT double CONVENTION  getDouble
  (char *memoryName, int valuePosition){
    double lfRetValue = get_Double(memoryName,valuePosition);
    return lfRetValue;
}

EXPORT void CONVENTION setString
  (char *memoryName, int valuePosition, char *strValue){
    set_String(memoryName,valuePosition,strValue);
}

EXPORT void CONVENTION getString
  (char *memoryName, int valuePosition, char *strRetValue){
    get_String(memoryName,valuePosition,strRetValue);

   // *str = strdup("EROSHACK");
}

EXPORT void CONVENTION getStringMatlab
  (char *memoryName, int valuePosition, char **strRetValue){
    get_String_Matlab(memoryName,valuePosition,strRetValue);

}

EXPORT int CONVENTION createMemory
  (char *memoryName, int quantity, int typeCode){
        int retValue = create_Memory(memoryName, quantity, typeCode);
        return retValue;
}
EXPORT void CONVENTION freeMemories(){
        free_Memories();
}

EXPORT void CONVENTION freeViews(){
        free_Views();
}