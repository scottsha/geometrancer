add_library(packnsmashlib
        io_utilities.cpp
        io_utilities.h
        )

target_link_libraries(packnsmashlib PUBLIC
        ${CONAN_LIBS}
        )
