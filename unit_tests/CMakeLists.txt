#find_package(GTest REQUIRED)
enable_testing()

SET(TEST_EXE_NAME unit_tests)
SET(TEST_SOURCE_FILES
        unit_test_main.cpp
)

file(GLOB BONUS_LOCAL_TEST_FILES ${PROJECT_SOURCE_DIR}/unit_tests/*.cpp)
list(APPEND TEST_SOURCE_FILES ${BONUS_LOCAL_TEST_FILES})

add_executable(${TEST_EXE_NAME} ${TEST_SOURCE_FILES})

target_compile_definitions(${TEST_EXE_NAME} PRIVATE
        UNIT_TEST_DATA_DIR="${CMAKE_CURRENT_SOURCE_DIR}/data")

target_link_libraries(${TEST_EXE_NAME} PUBLIC
        ${CONAN_LIBS}
        packnsmashlib
        )

include(GoogleTest)
