include ../Makefile.common

all: compilejava compilec

compilec:
	# This compilation pretends that we work with binary lib that we can't compile
	cc -g -shared -fpic c/extLib.c -o lib/libExtLib.$(EXT)

	# This is just a handler to exit (our new implementation of exit)
	cc -g -shared -fpic c/stopExit.c -o lib/libStopExit.$(EXT)
	
	# This compilation pretends that we work with library we can compile from the sources
	# We have to add -Dexit and we have to add library with new exit call handler
	cc -Dexit=stopExit -g -shared -fpic c/extLibCompiled.c -Llib -lStopExit -o lib/libExtLibCompiled.$(EXT)
	# This is the final library for JNI calls
	cc -Dexit=stopExit -g -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) c/dexit_SigTerm.c -Llib -lExtLib -lExtLibCompiled -lStopExit -o lib/libSigTerm.$(EXT)

compilejava:
	$(JAVA_HOME)/bin/javac -d target java/dexit/SigTerm.java
	$(JAVA_HOME)/bin/javah -jni -d c -cp target dexit.SigTerm
	$(JAVA_HOME)/bin/javac -d target java/dexit/SigTermExtLib.java
	$(JAVA_HOME)/bin/javah -jni -d c -cp target dexit.SigTermExtLib

test:
	$(JAVA_HOME)/bin/java -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp target dexit.SigTerm
	$(JAVA_HOME)/bin/java -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp target dexit.SigTermExtLib

clean:
	-rm -rfv target/*
	-rm c/dexit_SigTerm.h
	-rm c/dexit_SigTermExtLib.h
	-rm -rf lib/*
