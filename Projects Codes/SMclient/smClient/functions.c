/* Creation, management and access to named shared memories
 * 
 * Description: 
 * The following functions help to:
 * 1) CREATE each of the memories required by the user.
 * 2) ACCESS to reading and writing in the memories created
 * The sequence of the use of named shared memories is:
 * createMemory(s) -> read/write -> freeMemories()
 * 
 * 
 * Purpose of this file: 
 * A separate function file is made due to centralization.
 * This function file will then be used both for the creation 
 * of a dynamic link libraries with standard headers and for 
 * the creation of dynamic link libraries compatible with 
 * applications which use Java programming language.
 * In the same way by having separate functions, 
 * the files can be imported and used in other desired projects.
 * */


#include "functions.h"
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <tchar.h>

#define CHARACTER_LIMIT 13 //specifies the character limit to be stored 
				//in the character string type memories


//This structure contains each created named shared memory
struct memoryNode{
	HANDLE memoryHandle; 	//A handle to the file from which to create 
							// a file mapping object.
	struct memoryNode *pNextMemoryNode; 
};


//this structure will save access to a mapped object in memory
struct mappingNode{
    HANDLE mapHandle;          // handle to the specified file mapping 
								// object.
    struct mappingNode *pNextMapNode; 
};

// This structure will save the Maps views of a file mapping into the 
// address space of a calling process.
struct viewNode{
    void *pViewHandle;  //is the starting address of the mapped view
    char viewName[13];  //The name of the Named Shared Memory
    struct viewNode *pNextView;
};

// In programming language C we do not have a defined string variable type, 
// so we create a new type of variable to store character strings
typedef struct  strValues{
	char variable[CHARACTER_LIMIT];  //In this variable the character 
									// string is stored
} myStr_t; //The name of the new type of variables will be myStr_t


// To manage the creation of new dynamically named shared memories, 
// a stack concept is used, each new shared memory created will be 
// added to the top.
struct memoryNode *pTopMemNode = NULL;

// To manage the creation of new nodes which mapped to an object 
// in memory, a stack concept is used, each new mapped structure 
// will be added to the top.
struct mappingNode *pTopMapNode = NULL;


// To manage the creation of new nodes which maps view of a file
// mapping into the address space, a stack concept is used, 
// each new view structure will be added to the top.
struct viewNode *pTopViewNode = NULL;



/* Open an object mapped in memory and at the same time create a view 
 * of it to allow reading and writing in shared memories
 * 
 * In order to access a memory it is necessary to map the object (the memory) 
 * in a HANDLE variable and then create a view towards the memory to be able 
 * to read and write values
 * 
 * For this, two new nodes are managed, one mappingNode type that allows the 
 * mapping of the object in memory and a viewNode type node to create the 
 * view for data manipulation in memory, after managing these two objects, 
 * they are added to their corresponding stacks .
 */
