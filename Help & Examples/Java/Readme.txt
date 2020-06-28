###########################################################################
   ____ ____ ____ ____ ____ ____ _________ ____ ____ ____ ____ ____ ____ 
  ||S |||h |||a |||r |||e |||d |||       |||M |||e |||m |||o |||r |||y ||
  ||__|||__|||__|||__|||__|||__|||_______|||__|||__|||__|||__|||__|||__||
  |/__\|/__\|/__\|/__\|/__\|/__\|/_______\|/__\|/__\|/__\|/__\|/__\|/__\|



########################### Configurations  ##############################
In order to access and manipulate the shared memory we must import or in 
turn create a package called eros, and within that packet copy or in turn
 create a class called SmClient.java.

In the attached example we see the package "eros" and the file 
"SmClient.java" once we have the package and the file in our project, 
just import it

import eros.SmClient;

And we can use all the manipulation functions of our shared memories 
through the SmClient class, for example

SmClient.openMemory ("Memory0", 1);

NOTE: it is important to maintain this name structure since jni 
(java native interface) functions are being used and the structure 
corresponds to the internal structure of the system .dll file.

Calling library:
64 Bits = smClientJava64
32 Bits = smClientJava
static {      
	System.loadLibrary("smClientJava64");   
} 