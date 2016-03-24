/* HelloWorldJNA.java */
package jnijna;

import com.sun.jna.Library;
import com.sun.jna.Native;

public class HelloWorldJNA {
    public interface CTest extends Library {
        public void displayMessageJNA();
    }
    static public void main(String argv[]) {
        CTest ctest = (CTest) Native.loadLibrary("HelloWorldJNA", CTest.class);
        ctest.displayMessageJNA();
    }
}