int open_Memory(char *memoryName, int typeCode){
    struct mappingNode *pNewMapNode; // this variable will use for mapping 
									 // an object object in memory
	
    struct viewNode *pNewViewNode;   //this variable will use to create the
									// view for data manipulation in memory

	//Memory management for the new variable
    pNewMapNode = (struct mappingNode *)malloc(sizeof(struct mappingNode));
	
	//Here we open a file mapped in memory, more information in this link:
	//https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-openfilemapping
    pNewMapNode->mapHandle = OpenFileMapping(
								FILE_MAP_ALL_ACCESS, //we give access in 
													 //read and write mode
								FALSE,  // It does not allow inheriting 
										// the name
								_T(memoryName));  //Name of the mapped object

	// Error control, if NULL value was returned it is because the memory 
	// could not be mapped
    if(pNewMapNode->mapHandle == NULL){ 
        return 1; //Error found
    }
	
	// We add the new node to the top of the stack
	pNewMapNode->pNextMapNode = pTopMapNode; 
    pTopMapNode = pNewMapNode;
	
	/************* Create a new view to the mapped object *****************/
	// We manage the memory for our new variable of type viewNode
	pNewViewNode = (struct viewNode *)malloc(sizeof(struct viewNode)); 
	
	// We save the name of the named shared memory
	strcpy(pNewViewNode->viewName,memoryName);
				
	// Here we will Map a view of a file mapping into the address space of 
	// a calling process. More information in this link:
	//https://docs.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffile
    switch(typeCode){
        case 1:
                pNewViewNode->pViewHandle = (int *)MapViewOfFile(pNewMapNode->mapHandle,
                                     FILE_MAP_ALL_ACCESS, 
                                     0,
                                     0,
                                     0);
                break;
        case 2:
                pNewViewNode->pViewHandle = (float *)MapViewOfFile(pNewMapNode->mapHandle,
                                     FILE_MAP_ALL_ACCESS,
                                     0,
                                     0,
                                     0);
                break;
        case 3:
                pNewViewNode->pViewHandle = (double *)MapViewOfFile(pNewMapNode->mapHandle,
                                     FILE_MAP_ALL_ACCESS,
                                     0,
                                     0,
                                     0);
                break;

		case 4:
                pNewViewNode->pViewHandle = (myStr_t *)MapViewOfFile(pNewMapNode->mapHandle,
                                     FILE_MAP_ALL_ACCESS,
                                     0,
                                     0,
                                     0);
                break;

    }

	//Error control: Returns NULL if it could not map the object
	if(pNewViewNode->pViewHandle == NULL){
		return 1;
	}
	
	// We add the new view node to the top of the stack
	pNewViewNode->pNextView = pTopViewNode;
	pTopViewNode = pNewViewNode;

    return 0; //If everything was executed correctly, 0 is returned
}


int get_Int(char *memoryName, int valuePosition){
    struct viewNode *pTmpViewNode; //Temporal variable that points 
									// to the top of the view stack
    pTmpViewNode = pTopViewNode;
	
    int dRetValue=0; //to save the value stored in shared memory
	
	//Cycle that runs through the entire stack of views
    while(pTmpViewNode != NULL){
		//Find the view that contains the desired shared memory name.
        if(strcmp(pTmpViewNode->viewName,memoryName)==0){
			// If the shared memory is found, the value stored in the 
			// position (valuePosition) is retrieved
            dRetValue = *( (int *)pTmpViewNode->pViewHandle + valuePosition);
            break;
        }
		//While the name of the desired named shared memory is not found, 
		//continue runs through the stack
		pTmpViewNode = pTmpViewNode->pNextView;
   }
    return dRetValue;
}


void set_Int(char *memoryName, int valuePosition,int dValue){
    struct viewNode *pTmpViewNode;//Temporal variable that points 
									// to the top of the view stack
    pTmpViewNode = pTopViewNode;
	
	//Cycle that runs through the entire stack of views
    while(pTmpViewNode != NULL){
		//Find the view that contains the desired shared memory name.
        if(strcmp(pTmpViewNode->viewName,memoryName)==0){
			// If the shared memory is found, the value stored in (dValue)
			// is saved in position (valuePosition).
            *( (int *)pTmpViewNode->pViewHandle + valuePosition) = dValue;
            break;
        }
		//While the name of the desired named shared memory is not found, 
		//continue runs through the stack
		pTmpViewNode = pTmpViewNode->pNextView;
	}
}

void set_Float(char *memoryName, int valuePosition, float fValue){
    struct viewNode *pTmpViewNode; //Temporal variable that points 
									// to the top of the view stack
    pTmpViewNode = pTopViewNode;
	
	//Cycle that runs through the entire stack of views
    while(pTmpViewNode != NULL){
		//Find the view that contains the desired shared memory name.
        if(strcmp(pTmpViewNode->viewName,memoryName)==0){
			// If the shared memory is found, the value stored (fValue)
			// is saved in the position (valuePosition)
            *( (float *)pTmpViewNode->pViewHandle + valuePosition) = fValue;
            break;
        }
		//While the name of the desired named shared memory is not found, 
		//continue runs through the stack
		pTmpViewNode = pTmpViewNode->pNextView;
	}
}

