#include <string>

#include <jni.h>

#include "signature.h"

extern "C" {
JNIEXPORT jstring JNICALL
Java_com_easilydo_smartreply_signature_SignatureProcessor_nRemoveSignature(
        JNIEnv * env,
        jobject obj, //'this' in Java
        jstring jcontent,
        jstring jsender,
        jobjectArray jrecipients) {
    const char * content = env->GetStringUTFChars(jcontent, 0);
    const char * sender = env->GetStringUTFChars(jsender, 0);
    const int jrecipients_len = env->GetArrayLength(jrecipients);
    std::string content_str(content);
    std::string sender_str(sender);
    std::vector<std::string> recipients_str(jrecipients_len);
    for (int i=0; i<jrecipients_len; i++) {
        const jstring jrecipient = (jstring) env->GetObjectArrayElement(jrecipients, i);
        const char * recipient = env->GetStringUTFChars(jrecipient, 0);
        std::string recipient_str(recipient);
        env->ReleaseStringUTFChars(jrecipient, recipient);
        recipients_str.push_back(recipient_str);
    }
    const std::string cleaned = signature::RemoveSignature(content_str, sender_str, recipients_str);
    env->ReleaseStringUTFChars(jcontent, content);
    env->ReleaseStringUTFChars(jsender, sender);
    return env->NewStringUTF(cleaned.c_str());
}
}
