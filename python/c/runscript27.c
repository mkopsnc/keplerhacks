#include "jni.h"
#include "runscript27.h"
#include "python/Python.h"
#include <stdio.h>

static PyThreadState *tstate = NULL;
static PyGILState_STATE gstate = 0;

// Initialization should be done once
JNIEXPORT void JNICALL Java_python_Python_pyinitialize
  (JNIEnv *env, jclass obj) {
	
	Py_Initialize();

	// This is important!!
	// Remember to reserve PyGILState
	// It is not thread safe	
	gstate = PyGILState_Ensure();
}

// Finalization should be done once
JNIEXPORT void JNICALL Java_python_Python_pyfinalize
  (JNIEnv *env, jclass obj) {

  // once finished remember to release GIL
  PyGILState_Release(gstate);

  Py_Finalize();

}

JNIEXPORT void JNICALL Java_python_Python_runstring27
  (JNIEnv *env, jclass obj, jstring str) {
 
  // we have to get string bytes into C string
  const char *c_str;
  c_str = (*env)->GetStringUTFChars(env, str, NULL);
  if(c_str == NULL) {
    return;
  }

  // Some info for the user
  printf("Script from python.Python: %s\n", c_str);

  PyRun_SimpleString( c_str );

  // after using it, remember to release the memory
  (*env)->ReleaseStringUTFChars(env, str, c_str);
}

JNIEXPORT void JNICALL Java_python_Python_runscript27
  (JNIEnv *env, jclass obj, jstring str, jstring name) {
 
  // we have to get string bytes into C string
  const char *c_str;
  c_str = (*env)->GetStringUTFChars(env, str, NULL);
  if(c_str == NULL) {
    return;
  }

  // we have to get string bytes into C string
  const char *c_name;
  c_name = (*env)->GetStringUTFChars(env, name, NULL);
  if(c_name == NULL) {
    return;
  }

  // Some info for the user
  printf("Script from python.Python: %s\n", c_name);
  printf("File with script: %s\n",c_str);

  // We will open file passed as argument
  // and call this script via Python library	
  FILE* file;
  file = fopen(c_str,"r");
	
  PyRun_SimpleFile(file, c_str);

  // close file, clean up, and return. That's it.
  fclose(file);

  // after using it, remember to release the memory
  (*env)->ReleaseStringUTFChars(env, str, c_str);
  (*env)->ReleaseStringUTFChars(env, str, c_name);
}
