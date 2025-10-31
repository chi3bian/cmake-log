add_executable(main main.cpp)
target_include_directories(main PRIVATE ${PROJECT_SOURCE_DIR}/include/Log)
target_link_libraries(main PRIVATE Log)
install(TARGETS main
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

