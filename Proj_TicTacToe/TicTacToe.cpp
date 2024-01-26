/// @file TicTacToe
/// @brief Implementation for TicTacToeGame class
/// @author Erik Fryanov

#include <iostream>
#include <tuple>

using namespace std;

class TicTacToeGame
{
public: 
    TicTacToeGame();
    virtual ~TicTacToeGame();

    void play();

private:
    void initializeGrid();
    void displayGrid();
    tuple<int, int> findFirstUnoccSquare(); //AI move
    tuple<int, int> promptForCoord();       //User move
    bool checkForDraw();
    bool checkForWin();

    char** pp_cGrid = nullptr; //Pointer to pointer 2-D character array

};

//Default Constructor
TicTacToeGame::TicTacToeGame()
{
    this->pp_cGrid = new char* [3]; //Array of three pointers to characters

    for(int iRow = 0; iRow < 3; ++iRow) { //Note: can be without curly braces
        pp_cGrid[iRow] = new char[3];
    }

    initializeGrid(); //Populate Grid

}

//Destructor
TicTacToeGame::~TicTacToeGame()
{
    for(int iRow = 0; iRow < 3; ++iRow){
        delete[] pp_cGrid[iRow]; //Delete array of 3 characters
    }

    delete[] pp_cGrid; //Delete array of three pointers to character
    pp_cGrid = nullptr;
}

//Creates and populates all cells with the '~' character.
void TicTacToeGame::initializeGrid()
{
    for(int iRow = 0; iRow < 3; ++iRow){
        for(int iColumn = 0; iColumn < 3; ++iColumn){
            this->pp_cGrid[iRow][iColumn] = '~';
        }
    }
}

//Displays the game grid to the screen/console.
void TicTacToeGame::displayGrid()
{
    for(int iRow = 0; iRow < 3; ++iRow){
        for(int iColumn = 0; iColumn < 3; ++iColumn){
            cout << this->pp_cGrid[iRow][iColumn] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

//Core game loop.
void TicTacToeGame::play()
{
    bool bWin = false;
    bool bDraw = false;
    int iRow = 0;
    int iColumn = 0;

    cout << "Tic Tac Toe, The Video Game!" << endl << endl;

    displayGrid();

    //Main gameplay loop
    while(!bWin && !bDraw) {
        //Player turn
        tie(iRow, iColumn) = this->promptForCoord();
        this->pp_cGrid[iRow][iColumn] = 'X';

        this->displayGrid();

        //Check for win or draw
        bWin = this->checkForWin();
        bDraw = this->checkForDraw();

        //AI turn
        if(!bWin && !bDraw) {
            tie(iRow, iColumn) = findFirstUnoccSquare();
            this->pp_cGrid[iRow][iColumn] = 'O';

            cout << "AI turn" << endl;

            displayGrid();

            //Check for win or draw
            bWin = checkForWin();
            bDraw = checkForDraw();
        }

        //State if the game is a draw.
        if(bDraw && !bWin) {
            cout << "Draw!" << endl;
        }
    }

    cout << "Game over." << endl;
    return;
}

//Prompts the user for a grid coordinate.
tuple<int, int> TicTacToeGame::promptForCoord()
{
    int iRow = 0;
    int iColumn = 0;

    //Keeps getting user input until all of it is valid.
    while(true) {
        
        //Gets row input and checks if the row is within bounds.
        while(true) {
            cout << "Please enter grid row number: ";
            cin >> iRow;
            //Checks if the row input is vaild.
            if((iRow < 0) || (iRow > 2)) {
                cout << "The grid row number must 0, 1, or 2." << endl;
                continue;
            }
            break;
        }

        //Gets column input and checks if the column is within bounds
        while(true) {
            cout << "Please enter grid column number: ";
            cin >> iColumn;
            //Checks if the column input is between 0 and 2.
            if((iColumn < 0) || (iColumn > 2)) {
                cout << "The grid column number must 0, 1, or 2." << endl;
                continue;
            }
            break;
        }

        //Checks if the grid coordinate is occupied already
        if(this->pp_cGrid[iRow][iColumn] != '~') {
            cout << "The grid square " << iRow << " " << iColumn << " is already occupied." << endl;
            continue;
        }

        cout << endl;
        break;
    }

    tuple<int, int> tupleCoord = make_tuple(iRow, iColumn);
    
    return tupleCoord;
}

//Finds the first unoccupied cell to place a character on; AI's turn.
tuple<int, int> TicTacToeGame::findFirstUnoccSquare()
{
    int iRowUnocc;
    int iColumnUnocc;

    bool bFound = false;

    //Finds the first unoccupied cell.
    for(int iRow = 0; (iRow < 3) && !bFound; ++iRow){
        for(int iColumn = 0; (iColumn < 3) && !bFound; ++iColumn){
            if(this->pp_cGrid[iRow][iColumn] == '~') {
                iRowUnocc = iRow;
                iColumnUnocc = iColumn;
                bFound = true;
            }
        }
    }

    tuple<int, int> tupleUnoccupiedSquare(iRowUnocc, iColumnUnocc);
    return tupleUnoccupiedSquare;
}

//Checks if there are any available squares left.
bool TicTacToeGame::checkForDraw()
{
    bool bContinue = false;

    //Continue game if there are open squares left.
    //Otherwise, it must be a win or a draw.

    //Check to continue the game or not.
    for(int iRow = 0; iRow < 3; ++iRow){
        for(int iColumn = 0; iColumn < 3; ++iColumn){
            if((this->pp_cGrid[iRow][iColumn] != 'X') && (this->pp_cGrid[iRow][iColumn] != 'O')) {
                bContinue = true;
            }
        }
    }

    return !bContinue;
}

//
bool TicTacToeGame::checkForWin()
{
    bool bWin = false;

    //Check for three in one row
    for(int iRow = 0; (iRow < 3) && !bWin; ++iRow) {
        if(this->pp_cGrid[iRow][0] != '~') {
            if((this->pp_cGrid[iRow][0] == this->pp_cGrid[iRow][1]) && 
               (this->pp_cGrid[iRow][1] == this->pp_cGrid[iRow][2])) {
                bWin = true;
                cout << "Winner: " << this->pp_cGrid[iRow][0] << "!" << endl;
            }
        }
    }

    //Check for three in a column
    for(int iColumn = 0; (iColumn < 3) && !bWin; ++iColumn) {
        if(this->pp_cGrid[0][iColumn] != '~') {
            if((this->pp_cGrid[0][iColumn] == this->pp_cGrid[1][iColumn]) && 
               (this->pp_cGrid[1][iColumn] == this->pp_cGrid[2][iColumn])) {
                bWin = true;
                cout << "Winner: " << this->pp_cGrid[0][iColumn] << "!" << endl;
            }
        }
    }

    //Check for in a diagnol, left to right
    if(this->pp_cGrid[0][0] != '~') {
        if((this->pp_cGrid[0][0] == this->pp_cGrid[1][1]) &&
           (this->pp_cGrid[1][1] == this->pp_cGrid[2][2])) {
            bWin = true;
            cout << "Winner: " << this->pp_cGrid[0][0] << "!" << endl;
        }
    }

    //Check for in a diagnol, right to left
    if(this->pp_cGrid[0][2] != '~') {
        if((this->pp_cGrid[0][2] == this->pp_cGrid[1][1]) &&
           (this->pp_cGrid[1][1] == this->pp_cGrid[2][0])) {
            bWin = true;
            cout << "Winner: " << this->pp_cGrid[0][2] << "!" << endl;
        }
    }

    return bWin;
}

//g++ --std=c++17 tictactoe.cpp
