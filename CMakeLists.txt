cmake_minimum_required(VERSION 3.20)

project(spe)
add_executable(spe-win) # WIN32 - hide the console like this add_executable(spe-win WIN32)

target_sources(app
PRIVATE
	main.cpp
)

find_package(SDL3)
target_link_libraries(spe-win PRIVATE SDL3::SDL3)
target_compile_definitions(spe-win PRIVATE SLD_MAINE_USE_CALLBACKS)
target_link_options(spe-win PRIVATE -static)
