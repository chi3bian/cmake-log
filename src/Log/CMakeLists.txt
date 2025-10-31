# aux_source_directory(. SOURCE_DIR)
# message("IS_LOG_SHARED=${IS_LOG_SHARED}")
# message("SOURCE_DIR = ${SOURCE_DIR}")
# if(IS_LOG_SHARED STREQUAL ON)
# add_library(Logshared SHARED ${SOURCE_DIR})
# target_include_directories(Logshared PRIVATE ${PROJECT_SOURCE_DIR}/include/Log)
# target_link_libraries(Logshared Output)
# install(TARGETS Logshared
#     EXPORT LogTargets
#     ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/Log)

# else()

# add_library(Log STATIC ${SOURCE_DIR})
# target_include_directories(Log PRIVATE ${PROJECT_SOURCE_DIR}/include/Log)
# target_link_libraries(Log Output)

# install(TARGETS Log
#     EXPORT LogTargets
#     ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/Log)
# endif()


# install(
#     DIRECTORY ${PROJECT_SOURCE_DIR}/include/Log
#     DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
#     FILES_MATCHING PATTERN "*.hpp"
# )
