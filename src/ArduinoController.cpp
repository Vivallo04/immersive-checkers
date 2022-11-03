//
// Created by josev on 27/10/22.
//

#include "../include/ArduinoController.hpp"
bool Queen = false;
int keyscursor[4] = {'2', '6', '4', '8'};//Keypad keys for cursor movement
int piecesmovement[4] = {'A', 'B', 'C', 'D'};//Keypad keys for piece movement
bool occupied_mypiece = false;//Check if the position is occupied_mypiece
bool selected_piece = false;//Check if the piece is selected
int boardmatrix[8][8] =    {{0,3,0,3,0,3,0,3},
                            {3,0,3,0,3,0,3,0},
                            {0,3,0,3,0,3,0,3},
                            {1,0,1,0,1,0,1,0},
                            {0,1,0,1,0,1,0,1},
                            {2,0,2,0,2,0,2,0},
                            {0,2,0,2,0,2,0,2},
                            {2,0,2,0,2,0,2,0}
};//Board matrix
int rows_size = sizeof(boardmatrix)/sizeof(boardmatrix[0]);
//get the numbers of columns
int columns_size = sizeof(boardmatrix[0])/sizeof(boardmatrix[0][0]);



ArduinoController::ArduinoController()
{
    //This instance permits to open the serial port and also to check if it is connected
    serialport = new SerialPort("/dev/ttyACM0");


}


bool ArduinoController::Checkposition(int row, int column)
{
    if (boardmatrix[row][column] == 2)
    {
        occupied_mypiece = true;
    }
    occupied_mypiece = false;
}


int *ArduinoController::MoveCursor(int x,int y)
{
    ///Move the cursor to the position and press the button
    char movementtype;


    //Second we have to iterate the matrix made to synchronize the position of the cursor with the keypad input
    for (int i = x; i <rows_size ; ++i)
    {
        for (int j = y; j < columns_size; ++j)
        {
            //Initialize where the cursor is going to be

            int cursorpositionreal = boardmatrix[i][j];
            movementtype = serialport->getKeypadInput();
            //Make the cases based on the keypad input recursively

            switch (movementtype)
            {
                case '6':
                {
                    //Move the cursor to the right
                    int j = j+1;
                    cursorpositionreal = boardmatrix[i][j];
                    return MoveCursor(i,j);
                }
                case '4':
                {
                    //Move the cursor to the left
                    int j = j-1;
                    cursorpositionreal = boardmatrix[i][j];
                    return MoveCursor(i,j);
                }
                case '2':
                {
                    //Move the cursor to the up
                    int i = i-1;
                    cursorpositionreal = boardmatrix[i][j];
                    return MoveCursor(i,j);
                }
                case '8':
                {
                    //Move the cursor to the down
                    int i = i+1;
                    cursorpositionreal = boardmatrix[i][j];
                    return MoveCursor(i,j);
                }
                case '5':
                {
                    //Select the piece I want to move

                    bool occupied = Checkposition(i, j);
                    if (occupied)
                    {
                       selected_piece = true;
                        MovePiece(i,j);


                        break;
                    }
                    std::cout<<"The piece isn't occupied by your pieces, please choose another one"<<std::endl;
                    selected_piece = false;

                    return MoveCursor(i,j);
                }
                default:
                break;
            }


        }
    }
    //Third we have to move the cursor to the position using coords
    return nullptr;
}

/*
 * Inicializar al funcion moveCursor
 * Quedaría con un
 * Llamaría a movePiece dentro de move Cursor, esto con el objetivo de obtener el lugar en donde se quiere mover la pieza
 */




int *ArduinoController::MovePiece(int x, int y)
{
    int row = x;
    int column = y;
    //Move the piece to the position
    char movementtype;
    movementtype = serialport->getKeypadInput();
    //Make the cases based on the keypad input recursively

    switch (movementtype)
    {
        case '3':
        {
            //Move the piece diagonally right up
            //Piece first position
            int pieceoriginalposition = boardmatrix[row][column];
            x = x - 1;
            y = y + 1;
            //Piece position diagonally
            int piecepositionreal = boardmatrix[x][y];
            //Piece position x2 diagonally
            int pieceposposition = boardmatrix[x - 1][y + 1];
            if (piecepositionreal == 3 && pieceposposition == 1)
            {
                pieceoriginalposition = 1;
                piecepositionreal = 1;
                pieceposposition = 2;
                break;
            }
            if (piecepositionreal == 1)
            {
                pieceoriginalposition = 1;
                piecepositionreal = 2;
                break;
            }
            if (piecepositionreal == 3 && pieceposposition == 3)
            {
                std::cout << "You can't move the piece to this position, please choose another one" << std::endl;
                return MovePiece(row, column);
            }
            break;

        }
        case '1':
        {
            //Move the piece diagonally left up
            //Piece first position
            int pieceoriginalposition = boardmatrix[row][column];
            x = x - 1;
            y = y - 1;
            //Piece position diagonally
            int piecepositionreal = boardmatrix[x][y];
            //Piece position x2 diagonally
            int pieceposposition = boardmatrix[x - 1][y - 1];
            if (piecepositionreal == 3 && pieceposposition == 1)
            {
                pieceoriginalposition = 1;
                piecepositionreal = 1;
                pieceposposition = 2;
                break;
            }
            if (piecepositionreal == 1)
            {
                pieceoriginalposition = 1;
                piecepositionreal = 2;
                break;
            }
            if (piecepositionreal == 3 && pieceposposition == 3)
            {
                std::cout << "You can't move the piece to this position, please choose another one" << std::endl;
                return MovePiece(row, column);
            }
            break;
        }
        case '7':
        {
            //If(Queen){
            //Move the piece diagonally left down
            //Piece first position
            int pieceoriginalposition = boardmatrix[row][column];
            x = x + 1;
            y = y - 1;
            //Piece position diagonally
            int piecepositionreal = boardmatrix[x][y];
            //Piece position x2 diagonally
            int pieceposposition = boardmatrix[x + 1][y - 1];
            if (piecepositionreal == 3 && pieceposposition == 1)
            {
                pieceoriginalposition = 1;
                piecepositionreal = 1;
                pieceposposition = 2;
                break;
            }
            if (piecepositionreal == 1)
            {
                pieceoriginalposition = 1;
                piecepositionreal = 2;
                break;
            }
            if (piecepositionreal == 3 && pieceposposition == 3)
            {
                std::cout << "You can't move the piece to this position, please choose another one" << std::endl;
                return MovePiece(row, column);
            }
            break;
            //}
        }
        case '9':
        {
            //If(Queen){
            //Move the piece diagonally right down
            //Piece first position
            int pieceoriginalposition = boardmatrix[row][column];
            x = x + 1;
            y = y + 1;
            //Piece position diagonally
            int piecepositionreal = boardmatrix[x][y];
            //Piece position x2 diagonally
            int pieceposposition = boardmatrix[x + 1][y + 1];
            if (piecepositionreal == 3 && pieceposposition == 1)
            {
                pieceoriginalposition = 1;
                piecepositionreal = 1;
                pieceposposition = 2;
                break;
            }

            //}


        }
            return nullptr;


    }
}

    int ArduinoController::closeSerialPort()
    {
        serialport->closeSerialPort();
        return 0;
    }


