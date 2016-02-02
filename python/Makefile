include ../Makefile.common

all: compilejava compilec

compilec:
	cc -g -shared -fpic -I${JAVA_HOME}/include -I${JAVA_HOME}/include/$(ARCH) -lpython2.7 -lm c/runscript27.c -o lib/libcallpy27.$(EXT)

compilejava:
	$(JAVA_HOME)/bin/javac -d target java/python/Python.java

test:
	$(JAVA_HOME)/bin/java -Djava.library.path=$(LD_LIBRARY_PATH):./lib -cp target python.Python

clean:
	-rm -rfv target/*
	-rm -rf lib/*
