cmake_minimum_required(VERSION 3.0.0)
project(learning-sdl VERSION 0.1.0)

# Turn on the ability to create folders to organize projects (.vcproj)
# It creates "CMakePredefinedTargets" folder by default and adds CMake
# defined projects like INSTALL.vcproj and ZERO_CHECK.vcproj
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if(MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic")
endif()

if(WIN32)
    set(SDL2_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/thirdparty/SDL2-2.0.14/include")
    set(SDL2IMAGE_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/thirdparty/SDL2_image-2.0.5/include")

    # Support both 32 and 64 bit builds
    if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
        set(SDL2_LIBRARIES_DIR "${CMAKE_CURRENT_LIST_DIR}/thirdparty/SDL2-2.0.14/lib/x64")
        set(SDL2IMAGE_LIBRARIES_DIR "${CMAKE_CURRENT_LIST_DIR}/thirdparty/SDL2_image-2.0.5/lib/x64")
    else ()
        set(SDL2_LIBRARIES_DIR "${CMAKE_CURRENT_LIST_DIR}/thirdparty/SDL2-2.0.14/lib/x32")
        set(SDL2IMAGE_LIBRARIES_DIR "${CMAKE_CURRENT_LIST_DIR}/thirdparty/SDL2_image-2.0.5/lib/x32")
    endif ()

    set(SDL2_LIBRARIES "${SDL2_LIBRARIES_DIR}/SDL2.lib;${SDL2_LIBRARIES_DIR}/SDL2main.lib")
    set(SDL2IMAGE_LIBRARIES "${SDL2IMAGE_LIBRARIES_DIR}/SDL2_image.lib")

    string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)
else()
    INCLUDE(FindPkgConfig)

    PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
    PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
endif()

include_directories(
    ./include
    ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS}
)

add_executable(learning-sdl
    src/main.cpp
    "src/core/game.cpp"
    "src/core/texturemanager.cpp"
    "src/core/gameobject.cpp"
 "include/core/map.h" "src/core/map.cpp")

target_link_libraries(learning-sdl ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})

if(WIN32)
    add_custom_command(TARGET learning-sdl POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "${SDL2_LIBRARIES_DIR}/SDL2.dll" $<TARGET_FILE_DIR:learning-sdl>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "${SDL2IMAGE_LIBRARIES_DIR}/SDL2_image.dll" $<TARGET_FILE_DIR:learning-sdl>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "${SDL2IMAGE_LIBRARIES_DIR}/zlib1.dll" $<TARGET_FILE_DIR:learning-sdl>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "${SDL2IMAGE_LIBRARIES_DIR}/libpng16-16.dll" $<TARGET_FILE_DIR:learning-sdl>
    )
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
