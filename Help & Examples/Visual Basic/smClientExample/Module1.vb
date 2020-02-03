

' In order to use calling convention cdecl libraries we must import this class

' Imports System.Runtime.InteropServices

Module Module1


    ' If we want to use a Cdecl type library in a 32Bits application

    'Private Const pathDll As String = "C:\Windows\SysNative\smClient.dll"

    '<DllImport(pathDll, CallingConvention:=CallingConvention.Cdecl)>
    'Public Function openMemory(ByVal memName As String, ByVal typeCode As Integer) As Integer
    'End Function

    '<DllImport(pathDll, CallingConvention:=CallingConvention.Cdecl)>
    'Public Sub setInt(ByVal memName As String, ByVal position As Integer, ByVal value As Integer)
    'End Sub

    '<DllImport(pathDll, CallingConvention:=CallingConvention.Cdecl)>
    'Public Function getInt(ByVal memName As String, ByVal position As Integer) As Integer
    'End Function  

    '<DllImport(pathDll, CallingConvention:=CallingConvention.Cdecl)>
    'Public Sub setFloat(ByVal memName As String, ByVal position As Integer, ByVal value As Single)
    'End Sub

    '<DllImport(pathDll, CallingConvention:=CallingConvention.Cdecl)>
    'Public Function getFloat(ByVal memName As String, ByVal position As Integer) As Single
    'End Function

    '<DllImport(pathDll, CallingConvention:=CallingConvention.Cdecl)>
    'Public Sub setDouble(ByVal memName As String, ByVal position As Integer, ByVal value As Double)
    'End Sub

    '<DllImport(pathDll, CallingConvention:=CallingConvention.Cdecl)>
    'Public Function getDouble(ByVal memName As String, ByVal position As Integer) As Double
    'End Function

    '<DllImport(pathDll, CallingConvention:=CallingConvention.Cdecl)>
    'Public Sub setString(ByVal memName As String, ByVal position As Integer, ByVal value As String)
    'End Sub

    '<DllImport(pathDll, CallingConvention:=CallingConvention.Cdecl)>
    'Public Sub getString(ByVal namMemory As String, ByVal posicion As Integer, ByVal value As String)
    'End Sub




    'Call library stdcall in 32bits System you have to put Alias "openMemory@8" after the library path
    ' Example:
    ' Public Declare Function openMemory Lib "C:\Windows\SysNative\smClient.dll" Alias "openMemory@8" _
    ' (ByVal nombre As String, ByVal cantidad As Integer) As Integer

    'Use of the library in 32Bits application
    Public Declare Function openMemory Lib "C:\Windows\SysNative\smClientStd.dll" Alias "openMemory@8" _
    (ByVal memName As String, ByVal cantidad As Integer) As Integer

    Public Declare Function getInt Lib "C:\Windows\SysNative\smClientStd.dll" Alias "getInt@8" _
    (ByVal memName As String, ByVal position As Integer) As Integer

    Public Declare Sub setInt Lib "C:\Windows\SysNative\smClientStd.dll" Alias "setInt@12" _
    (ByVal memName As String, ByVal position As Integer, ByVal value As Integer)

    Public Declare Function getFloat Lib "C:\Windows\SysNative\smClientStd.dll" Alias "getFloat@8" _
    (ByVal namMemory As String, ByVal posicion As Integer) As Single

    Public Declare Sub setFloat Lib "C:\Windows\SysNative\smClientStd.dll" Alias "setFloat@12" _
    (ByVal namMemory As String, ByVal position As Integer, ByVal value As Single)

    Public Declare Function getDouble Lib "C:\Windows\SysNative\smClientStd.dll" Alias "getDouble@8" _
    (ByVal namMemory As String, ByVal posicion As Integer) As Double

    Public Declare Sub setDouble Lib "C:\Windows\SysNative\smClientStd.dll" Alias "setDouble@16" _
    (ByVal namMemory As String, ByVal position As Integer, ByVal value As Double)

    Public Declare Sub getString Lib "C:\Windows\SysNative\smClientStd.dll" Alias "getString@12" _
    (ByVal namMemory As String, ByVal position As Integer, ByVal value As String)

    Public Declare Sub setString Lib "C:\Windows\SysNative\smClientStd.dll" Alias "setString@12" _
    (ByVal namMemory As String, ByVal position As Integer, ByVal value As String)


    Sub Main()
        ' Work with Integer shared memory
        Dim retOpen As Integer
        Dim retInteger As Integer

        retOpen = openMemory("Memory0", 1)

        setInt("Memory0", 8, 5555)

        retInteger = getInt("Memory0", 8)

        Console.WriteLine("probando " & retInteger)
        System.Threading.Thread.Sleep(1000)

        ' Work with float shared memory
        Dim retFloat As Single

        retOpen = openMemory("Memory1", 2)
        setFloat("Memory1", 2, 2.254)

        retFloat = getFloat("Memory1", 2)
        Console.WriteLine("probando " & retFloat)
        System.Threading.Thread.Sleep(1000)

        ' Work with Double shared memory
        Dim retDouble As Double

        retOpen = openMemory("Memory2", 3)
        setDouble("Memory2", 4, -0.78854)

        retDouble = getDouble("Memory2", 4)
        Console.WriteLine("probando " & retDouble)
        System.Threading.Thread.Sleep(1000)

        ' Work with String shared memory
        Dim retString As New String(" ", 13)

        retOpen = openMemory("Memory3", 4)
        setString("Memory3", 3, "Hello VB")

        getString("Memory3", 3, retString)

        Console.WriteLine("probando " & retString)
        System.Threading.Thread.Sleep(1000)
    End Sub

End Module
