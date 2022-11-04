cmake_minimum_required(VERSION 3.23)
project(immersive_checkers)

set(CMAKE_CXX_STANDARD 20)

# Enable debug symbols by default
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug
            CACHE STRING
            "Choose the type of build (Debug or Release)" FORCE)
endif()


# Boost Asio
find_package(Boost COMPONENTS log REQUIRED)
if (Boost_FOUND)
    set(ASIO_FOUND "YES")
    include_directories(${Boost_INCLUDE_DIR})
    ADD_DEFINITIONS( "-DHAS_BOOST")
    message(STATUS "Boost found and configured")
    message(STATUS "Directory" ${Boost_INCLUDE_DIR})
endif()

# Boost Log
ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)


# Find SFML shared libraries
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)


add_executable(immersive_checkers main.cpp src/PlayState.cpp
        include/PlayState.hpp src/GameUi.cpp include/GameUi.hpp src/util.hpp
        src/StateMachine.cpp include/StateMachine.hpp
        include/BaseState.hpp src/Board.cpp include/Board.hpp src/Tile.cpp include/Tile.hpp src/Checker.cpp
        include/Checker.hpp src/ComputerAI.cpp include/ComputerAI.hpp src/Piece.cpp include/Piece.hpp)


# Link executable to required SFML modules
target_link_libraries(immersive_checkers
        sfml-graphics
        sfml-audio
        ${Boost_INCLUDE}
        Boost::boost
        Boost::log)



# Set executable install location
install(TARGETS immersive_checkers DESTINATION bin)

# Set install location for resources
install(DIRECTORY content
        DESTINATION "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}"
        )