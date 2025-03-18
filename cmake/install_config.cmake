# 输出安装路径
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/install)
include(GNUInstallDirs)
install(IMPORTED_RUNTIME_ARTIFACTS
    ${PROJECT_SHARED_LIBRARIES}
)
install(DIRECTORY ${QT_MSVC_DIR}/plugins/platforms DESTINATION .)
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION .
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION bin
)
install(FILES ${qm_files} DESTINATION "translations")
include(InstallRequiredSystemLibraries)
install(FILES LICENSE DESTINATION .)
install(FILES ${qm_files} DESTINATION ${PROJECT_BINARY_DIR}/translations)

