/* HelloWorldJNI.java */
package jnijna;

public class HelloWorldJNI {

  /* This is the native method we want to call */
  public static native void displayMessageJNI();

  /* Inside static block we will load shared library */
  static {
    System.loadLibrary("HelloWorldJNI");
  }

  public static void main(String[] args) {
    /* This message will help you determine whether
       LD_LIBRARY_PATH is correctly set
    */
    System.out.println("library: " 
			+ System.getProperty("java.library.path"));

    /* Call to shared library */
    HelloWorldJNI.displayMessageJNI();
  }
}