float get_Float(char *memoryName, int valuePosition){
    struct viewNode *pTmpViewNode;//Temporal variable that points 
									// to the top of the view stack
    pTmpViewNode = pTopViewNode;
    float fValue=0.0;
	
	//Cycle that runs through the entire stack of views
    while(pTmpViewNode != NULL){
		//Find the view that contains the desired shared memory name.
        if(strcmp(pTmpViewNode->viewName,memoryName)==0){
			// If the shared memory is found, the value stored in the 
			// position (valuePosition) is retrieved
            fValue = *( (float *)pTmpViewNode->pViewHandle + valuePosition);
            break;
        }
		//While the name of the desired named shared memory is not found, 
		//continue runs through the stack
		pTmpViewNode = pTmpViewNode->pNextView;
	}
    return fValue;
}

void set_Double(char *memoryName, int valuePosition, double lfValue){
    struct viewNode *pTmpViewNode;//Temporal variable that points 
									// to the top of the view stack
    pTmpViewNode = pTopViewNode;
	
	//Cycle that runs through the entire stack of views
    while(pTmpViewNode != NULL){
		//Find the view that contains the desired shared memory name.
        if(strcmp(pTmpViewNode->viewName,memoryName)==0){
			// If the shared memory is found, the value stored in (lfValue) 
			// is saved in the position (valuePosition)
            *( (double *)pTmpViewNode->pViewHandle + valuePosition) = lfValue;
            break;
        }
		//While the name of the desired named shared memory is not found, 
		//continue runs through the stack
		pTmpViewNode = pTmpViewNode->pNextView;
	}
}

double get_Double(char *memoryName, int valuePosition){
    struct viewNode *pTmpViewNode;//Temporal variable that points 
									// to the top of the view stack
    pTmpViewNode = pTopViewNode;
    double lfValue=0.0;
	
	//Cycle that runs through the entire stack of views
    while(pTmpViewNode != NULL){
		//Find the view that contains the desired shared memory name.
        if(strcmp(pTmpViewNode->viewName,memoryName)==0){
			// If the shared memory is found, the value stored in the 
			// position (valuePosition) is retrieved
            lfValue = *( (double *)pTmpViewNode->pViewHandle + valuePosition);
            break;
        }
		//While the name of the desired named shared memory is not found, 
		//continue runs through the stack
		pTmpViewNode = pTmpViewNode->pNextView;
	}
    return lfValue;
}

void set_String(char *memoryName, int valuePosition, char *strValue){
    struct viewNode *pTmpViewNode;//Temporal variable that points 
									// to the top of the view stack
    pTmpViewNode = pTopViewNode;
	myStr_t tmp;
	
	//Cycle that runs through the entire stack of views
    while(pTmpViewNode != NULL){
		//Find the view that contains the desired shared memory name.
        if(strcmp(pTmpViewNode->viewName,memoryName)==0){
			// If the shared memory is found, the value stored in (strValue)
			// is saved in the position (valuePosition)
			strcpy(tmp.variable,strValue);
			*( (myStr_t *)pTmpViewNode->pViewHandle + valuePosition) = tmp;
            break;
        }
		//While the name of the desired named shared memory is not found, 
		//continue runs through the stack
		pTmpViewNode = pTmpViewNode->pNextView;
	}
}

void get_String(char *memoryName, int valuePosition, char *strRetValue){
    struct viewNode *pTmpViewNode;//Temporal variable that points 
									// to the top of the view stack
    pTmpViewNode = pTopViewNode;
	myStr_t strValue;	
	
	//Cycle that runs through the entire stack of views
    while(pTmpViewNode != NULL){
		//Find the view that contains the desired shared memory name.
        if(strcmp(pTmpViewNode->viewName,memoryName)==0){
			// If the shared memory is found, the value stored in the 
			// position (valuePosition) is stord in the variable
			// (strRetValue)
			strValue = *( (myStr_t *)pTmpViewNode->pViewHandle + valuePosition);
            strcpy(strRetValue,strValue.variable);
            break;
        }
		//While the name of the desired named shared memory is not found, 
		//continue runs through the stack
		pTmpViewNode = pTmpViewNode->pNextView;
   }
}


