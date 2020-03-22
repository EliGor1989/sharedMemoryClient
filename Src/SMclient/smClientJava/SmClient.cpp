#include "eros_SmClient.hpp"
#include <ctype.h>
#include <string.h>
#include "../smClient/functions.c"


/*
 * Class:     eros_SmClient
 * Method:    openMemory
 * Signature: (Ljava/lang/String;I)I
 */
 
JNIEXPORT jint JNICALL Java_eros_SmClient_openMemory
  (JNIEnv* env, jobject obj, jstring memoryName, jint typeCode){
	  const char* str = env->GetStringUTFChars(memoryName, 0);
      char memory_name[32];
      strcpy(memory_name, str);
      env->ReleaseStringUTFChars(memoryName, str);
	
	  return open_Memory(memory_name, typeCode);
	  
  }

/*
 * Class:     eros_SmClient
 * Method:    getInt
 * Signature: (Ljava/lang/String;I)I
 */
JNIEXPORT jint JNICALL Java_eros_SmClient_getInt
  (JNIEnv* env, jobject obj, jstring memoryName, jint valuePosition){
	  const char* str = env->GetStringUTFChars(memoryName, 0);
      char memory_name[32];
      strcpy(memory_name, str);
      env->ReleaseStringUTFChars(memoryName, str);
	  
	  return get_Int(memory_name, valuePosition);
  }

/*
 * Class:     eros_SmClient
 * Method:    setInt
 * Signature: (Ljava/lang/String;II)V
 */
JNIEXPORT void JNICALL Java_eros_SmClient_setInt
  (JNIEnv* env, jobject obj, jstring memoryName, jint valuePosition, jint value){
	  const char* str = env->GetStringUTFChars(memoryName, 0);
      char memory_name[32];
      strcpy(memory_name, str);
      env->ReleaseStringUTFChars(memoryName, str);
	  
	  set_Int(memory_name, valuePosition, value);
  }

/*
 * Class:     eros_SmClient
 * Method:    setFloat
 * Signature: (Ljava/lang/String;IF)V
 */
JNIEXPORT void JNICALL Java_eros_SmClient_setFloat
  (JNIEnv* env, jobject obj, jstring memoryName, jint valuePosition, jfloat value){
	  const char* str = env->GetStringUTFChars(memoryName, 0);
      char memory_name[32];
      strcpy(memory_name, str);
      env->ReleaseStringUTFChars(memoryName, str);
	  
	  set_Float(memory_name, valuePosition, value);
  }

/*
 * Class:     eros_SmClient
 * Method:    getFloat
 * Signature: (Ljava/lang/String;I)F
 */
JNIEXPORT jfloat JNICALL Java_eros_SmClient_getFloat
  (JNIEnv* env, jobject obj, jstring memoryName, jint valuePosition){
	  const char* str = env->GetStringUTFChars(memoryName, 0);
      char memory_name[32];
      strcpy(memory_name, str);
      env->ReleaseStringUTFChars(memoryName, str);
	  
	  return get_Float(memory_name, valuePosition);
  }

/*
 * Class:     eros_SmClient
 * Method:    setDouble
 * Signature: (Ljava/lang/String;ID)V
 */
JNIEXPORT void JNICALL Java_eros_SmClient_setDouble
  (JNIEnv* env, jobject obj, jstring memoryName, jint valuePosition, jdouble value){
	  const char* str = env->GetStringUTFChars(memoryName, 0);
      char memory_name[32];
      strcpy(memory_name, str);
      env->ReleaseStringUTFChars(memoryName, str);
	  
	  set_Double(memory_name, valuePosition, value);
  }

/*
 * Class:     eros_SmClient
 * Method:    getDouble
 * Signature: (Ljava/lang/String;I)D
 */
JNIEXPORT jdouble JNICALL Java_eros_SmClient_getDouble
  (JNIEnv* env, jobject obj, jstring memoryName, jint valuePosition){
	  const char* str = env->GetStringUTFChars(memoryName, 0);
      char memory_name[32];
      strcpy(memory_name, str);
      env->ReleaseStringUTFChars(memoryName, str);
	  
	  return get_Double(memory_name, valuePosition);
  }

/*
 * Class:     eros_SmClient
 * Method:    setString
 * Signature: (Ljava/lang/String;ILjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_eros_SmClient_setString
  (JNIEnv* env, jobject obj, jstring memoryName, jint valuePosition, jstring strValue){
	  const char* str = env->GetStringUTFChars(memoryName, 0);
	  const char* mensaje = env->GetStringUTFChars(strValue, 0);
	  
      char memory_name[32];
	  char str_Value[13];
	  
      strcpy(memory_name, str);
	  strcpy(str_Value, mensaje);
	  
      env->ReleaseStringUTFChars(memoryName, str);
	  env->ReleaseStringUTFChars(strValue, mensaje);
	  
	  set_String(memory_name,valuePosition,str_Value);
  }

/*
 * Class:     eros_SmClient
 * Method:    getString
 * Signature: (Ljava/lang/String;I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_eros_SmClient_getString
  (JNIEnv* env, jobject obj, jstring memoryName, jint valuePosition){
	  const char* str = env->GetStringUTFChars(memoryName, 0);
	  
      char memory_name[32];
	  char strRetValue[13];
	  
      strcpy(memory_name, str);
	  
      env->ReleaseStringUTFChars(memoryName, str);
	  
	  get_String(memory_name,valuePosition,strRetValue);
	  
	  return env->NewStringUTF(strRetValue);
  }
/*
 * Class:     eros_SmClient
 * Method:    createMemory
 * Signature: (Ljava/lang/String;II)I
 */
JNIEXPORT jint JNICALL Java_eros_SmClient_createMemory
  (JNIEnv* env, jobject obj, jstring memoryName, jint cant, jint typeCode){
	  const char* str = env->GetStringUTFChars(memoryName, 0);
      char memory_name[32];
      strcpy(memory_name, str);
      env->ReleaseStringUTFChars(memoryName, str);
	  
	  return create_Memory(memory_name, cant, typeCode);
  }

/*
 * Class:     eros_SmClient
 * Method:    freeMemories
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_eros_SmClient_freeMemories
  (JNIEnv* env, jobject obj){
	  free_Memories();
  }

/*
 * Class:     eros_SmClient
 * Method:    freeViews
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_eros_SmClient_freeViews
  (JNIEnv* env, jobject obj){
	  free_Views();
  }
