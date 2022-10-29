//
// Created by josev on 27/10/22.
//

#include "../include/ArduinoController.hpp"
bool Queen = false;
int keyscursor[4] = {'2', '6', '4', '8'};//Keypad keys for cursor movement
int piecesmovement[4] = {'A', 'B', 'C', 'D'};//Keypad keys for piece movement
bool occupied = false;//Check if the position is occupied
int boardmatrix[8][8] =    {{0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,1,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0}
};//Board matrix
int rows_size = sizeof(boardmatrix)/sizeof(boardmatrix[0]);
//get the numbers of columns
int columns_size = sizeof(boardmatrix[0])/sizeof(boardmatrix[0][0]);



ArduinoController::ArduinoController()
{
    //This instance permits to open the serial port and also to check if it is connected
    serialport = new SerialPort("/dev/ttyACM0");


}

int *ArduinoController::MoveCursor()
{
    ///Move the cursor to the position and press the button
    char movementtype;
    //get the numbers of rows

    //Second we have to iterate the matrix made to synchronize the position of the cursor with the keypad input
    for (int i = 0; i <rows_size ; ++i)
    {
        for (int j = 0; j < columns_size; ++j)
        {
            //Initialize where the cursor is going to be
            int cursorposition[2] = {4,4};
            movementtype = serialport->getKeypadInput();
            //Make the cases based on the keypad input recursively

            switch (movementtype)
            {
                case '6'://Move the cursor to the right
                    cursorposition[1] = cursorposition[1] + 1;
                    return MoveCursor();
                case '4'://Move the cursor to the left
                    cursorposition[1] = cursorposition[1] - 1;
                    return MoveCursor();
                case '2'://Move the cursor to the up
                    cursorposition[0] = cursorposition[0] - 1;
                    return MoveCursor();
                case '8'://Move the cursor to the down
                    cursorposition[0] = cursorposition[0] + 1;
                    return MoveCursor();
                case '5'://Press the button
                    occupied = Checkposition();
                    if (!occupied)
                    {
                        boardmatrix[cursorposition[0]][cursorposition[1]] = 1;
                    }
                    return MoveCursor();
                case 'D'://Cancel the position chosen
                    occupied = Checkposition();
                    if (!occupied)
                    {
                        boardmatrix[cursorposition[0]][cursorposition[1]] = 0;
                    }
                    return MoveCursor();
                    default:
                        break;
            }


        }
    }
    //Third we have to move the cursor to the position using coords
    return nullptr;
}

bool ArduinoController::Checkposition()
{
    for (int i = 0; i <rows_size ; ++i)
    {
        for (int j = 0; j < columns_size; ++j)
        {
            if (boardmatrix[i][j] == 1)
            {
                occupied = true;
            }
            occupied = false;
        }


    }
}

int *ArduinoController::MovePiece()
{
    char movementpiece;
    //get the numbers of rows

    //Second we have to iterate the matrix made to synchronize the position of the cursor with the keypad input
    for (int i = 0; i <rows_size ; ++i)
    {
        for (int j = 0; j < columns_size; ++j)
        {
            //Initialize where the cursor is going to be
            int cursorposition[2] = {4,4};
            movementpiece = serialport->getKeypadInput();
            //Make the cases based on the keypad input recursively

            switch (movementpiece)
            {
                case '3'://Move the piece diagonally to the right up

                    cursorposition[1] = cursorposition[1] + 1;
                    cursorposition[0] = cursorposition[0] - 1;
                    return MovePiece();
                case '1'://Move the piece diagonally to the left up
                    cursorposition[1] = cursorposition[1] - 1;
                    cursorposition[0] = cursorposition[0] - 1;
                    return MovePiece();
                if(Queen){
                    case '7'://Move the piece diagonally to the left up
                        cursorposition[1] = cursorposition[1] - 1;
                        cursorposition[0] = cursorposition[0] + 1;
                    return MovePiece();
                    case '9'://Move the piece diagonally to the right up
                        cursorposition[1] = cursorposition[1] + 1;
                        cursorposition[0] = cursorposition[0] + 1;
                    return MovePiece();
                }
                case '5'://Press the button
                    occupied = Checkposition();
                    if (!occupied)
                    {
                        boardmatrix[cursorposition[0]][cursorposition[1]] = 1;
                    }
                    break;
                case 'D'://Cancel the position chosen
                    occupied = Checkposition();
                    if (!occupied)
                    {
                        boardmatrix[cursorposition[0]][cursorposition[1]] = 0;
                    }
                    return MovePiece();
                default:
                    return MovePiece();
            }


        }
    }
    return nullptr;
}

int ArduinoController::closeSerialPort()
{
    serialport->closeSerialPort();
    return 0;
}

