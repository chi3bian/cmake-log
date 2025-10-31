# aux_source_directory(. OUTPUT_DIR)

# add_library(Output STATIC ${OUTPUT_DIR})

# target_include_directories(Output PRIVATE ${PROJECT_SOURCE_DIR}/include/Output)

# install(TARGETS Output
#     EXPORT OutputTargets
#     ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/Output)

# install(
#     DIRECTORY ${PROJECT_SOURCE_DIR}/include/Output
#     DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
#     FILES_MATCHING PATTERN "*.hpp"
# )
