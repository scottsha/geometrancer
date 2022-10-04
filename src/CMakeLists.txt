add_library(packnsmashlib
        utils.cpp
        )

target_link_libraries(packnsmashlib PUBLIC
        ${CONAN_LIBS}
        )
