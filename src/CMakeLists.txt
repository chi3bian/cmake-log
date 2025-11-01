# add_subdirectory(Log)
# add_subdirectory(Output)
# Log
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

file(GLOB_RECURSE LOG_SOURCE
    CONFIGURE_DEPENDS
    RELATIVE ${PROJECT_SOURCE_DIR}/src/
    *.cpp)


if(IS_LOG_SHARED STREQUAL OFF)
    add_library(Log STATIC ${LOG_SOURCE})
else()
    add_library(Log SHARED ${LOG_SOURCE})
endif()

target_include_directories(Log PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Output
# file(GLOB_RECURSE OUTPUT_SOURCE
#     CONFIGURE_DEPENDS
#     RELATIVE ${PROJECT_SOURCE_DIR}/src/
#     Output/*.cpp)

# add_library(Output STATIC ${OUTPUT_SOURCE})
# target_include_directories(Output PUBLIC ${PROJECT_SOURCE_DIR}/include)

# link Output to Log
# target_link_libraries(Log PRIVATE Output)

#install log

# install(TARGETS Log Output
install(TARGETS Log 
    EXPORT LogTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

#install include 
install(
    DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
     FILES_MATCHING PATTERN "*.hpp"
)

