cmake_minimum_required(VERSION 3.12)

add_library(imgui STATIC
	source/imgui.cpp
	source/imgui_draw.cpp
	source/imgui_tables.cpp
	source/imgui_widgets.cpp
	source/imgui_demo.cpp
	source/backends/imgui_impl_dx12.cpp
	source/misc/cpp/imgui_stdlib.cpp
)

target_include_directories(imgui PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/source>
	$<INSTALL_INTERFACE:include/imgui>
)

target_link_libraries(imgui
	imm32.lib
)

install(TARGETS imgui
	EXPORT imguiTargets
	INCLUDES DESTINATION include
)

install(FILES
	source/imgui.h
	source/imgui_internal.h
	source/imstb_rectpack.h
	source/imstb_textedit.h
	source/imstb_truetype.h
	source/backends/imgui_impl_dx12.h
DESTINATION include/imgui
)
