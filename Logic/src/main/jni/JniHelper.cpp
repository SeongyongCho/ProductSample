//
// Created by sycho on 2019-04-30.
//

#include <jni.h>
#include <string>

#include <android/log.h>

#include "Logic.h"

#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, "native_logic", __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG  , "native_logic", __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO   , "native_logic", __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN   , "native_logic", __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR  , "native_logic", __VA_ARGS__)

namespace native_logic {

    static jfieldID ptrFieldId = nullptr;

    jfieldID getPtrFieldId(JNIEnv *env, jobject obj) {
        if (!ptrFieldId) {
            jclass c = env->GetObjectClass(obj);
            ptrFieldId = env->GetFieldID(c, "objPtr", "J");
            env->DeleteLocalRef(c);
        }

        return ptrFieldId;
    }

    extern "C" {

        JNIEXPORT void JNICALL Java_com_sycho_logic_Logic_createCppObject(JNIEnv *env, jobject obj) {
            env->SetLongField(obj, getPtrFieldId(env, obj), (jlong) new Logic);
        }

        JNIEXPORT void JNICALL Java_com_sycho_logic_Logic_setValues(JNIEnv *env, jobject obj, jint a, jint b) {
            LOGD("setValues %d, %d", a, b);
            auto * logic = (Logic*) env->GetLongField(obj, getPtrFieldId(env, obj));
            logic->setValue(a, b);
        }

        JNIEXPORT jint JNICALL Java_com_sycho_logic_Logic_add(JNIEnv *env, jobject obj) {
            auto * logic = (Logic*) env->GetLongField(obj, getPtrFieldId(env, obj));
            jint result = logic->add();
            LOGD("add %d", result);
            return result;
        }

        JNIEXPORT void JNICALL Java_com_sycho_logic_Logic_deleteCppObject(JNIEnv *env, jobject obj) {
            auto * logic = (Logic*) env->GetLongField(obj, getPtrFieldId(env, obj));
            delete logic;
        }
    }
}