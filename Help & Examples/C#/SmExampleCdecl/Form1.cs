using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SmExampleCdecl
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnOpenInt_Click(object sender, EventArgs e)
        {
            String namIntMem = tbMemInt.Text;     // Name of shared memory to open

            if (SmClientCdecl.openMemory(namIntMem, (int)SmClientCdecl.memoryType.Integer) == 0)
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

        private void btnWriteInt_Click(object sender, EventArgs e)
        {
            int value = Convert.ToInt32(tbValueInt.Text);  // The value we want to store
            String namIntMem = tbMemInt.Text;             // Name of the Memory in which we will store
            int position = Convert.ToInt32(tbPosInt.Text); // Position to be written in
            SmClientCdecl.setInt(namIntMem, position, value);           // Function use
        }

        private void btnReadInt_Click(object sender, EventArgs e)
        {
            String namIntMem = tbMemInt.Text;               // Name of the Memory from which we will read
            int position = Convert.ToInt32(
                                            tbPosResInt.Text // Memory position we want to read
                                          );
            tbResInt.Text = Convert.ToString(                // Function use
                                            SmClientCdecl.getInt(namIntMem, position)
                                            ); 
        }

        private void btnOpenFloat_Click(object sender, EventArgs e)
        {
            String namFloatMem = tbMemFloat.Text;      // Name of shared memory to open
            if (SmClientCdecl.openMemory(namFloatMem, (int)SmClientCdecl.memoryType.Float) == 0)
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

        private void btnWriteFloat_Click(object sender, EventArgs e)
        {
            float value = (float)Convert.ToDouble(         // The value we want to store
                                                 tbValueFloat.Text
                                                 );
            String namFloatMem = tbMemFloat.Text;          // Name of the Memory in which we will store
            int position = Convert.ToInt32(
                                          tbPosFloat.Text  // Position to be written in
                                          );
            SmClientCdecl.setFloat(namFloatMem, position, value);        // Function use
        }

        private void btnReadFloat_Click(object sender, EventArgs e)
        {
            String namFloatMem = tbMemFloat.Text;          // Name of the Memory from which we will read
            int position = Convert.ToInt32(                // Memory position we want to read
                                        tbPosRestFloat.Text
                                          );
            tbResFloat.Text = Convert.ToString(            // Function use
                                            SmClientCdecl.getFloat(namFloatMem, position)
                                              ); 
        }

        private void btnOpenDouble_Click(object sender, EventArgs e)
        {
            String namDoubleMem = tbMemDouble.Text;       // Name of shared memory to open
            if (SmClientCdecl.openMemory(namDoubleMem, (int)SmClientCdecl.memoryType.Double) == 0)
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

        private void btnWriteDouble_Click(object sender, EventArgs e)
        {
            double value = Convert.ToDouble(              // The value we want to store
                                           tbValueDouble.Text
                                           );
            String namDoubleMem = tbMemDouble.Text;      // Name of the Memory in which we will store
            int position = Convert.ToInt32(              // Position to be written
                                          tbPosDouble.Text
                                          );
            SmClientCdecl.setDouble(namDoubleMem, position, value);    // Funtion use
        }

        private void btnReadDouble_Click(object sender, EventArgs e)
        {
            String namDoubleMem = tbMemDouble.Text;       // Name of the Memory from which we will read
            int position = Convert.ToInt32(               // Memory position we want to read
                                          tbPosResDouble.Text
                                          );
            tbResDouble.Text = Convert.ToString(          // Function use
                                               SmClientCdecl.getDouble(namDoubleMem, position)
                                               ); 
        }

        private void btnOpenString_Click(object sender, EventArgs e)
        {
            String namStrMem = tbMemString.Text;   // Name of shared memory to open
            if (SmClientCdecl.openMemory(namStrMem, (int)SmClientCdecl.memoryType.String) == 0)
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

        private void btnWriteString_Click(object sender, EventArgs e)
        {
            String value = tbValueString.Text;          // The value we want to store
            String namStrMem = tbMemString.Text;        // Name of the Memory in which we will store
            int position = Convert.ToInt32(             // Position to be written in
                                          tbPosString.Text
                                          );
            SmClientCdecl.setString(namStrMem, position, value); // Function use
        }

        private void btnReadString_Click(object sender, EventArgs e)
        {
            var sb = new StringBuilder((int)64);

            String nomMemoria = tbMemString.Text;      // Name of the Memory from which we will read
            int posicion = Convert.ToInt32(            // Memory position we want to read
                                          tbPosResString.Text
                                          );
            SmClientCdecl.getString(nomMemoria, posicion, sb);       // Function use
            string palabra = sb.ToString();
            tbResString.Text = palabra;
        }

        private void btnCreateInt_Click(object sender, EventArgs e)
        {
            String namIntMem = tbMemIntCreate.Text;
            int intQuantity = Convert.ToInt32(tbIntQuantity.Text);
            int ret = SmClientCdecl.createMemory(namIntMem, intQuantity, (int)SmClientCdecl.memoryType.Integer);

            if (ret == 0)
            {
                MessageBox.Show("Shared Memory was created correctly",
                    "SM type: Integers",
                    MessageBoxButtons.OK,
                    MessageBoxIcon.Information);
            }
            else
            {
                MessageBox.Show("Error creating Shared Memory",
                    "SM type: Integers",
                    MessageBoxButtons.OK,
                    MessageBoxIcon.Error);
        }
    }

        private void btnCreateFloat_Click(object sender, EventArgs e)
        {
            String namFloatMem = tbMemFloatCreate.Text;
            int floatQuantity = Convert.ToInt32(tbFloatQuantity.Text);
            int ret = SmClientCdecl.createMemory(namFloatMem, floatQuantity, (int)SmClientCdecl.memoryType.Float);
            if (ret == 0)
            {
                MessageBox.Show("Shared Memory was created correctly",
                    "SM type: Float",
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

        private void btnCreateDouble_Click(object sender, EventArgs e)
        {
             String namDoubleMem = tbMemDoubleCreate.Text;
            int doubleQuantity = Convert.ToInt32(tbDoubleQuantity.Text);
            int ret = SmClientCdecl.createMemory(namDoubleMem, doubleQuantity, (int)SmClientCdecl.memoryType.Double);
            if (ret == 0)
            {
                MessageBox.Show("Shared Memory was created correctly",
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

        private void btnCreateString_Click(object sender, EventArgs e)
        {
             String namStringMem = tbMemStringCreate.Text;
            int stringQuantity = Convert.ToInt32(tbStringQuantity.Text);
            int ret = SmClientCdecl.createMemory(namStringMem, stringQuantity, (int)SmClientCdecl.memoryType.String);
            if (ret == 0)
            {
                MessageBox.Show("Shared Memory was created correctly",
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

        private void button5_Click(object sender, EventArgs e)
        {
            SmClientCdecl.freeMemories();
            MessageBox.Show("The memories have been released.",
                   "SMClient",
                   MessageBoxButtons.OK,
                   MessageBoxIcon.Information);
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            SmClientCdecl.freeViews();
            MessageBox.Show("All views created are released",
                   "Views Releasing",
                   MessageBoxButtons.OK,
                   MessageBoxIcon.Information);
        }
        }
}
