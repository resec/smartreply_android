LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := sentencepiece-prebuilt
LOCAL_SRC_FILES := ../../../libs/$(TARGET_ARCH_ABI)/libsentencepiece.so
LOCAL_EXPORT_C_INCLUDES := include/sentencepiece
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := sentencepiece_processor_jni
LOCAL_SRC_FILES := sentencepiece_processor_jni.cc
LOCAL_CPP_EXTENSION := .cc
LOCAL_C_INCLUDES := src/main/cpp
LOCAL_CFLAGS += --std=c++11 -fPIC
LOCAL_LDLIBS += -landroid
LOCAL_SHARED_LIBRARIES := sentencepiece-prebuilt
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := signature_processor_jni
LOCAL_SRC_FILES := signature.cc signature_processor_jni.cc
LOCAL_CPP_EXTENSION := .cc
LOCAL_C_INCLUDES := src/main/cpp
LOCAL_CFLAGS += --std=c++11 -fPIC
LOCAL_LDLIBS += -latomic
include $(BUILD_SHARED_LIBRARY)
