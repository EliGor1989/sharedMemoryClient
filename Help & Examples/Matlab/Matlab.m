%%%%%%%%%%%%%%%%%% How to use the Library %%%%%%%%%%%%%%%%%%%
% We can use the library for both 32bits and 64
% 32bits: smClient.dll (It has not yet been tested)
% 64bits: smClient64.dll


%%%%%%%%%%%%%%%%%%% Loading  .dll %%%%%%%%%%%%%%%%%%%%%%%%%%%%
% If we specify only the name of the library, it will search 
% the current folder of the .m file and the folders added to 
% the windows path (example: System32)

loadlibrary('smClient64.dll','./smClient.h')

% We use this path if we are in a 64-bit system and want to load a dll 
% that is in the system32 folder from a 32-bit application

% loadlibrary('C:\\Windows\\SysNative\\smClient.dll','./main.h')

%%%%%%%%%%%%%%% General library call %%%%%%%%%%%%%%%%%%%%%%%
% When we work with a library, the use of functions and sending 
% parameters has a standard structure
% calllib('Library_Name','Function_name', '1_Parameter', '2_parameter', 'n_parameter')

%%%%%%%%%%%%%%%%% Working with Integer Values %%%%%%%%%%%%%%%%
% to start a memory we need the name of the memory and the type
% Returns a value of 0 (zero) if opened correctly
%
% Explanation: 
% smClient64: It is the name of the library we are using
% openMemory: It is the name of the function we want to call
% Memory0   : The name of the memory we wish to open
% 1 		: means this is a Integer Memory
calllib('smClient64','openMemory','Memory0',1)

% Saving an integer value. Parameters:
% smClient64: It is the name of the library we are using
% setInt	: Function name 
% Memory0	: Memory Name
% 2			: Position in which we will store the value
% 30		: Value we are going to store
calllib('smClient64','setInt','Memory0',2,30)

% Reading an integer value. Parameters:
% smClient64: It is the name of the library we are using
% getInt	: Function name 
% Memory0	: Memory Name
% 3			: Position from which we want to read a value
% retInt	: The return value of the function will be stored in this variable
retInt = calllib('smClient64','getInt','Memory0',1)

%%%%%%%%%%%%%%%% Working with Float values %%%%%%%%%%%%%%%%%%%%
% to start a memory we need the name of the memory and the type
% Returns a value of 0 (zero) if opened correctly
%
% Explanation: 
% smClient64: It is the name of the library we are using
% openMemory: It is the name of the function we want to call
% Memory1   : The name of the memory we wish to open
% 2			: means this is a Float Memory
calllib('smClient64','openMemory','Memory1',2)

% Saving a float value. Parameters:
% smClient64: It is the name of the library we are using
% setFloat	: Function name 
% Memory1	: Memory Name
% 1			: Position in which we will store the value
% 30.1204		: Value we are going to store
calllib('smClient64','setFloat','Memory1',1,30.1204)

% Reading a float value. Parameters:
% smClient64: It is the name of the library we are using
% getFloat	: Function name 
% Memory1	: Memory Name
% 2			: Position from which we want to read a value
% retFloat	: The return value of the function will be stored in this variable
retFloat = calllib('smClient64','getFloat','Memory1',2)

%%%%%%%%%%%%%%%%%% Working with Double Values %%%%%%%%%%%%%%%%%
% to start a memory we need the name of the memory and the type
% Returns a value of 0 (zero) if opened correctly
%
% Explanation: 
% smClient64: It is the name of the library we are using
% openMemory: It is the name of the function we want to call
% Memory2   : The name of the memory we wish to open
% 3			: means this is a Double Memory
calllib('smClient64','openMemory','Memory2',3)

% Saving a Double value. Parameters:
% smClient64: It is the name of the library we are using
% setDouble	: Function name 
% Memory2	: Memory Name
% 0			: Position in which we will store the value
% 30.4511482		: Value we are going to store
calllib('smClient64','setDouble','Memory2',0,30.4511482)

% Reading a Double value. Parameters:
% smClient64: It is the name of the library we are using
% getDouble	: Function name 
% Memory2	: Memory Name
% 2			: Position from which we want to read a value
% retDouble	: The return value of the function will be stored in this variable

format long  % If we want to visualize more decimals, we execute this line of code
retDouble = calllib('smClient64','getDouble','Memory2',2)

%%%%%%%%%%%%%%%%%%%%% TRABAJAR CON CADENAS %%%%%%%%%%%%%%%%%%%%%%%%%%%%
% to start a memory we need the name of the memory and the type
% Returns a value of 0 (zero) if opened correctly
%
% Explanation: 
% smClient64: It is the name of the library we are using
% openMemory: It is the name of the function we want to call
% Memory3   : The name of the memory we wish to open
% 4			: means this is a String Memory (By default it only 
%			  stores 13 characters per position)
calllib('smClient64','openMemory','Memory3',4)

% Saving a String value. Parameters:
% smClient64	 : It is the name of the library we are using
% setString		 : Function name 
% Memory3		 : Memory Name
% 1				 : Position in which we will store the value
% 'Hello Matlab' : Value we are going to store
calllib('smClient64','setString','Memory3',1,'Hello Matlab')

% Reading a String value. Parameters:
% smClient64		: It is the name of the library we are using
% getStringMatlab	: Function name 
% Memory3			: Memory Name
% 5					: Position from which we want to read a value
% retString			: The return value of the function will be stored in this variable
retString = libpointer('stringPtrPtr',{''}); %We specify this variable as a pointer
calllib('smClient64','getStringMatlab','Memory3',5,retString)
retString.value % We display the return value

%%%%%%%%%%%%%%%%%%%%% Free the memories and the library %%%%%%%%%%%%%%%%%%%
calllib('smClient64','freeViews')
unloadlibrary smClient64




%%%%%%%%%%%%%%%%%%%%%%%% Manage Shared Memories %%%%%%%%%%%%%%%%%%%%%%%%%%
% If we want to manage the memories from Matlab instead of the 
% administrator panel, we must follow these steps:

% FIRST: We need to create the memories we want, example creation of 2 memories.
% Parameters:
% Memory name
% Amount of values to be stored in this memory
% Type of value to store: 
%						1 = Integer
%						2 = Float
%						3 = Doubles
%						4 = String (Maximum 13 characters by default)
% 	RETURN:
%	0 = If it runs correctly
%	1 = if there was an error
% Structure of the shared memory creation function:
% calllib('smClient64','createMemory','Mamory_Name',Number_of_spaces,Type_Code)

calllib('smClient64','createMemory','Memory_Int',8,1)   
calllib('smClient64','createMemory','Memory_Float',5,3)

% If we manage the creation of shared memories from Matlab, we must also 
% release them once we finish working with them.
calllib('smClient64','freeMemories')
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
