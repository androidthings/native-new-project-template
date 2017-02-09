Android Things empty project template
=====================================
Use this empty project as a template for your native Android Things project.

Pre-requisites
--------------
- Android Things compatible board
- Android Studio 2.2+
- Android NDK bundle

Build and install
=================

[Download](https://github.com/androidthings/native-libandroidthings/releases) the latest Android Things native library release and extract it in the project root directory.

It should contains the following directories:
```
libandroidthings/
  ${ABI}/
    include/
      pio/
        *.h
    lib/
      libandroidthings.so
```

On Android Studio, click on the "Run" button.
If you prefer to run on the command line, type
```bash
./gradlew installDebug
adb shell am start com.example.androidthings.mynativeproject/android.app.NativeActivity
```

License
-------
Copyright 2016 The Android Open Source Project, Inc.
Licensed to the Apache Software Foundation (ASF) under one or more contributor
license agreements.  See the NOTICE file distributed with this work for
additional information regarding copyright ownership.  The ASF licenses this
file to you under the Apache License, Version 2.0 (the "License"); you may not
use this file except in compliance with the License.  You may obtain a copy of
the License at
  http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
License for the specific language governing permissions and limitations under
the License.
