/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <android/log.h>
#include <android_native_app_glue.h>

const char* TAG = "nativeapp";
const int LOOPER_POLL_DELAY_MS = 0;

#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)
#define ASSERT(cond, ...) if (!(cond)) { __android_log_assert(#cond, TAG, __VA_ARGS__);}

void android_main(android_app* app) {
    while (!app->destroyRequested) {
        android_poll_source* source;
        int pollResult = ALooper_pollOnce(LOOPER_POLL_DELAY_MS,
                                          NULL, NULL, reinterpret_cast<void**>(&source));
        if (pollResult >= 0) {
            if (source != NULL) {
                // forward event to native-app-glue to handle lifecycle and input event
                // and update `app` state.
                source->process(app, source);
            }
        }
    }
}
