cmake_minimum_required(VERSION 3.23)
project(inmersivecheckers)

set(CMAKE_CXX_STANDARD 14)

# Enable debug symbols by default
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug
            CACHE STRING
            "Choose the type of build (Debug or Release)" FORCE)
endif()

add_executable(inmersivecheckers main.cpp src/Button.cpp include/Button.hpp include/CheckersBoard.hpp src/CheckersBoard.cpp include/checkersFunctions.hpp src/checkersFunctions.cpp
        src/CheckersPiece.cpp include/CheckersPiece.hpp include/CheckersSquare.hpp src/CheckersSquare.cpp include/checkersVariables.hpp src/checkersVariables.cpp
        include/constants.hpp src/error.cpp include/error.hpp include/filler.hpp src/gameBoard.cpp include/gameBoard.hpp src/square.cpp include/square.hpp
        include/ArduinoController.hpp src/ArduinoController.cpp include/SerialPort.hpp src/SerialPort.cpp )


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




target_link_libraries(inmersivecheckers
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
        ${Boost_INCLUDE}
        Boost::boost
        Boost::log)
# Set executable install location
install(TARGETS inmersivecheckers DESTINATION bin)

# Set install location for resources
install(DIRECTORY content
        DESTINATION "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}"
        )