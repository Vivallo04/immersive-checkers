cmake_minimum_required(VERSION 3.23)
project(immersive_checkers)

set(CMAKE_CXX_STANDARD 20)


## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

# Enable debug symbols by default
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug
            CACHE STRING
            "Choose the type of build (Debug or Release)" FORCE)
endif()


# Find SFML shared libraries
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)


add_executable(immersive_checkers main.cpp src/Board.cpp include/Board.hpp)



# Link executable to required SFML modules
target_link_libraries(immersive_checkers sfml-graphics sfml-audio)



# Set executable install location
install(TARGETS immersive_checkers DESTINATION bin)

# Set install location for resources
install(DIRECTORY content
        DESTINATION "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}"
        )