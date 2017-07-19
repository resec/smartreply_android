package com.easilydo.smartreply.sentencepiece;

import android.content.res.AssetManager;
import android.util.Log;

public class SentencepieceProcessor implements SentencepieceProcessorInterface {

    private static final String TAG = SentencepieceProcessor.class.getSimpleName();
    private static final String NATIVE_LIB_NAME = "sentencepiece_processor_jni";

    /*
     * Initialize SentencepieceProcessor with a Sentenpiece model from the AssetManager.
     * It will try to find the native lib automatically.
     *
     * @param assetManager The AssetManager to use to load the model file.
     * @param model The filepath to the proto file representing the model.
     */
    public SentencepieceProcessor(AssetManager assetManager, String model) {
        Log.i(TAG, "Checking to see if Sentencepiece native methods are already loaded");
        try {
            // Hack to see if the native libraries have been loaded.
            nEncode("Test");
            Log.i(TAG, "Sentencepiece native methods already loaded");
        } catch (UnsatisfiedLinkError e1) {
            Log.i(TAG, "Sentencepiece native methods not found, attempting to load via " + NATIVE_LIB_NAME);
            try {
                System.loadLibrary(NATIVE_LIB_NAME);
                Log.i(TAG, "Successfully loaded Sentencepiece native methods");
            } catch (UnsatisfiedLinkError e2) {
                throw new RuntimeException(
                        "Native Sentencepiece methods not found; check that the correct native"
                                + " libraries are present in the APK.");
            }
        }

        final long startMs = System.currentTimeMillis();
        if (!nLoadModel(assetManager, model)) {
            throw new RuntimeException("Failed to load model from " + model);
        } else {
            final long endMs = System.currentTimeMillis();
            Log.i(TAG, "Model load took " + (endMs - startMs) + "ms");
        }
    }

    @Override
    public int[] encode(String content) {
        return nEncode(content);
    }

    @Override
    public String decode(int[] ids) {
        return nDecode(ids);
    }

    private native int[] nEncode(String content);

    private native String nDecode(int[] ids);

    private native boolean nLoadModel(AssetManager assetManager, String model);

}
