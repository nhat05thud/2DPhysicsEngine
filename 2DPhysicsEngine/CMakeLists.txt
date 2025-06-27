# Gộp CMAKE_PREFIX_PATH đúng cách
set(CMAKE_PREFIX_PATH
    "${CMAKE_SOURCE_DIR}/libs/SDL2-2.30.4"
    "${CMAKE_SOURCE_DIR}/libs/SDL2_image-2.6.0"
)

# Tìm SDL2 và SDL2_image
find_package(SDL2 REQUIRED CONFIG)
find_package(SDL2_image REQUIRED CONFIG)

# Quét tất cả .cpp và .h trong src và lib
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "src/*.cpp"
    "src/*.h"
    "lib/*.c"
    "lib/*.h"
)

# Tạo executable
add_executable(2DPhysicsEngine Main.cpp ${SOURCES})

# Link thư viện
target_link_libraries(2DPhysicsEngine PRIVATE SDL2::SDL2 SDL2_image::SDL2_image)

# Copy SDL2.dll sau khi build
add_custom_command(TARGET 2DPhysicsEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/libs/SDL2-2.30.4/lib/x64/SDL2.dll"
        $<TARGET_FILE_DIR:2DPhysicsEngine>
)

# Copy SDL2_image.dll
add_custom_command(TARGET 2DPhysicsEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/libs/SDL2_image-2.6.0/lib/x64/SDL2_image.dll"
        $<TARGET_FILE_DIR:2DPhysicsEngine>
)