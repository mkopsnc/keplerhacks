#include "jni.h"
#include "runscript27.h"
#include "python/Python.h"
#include <stdio.h>

static PyThreadState *tstate = NULL;

JNIEXPORT void JNICALL Java_python_Python_pyinitialize
  (JNIEnv *env, jclass obj) {
	
	Py_Initialize();
}

JNIEXPORT void JNICALL Java_python_Python_pyfinalize
  (JNIEnv *env, jclass obj) {

  Py_Finalize();

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

  printf("Script from python.Python: %s\n", c_name);
  printf("File with script: %s\n",c_str);
	
  FILE* file;
  file = fopen(c_str,"r");
	
  PyGILState_STATE gstate;
  gstate = PyGILState_Ensure();
	
  PyRun_SimpleFile(file, c_str);

  PyGILState_Release(gstate);

  fclose(file);

  // after using it, remember to release the memory
  (*env)->ReleaseStringUTFChars(env, str, c_str);
  (*env)->ReleaseStringUTFChars(env, str, c_name);
}
