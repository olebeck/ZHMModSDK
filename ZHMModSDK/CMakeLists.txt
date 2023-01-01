cmake_minimum_required(VERSION 3.20)

file(GLOB_RECURSE SRC_FILES
	CONFIGURE_DEPENDS
	Src/*.cpp
	Src/*.c
	Src/*.hpp
	Src/*.h
)

find_package(directx-headers CONFIG REQUIRED)
find_package(directxmath CONFIG REQUIRED)

add_library(ZHMModSDK SHARED
	${SRC_FILES}
)

target_include_directories(ZHMModSDK
PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/Src
	${CMAKE_SOURCE_DIR}/External/mINI/src/mini
PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include>
	$<INSTALL_INTERFACE:include>
)


target_compile_definitions(ZHMModSDK PRIVATE
	LOADER_EXPORTS
)

if(CTT)
	target_compile_definitions(ZHMModSDK PUBLIC CTT)
endif()

target_link_libraries(ZHMModSDK
PRIVATE
	minhook
	DirectXTK12
	d3d12.lib
	dxgi.lib
	dxguid.lib
	runtimeobject.lib
PUBLIC
	imgui
	d3dcompiler.lib
	Microsoft::DirectXMath
	spdlog_header_only
)


exec_program(git
	ARGS describe --tags --dirty=-d
	OUTPUT_VARIABLE VERSION
)

#parse the version information into pieces.
string(REGEX REPLACE "^v([0-9]+)\\..*" "\\1" VERSION_MAJOR "${VERSION}")
string(REGEX REPLACE "^v[0-9]+\\.([0-9]+).*" "\\1" VERSION_MINOR "${VERSION}")
string(REGEX REPLACE "^v[0-9]+\\.[0-9]+\\.([0-9]+).*" "\\1" VERSION_PATCH "${VERSION}")
string(REGEX REPLACE "^v[0-9]+\\.[0-9]+\\.[0-9]+(.*)" "\\1" VERSION_SHA1 "${VERSION}")
set(VERSION_SHORT "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")


export(TARGETS ZHMModSDK spdlog_header_only imgui
	NAMESPACE ZHMModSDK::
	FILE ZHMModSDKTargets.cmake
)

export(PACKAGE ZHMModSDK)


install(DIRECTORY Include/
	DESTINATION "include"
)

install(TARGETS ZHMModSDK spdlog_header_only imgui
	EXPORT ZHMModSDKTargets
)

install(EXPORT ZHMModSDKTargets
	FILE ZHMModSDKTargets.cmake
	NAMESPACE ZHMModSDK::
	DESTINATION lib/cmake/ZHMModSDK
)


include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ZHMModSDKConfigVersion.cmake
    VERSION ${VERSION_SHORT}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(
	ZHMModSDKConfig.cmake.in
	ZHMModSDKConfig.cmake
	INSTALL_DESTINATION lib/cmake/ZHMModSDK
)

install(FILES 
	${CMAKE_CURRENT_BINARY_DIR}/ZHMModSDKConfig.cmake
	${CMAKE_CURRENT_BINARY_DIR}/ZHMModSDKConfigVersion.cmake
    DESTINATION lib/cmake/ZHMModSDK
)
