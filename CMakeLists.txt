cmake_minimum_required(VERSION 3.10.0)
project(myProject VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GNUInstallDirs)

add_custom_target("uninstall" COMMENT "Uninstall files")
add_custom_command(
    TARGET "uninstall"
    POST_BUILD
    COMMENT "根据 install_manifest.txt 中的路径删除安装的文件,然后删除安装时新建的目录(文件删除后应该为空)"
    # 删除安装的所有文件
    COMMAND xargs rm -vf < ./install_manifest.txt || echo install_manifest.txt为空, 没有文件被安装过
    # 删除空文件夹，-t显示删除目录，-n 1每行处理一个参数
    COMMAND find ${CMAKE_INSTALL_PREFIX} -type d -name ${Install_Folder_Name} | xargs -t -n 1 rm -r
)

option(IS_LOG_SHARED "control whether Log is shared" OFF)

# set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
# set(CMAKE_INSTALL_RPATH "$ORIGIN/../lib")
# set(CMAKE_SKIP_INSTALL_RPATH FALSE)

set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
# CMAKE_INSTALL_RPATH_USE_LINK_PATH:if set to True, will append to the runtime search path (rpath) of installed binaries 
# any directories outside the project that are in the linker search path or contain linked library files. 
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
if(APPLE)
set(CMAKE_INSTALL_RPATH "@loader_path/../lib")
else()
set(CMAKE_INSTALL_RPATH "$ORIGIN/../lib")
endif()

add_subdirectory(src)
add_subdirectory(Demo)
