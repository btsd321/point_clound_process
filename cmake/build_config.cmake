
# 设置编译选项
if(MSVC)
    add_compile_options("/utf-8")
    add_definitions(-DUNICODE -D_UNICODE)
else()
    # MinGW
    add_compile_options("-Wall")
    add_compile_options("-Wextra")
    add_compile_options("-finput-charset=UTF-8")
    add_compile_options("-fexec-charset=UTF-8")
endif()

# 在Debug模式下添加宏定义
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    
    add_definitions(-DDEBUG)
endif()
# 在Release模式下添加宏定义
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_definitions(-DRELEASE)
endif()
# 设置Debug模式下编译后文件名后缀
set(CMAKE_DEBUG_POSTFIX d)

# 设置三方库路径
set(QT_MSVC_DIR "D:/SoftWare/Library/QT/6.8.2/msvc2022_64")
set(PCL_WANT_DIR "D:/SoftWare/Library/PCL/install")
set(QsLog_CMAKE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/QsLog/cmake)
set(Eigen3_WANT_DIR "D:/SoftWare/Library/Eigen3/install")
set(Boost_WANT_DIR "D:/SoftWare/Library/Boost/install")
set(VTK_WANT_DIR "D:/SoftWare/Library/VTK/install/vtk-9.3")
set(Qhull_WANT_DIR "D:/SoftWare/Library/Qhull/install")
set(flann_WANT_DIR "D:/SoftWare/Library/flann/install")
set(lz4_WANT_DIR "D:/SoftWare/Library/lz4/install/lz4_win64_v1_10_0")

set(CMAKE_PREFIX_PATH 
    "${QT_MSVC_DIR}/lib/cmake"
    "${QsLog_CMAKE_DIR}"
    "${PCL_WANT_DIR}/cmake"
    "${Eigen3_WANT_DIR}/share/Eigen3/cmake"
    "${Boost_WANT_DIR}/lib/cmake/Boost-1.87.0"
    "${VTK_WANT_DIR}/lib/cmake/vtk-9.3"
    "${Qhull_WANT_DIR}/lib/cmake/Qhull"
    "${flann_WANT_DIR}/lib/cmake/flann"
    "${lz4_WANT_DIR}/lib/cmake/lz4"
)
