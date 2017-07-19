package com.easilydo.smartreply.signature;

import android.util.Log;

public class SignatureProcessor implements SignatureProcessorInterface {

    private static final String TAG = SignatureProcessor.class.getSimpleName();
    private static final String NATIVE_LIB_NAME = "signature_processor_jni";

    /*
     * Initialize SignatureProcessor. It will try to find the native lib automatically.
     */
    public SignatureProcessor() {
        Log.i(TAG, "Checking to see if Signature native methods are already loaded");
        try {
            // Hack to see if the native libraries have been loaded.
            nRemoveSignature("Test", "Test", new String[]{"Test"});
            Log.i(TAG, "Signature native methods already loaded");
        } catch (UnsatisfiedLinkError e1) {
            Log.i(TAG, "Signature native methods not found, attempting to load via " + NATIVE_LIB_NAME);
            try {
                System.loadLibrary(NATIVE_LIB_NAME);
                Log.i(TAG, "Successfully loaded Signature native methods");
            } catch (UnsatisfiedLinkError e2) {
                throw new RuntimeException(
                        "Native Signature methods not found; check that the correct native"
                                + " libraries are present in the APK.");
            }
        }
    }

    @Override
    public String removeSignature(String content, String sender, String[] recipients) {
    	return nRemoveSignature(content, sender, recipients);
    }

    private native String nRemoveSignature(String content, String sender, String[] recipients);
}