package python;

import java.io.*;

public class Python {

	static {
		System.loadLibrary("callpy27");
		Python.pyinitialize();
	}

	public static native void runscript27(String script, String name);
	public static native void pyinitialize();
	public static native void pyfinalize();

	public static void main(String [] arg) {
		String script = "print 'Hello from python'";
		
		try {
			PrintWriter writer = new PrintWriter("script.py", "UTF-8");
			writer.println(script);
			writer.flush();
			writer.close();

			runscript27("script.py", "test");
		} catch(Exception ex) {
			ex.printStackTrace();
		}
	}
}
