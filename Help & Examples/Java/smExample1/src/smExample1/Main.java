package smExample1;

import java.awt.EventQueue;
import javax.swing.JFrame;

import eros.SmClient;
import javax.swing.JLabel;
import java.awt.Font;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class Main {

	private JFrame frame;
	private JTextField tfMemInteger;
	private JTextField tfPosWrInt;
	private JTextField tfValueWrInt;
	private JTextField tfValueReadInt;
	private JTextField tfPosReadInt;
	private JTextField tfMemFloat;
	private JTextField tfPosWrFloat;
	private JTextField tfValueWrFloat;
	private JTextField tfValueReadFloat;
	private JTextField tfPosReadFloat;
	private JTextField tfMemDouble;
	private JTextField tfPosWrDouble;
	private JTextField tfValueWrDouble;
	private JTextField tfValueReadDouble;
	private JTextField tfPosReadDouble;
	private JTextField tfMemString;
	private JTextField tfPosWrString;
	private JTextField tfValueWrString;
	private JTextField tfValueReadString;
	private JTextField tfPosReadString;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Main window = new Main();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
		
		
	}

	/**
	 * Create the application.
	 */
	public Main() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 481, 551);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		JLabel lblSharedMemory = new JLabel("Example of shared memory usage");
		lblSharedMemory.setFont(new Font("Tahoma", Font.BOLD, 14));
		lblSharedMemory.setBounds(110, 10, 300, 20);
		frame.getContentPane().add(lblSharedMemory);
		
		JLabel lblIntegers = new JLabel("Integers");
		lblIntegers.setFont(new Font("Tahoma", Font.BOLD, 12));
		lblIntegers.setBounds(20, 40, 55, 13);
		frame.getContentPane().add(lblIntegers);
		
		JLabel lblMemory = new JLabel("Memory");
		lblMemory.setBounds(25, 63, 58, 13);
		frame.getContentPane().add(lblMemory);
		
		JLabel lblPos = new JLabel("Pos");
		lblPos.setBounds(174, 63, 23, 13);
		frame.getContentPane().add(lblPos);
		
		JLabel lblValue = new JLabel("Value");
		lblValue.setBounds(207, 63, 46, 13);
		frame.getContentPane().add(lblValue);
		
		JLabel lblPos_1 = new JLabel("Pos");
		lblPos_1.setBounds(344, 63, 23, 13);
		frame.getContentPane().add(lblPos_1);
		
		JLabel lblValue_1 = new JLabel("Value");
		lblValue_1.setBounds(383, 63, 46, 13);
		frame.getContentPane().add(lblValue_1);
		
		tfMemInteger = new JTextField();
		tfMemInteger.setBounds(22, 79, 61, 19);
		frame.getContentPane().add(tfMemInteger);
		tfMemInteger.setColumns(10);
		
		tfPosWrInt = new JTextField();
		tfPosWrInt.setBounds(162, 79, 23, 19);
		frame.getContentPane().add(tfPosWrInt);
		tfPosWrInt.setColumns(10);
		
		tfValueWrInt = new JTextField();
		tfValueWrInt.setBounds(192, 79, 61, 19);
		frame.getContentPane().add(tfValueWrInt);
		tfValueWrInt.setColumns(10);
		
		tfValueReadInt = new JTextField();
		tfValueReadInt.setColumns(10);
		tfValueReadInt.setBounds(368, 79, 61, 19);
		frame.getContentPane().add(tfValueReadInt);
		
		tfPosReadInt = new JTextField();
		tfPosReadInt.setColumns(10);
		tfPosReadInt.setBounds(344, 79, 23, 19);
		frame.getContentPane().add(tfPosReadInt);
		
		//Open Integer memory
		JButton btnOpenInt = new JButton("Open");
		btnOpenInt.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String memName = tfMemInteger.getText(); // Memory Name
				SmClient.open_Memory(memName, 1);        // Memory Type: 1 means integer values
			}
		});
		btnOpenInt.setBounds(10, 108, 85, 21);
		frame.getContentPane().add(btnOpenInt);
		
		// Write Integer value
		JButton btnWriteInt = new JButton("Write");
		btnWriteInt.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String nomMemoria = tfMemInteger.getText();				// Memory Name
				
				int posicion = Integer.parseInt(tfPosWrInt.getText());	// Position where the 
																		// value will be stored
				
				int valor = Integer.parseInt(tfValueWrInt.getText());	// Value to be stored
				
				SmClient.writeInt(nomMemoria, posicion, valor);			// Function use
			}
			
		});
		btnWriteInt.setBounds(168, 108, 85, 21);
		frame.getContentPane().add(btnWriteInt);
		
		// Read Integer Value from shared memory
		JButton btnReadInt = new JButton("Read");
		btnReadInt.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String memName = tfMemInteger.getText();				 // Memory Name
				
				int position = Integer.parseInt(tfPosReadInt.getText()); // position where 
																		 // the value will be read

				int value = SmClient.readInt(memName, position);		// Get value saved in memory
				
				tfValueReadInt.setText(Integer.toString(value));		// Show the value in the interface
				
			}
		});
		btnReadInt.setBounds(344, 108, 85, 21);
		frame.getContentPane().add(btnReadInt);
		
		JLabel lblFloats = new JLabel("Floats");
		lblFloats.setFont(new Font("Tahoma", Font.BOLD, 12));
		lblFloats.setBounds(25, 169, 58, 13);
		frame.getContentPane().add(lblFloats);
		
		tfMemFloat = new JTextField();
		tfMemFloat.setColumns(10);
		tfMemFloat.setBounds(22, 208, 61, 19);
		frame.getContentPane().add(tfMemFloat);
		
		JLabel label_1 = new JLabel("Memory");
		label_1.setBounds(25, 192, 58, 13);
		frame.getContentPane().add(label_1);
		
		// Open Float Memory
		JButton btnOpenFloat = new JButton("Open");
		btnOpenFloat.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String memName = tfMemFloat.getText(); 	// Memory name
				SmClient.open_Memory(memName, 2); 	    // Memory Type: 2 means float values
			}
		});
		btnOpenFloat.setBounds(10, 237, 85, 21);
		frame.getContentPane().add(btnOpenFloat);
		
		tfPosWrFloat = new JTextField();
		tfPosWrFloat.setColumns(10);
		tfPosWrFloat.setBounds(162, 208, 23, 19);
		frame.getContentPane().add(tfPosWrFloat);
		
		JLabel label_2 = new JLabel("Pos");
		label_2.setBounds(174, 192, 23, 13);
		frame.getContentPane().add(label_2);
		
		JLabel label_3 = new JLabel("Value");
		label_3.setBounds(207, 192, 46, 13);
		frame.getContentPane().add(label_3);
		
		tfValueWrFloat = new JTextField();
		tfValueWrFloat.setColumns(10);
		tfValueWrFloat.setBounds(192, 208, 61, 19);
		frame.getContentPane().add(tfValueWrFloat);
		
		//Write Float Value in shared memory
		JButton btnWriteFloat = new JButton("Write");
		btnWriteFloat.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String memName = tfMemFloat.getText();					 // Memory Name
				
				int position = Integer.parseInt(tfPosWrFloat.getText()); // Position where 
																		 // the value will be stored 
				
				float value = Float.parseFloat(tfValueWrFloat.getText());// Value to be stored
				
				SmClient.writeFloat(memName, position, value);			 // Function use
			}
		});
		btnWriteFloat.setBounds(168, 237, 85, 21);
		frame.getContentPane().add(btnWriteFloat);
		
		JLabel label_4 = new JLabel("Pos");
		label_4.setBounds(344, 192, 23, 13);
		frame.getContentPane().add(label_4);
		
		JLabel label_5 = new JLabel("Value");
		label_5.setBounds(383, 192, 46, 13);
		frame.getContentPane().add(label_5);
		
		tfValueReadFloat = new JTextField();
		tfValueReadFloat.setColumns(10);
		tfValueReadFloat.setBounds(368, 208, 61, 19);
		frame.getContentPane().add(tfValueReadFloat);
		
		tfPosReadFloat = new JTextField();
		tfPosReadFloat.setColumns(10);
		tfPosReadFloat.setBounds(344, 208, 23, 19);
		frame.getContentPane().add(tfPosReadFloat);
		
		// Read Float value from shared memory
		JButton btnReadFloat = new JButton("Read");
		btnReadFloat.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String memName = tfMemFloat.getText();						// Memory name
				int position = Integer.parseInt(tfPosReadFloat.getText());  // Position where 
																			// the value will be read
				
				float value = SmClient.readFloat(memName, position);		// Get value saved in memory
				
				tfValueReadFloat.setText(Float.toString(value));			// Show the value in the interface
			}
		});
		btnReadFloat.setBounds(344, 237, 85, 21);
		frame.getContentPane().add(btnReadFloat);
		
		JLabel lblDoubles = new JLabel("Doubles");
		lblDoubles.setFont(new Font("Tahoma", Font.BOLD, 12));
		lblDoubles.setBounds(25, 283, 70, 13);
		frame.getContentPane().add(lblDoubles);
		
		tfMemDouble = new JTextField();
		tfMemDouble.setColumns(10);
		tfMemDouble.setBounds(22, 322, 61, 19);
		frame.getContentPane().add(tfMemDouble);
		
		JLabel label_7 = new JLabel("Memory");
		label_7.setBounds(25, 306, 58, 13);
		frame.getContentPane().add(label_7);
		
		// Open Double Shared Memory
		JButton btnOpenDouble = new JButton("Open");
		btnOpenDouble.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String memName = tfMemDouble.getText(); // Memory Name
				SmClient.open_Memory(memName, 3);  	   // Memory Type: 3 means Double values
			}
		});
		btnOpenDouble.setBounds(10, 351, 85, 21);
		frame.getContentPane().add(btnOpenDouble);
		
		tfPosWrDouble = new JTextField();
		tfPosWrDouble.setColumns(10);
		tfPosWrDouble.setBounds(162, 322, 23, 19);
		frame.getContentPane().add(tfPosWrDouble);
		
		JLabel label_8 = new JLabel("Pos");
		label_8.setBounds(174, 306, 23, 13);
		frame.getContentPane().add(label_8);
		
		JLabel label_9 = new JLabel("Value");
		label_9.setBounds(207, 306, 46, 13);
		frame.getContentPane().add(label_9);
		
		tfValueWrDouble = new JTextField();
		tfValueWrDouble.setColumns(10);
		tfValueWrDouble.setBounds(192, 322, 61, 19);
		frame.getContentPane().add(tfValueWrDouble);
		
		// Write double value in shared memory
		JButton btnWriteDouble = new JButton("Write");
		btnWriteDouble.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String memName = tfMemDouble.getText();						  // Memory Name
				int position = Integer.parseInt(tfPosWrDouble.getText());	  // Position where 
																			  // value will be stored
				
				double value = Double.parseDouble(tfValueWrDouble.getText()); // Value to be stored
				
				SmClient.writeDouble(memName, position, value);				  // Function use
			}
		});
		btnWriteDouble.setBounds(168, 351, 85, 21);
		frame.getContentPane().add(btnWriteDouble);
		
		JLabel label_10 = new JLabel("Pos");
		label_10.setBounds(344, 306, 23, 13);
		frame.getContentPane().add(label_10);
		
		JLabel label_11 = new JLabel("Value");
		label_11.setBounds(383, 306, 46, 13);
		frame.getContentPane().add(label_11);
		
		tfValueReadDouble = new JTextField();
		tfValueReadDouble.setColumns(10);
		tfValueReadDouble.setBounds(368, 322, 61, 19);
		frame.getContentPane().add(tfValueReadDouble);
		
		tfPosReadDouble = new JTextField();
		tfPosReadDouble.setColumns(10);
		tfPosReadDouble.setBounds(344, 322, 23, 19);
		frame.getContentPane().add(tfPosReadDouble);
		
		// Read Double value from shared memory
		JButton btnReadDouble = new JButton("Read");
		btnReadDouble.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String memName = tfMemDouble.getText();						// Memory Name
				int position = Integer.parseInt(tfPosReadDouble.getText()); // Position where 
																			// the value will be read
				
				double value = SmClient.readDouble(memName, position);		// Get value saved in Memory
				
				tfValueReadDouble.setText(Double.toString(value));			// Show value in the interface
			}
		});
		btnReadDouble.setBounds(344, 351, 85, 21);
		frame.getContentPane().add(btnReadDouble);
		
		JLabel lblStrings = new JLabel("Strings");
		lblStrings.setFont(new Font("Tahoma", Font.BOLD, 12));
		lblStrings.setBounds(25, 403, 70, 13);
		frame.getContentPane().add(lblStrings);
		
		tfMemString = new JTextField();
		tfMemString.setColumns(10);
		tfMemString.setBounds(22, 442, 61, 19);
		frame.getContentPane().add(tfMemString);
		
		JLabel label_13 = new JLabel("Memory");
		label_13.setBounds(25, 426, 58, 13);
		frame.getContentPane().add(label_13);
		
		// Open String (char *) Shared memory
		JButton btnOpenString = new JButton("Open");
		btnOpenString.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String memName = tfMemString.getText();		// Memory Name
				SmClient.open_Memory(memName, 4); 			// Memory Type: 3 means Double values
			}
		});
		btnOpenString.setBounds(10, 471, 85, 21);
		frame.getContentPane().add(btnOpenString);
		
		tfPosWrString = new JTextField();
		tfPosWrString.setColumns(10);
		tfPosWrString.setBounds(162, 442, 23, 19);
		frame.getContentPane().add(tfPosWrString);
		
		JLabel label_14 = new JLabel("Pos");
		label_14.setBounds(174, 426, 23, 13);
		frame.getContentPane().add(label_14);
		
		JLabel label_15 = new JLabel("Value");
		label_15.setBounds(207, 426, 46, 13);
		frame.getContentPane().add(label_15);
		
		tfValueWrString = new JTextField();
		tfValueWrString.setColumns(10);
		tfValueWrString.setBounds(192, 442, 61, 19);
		frame.getContentPane().add(tfValueWrString);
		
		// Write String value in the shared memory
		JButton btnWriteString = new JButton("Write");
		btnWriteString.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String memName = tfMemString.getText();					  // Memory Name
				
				int position = Integer.parseInt(tfPosWrString.getText()); // Position where the 
																		  // value will be stored
				
				String value = tfValueWrString.getText();				  // Value to be stored
				
				SmClient.writeString(memName, position, value);			  // Function Use
			}
		});
		btnWriteString.setBounds(168, 471, 85, 21);
		frame.getContentPane().add(btnWriteString);
		
		JLabel label_16 = new JLabel("Pos");
		label_16.setBounds(344, 426, 23, 13);
		frame.getContentPane().add(label_16);
		
		JLabel label_17 = new JLabel("Value");
		label_17.setBounds(383, 426, 46, 13);
		frame.getContentPane().add(label_17);
		
		tfValueReadString = new JTextField();
		tfValueReadString.setColumns(10);
		tfValueReadString.setBounds(368, 442, 61, 19);
		frame.getContentPane().add(tfValueReadString);
		
		tfPosReadString = new JTextField();
		tfPosReadString.setColumns(10);
		tfPosReadString.setBounds(344, 442, 23, 19);
		frame.getContentPane().add(tfPosReadString);
		
		// Read String (char *) From Shared memory
		JButton btnReadString = new JButton("Read");
		btnReadString.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String memName = tfMemString.getText();						// Memory Name
				int position = Integer.parseInt(tfPosReadString.getText()); // Position where the
																			// value will be read
				
				String value = SmClient.readString(memName, position);		// Get value from memory
				
				tfValueReadString.setText(value);							// Show the value in 
																			// the interface
			}
		});
		btnReadString.setBounds(344, 471, 85, 21);
		frame.getContentPane().add(btnReadString);

	}
}
