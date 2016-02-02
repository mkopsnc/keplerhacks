include ../Makefile.common

all: compilejava compilec

compilec:
	cc -g -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) c/sigsegv_SigSegv.c -o lib/libSigSegv.$(EXT)

compilejava:
	$(JAVA_HOME)/bin/javac -d target java/sigsegv/SigSegv.java
	$(JAVA_HOME)/bin/javah -jni -d c -cp target sigsegv.SigSegv
	$(JAVA_HOME)/bin/javac -d target java/sigsegv/SigSegvNoHandler.java
	$(JAVA_HOME)/bin/javah -jni -d c -cp target sigsegv.SigSegvNoHandler

test:
	$(JAVA_HOME)/bin/java -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp target sigsegv.SigSegv
	$(JAVA_HOME)/bin/java -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp target sigsegv.SigSegvNoHandler

clean:
	-rm -rfv target/*
	-rm c/sigsegv_SigSegv.h
	-rm c/sigsegv_SigSegvNoHandler.h
	-rm -rf lib/*
