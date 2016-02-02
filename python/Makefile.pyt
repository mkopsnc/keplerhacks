all:
	gcc -g -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux -lpython2.6 -lm runscript26.c -o libcallpy26.so
