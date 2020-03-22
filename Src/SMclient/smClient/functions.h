#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// FUNCTION NAME: 
//		open_Memory
// DESCIPTION: 
//		this function opens a memory with a specific name (memoryName) 
// 		and a specified type (typeCode): 
// PARAMETERS: 
//		memoryName : We specify the name of the memory we wish to open
//		typeCode   : We specify the code of the type of memory we 
//					 want to open, it can be:
// 						1 = Integer
// 						2 = Float
// 						3 = Double
// 						4 = String (max 13 character), you can change 
//							this limit in the implementation code.
// RETURN:
//		0 = If it runs correctly
//		1 = if there was an error
int open_Memory(char *memoryName, int typeCode);

// FUNCTION NAME: 
//		get_Int
// DESCIPTION: 
//		This function returns the value stored in position (valuePosition)
//		belonging to memory with the name (memoryName)
// PARAMETERS: 
//		memoryName    : We specify the name of the memory we wish to work with
//		valuePosition : We specify the position we want to read the value
// RETURN:
//		returns the integer value stored in position (valuePosition)
//		belonging to memory with the name (memoryName)
int get_Int(char *memoryName, int valuePosition);

// FUNCTION NAME: 
//		set_Int
// DESCIPTION: 
//		This function stores a value (dValue) in position (valuePosition)
//		belonging to memory with the name (memoryName)
// PARAMETERS: 
//		memoryName    : We specify the name of the memory we wish to work with
//		valuePosition : We specify the position we want to write the value
//		dValue		  : The value that will be stored
// RETURN:
//		0 = If the value was stored
//		1 = if memoryName wasnt found
void set_Int(char *memoryName, int valuePosition,int dValue);

// FUNCTION NAME: 
//		set_Float
// DESCIPTION: 
//		this function has the same behavior as the "set_Int" function, 
//		the only difference is that it stores a float type value.
void set_Float(char *memoryName, int valuePosition, float fValue);

// FUNCTION NAME: 
//		get_Float
// DESCIPTION: 
//		this function has the same behavior as the "get_int" function, 
//		the only difference is that it return a float type value.
float get_Float(char *memoryName, int valuePosition);

// FUNCTION NAME: 
//		set_Double
// DESCIPTION: 
//		this function has the same behavior as the "set_Int" function, 
//		the only difference is that it stores a double type value.
void set_Double(char *memoryName, int valuePosition, double lfValue);

// FUNCTION NAME: 
//		get_Double
// DESCIPTION: 
//		this function has the same behavior as the "get_int" function, 
//		the only difference is that it return a double type value.
double get_Double(char *memoryName, int valuePosition);

// FUNCTION NAME: 
//		set_String
// DESCIPTION: 
//		this function has the same behavior as the "set_Int" function, 
//		the only difference is that it stores a string of characters.
void set_String(char *memoryName, int valuePosition, char *strValue);

// FUNCTION NAME: 
//		get_String
// DESCIPTION: 
//		This function returns the string of characters stored
//		 in position (valuePosition)
//		belonging to memory with the name (memoryName)
// PARAMETERS: 
//		memoryName    : We specify the name of the memory we wish to work with
//		valuePosition : We specify the position we want to read the value
//		strRetValue	  : This pointer will point to the character string stored 
//						in the (valuePosition) position
void get_String(char *memoryName, int valuePosition, char *strRetValue);

// FUNCTION NAME: 
//		get_String_Matlab
// DESCIPTION: 
//		this function has the same behavior as the "get_String" function, 
//		the only difference is that to point to the chain stored 
//		in memory, you need a double pointer
void get_String_Matlab(char *memoryName, int valuePosition, char **strRetValue);

// FUNCTION NAME: 
//		create_Memory
// DESCIPTION: 
//		This function creates a shared memory labeled with the name 
//		specified in (memoryName), which may contain a quantity of values 
//		specified in (quantity), and the values will be of the type 
//		specified in (typeCode)
// PARAMETERS: 
//		memoryName : We specify the name of the memory we want to create
//		quantity   : We specify the maximum amount of values that we can store 
//					 in this memory
//		typeCode   : We specify the code of the type of memory we 
//					 want to create, it can be:
// 						1 = Integer
// 						2 = Float
// 						3 = Double
// 						4 = String (max 13 character), you can change 
//							this limit in the implementation code.
// RETURN:
//		0 = If it runs correctly
//		1 = if there was an error
int create_Memory(char *memoryName, int quantity, int typeCode);

// FUNCTION NAME: 
//		free_Memories
// DESCIPTION: 
//		This function frees managed memory for the creation of 
//		named shared memories.
void free_Memories();

// FUNCTION NAME: 
//		free_Views
// DESCIPTION: 
//		This function frees managed memory for the creation of 
//		views of named shared memories.
void free_Views();

#endif