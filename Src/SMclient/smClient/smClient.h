#ifndef SMCLIENT_H
#define SMCLIENT_H
#define EXPORT __declspec(dllexport)

// #define CONVENTION __fastcall
// #define CONVENTION __cdecl
#define CONVENTION __stdcall

EXPORT int CONVENTION  openMemory
  (char *memoryName, int typeCode);

EXPORT int CONVENTION  getInt
  (char *memoryName, int valuePosition);
  
EXPORT void CONVENTION  setInt
  (char *memoryName, int valuePosition,int dValue);
  
EXPORT void CONVENTION  setFloat
  (char *memoryName, int valuePosition, float fValue);
  
EXPORT float CONVENTION  getFloat
  (char *memoryName, int valuePosition);
  
EXPORT void CONVENTION  setDouble
  (char *memoryName, int valuePosition, double lfValue);
  
EXPORT double CONVENTION  getDouble
  (char *memoryName, int valuePosition);
  
EXPORT void CONVENTION  setString
  (char *memoryName, int valuePosition, char *strValue);
  
EXPORT void CONVENTION  getString
  (char *memoryName, int valuePosition, char *strRetValue);
  
EXPORT void CONVENTION  getStringMatlab
  (char *memoryName, int valuePosition, char **strRetValue);
  

EXPORT int CONVENTION  createMemory
  (char *memoryName, int quantity, int typeCode);
  
EXPORT void CONVENTION  freeMemories();

EXPORT void CONVENTION  freeViews();

#endif