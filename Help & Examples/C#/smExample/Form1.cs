using System;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace smExample
{
    public partial class Form1 : Form
    {
		/*
         * Use this path if the dll is 32 bits and is located in the 'System32' folder on a 64-bit system,
         * const string dllPath = "C:\\Windows\\SysNative\\smClient.dll";
		*/
            
        const string dllPath = "smClient64.dll";
        /*
         * Import of the library according to your calling convention
         * You can find all the names of the functions corresponding to 
         * the calling conventions Cdecl, StdCall and FastCall in the file 'conventions.pdf'
        */

        // [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        // [DllImport(dllPath, EntryPoint = "openMemory@8", CallingConvention = CallingConvention.StdCall)] 
        // [DllImport(dllPath, EntryPoint = "@openMemory@8", CallingConvention = CallingConvention.FastCall)]
        [DllImport(dllPath)] // For 64 Bits System
        static extern int openMemory(String name, int type);

        // [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        // [DllImport(dllPath, EntryPoint = "setInt@12", CallingConvention = CallingConvention.StdCall)] 
        // [DllImport(dllPath, EntryPoint = "@setInt@12", CallingConvention = CallingConvention.FastCall)]
        [DllImport(dllPath)] // For 64 Bits System
        static extern void setInt(String memName, int position, int value);

        // [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        // [DllImport(dllPath, EntryPoint = "getInt@8", CallingConvention = CallingConvention.StdCall)] 
        // [DllImport(dllPath, EntryPoint = "@getInt@8", CallingConvention = CallingConvention.FastCall)]
        [DllImport(dllPath)]
        static extern int getInt(String memName, int position);

        // [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        // [DllImport(dllPath, EntryPoint = "setFloat@12", CallingConvention = CallingConvention.StdCall)] 
        // [DllImport(dllPath, EntryPoint = "@setFloat@12", CallingConvention = CallingConvention.FastCall)]
        [DllImport(dllPath)]
        static extern void setFloat(String memName, int position, float value);


        // [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        // [DllImport(dllPath, EntryPoint = "getFloat@8", CallingConvention = CallingConvention.StdCall)] 
        // [DllImport(dllPath, EntryPoint = "@getFloat@8", CallingConvention = CallingConvention.FastCall)]
        [DllImport(dllPath)]
        static extern float getFloat(String memName, int position);

        // [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        // [DllImport(dllPath, EntryPoint = "getDouble@8", CallingConvention = CallingConvention.StdCall)] 
        // [DllImport(dllPath, EntryPoint = "@getDouble@8", CallingConvention = CallingConvention.FastCall)]
        [DllImport(dllPath)]
        static extern double getDouble(String memName, int position);

        // [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        // [DllImport(dllPath, EntryPoint = "setDouble@16", CallingConvention = CallingConvention.StdCall)] 
        // [DllImport(dllPath, EntryPoint = "@setDouble@16", CallingConvention = CallingConvention.FastCall)]
        [DllImport(dllPath)]
        static extern void setDouble(String memName, int position, double value);

        // [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        // [DllImport(dllPath, EntryPoint = "setString@12", CallingConvention = CallingConvention.StdCall)] 
        // [DllImport(dllPath, EntryPoint = "@setString@12", CallingConvention = CallingConvention.FastCall)]
        [DllImport(dllPath)]
        static extern void setString(String memName, int position, String str);

        // [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        // [DllImport(dllPath, EntryPoint = "getString@12", CallingConvention = CallingConvention.StdCall)] 
        // [DllImport(dllPath, EntryPoint = "@getString@12", CallingConvention = CallingConvention.FastCall)]
        [DllImport(dllPath)]
        public static extern Boolean getString(String memName, int position, [MarshalAs(UnmanagedType.LPStr)] StringBuilder str);

        public Form1()
        {
            InitializeComponent();
            MessageBox.Show("BE CAREFUL WITH THE DECIMAL SEPARATOR, between the comma and the period",
                    "Help",
                    MessageBoxButtons.OK,
                    MessageBoxIcon.Information);
        }

        private void btnOpenInt_Click(object sender, EventArgs e)
        {
            String namIntMem = tbMemInt.Text;     // Name of shared memory to open
            int type = 1;                      // Memory Type: 1 means integer values
            if (openMemory(namIntMem, type) == 0)
            {
                MessageBox.Show("Shared Memory opened correctly",
                    "SM type: Integers",
                    MessageBoxButtons.OK,
                    MessageBoxIcon.Information);
            }
            else
            {
                MessageBox.Show("Error opening Shared Memory",
                    "SM type: Integers",
                    MessageBoxButtons.OK,
                    MessageBoxIcon.Error);
            }
        }

        private void btnOpenFloat_Click(object sender, EventArgs e)
        {
            String namFloatMem = tbMemFloat.Text;      // Name of shared memory to open
            int tipo = 2;                         // Memory Type: 2 means float values
            if (openMemory(namFloatMem, tipo) == 0)
            {
                MessageBox.Show("Shared Memory opened correctly",
                    "SM type: float",
                    MessageBoxButtons.OK,
                    MessageBoxIcon.Information);
            }
            else
            {
                MessageBox.Show("Error opening Shared Memory",
                    "SM type: Float",
                    MessageBoxButtons.OK,
                    MessageBoxIcon.Error);
            }
        }

        private void btnOpenDouble_Click(object sender, EventArgs e)
        {
            String namDoubleMem = tbMemDouble.Text;       // Name of shared memory to open
            int tipo = 3;                           // Memory Type: 3 means double values
            if (openMemory(namDoubleMem, tipo) == 0)
            {
                MessageBox.Show("Shared Memory opened correctly",
                    "SM type: Double",
                    MessageBoxButtons.OK,
                    MessageBoxIcon.Information);
            }
            else
            {
                MessageBox.Show("Error opening Shared Memory",
                    "SM type: Double",
                    MessageBoxButtons.OK,
                    MessageBoxIcon.Error);
            }
        }

        private void btnOpenString_Click(object sender, EventArgs e)
        {
            String namStrMem = tbMemString.Text;   // Name of shared memory to open
            int tipo = 4;                           // Memory Type: 4 means string values
            if (openMemory(namStrMem, tipo) == 0)
            {
                MessageBox.Show("Shared Memory opened correctly",
                    "SM type: String",
                    MessageBoxButtons.OK,
                    MessageBoxIcon.Information);
            }
            else
            {
                MessageBox.Show("Error opening Shared Memory",
                    "SM type: String",
                    MessageBoxButtons.OK,
                    MessageBoxIcon.Error);
            }
        }

        private void btnWriteInt_Click(object sender, EventArgs e)
        {
            int value = Convert.ToInt32(tbValueInt.Text);  // The value we want to store
            String namIntMem = tbMemInt.Text;             // Name of the Memory in which we will store
            int position = Convert.ToInt32(tbPosInt.Text); // Position to be written in
            setInt(namIntMem, position, value);           // Function use
        }

        private void btnReadInt_Click(object sender, EventArgs e)
        {
            String namIntMem = tbMemInt.Text;               // Name of the Memory from which we will read
            int position = Convert.ToInt32(
                                            tbPosResInt.Text // Memory position we want to read
                                          ); 
            tbResInt.Text = Convert.ToString(                // Function use
                                            getInt(namIntMem, position)
                                            ); 
        }

        private void btnWriteFloat_Click(object sender, EventArgs e)
        {
            float value = (float)Convert.ToDouble(         // The value we want to store
                                                  tbValueFloat.Text
                                                  ); 
            String namFloatMem = tbMemFloat.Text;          // Name of the Memory in which we will store
            int position = Convert.ToInt32(
                                          tbPosFloat.Text  // Position to be written in
                                          ); 
            setFloat(namFloatMem, position, value);        // Function use
        }

        private void btnReadFloat_Click(object sender, EventArgs e)
        {
            String namFloatMem = tbMemFloat.Text;          // Name of the Memory from which we will read
            int position = Convert.ToInt32(                // Memory position we want to read
                                        tbPosRestFloat.Text
                                          ); 
            tbResFloat.Text = Convert.ToString(            // Function use
                                            getFloat(namFloatMem, position)
                                              ); 
        }

        private void btnWriteDouble_Click(object sender, EventArgs e)
        {
            double value = Convert.ToDouble(              // The value we want to store
                                           tbValueDouble.Text
                                           ); 
            String namDoubleMem = tbMemDouble.Text;      // Name of the Memory in which we will store
            int position = Convert.ToInt32(              // Position to be written
                                          tbPosDouble.Text
                                          ); 
            setDouble(namDoubleMem, position, value);    // Funtion use
        }

        private void btnReadDouble_Click(object sender, EventArgs e)
        {
            String namDoubleMem = tbMemDouble.Text;       // Name of the Memory from which we will read
            int position = Convert.ToInt32(               // Memory position we want to read
                                          tbPosResDouble.Text
                                          ); 
            tbResDouble.Text = Convert.ToString(          // Function use
                                               getDouble(namDoubleMem, position)
                                               ); 
        }

        private void btnWriteString_Click(object sender, EventArgs e)
        {
            String value = tbValueString.Text;          // The value we want to store
            String namStrMem = tbMemString.Text;        // Name of the Memory in which we will store
            int position = Convert.ToInt32(             // Position to be written in
                                          tbPosString.Text
                                          ); 
            setString(namStrMem, position, value);      // Function use
        }

        private void btnReadString_Click(object sender, EventArgs e)
        {
            var sb = new StringBuilder((int)13);

            String nomMemoria = tbMemString.Text;      // Name of the Memory from which we will read
            int posicion = Convert.ToInt32(            // Memory position we want to read
                                          tbPosResString.Text
                                          );
            getString(nomMemoria, posicion, sb);       // Function use
            string palabra = sb.ToString();
            tbResString.Text = palabra;
        }
    }
}
