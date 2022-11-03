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
                    cursorpositionreal = boardmatrix[i+1][j];
                    return MoveCursor(i,j);
                }
                case '5':
                {
                    //Select the piece I want to move

                    bool occupied = Checkposition(i, j);
                    if (occupied)
                    {
                       selected_piece = true;
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
                    //occupied_mypiece = Checkposition();
                    if (!occupied_mypiece)
                    {
                        boardmatrix[cursorposition[0]][cursorposition[1]] = 1;
                    }
                    return MovePiece();
                case 'D'://Cancel the position chosen
                    //occupied_mypiece = Checkposition();
                    if (!occupied_mypiece)
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



