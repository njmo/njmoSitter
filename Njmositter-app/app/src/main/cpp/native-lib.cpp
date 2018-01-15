#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_njmo_njmositter_1app_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Magda smierdzi jajem i robi zielone kupy";
    return env->NewStringUTF(hello.c_str());
}
