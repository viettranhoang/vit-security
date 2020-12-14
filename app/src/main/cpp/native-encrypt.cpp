#include <jni.h>
#include <string>

static const int app_signature_hash_code_debug = 1391684134;
static const int app_signature_hash_code_release = 117722628;
static const int app_signature_hash_code_old = 1153359778;

jboolean is_debug(JNIEnv *env) {
    jclass clazz = env->FindClass("com/vit/security/VITSecurity");
    jmethodID messageMe = env->GetStaticMethodID(clazz, "isDebug","()Z");
    jboolean isDebug = env->CallStaticBooleanMethod(clazz, messageMe);
    return isDebug;
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_vit_security_VITSecurity_adMobInterstitialRandomId(JNIEnv* env, jclass clazz) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_vit_security_VITSecurity_adMobInterstitialNormalId(JNIEnv* env, jclass clazz) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_vit_security_VITSecurity_adMobBannerId(JNIEnv* env, jclass clazz) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_vit_security_VITSecurity_settingUrl(JNIEnv* env, jclass clazz) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_vit_security_VITSecurity_encode(JNIEnv *env, jclass thiz, jobject context, jstring str) {
    return str;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_vit_security_VITSecurity_decode(JNIEnv *env, jclass thiz, jobject context, jstring str) {
    return str;
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_vit_security_VITSecurity_checkSignature(JNIEnv *env, jclass clazz, jobject context) {
//    jclass vitSecurityClazz = env->FindClass("com/vit/security/VITSecurity");
    jmethodID getSignature = env->GetStaticMethodID(clazz, "getSignature",
                                                    "(Landroid/content/Context;)I");
    int code = env->CallStaticIntMethod(clazz, getSignature, context);

    jint app_signature_hash_code = is_debug(env) ? app_signature_hash_code_debug
                                                       : app_signature_hash_code_release;

    if (code != app_signature_hash_code && code != app_signature_hash_code_old) {
        return false;
    }

    return true;

}




