#include <string>
#include <iostream>
#include <sstream>

#include <jni.h>

#include <android/asset_manager_jni.h>

#include "sentencepiece_processor.h"

static sentencepiece::SentencePieceProcessor processor;

extern "C" {
JNIEXPORT jboolean JNICALL
Java_com_easilydo_smartreply_sentencepiece_SentencepieceProcessor_nLoadModel(
        JNIEnv *env,
        jobject obj, //'this' in Java
        jobject asset_manager,
        jstring jsp_path) {
    const char *sp_path = env->GetStringUTFChars(jsp_path, 0);
    AAssetManager *passet_manager = AAssetManager_fromJava(env, asset_manager);
    AAsset *p_asset = AAssetManager_open(passet_manager, sp_path, AASSET_MODE_BUFFER);

    size_t len = static_cast<size_t>(AAsset_getLength(p_asset));
    char *buf = new char[len];

    AAsset_read(p_asset, buf, len);
    AAsset_close(p_asset);
    env->ReleaseStringUTFChars(jsp_path, sp_path);

    std::istringstream ss(std::string(buf, static_cast<int>(len)));
    return static_cast<jboolean>(processor.LoadFromIstream(ss));
}

JNIEXPORT jintArray JNICALL
Java_com_easilydo_smartreply_sentencepiece_SentencepieceProcessor_nEncode(
        JNIEnv *env,
        jobject obj, //'this' in Java
        jstring jcontent) {
    const char *content = env->GetStringUTFChars(jcontent, 0);
    std::vector<int> encoded;
    processor.Encode(content, &encoded);
    const jintArray output = env->NewIntArray(encoded.size());
    env->SetIntArrayRegion(output, 0, encoded.size(), &encoded[0]);
    env->ReleaseStringUTFChars(jcontent, content);
    return output;
}

JNIEXPORT jstring JNICALL
Java_com_easilydo_smartreply_sentencepiece_SentencepieceProcessor_nDecode(
        JNIEnv *env,
        jobject obj, //'this' in Java
        jintArray jids) {
    const int jids_len = env->GetArrayLength(jids);
    std::vector<int> encoded(jids_len);
    env->GetIntArrayRegion(jids, 0, jids_len, &encoded[0]);
    std::string output;
    processor.Decode(encoded, &output);
    return env->NewStringUTF(output.c_str());
}
}
