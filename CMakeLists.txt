cmake_policy(SET CMP0091 NEW)
cmake_minimum_required(VERSION 3.14.1)
project(My7z)

# Determine the platform.
if("${CMAKE_SYSTEM_NAME}" STREQUAL "Darwin")
  set(OS_MACOSX 1)
  set(OS_POSIX 1)
elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
  set(OS_LINUX 1)
  set(OS_POSIX 1)
elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
  set(OS_WINDOWS 1)
endif()

# Determine the project architecture.
if(NOT DEFINED PROJECT_ARCH)
  if(CMAKE_SIZEOF_VOID_P MATCHES 8)
    set(PROJECT_ARCH "x64")
  else()
    set(PROJECT_ARCH "x86")
  endif()

  if(OS_MACOSX)
    # PROJECT_ARCH should be specified on Mac OS X.
    message(WARNING "No PROJECT_ARCH value specified, using ${PROJECT_ARCH}")
  endif()
endif()

if(OS_WINDOWS)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /source-charset:utf-8")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")
    set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")
elseif(OS_LINUX)
  MESSAGE("platform linux not supported !")
endif()


## add 7z lib\
add_subdirectory(7zpp)
# file(GLOB 7ZPP_SOURCES  ${PROJECT_SOURCE_DIR}/7zpp/*.cpp )
# add_library(7zpp ${7ZPP_SOURCES})
# target_include_directories(7zpp PRIVATE  ${PROJECT_SOURCE_DIR}   ${PROJECT_SOURCE_DIR}/7zpp ${PROJECT_SOURCE_DIR}/7z/C  ${PROJECT_SOURCE_DIR}/7z/CPP)

## add testing application files. 7zApplication.exe
add_subdirectory(7zApplication)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}
)