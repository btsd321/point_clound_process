cmake_minimum_required(VERSION 3.28)

project(point_clound_process VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


include(cmake/build_config.cmake)

find_package(QT NAMES Qt6 REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS
    Core
    Widgets
    Gui
    LinguistTools
)

find_package(QsLog REQUIRED)
find_package(PCL REQUIRED)

qt_standard_project_setup(
    I18N_SOURCE_LANGUAGE en_AS         # optional - this is the default
    I18N_TRANSLATED_LANGUAGES zh_CN
)
qt_add_translations(${PROJECT_NAME}
    TS_FILE_BASE ${PROJECT_NAME}
    TS_FILE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/translations
    QM_FILES_OUTPUT_VARIABLE qm_files
)


file(GLOB UI_FILES ${CMAKE_CURRENT_SOURCE_DIR}/ui/*.ui)
list(APPEND CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/ui")

# 打印ui文件
message("ui files: ${UI_FILES}")

set(INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include")

file(GLOB SRC_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/main.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/**/*.h"
)

set(PROJECT_SOURCES
    ${SRC_FILES}
    ${UI_FILES}
    ${TS_FILES}
)

set(PROJECT_SHARED_LIBRARIES
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Gui
)

set(PROJECT_STATIC_LIBRARIES
    ${QsLog_LIBRARIES}
    "${PCL_LIBRARIES}"
)

set(PROJECT_LIBRARIES
    ${PROJECT_SHARED_LIBRARIES}
    ${PROJECT_STATIC_LIBRARIES}
)

set(PROJECT_LIBRARIE_DIRS
    ${QT_MSVC_DIR}/bin
)

qt_add_executable(${PROJECT_NAME} WIN32
    ${PROJECT_SOURCES}
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    ${PROJECT_LIBRARIES}
)

include(cmake/install_config.cmake)
