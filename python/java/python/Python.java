package python;

import java.io.*;

/**
 * This class illustrates execution of Python script directly from the Java
 * Using Python library (we call it from JNI wrapper) it's possible to call
 * regular python script.
 **/
public class Python {
	// we want to load Python library
        // note that library must be Python dependent
	static {
		System.loadLibrary("callpy27");
		Python.pyinitialize();
	}

	// some functions we want to call via JNI
	public static native void runscript27(String script, String name);
	public static native void pyinitialize();
	public static native void pyfinalize();

	public static void main(String [] arg) {
		// Super simple sctipt to call
		String script = "print 'Hello from python'";
		
		try {
			// we have to store it in external file (it's also possible to pass
                        // the script itself). Due to the fact we have no idea what will be the
                        // size of the script, or due to the fact we want to call some existing file
                        // we pass the file name. It will be executed from JNI lib.
			PrintWriter writer = new PrintWriter("script.py", "UTF-8");
			writer.println(script);
			writer.flush();
			writer.close();

			// oce file is ready, just call it
			runscript27("script.py", "test");
		} catch(Exception ex) {
			ex.printStackTrace();
		}
	}
}
