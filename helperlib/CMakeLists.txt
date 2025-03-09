project(helpers)

set(HEADER_FILES
    helpers.h)

set(SOURCE_FILES
    helpers.cpp)


add_library(helpers STATIC ${SOURCE_FILES} ${HEADER_FILES})