find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

# Quét tất cả .cpp và .h trong thư mục src và các thư mục con
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "src/*.cpp"
    "src/*.h"
    "lib/*.c"
    "lib/*.h"
)

add_executable (2DPhysicsEngine "Main.cpp" ${SOURCES})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 2DPhysicsEngine PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(2DPhysicsEngine PRIVATE SDL2::SDL2 SDL2_image::SDL2_image)