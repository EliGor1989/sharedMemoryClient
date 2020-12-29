/*
 * All information is documented in the address
 * https://github.com/EliGor1989/sharedMemoryClient
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace SmExampleCdecl
{
    public class SmClientCdecl
    {
        public enum memoryType
        {
            Integer = 1,
            Float = 2,
            Double = 3,
            String = 4
        }

        /// <summary>
        /// Library name or full path
        /// </summary>
        const string dllPath = "smClientCdecl.dll";
               
        /// <summary>
        /// Calls the function that opens a shared memory
        /// </summary>
        /// <param name="name">Memory name</param>
        /// <param name="typeCode">Type of memory to open (Integer, Float, Double, String), Use the Enum memoryType</param>
        /// <returns>0 if it runs correctly, 1 if there was an error</returns>
        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern int openMemory(String name, int typeCode);

        /// <summary>
        /// Stores a integer type value (dValue) in position (position) belonging to memory with the name (memName).
        /// </summary>
        /// <param name="memName">Shared memory name</param>
        /// <param name="position">Position where you want to store the integer value</param>
        /// <param name="dValue">Integer value to store</param>
        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern void setInt(String memName, int position, int dValue);

        /// <summary>
        /// Returns the value of Integer type stored in position (position) belonging to memory with the name (memName).
        /// </summary>
        /// <param name="memName">Shared memory name</param>
        /// <param name="position">Position from which you want to read the integer value</param>
        /// <returns>Returns the integer type value stored in position (position) belonging to memory with the name (memName).</returns>
        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern int getInt(String memName, int position);

        /// <summary>
        /// Stores a float type value (fValue) in position (position) belonging to memory with the name (memName).
        /// </summary>
        /// <param name="memName">Shared memory name</param>
        /// <param name="position">Position where you want to store the float value</param>
        /// <param name="fValue">Float value to store</param>
        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern void setFloat(String memName, int position, float fValue);

        /// <summary>
        /// Returns the float type value stored in position (position) belonging to memory with the name (memName).
        /// </summary>
        /// <param name="memName">Shared memory name</param>
        /// <param name="position">Position from which you want to read the float value</param>
        /// <returns>Returns the float type value stored in position (position) belonging to memory with the name (memName).</returns>
        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern float getFloat(String memName, int position);

        /// <summary>
        /// Stores a double type value (lfValue) in position (position) belonging to memory with the name (memName).
        /// </summary>
        /// <param name="memName">Shared memory name</param>
        /// <param name="position">Position where you want to store the double value</param>
        /// <param name="lfValue">Double value to store</param>
        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern void setDouble(String memName, int position, double lfValue);

        /// <summary>
        /// Returns the Double type value stored in position (position) belonging to memory with the name (memName).
        /// </summary>
        /// <param name="memName">Shared memory name</param>
        /// <param name="position">Position from which you want to read the Double type value</param>
        /// <returns>Returns the double type value stored in position (position) belonging to memory with the name (memName).</returns>
        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern double getDouble(String memName, int position);

        /// <summary>
        ///  Stores a string type value (strValue) in position (position) into the memory with the name (memName).
        /// </summary>
        /// <param name="memName">Shared memory name</param>
        /// <param name="position">Position where you want to store the String value</param>
        /// <param name="strValue">String value to store</param>
        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern void setString(String memName, int position, String strValue);

        /// <summary>
        ///  Returns the string of characters stored in position (position) stored into the memory with the name (memName).
        /// </summary>
        /// <param name="memName">Shared memory name</param>
        /// <param name="position">Position from which you want to read the String value</param>
        /// <param name="strReturn">Variable where the return value will be stored</param>
        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern void getString(String memName, int position, [MarshalAs(UnmanagedType.LPStr)] StringBuilder strReturn);

        /// <summary>
        /// Creates a shared memory labeled with the name specified in (memoryName), 
        /// which can contain a number of values specified in (quantity), 
        /// and the values will be of the type specified in (typeCode).
        /// </summary>
        /// <param name="name">Shared memory name</param>
        /// <param name="quantity">Specify the maximum amount of values that we can store in the memory</param>
        /// <param name="typeCode">Type of memory to open (Integer, Float, Double, String), Use the Enum memoryType</param>
        /// <returns>0 if it runs correctly, 1 if there was an error</returns>
        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern int createMemory(String name, int quantity, int typeCode);

        /// <summary>
        /// Frees up separate memory space for creating links between views to shared memories.
        /// </summary>
        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern void freeViews();

        /// <summary>
        /// This function releases the memory spaces created by the createMemory () function.
        /// </summary>
        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern void freeMemories();
        
    }
}
