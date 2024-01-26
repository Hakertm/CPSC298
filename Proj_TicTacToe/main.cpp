/// @file main
/// @brief main function file for TicTacToeGame. Plays one complete game.
/// @author Erik Fryanov

#include "TicTacToe.h"

using namespace std;

int main() {
    TicTacToeGame* p_game = new TicTacToeGame();

    p_game->play();

    delete p_game;

    return 0;
}
