add_library(packnsmashlib
        io_utilities.cpp
        io_utilities.h
        eigen_triangulation.h)

target_link_libraries(packnsmashlib PUBLIC
        ${CONAN_LIBS}
        )
