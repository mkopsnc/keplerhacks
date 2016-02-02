include ../Makefile.common

all: compilejava compilec

compilec:
	cc -g -shared -fpic c/externalLib.c -o lib/libExternalLib.$(EXT)
	cc -g -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) -Llib -lExternalLib c/atexit_SigTerm.c -o lib/libSigTerm.$(EXT)

compilejava:
	$(JAVA_HOME)/bin/javac -d target java/atexit/SigTerm.java
	$(JAVA_HOME)/bin/javah -jni -d c -cp target atexit.SigTerm
	$(JAVA_HOME)/bin/javac -d target java/atexit/SigTermNoHandler.java
	$(JAVA_HOME)/bin/javah -jni -d c -cp target atexit.SigTermNoHandler

test:
	$(JAVA_HOME)/bin/java -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp target atexit.SigTerm
	$(JAVA_HOME)/bin/java -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp target atexit.SigTermNoHandler

clean:
	-rm -rfv target/*
	-rm c/atexit_SigTerm.h
	-rm c/atexit_SigTermNoHandler.h
	-rm -rf lib/*
