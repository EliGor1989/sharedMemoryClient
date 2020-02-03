package eros;

public class SmClient {
	public native int openMemory(String nombre, int type);  
	
    public native int getInt(String memName, int position);
    public native void setInt(String memName, int position, int value);
    
    public native void setFloat(String memName, int position, float value);
	public native float getFloat(String memName, int position);
	
	public native void setDouble(String memName, int position, double value);
	public native double getDouble(String memName, int position);
		
	public native void setString(String memName, int position, String word);
	public native String getString(String memName, int position);
	
	public native int createMemory(String memName, int quantity, int type);
	public native void freeMemories();
	public native void freeViews();
	
	/*
     * Use this path if the dll is 32 bits and is located in the 'System32' folder on a 64-bit system,
     * System.loadLibrary("C:\\Windows\\SysNative\\smClientJava");
     * 
     * Java 32Bits = smClientJava
     * Java 64Bits = smClientJava64
	*/
	
	static {      
	System.loadLibrary("smClientJava64");   
	} 
		
    public static SmClient smClient = new SmClient();
    
    /**
     * <p> Free the memory of all open memories
     * </p>
     */
    public static void free_Memories() {
    	smClient.freeMemories();
    }
    
    /**
     * <p> Free the Views of all open memories
     * </p>
     */
    public static void free_Views() {
    	smClient.freeViews();
    }
    
    /**
     * <p>Create a shared memory with the name, number of spaces and type specified
     * </p>
     * @param namMemory shared memory name
     * @param quantity Specify the number of variables to be stored
     * @param type Type of memory to be created: 1 = Integer, 2 = Float, 3 = Double, 4 = Char *  
     * The default limit for char * type is 13 characters
     * @return Returns 0 if it was executed correctly
     */
    public static int create_Memory(String namMemory, int quantity, int type) {
    	int retorno = smClient.createMemory(namMemory, quantity, type);
    	return retorno;
    }
       
    /**
     * <p>Read the String type value from the specified memory and location.
     * </p>
     * @param namMemory shared memory name
     * @param position Position of the variable we want to read
     * @return Returns the word stored in the indicated position
     */
    public static String readString(String namMemory, int position) {
    	String valor = smClient.getString(namMemory, position);
    	return valor;
    }
    
    /**
     * <p>Write a value of type String in the memory and indicated position.
     * </p>
     * @param namMemory shared memory name
     * @param position Position of the variable we want to read
     * @param word String type value to be stored
     */
    public static void writeString(String namMemory, int position, String word) {
    	smClient.setString(namMemory, position, word);
    }
    
    /**
     * <p>Read the Double type value from the specified memory and location.
     * </p>
     * @param namMemory shared memory name
     * @param position Position of the variable we want to read
     * @return Returns the Double type Value stored in the indicated position
     */
    public static double readDouble(String namMemory, int position) {
    	double retorno = smClient.getDouble(namMemory, position);
    	return retorno;
    }
    
    /**
     * <p>Write a value of type Double in the memory and indicated position.
     * </p>
     * @param namMemory shared memory name
     * @param position Position of the variable we want to read
     * @param value Double type value to be stored
     */
    public static void writeDouble(String namMemory, int position, double value) {
    	smClient.setDouble(namMemory, position, value);
    }
    
    /**
     * <p>Read the Float type value from the specified memory and location.
     * </p>
     * @param namMemory shared memory name
     * @param position Position of the variable we want to read
     * @return Returns the Float type Value stored in the indicated position
     */
    public static float readFloat(String namMemory, int position) {
    	float retorno = smClient.getFloat(namMemory, position);
    	return retorno;
    }
    
    /**
     * <p>Write a value of type Float in the memory and indicated position.
     * </p>
     * @param namMemory shared memory name
     * @param position Position of the variable we want to read
     * @param value Float type value to be stored
     */
    public static void writeFloat(String namMemory, int position, float value) {
    	smClient.setFloat(namMemory, position, value);
    }
    
    /**
     * <p>Write a value of type Integer in the memory and indicated position.
     * </p>
     * @param namMemory shared memory name
     * @param position Position of the variable we want to read
     * @param value Integer type value to be stored
     */
    public static void writeInt(String namMemory, int position, int value) {
    	smClient.setInt(namMemory, position, value);
    }
    
    /**
     * <p>Read the Integer type value from the specified memory and location.
     * </p>
     * @param namMemory shared memory name
     * @param position Position of the variable we want to read
     * @return Returns the Integer type value stored in the indicated position
     */
    public static int readInt(String namMemory, int position) {
		int retorno = smClient.getInt(namMemory, position);
		return retorno;
	}

    /**
     * <p>Function that opens a previously created shared memory
     * </p>
     * @param namMemory shared memory name
     * @param type Type of memory to be opened: 1 = Integer, 2 = Float, 3 = Double, 4 = Char *
     * @return Returns 0 if it was executed correctly
     */
    public static int open_Memory(String namMemory, int type){
		int retorno = smClient.openMemory(namMemory, type);
		return retorno;
	}
    
}
