//
// Created by Harris.Lu on 2024/1/30.
//

#ifndef GDCESIUM_TEST_HELLO_CESIUM_H
#define GDCESIUM_TEST_HELLO_CESIUM_H

#include "core/io/file_access.h"
#include "tests/test_macros.h"

namespace TestCesium {
namespace {
	const char fileProtocol[] = "file:///";
	bool isFile(const std::string& url)
	{
		return url.compare(0, sizeof(fileProtocol) - 1, fileProtocol) == 0;
	}

	std::string convertFileUriToFilename(const std::string& url) {
		// According to the uriparser docs, both uriUriStringToWindowsFilenameA and
		// uriUriStringToUnixFilenameA require an output buffer with space for at most
		// length(url)+1 characters.
		// https://uriparser.github.io/doc/api/latest/Uri_8h.html#a4afbc8453c7013b9618259bc57d81a39
		std::string result(url.size() + 1, '\0');

// #ifdef _WIN32
// 		int errorCode = uriUriStringToWindowsFilenameA(url.c_str(), result.data());
// #else
// 		int errorCode = uriUriStringToUnixFilenameA(url.c_str(), result.data());
// #endif

		// Truncate the string if necessary by finding the first null character.
		// size_t end = result.find('\0');
		// if (end != std::string::npos) {
		// 	result.resize(end);
		// }
		//
		// // Remove query parameters from the URL if present, as they are no longer
		// // ignored by Unreal.
		// size_t pos = result.find("?");
		// if (pos != std::string::npos) {
		// 	result.erase(pos);
		// }

		return url;
	}

}

TEST_CASE("[Cesium] Demo1") {
//    String engine =
//            String("Godot Engine ") + String(ProjectSettings::get_singleton()->get_setting( "application/config/name_localized" ));
//    WARN_PRINT("Hello Cesium! " + engine);
    WARN_PRINT(vformat("os version: %s , cache_path: %s, platform: %s", OS::get_singleton()->get_version(), OS::get_singleton()->get_cache_path(), OS::get_singleton()->get_name()));

    String hello = "Hello World!";
    CHECK(hello == "Hello World!");
}

TEST_CASE("[Cesium] Demo2") {
	String file = "C:/Users/10968/Desktop/WorkSpace/engine/cesium-godot/engine/GDExtensionTemplate/extern/cesium-native/Cesium3DTilesSelection/test/data/MultipleKindsOfTilesets/EmptyTileTileset.json";
	// bool isfile = isFile(file.utf8().get_data());
	// // Ref<FileAccess> f = FileAccess::open(TestUtils::get_data_path("testdata.csv"), FileAccess::READ);
	// if(isfile) {
	// 	WARN_PRINT("isfile");
	// } else {
	// 	WARN_PRINT("not file");
	// }

	// String realFile = convertFileUriToFilename(file.utf8().get_data()).c_str();

	// WARN_PRINT(vformat(" >>>> %s", realFile));
	Vector<uint8_t> array = FileAccess::get_file_as_bytes(file);

	// Ref<FileAccess> f = FileAccess::open(file, FileAccess::READ);
	// REQUIRE(!f.is_null());
	//
	// String text = f->get_buffer();
	// WARN_PRINT(text);

}


}



#endif //GDCESIUM_TEST_HELLO_CESIUM_H
