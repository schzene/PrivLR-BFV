add_subdirectory(protocols)
add_subdirectory(utils)

add_library(PrivLR-BFV
    logistic.cpp
)

target_include_directories(PrivLR-BFV PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(PrivLR-BFV PUBLIC
    PrivLR_PROTOCOLS
    PrivLR_UTILS
)