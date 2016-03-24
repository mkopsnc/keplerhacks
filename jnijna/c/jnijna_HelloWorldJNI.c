#include <stdio.h>
#include "jni.h"
#include "jnijna_HelloWorldJNI.h"

JNIEXPORT void JNICALL Java_jnijna_HelloWorldJNI_displayMessageJNI
  (JNIEnv *env, jclass obj) {

	printf("Hello world!\n");

}
