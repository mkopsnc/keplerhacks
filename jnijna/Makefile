include ../Makefile.common

all: compilejava compilec

compilec:
	cc -g -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) c/jnijna_HelloWorldJNI.c -o lib/libHelloWorldJNI.$(EXT)
	cc -g -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) c/jnijna_HelloWorldJNA.c -o lib/libHelloWorldJNA.$(EXT)

compilejava:
	$(JAVA_HOME)/bin/javac -d target java/jnijna/HelloWorldJNI.java
	$(JAVA_HOME)/bin/javah -jni -d c -cp target jnijna.HelloWorldJNI

	$(JAVA_HOME)/bin/javac -cp ./jar/jna-4.2.2.jar -d target java/jnijna/HelloWorldJNA.java

test:
	$(JAVA_HOME)/bin/java -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp target jnijna.HelloWorldJNI
	$(JAVA_HOME)/bin/java -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp ./lib:target:./jar/jna-4.2.2.jar jnijna.HelloWorldJNA

clean:
	-rm -rfv target/*
	-rm c/jnijna_HelloWorldJNI.h
	-rm -rf lib/*
