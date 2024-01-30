//
// Created by Harris.Lu on 2024/1/30.
//

#ifndef GDCESIUM_TEST_HELLO_CESIUM_H
#define GDCESIUM_TEST_HELLO_CESIUM_H

#include "tests/test_macros.h"

namespace TestCesium {

TEST_CASE("[Cesium] Hello World!") {
//    String engine =
//            String("Godot Engine ") + String(ProjectSettings::get_singleton()->get_setting( "application/config/name_localized" ));
//    WARN_PRINT("Hello Cesium! " + engine);

    WARN_PRINT(vformat("os version: %s , cache_path: %s, platform: %s", OS::get_singleton()->get_version(), OS::get_singleton()->get_cache_path(), OS::get_singleton()->get_name()));

    String hello = "Hello World!";
    CHECK(hello == "Hello World!");
}

}



#endif //GDCESIUM_TEST_HELLO_CESIUM_H
