using System;
using System.Text;
using System.Windows.Forms;

namespace smExample
{
    public partial class Form1 : Form
    {
        
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

            if (SmClient64.openMemory(namIntMem, (int)SmClient64.memoryType.Integer) == 0)
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
            if (SmClient64.openMemory(namFloatMem, (int)SmClient64.memoryType.Float) == 0)
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
            if (SmClient64.openMemory(namDoubleMem, (int)SmClient64.memoryType.Double) == 0)
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
            if (SmClient64.openMemory(namStrMem, (int)SmClient64.memoryType.String) == 0)
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
            SmClient64.setInt(namIntMem, position, value);           // Function use
        }

        private void btnReadInt_Click(object sender, EventArgs e)
        {
            String namIntMem = tbMemInt.Text;               // Name of the Memory from which we will read
            int position = Convert.ToInt32(
                                            tbPosResInt.Text // Memory position we want to read
                                          ); 
            tbResInt.Text = Convert.ToString(                // Function use
                                            SmClient64.getInt(namIntMem, position)
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
            SmClient64.setFloat(namFloatMem, position, value);        // Function use
        }

        private void btnReadFloat_Click(object sender, EventArgs e)
        {
            String namFloatMem = tbMemFloat.Text;          // Name of the Memory from which we will read
            int position = Convert.ToInt32(                // Memory position we want to read
                                        tbPosRestFloat.Text
                                          ); 
            tbResFloat.Text = Convert.ToString(            // Function use
                                            SmClient64.getFloat(namFloatMem, position)
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
            SmClient64.setDouble(namDoubleMem, position, value);    // Funtion use
        }

        private void btnReadDouble_Click(object sender, EventArgs e)
        {
            String namDoubleMem = tbMemDouble.Text;       // Name of the Memory from which we will read
            int position = Convert.ToInt32(               // Memory position we want to read
                                          tbPosResDouble.Text
                                          ); 
            tbResDouble.Text = Convert.ToString(          // Function use
                                               SmClient64.getDouble(namDoubleMem, position)
                                               ); 
        }

        private void btnWriteString_Click(object sender, EventArgs e)
        {
            String value = tbValueString.Text;          // The value we want to store
            String namStrMem = tbMemString.Text;        // Name of the Memory in which we will store
            int position = Convert.ToInt32(             // Position to be written in
                                          tbPosString.Text
                                          );
            SmClient64.setString(namStrMem, position, value); // Function use
        }

        private void btnReadString_Click(object sender, EventArgs e)
        {
            var sb = new StringBuilder((int)64);

            String nomMemoria = tbMemString.Text;      // Name of the Memory from which we will read
            int posicion = Convert.ToInt32(            // Memory position we want to read
                                          tbPosResString.Text
                                          );
            SmClient64.getString(nomMemoria, posicion, sb);       // Function use
            string palabra = sb.ToString();
            tbResString.Text = palabra;
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            SmClient64.freeViews();
            MessageBox.Show("All views created are released",
                   "Views Releasing",
                   MessageBoxButtons.OK,
                   MessageBoxIcon.Information);
        }

        private void btnCreateInt_Click(object sender, EventArgs e)
        {
            String namIntMem = tbMemIntCreate.Text;
            int intQuantity = Convert.ToInt32(tbIntQuantity.Text);
            int ret = SmClient64.createMemory(namIntMem, intQuantity, (int)SmClient64.memoryType.Integer);

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
            int ret = SmClient64.createMemory(namFloatMem, floatQuantity, (int)SmClient64.memoryType.Float);
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
            int ret = SmClient64.createMemory(namDoubleMem, doubleQuantity, (int)SmClient64.memoryType.Double);
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
            int ret = SmClient64.createMemory(namStringMem, stringQuantity, (int)SmClient64.memoryType.String);
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
            SmClient64.freeMemories();
            MessageBox.Show("The memories have been released.",
                   "SMClient",
                   MessageBoxButtons.OK,
                   MessageBoxIcon.Information);
        }
    }
}
