project(translator)

add_executable(${PROJECT_NAME} translator_main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/src")
target_link_libraries(${PROJECT_NAME}
        PUBLIC
        packnsmashlib
        ${CONAN_LIBS}
        )