void get_String_Matlab(char *memoryName, int valuePosition, char **strRetValue){
    struct viewNode *pTmpViewNode;//Temporal variable that points 
									// to the top of the view stack
    pTmpViewNode = pTopViewNode;
	myStr_t strValue;
	
	//Cycle that runs through the entire stack of views
    while(pTmpViewNode != NULL){
		//Find the view that contains the desired shared memory name.
        if(strcmp(pTmpViewNode->viewName,memoryName)==0){
			// If the shared memory is found, the value stored in the 
			// position (valuePosition) is stord in the variable
			// (strRetValue)
            strValue = *( (myStr_t *)pTmpViewNode->pViewHandle + valuePosition);
            *strRetValue = strdup(strValue.variable);
            break;
        }
		//While the name of the desired named shared memory is not found, 
		//continue runs through the stack
		pTmpViewNode = pTmpViewNode->pNextView;
	}
}


/* This function manages the space required by each Memory. Example
 * The "Memory0" will contain 5 Integer-type values, so it is necessary to 
 * manage a space in memory called "Memory0" and that it can contain 5 
 * Integer-type values.
 * When working with dynamic memory, it is necessary to manage the pointers
 * 
 * To achieve this, we need the global access name to be assigned 
 * to the Memory is used, the amount of values that will be stored and 
 * the type of value to be stored.
 */
int create_Memory(char *memoryName, int quantity, int typeCode){
        int typeSize; // It will contain the required size depending 
					// on the type of variable
        switch(typeCode){
                case 1:
                        typeSize = sizeof(int); 
                        break;
                case 2:
                        typeSize = sizeof(float); 
                        break;
                case 3:
                        typeSize = sizeof(double);
                        break;
                case 4:
                        typeSize = sizeof(myStr_t); // type char is 1 byte 
											//but to store complete words we 
											// multiply it by the number of 
											// characters that we have 
											// specified in CHARACTER_LIMIT
                        break;
						
        }
		
		
		struct memoryNode *pNewMemoryNode = (struct memoryNode *)malloc(sizeof(struct memoryNode));
		// create a named shared memory, it is a mapped files that the 
		// system paging file stores. Official link:
		//https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-createfilemappinga
        pNewMemoryNode->memoryHandle = CreateFileMapping(INVALID_HANDLE_VALUE,
                                      NULL, // default security
                                      0x04, // Memory views can read and write
                                      0,    // max. object size
                                      typeSize * quantity, // buffer size
                                      _T(memoryName)); // Name of the mapped object

        
		//If the new shared memory cannot be managed, the value 1 is returned
		if(pNewMemoryNode->memoryHandle == NULL){ 
                return 1;
        }

		// We add the new node with the named shared memory 
		// at the top of the stack
		pNewMemoryNode->pNextMemoryNode = pTopMemNode;
		pTopMemNode = pNewMemoryNode;
		
		//If everything runs correctly, 0 is returned
        return 0;
}


// When we manage memory to be used, we must also free the memory 
// space when we finish working. The following function frees up 
// the space of all shared memories created.
void free_Memories(){
	struct memoryNode *pNextMemory;
	
	while(pTopMemNode != NULL){
		pNextMemory = pTopMemNode->pNextMemoryNode;
		CloseHandle(pTopMemNode->memoryHandle);
		free(pTopMemNode);
		pTopMemNode = pNextMemory;
	}
}


// To be able to access the shared memories we create nodes to map 
// the objects and nodes that will contain the views of the shared memories. 
// When we finish using these objects we must release them.
// The following function releases both the object mapping stack and the 
// named shared memory view stack.
void free_Views(){
	struct viewNode *pNextViewNode;
	
	struct mappingNode *pNextMapNode;
	
	while(pTopViewNode != NULL){
		pNextViewNode = pTopViewNode->pNextView;
		UnmapViewOfFile(pTopViewNode->pViewHandle);
		free(pTopViewNode);
		pTopViewNode = pNextViewNode;
	}
	
	while(pTopMapNode != NULL){
		pNextMapNode = pTopMapNode->pNextMapNode;
		CloseHandle(pTopMapNode->mapHandle);
		free(pTopMapNode);
		pTopMapNode = pNextMapNode;
	}

}