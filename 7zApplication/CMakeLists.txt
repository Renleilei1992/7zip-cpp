set(PROJ_NAME 7zApplication)

set(CMAKE_CXX_STANDARD 17)
aux_source_directory(. SOURCE_FILES)

file(GLOB HEADER_FILES *.h)
file(GLOB RESOURCE_FILES *.rc)

source_group("Header Files" FILES ${HEADER_FILES})
source_group("Source Files" FILES ${SOURCE_FILES})
source_group("Resource Files" FILES ${RESOURCE_FILES})

add_executable( ${PROJ_NAME}
	${SOURCE_FILES}
	${HEADER_FILES}
)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/${PROJECT_ARCH})
SET(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/${PROJECT_ARCH})
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${PROJECT_ARCH})

# 静态库 可以不链接
target_link_libraries(${PROJ_NAME} PRIVATE
	lib-7zpp
)

set_target_properties(${PROJ_NAME} PROPERTIES 
	MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
	COMPILE_FLAGS /EHa
)