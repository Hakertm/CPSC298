#if !defined(TICTACTOE_H)
#define TICTACTOE_H

/// @file TicTacToe.cpp
/// @brief Header file for TicTacToeGame class
/// @author Erik Fryanov
#include <tuple>

using namespace std;

/// Implements the game "Tic Tac Toe"
/// @details The childhood classic Tic Tac Toe game played against a simple AI. The AI
///          chooses the first unoccupied tile to place an 'O' character. The player
///          goes first choosing which grid to place an 'X' character on. The game ends
///          when either the AI or player gets 3 in a row of their respective character.
class TicTacToeGame{
public:
    /// Default constructor for TicTacToeGame object.
	/// @details Initializes the pointer to pointer 2-D character array as well as
    ///          initialize a 3x3 grid with '~' characters. 
    TicTacToeGame();

    /// Destructor for TicTacToeGame object.
	/// @details Deallocates the memory of the pointer to pointer array.
    virtual ~TicTacToeGame();

	/// Game Loop; plays one complete game.
	/// @return void
	/// @details Human player goes first, AI second. Checks for a win and draw after each turn.
    ///          Game ends when either a draw or win occurs. See check for win for win conditions.
    void play();

private:
	/// Initialize a two dimensinal 3x3 playing grid that contains all '~' characters. 
	/// @return void
    void initializeGrid();

    /// Outputs the playing grid to the screen/console.
    /// @return void
    void displayGrid();

    /// The AI's turn. Finds the first unoccupied cell to place a character on.
    /// @return tuple containing two integers, the row and column index 
    ///         of the first unoccupied square.
    tuple<int, int> findFirstUnoccSquare();

    /// Prompts the user for a grid coordinate and checks their input.
    /// @return tuple containing two integer, the row and column index
    ///         chosen by the user in which to place an 'X' character.
    /// @details Checks for a valid row and column number as well if a cell is already occupied.
    tuple<int, int> promptForCoord();

    /// Checks if there are any available squares left, which determines a draw.
    /// @return boolean indicating whether or not to continue the game.
    bool checkForDraw();

    /// Checks for 3 in a row, 3 in a column, or 3 in a diagnol and reports a victory for
    /// the respective character. Note: Can trigger multiple win conditions
    /// @return boolean which determines if someone won
    bool checkForWin();

    /// Pointer to Pointer 2-D Character Array
    char** pp_cGrid = nullptr;
};

#endif