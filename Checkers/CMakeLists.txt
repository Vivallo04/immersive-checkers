cmake_minimum_required(VERSION 3.23)
project(githubproueba)

set(CMAKE_CXX_STANDARD 14)

add_executable(githubproueba main.cpp src/Button.cpp include/Button.hpp include/CheckersBoard.hpp src/CheckersBoard.cpp include/checkersFunctions.hpp src/checkersFunctions.cpp
        src/CheckersPiece.cpp include/CheckersPiece.hpp include/CheckersSquare.hpp src/CheckersSquare.cpp include/checkersVariables.hpp src/checkersVariables.cpp
        include/constants.hpp src/error.cpp include/error.hpp include/filler.hpp src/gameBoard.cpp include/gameBoard.hpp src/square.cpp include/square.hpp)


target_link_libraries(githubproueba
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio)
# Set executable install location
install(TARGETS githubproueba DESTINATION bin)

# Set install location for resources
install(DIRECTORY content
        DESTINATION "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}"
        )