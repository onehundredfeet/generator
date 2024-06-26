cmake_minimum_required(VERSION 3.12)
project(generator)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(GNUInstallDirs)

if(MSVC)
	add_definitions(/W3)
else()
	add_definitions(-std=c++20 -pedantic -Wall -Wextra)
endif()

set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

include_directories(${CMAKE_SOURCE_DIR}/include)

option(GENERATOR_USE_GLM "Use GLM instead of GML (experimental)" OFF)
if(GENERATOR_USE_GLM)
	message(STATUS "Using GLM instead of GML for math (note the similar names).  Support for this is experimental!")
	add_definitions(-DGENERATOR_USE_GLM -DGLM_ENABLE_EXPERIMENTAL)
endif()

if(GENERATOR_USE_GLM)
	option(GENERATOR_SUFFIX_GLM "Suffix library name with 'glm' when using GLM (otherwise, does nothing)" OFF)
	set(GLM_INCLUDE_DIR "" CACHE FILEPATH "GLM include path")

	if(GENERATOR_SUFFIX_GLM AND GENERATOR_USE_GLM)
		set(SUFFIX "-glm")
	endif()
else()
	set(GML_INCLUDE_DIR "" CACHE FILEPATH "GML include path")
endif()

if(GML_INCLUDE_DIR AND NOT GENERATOR_USE_GLM)
	include_directories(SYSTEM ${GML_INCLUDE_DIR})
elseif(GLM_INCLUDE_DIR AND GENERATOR_USE_GLM)
	include_directories(SYSTEM ${GLM_INCLUDE_DIR})
endif()

set(TARGET_NAME ${CMAKE_STATIC_LIBRARY_PREFIX}generator${SUFFIX}${CMAKE_STATIC_LIBRARY_SUFFIX})

message(STATUS "Target name is '${TARGET_NAME}'")

add_subdirectory(src)
add_subdirectory(images)

install(DIRECTORY include/generator DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES lib/${TARGET_NAME} DESTINATION ${CMAKE_INSTALL_LIBDIR})
