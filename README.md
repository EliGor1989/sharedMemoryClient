# SharedMemoryClient
**SMClient** is a project that offers dynamic link libraries (.DLL) with functions for creating, reading, writing and releasing virtual memories. 
The use of **Shared Memories is a type of Interprocess Communication (IPC)** that allows several programs to access a memory location making it possible to transfer data between processes and between applications.

# Content
The project is divided into two parts:
Executable files that are ready to be used by the user.
- Admin Panel
- Libraries
- Help & Examples

Source codes that can be studied and modified.
- Projects Codes
	- SMPanel
	- SMClient

# Quick Start
To perform a quick test of operation and use we need:
- The shared memory creation and management panel **(Admin Panel)**
- The dynamic link library with functions **(Libraries)**
- Sample codes in the language or application we want **(Help & Examples)**

#Usage
#### Administration Panel 
Once we have downloaded the necessary folders and files, the first thing is to run the panel for creating shared memories "Admin Panel\smProject.exe", in this administration panel we can perform the following actions:
- Specify the shared memories that we want to create, for which we need to establish: Name of the shared memory, number of values to be stored and the type of value to be stored.
- Create and release the specified shared memories
- View the data that is stored in the shared memories
- Save and load the list of specified memories

For quick use of the examples, you must load the sample memory scheme File-> Open "exampleCreation.sav" and then initialize the Memories-> create memories.

<img src="Images/SMpanel.jpg" width="300" />

#### Client library
The next step is to choose which programming language or application we want to test reading and writing in shared memories, the available examples are:
- C # (Visual Studio Standard and Unity3D)
- C / C ++
- Excel
- Java
- Matlab
- Python
- Visual basic

In all the examples the steps to follow are the same:
1. First we need to ** Load de Dynamic Link Library** (For 32Bits or 64Bits) depends on your application. The library must be in the same place as the executable or it can be in the System32 folder.
2. Then we must **open the shared memory **with which we wish to work by calling the openMemory function, specifying the name of the memory and the type of memory (We open all the memories with which we wish to work).
3. Once the memory (s) are open **we can read and/or write** to it using the function corresponding to each type of variable (Integer, float, double, char *).  

A more detailed tutorial about the functions can be found in the source code file or in the Wiki [here](https://github.com/portalTS/json-gui/wiki).

#### Matlab Example
Example of using the dynamic link library in Matlab.
1. Load de Dynamic Link Library. If we are in a 64-bit Matlab we load "smClient64.dll", the library must be in the same place where we are or in the System32 folder.
```
loadlibrary('smClient64.dll','./smClient.h')
```
2. Then we need to open the memory or the shared memories we want to work with.
Open an Integer memory (1 means Integer Memory)
```
calllib('smClient64','openMemory','Memory0',1)
``` 
Open a Float memory (2 means Float Memory)
```
calllib('smClient64','openMemory','Memory1',2) 
```
3. We can read and/or write in memory.
Write in the memory "Memory0" in position 2 the value 30
```
calllib('smClient64','setInt','Memory0',2,30)
``` 
Write in the memory "Memory1" in position 1 the value 30.1204
```
calllib('smClient64','setFloat','Memory1',1,30.1204)
``` 

#### C# Example
The following codes work perfectly in both a project created in Visual Studio in C # language and if we create a project in Unity3D that uses code in C #.

We compile and execute the C # sample project that was carried out in Visual Studio 2017.

In the interface we must specify the Name of the shared memories to Open, then click Open in each memory.



1. Load de Dynamic Link Library. If we are in a 64-bit Matlab we load "smClient64.dll", the library must be in the same place where we are or in the System32 folder.
The [DllImport (dllPath)] statement must be in each function call statement of the library.
We will use the functions of open shared memory and read Integer and Float memories.

```csharp
const string dllPath = "smClient64.dll";

[DllImport(dllPath)]
static extern int openMemory(String name, int type);

[DllImport(dllPath)]
static extern int getInt(String memName, int position);


[DllImport(dllPath)]
static extern float getFloat(String memName, int position);
```
2. Then we need to open the memory or the shared memories we want to work with.
Open an Integer memory (1 means Integer Memory)
```
int retOpen = openMemory("Memory0", 1);
``` 
Open a Float memory (2 means Float Memory)
```
int retOpen = openMemory("Memory1", 2);
```
3. We can read and/or write in memory.
Read in the Integer memory "Memory0" in position 2.
```
int value = getInt("Memory0", 2);
``` 
Read in the Float memory "Memory1" in position 1.
```
float Value = getFloat("Memory1", 1);
```

#### Result
What we did was that Matlab records whole numbers in an Integer type memory and also floating numbers in a floating type memory, in the same way in Unity3D these values are read.

Note: For more information on the available functions, you can consult the Wiki page or in the example codes the respective explanations to each code fragment are commented.

# Wiki 
