from ctypes import *
import os
import platform

if __name__ == '__main__':
    # Specify whether you want to use the 32 or 64 bit library
    # 32 bits = smClient.dll
    # 64 bits = smClient64.dll
    dll = 'smClientFcall.dll'

    # Specification of library load folder
    # If we are in a 64-bit system and want to load a dll
    # that is in the system32 folder from a 32-bit application it will load
    # the path: C:\\Windows\\SysNative\\
    system32 = os.path.join(os.environ['SystemRoot'], 'SysNative' if
    platform.architecture()[0] == '32bit' else 'System32')
    dllPath = os.path.join(system32, dll)

    # Library load
    mydll = cdll.LoadLibrary(dllPath)     # cdecl type DLL load
    # mydll = windll.LoadLibrary(dllPath) # DLL load of type stdcall

    ###################################### Work with integer memory ###################################
    ########## Open integer memory
    # to start a memory we need the name of the memory and the type
    # Returns a value of 0 (zero) if opened correctly
    memory = b'Memory0'  # Memory name
    type = int(1)        # 1 indicates that an integer memory will open
    
    ## stdcall - this is for 32 bits type __stdcall library
    # openMemory = getattr(mydll, 'openMemory@8')
    # open = openMemory(memory, type)

    ##cdecl - this is for 32 bits type __cdecl library or for 64Bits library
    open = mydll.openMemory(memory, type)
    print(open)

    ######### Write in an integer memory
    # Parameters are:
    # - the name of the memory,
    # - in which position you want to write,
    # - value to write

    ##stdcall - this is for 32 bits type __stdcall library
    # setInt = getattr(mydll, 'setInt@12')
    # setInt(memory, int(0), int(56))

    ##cdecl - this is for 32 bits type __cdecl library or for 64Bits library
    mydll.setInt(memory, int(0), int(56))

    print("the integer value has been written")

    ############ Read from integer memory
    # Parameters are:
    # - the name of the memory
    # - position to be read
    # - Return de value saved in the memory

    ##stdcall - this is for 32 bits type __stdcall library
    # getInt = getattr(mydll, 'getInt@8')
    # read = getInt(memory, int(1))

    ##cdecl - this is for 32 bits type __cdecl library or for 64Bits library
    read = mydll.getInt(memory, int(1))
    print(read)

    ################################## Work with float memory ###################################
    ########## Open float memory
    memory2 = b'Memory1'  # Memory Name
    type2 = int(2)        # 2 indicates that a floating type memory will open

    ## stdcall - this is for 32 bits type __stdcall library
    # openMemory = getattr(mydll, 'openMemory@8')
    # open2 = openMemory(memory, type)

    ##cdecl - this is for 32 bits type __cdecl library or for 64Bits library
    open2 = mydll.openMemory(memory2, type2)
    print(open2)

    ########## Write in float memory
    # Parameters are:
    # - the name of the memory
    # - position to be written
    # - value to write

    ## This is for 32 bits type __stdcall library
    # setFloat = getattr(mydll, 'setFloat@12')
    # setFloat(memory2, int(3), c_float(0.1245))

    ## this is for 32 bits type __cdecl library or for 64Bits library
    mydll.setFloat(memory2, int(3), c_float(0.1245))
    print("floating value was written")

    ########### Read in floating memory
    read2 = c_float # Stores the return value of the function

    # Parameters are:
    # - the name of the memory
    # - position to be read
    # - Return de value saved in the memory

    ##stdcall - this is for 32 bits type __stdcall library
    # getFloat = getattr(mydll, 'getFloat@8')
    # getFloat.restype = c_float
    # read2 = getFloat(memory, int(1))


    ##cdecl - this is for 32 bits type __cdecl library or for 64Bits library
    mydll.getFloat.restype = c_float
    read2 = mydll.getFloat(memory2, int(3))

    print(read2)

    #################################### Work with double type memory ######################################
    ########## Open Double Memory
    memory3 = b'Memory2'  # Memory Name
    type3 = int(3)        # 3 indicates that a Double type memory will open

    ## stdcall - this is for 32 bits type __stdcall library
    # openMemory = getattr(mydll, 'openMemory@8')
    # open3 = openMemory(memory, type)

    ##cdecl - this is for 32 bits type __cdecl library or for 64Bits library
    open3 = mydll.openMemory(memory3, type3)
    print(open3)

    ########## Write in a memory of type Double
    # Parameters are:
    # - the name of the memory
    # - position to be written
    # - value to write

    ## This is for 32 bits type __stdcall library
    # setDouble = getattr(mydll, 'setDouble@16')
    # setDouble(memory3, int(0), c_double(0.789454))

    ## this is for 32 bits type __cdecl library or for 64Bits library
    mydll.setDouble(memory3, int(0), c_double(0.789454))
    print("double value was written")

    ############ Read from a memory of type Double
    read3 = c_double # Stores the return value of the function

    # Parameters are:
    # - name of the memory
    # - position to be read

    ##stdcall - this is for 32 bits type __stdcall library
    # getDouble = getattr(mydll, 'getDouble@8')
    # getDouble.restype = c_double
    # read3 = getDouble(memory3, int(2))


    ##cdecl - this is for 32 bits type __cdecl library or for 64Bits library
    mydll.getDouble.restype = c_double
    read3 = mydll.getDouble(memory3, int(2))
    print(read3)

    #################################### Work with string memory ######################################
    ########## Open Double Memory
    memory4 = b'Memory3'  # Memory Name
    type4 = int(4)  # 4 indicates that a String type memory will open

    ## stdcall - this is for 32 bits type __stdcall library
    # openMemory = getattr(mydll, 'openMemory@8')
    # open4 = openMemory(memory, type)

    ##cdecl - this is for 32 bits type __cdecl library or 64Bits library
    open4 = mydll.openMemory(memory4, type4)
    print(open4)

    ########## Write in a memory of type String
    message = b'python'
    # Parameters are:
    # - the name of the memory
    # - position to be written
    # - string to write

    ## This is for 32 bits type __stdcall library
    # setString = getattr(mydll, 'setString@12')
    # setString(memory4, int(0), message)

    ## this is for 32 bits type __cdecl library or 64Bits library
    mydll.setString(memory4, int(0), message)
    print("string value was written")

    ########## Read from a string memory
    string_buffers = [create_string_buffer(13)]             # create a 13 byte buffer
    pointer = (c_char_p)(*map(addressof, string_buffers))   # Create a pointer

    # Parameters are:
    # - name of the memory
    # - position to be read
    # - Variable in which the memory value will be stored

    ## stdcall - this is for 32 bits type __stdcall library
    # getString = getattr(mydll, 'getString@12')
    # read4 = getString(memory4, int(1), pointer)

    ## cdecl - this is for 32 bits type __cdecl library or 64Bits library
    mydll.getString(memory4, int(1), pointer)

    # get the value from the Pointer
    res = string_buffers
    results = [s.value for s in string_buffers]
    word = results[0]
    print(word)

    ######################################## Free open shared memories #################################

    ## stdcall - this is for 32 bits type __stdcall library
    # freeViews = getattr(mydll, 'freeViews@0')
    # freeViews()

    ## cdecl - this is for 32 bits type __cdecl library or 64Bits library
    mydll.freeViews()

#################################### Administration functions ######################################
    ## The following functions are used if you want to manage both creation, management and deletion
    ## of shared memories, and DO NOT use the shared memory management panel

    ############## Shared memory creation
    # Parameters are:
    # - name of the memory
    # - Amount of values to be stored
    # - type of variables that will be stored in memory
    #       1 = Integer
    #       2 = Float
    #       3 = Double
    #       4 = String (Char *) 13 characters by default
    # 	RETURN:
    #	0 = If it runs correctly
    #	1 = if there was an error
    # Examples
    '''

    return1 = mydll.createMemory(b'Memory0', 8, 1) # Create a memory called "Memory0" that contains 8 spaces and 
                                                   # is of type Integer
    return2 = mydll.createMemory(b'Memory1', 4, 2) # Create a memory called "Memory1" that contains 4 spaces and 
                                                    #is of type Float
    return3 = mydll.createMemory(b'Memory2', 5, 3) # Create a memory called "Memory3" that contains 5 spaces and 
                                                    #is of type Double

    mydll.freeMemories()  # Free all shared memories created
    '''

