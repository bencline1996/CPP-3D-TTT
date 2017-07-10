#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ctype.h>


using std::string;
using std::cout;
using std::cin;
using std::srand;
using std::time;
using std::rand;
using std::endl;


char turn;
bool draw = false;

class GameBoard //Gameboard Class
{
private:
        string board[3][3][3];
 
public:
        GameBoard();
        void display_board();
        void player_turn();
        bool gameover();
 
};

GameBoard::GameBoard() //Gameboard Array values
{
	board[0][0][0] = "1";
	board[0][0][1] = "2";
	board[0][0][2] = "3";
	board[0][1][0] = "4";
	board[0][1][1] = "5";
	board[0][1][2] = "6";
	board[0][2][0] = "7";
	board[0][2][1] = "8";
	board[0][2][2] = "9";
	
	board[1][0][0] = "1";
	board[1][0][1] = "2";
	board[1][0][2] = "3";
	board[1][1][0] = "4";
	board[1][1][1] = "5";
	board[1][1][2] = "6";
	board[1][2][0] = "7";
	board[1][2][1] = "8";
	board[1][2][2] = "9";
	
	board[2][0][0] = "1";
	board[2][0][1] = "2";
	board[2][0][2] = "3";
	board[2][1][0] = "4";
	board[2][1][1] = "5";
	board[2][1][2] = "6";
	board[2][2][0] = "7";
	board[2][2][1] = "8";
	board[2][2][2] = "9";
}

void GameBoard::display_board()
{
        cout << "---------------------\n\n";
        cout << "\tBoard 0\n";  //First Board
        cout << "     |     |     \n";
        cout << "  " << board[0][0][0] << "  |  " << board[0][0][1] << "  |  " << board[0][0][2] << endl;
        cout << "_____|_____|_____\n";
        cout << "     |     |     \n";
        cout << "  " << board[0][1][0] << "  |  " << board[0][1][1] << "  |  " << board[0][1][2] << endl;
        cout << "_____|_____|_____\n";
        cout << "     |     |     \n";
        cout << "  " << board[0][2][0] << "  |  " << board[0][2][1] << "  |  " << board[0][2][2] << endl;
        cout << "     |     |     \n\n";
        
        cout << "\tBoard 1\n"; //Second Board
		cout << "     |     |     \n";
        cout << "  " << board[1][0][0] << "  |  " << board[1][0][1] << "  |  " << board[1][0][2] << endl;
        cout << "_____|_____|_____\n";
        cout << "     |     |     \n";
        cout << "  " << board[1][1][0] << "  |  " << board[1][1][1] << "  |  " << board[1][1][2] << endl;
        cout << "_____|_____|_____\n";
        cout << "     |     |     \n";
        cout << "  " << board[1][2][0] << "  |  " << board[1][2][1] << "  |  " << board[1][2][2] << endl;
        cout << "     |     |     \n\n";
        
        cout << "\tBoard 2\n"; //Third Board
		cout << "     |     |     \n";
        cout << "  " << board[2][0][0] << "  |  " << board[2][0][1] << "  |  " << board[2][0][2] << endl;
        cout << "_____|_____|_____\n";
        cout << "     |     |     \n";
        cout << "  " << board[2][1][0] << "  |  " << board[2][1][1] << "  |  " << board[2][1][2] << endl;
        cout << "_____|_____|_____\n";
        cout << "     |     |     \n";
        cout << "  " << board[2][2][0] << "  |  " << board[2][2][1] << "  |  " << board[2][2][2] << endl;
        cout << "     |     |     \n\n";
}

void GameBoard::player_turn() //Decides if the player or computer moves first, then places a marker where they desire on the TTT board
{
        int board_choice;
        int place_choice = 0;
        int row = 0, column = 0;
 
        if (turn == 'X')
        {
                cout << "Please choose which board to mark: ";
                cin >> board_choice;
                cout << "\nSelect where to mark the board: ";
                cin >> place_choice;
        }
        else if (turn == 'O') //Crashes approximately 1/10 runs? Maybe the random function is bringing up a value not on the board, but it shouldn't.
        {
                board_choice = rand() % 3;
                place_choice = rand() % 9 + 1;
                if (turn == '0' && board[board_choice][row][column] == "X" || board[board_choice][row][column] == "O")
                {
                        player_turn();
                }
        }

        switch (place_choice)
        {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
                cout << "You did not enter a correct number. Please try again.\n\n"; //Crashes if you input a letter/symbol, but works properly with incorrect numbers
                player_turn();
        }
 
        if (turn == 'X' && board[board_choice][row][column] != "X" && board[board_choice][row][column] != "O")
        {
                board[board_choice][row][column] = "X"; //Appears to put in the numerical value of the letters, not sure why. Attempted to declare "X" and "O" as chars and use X and O instead of 'X' and 'O', but it outputs the same numerical values.
                turn = 'O';
                cout << "It is now the computer's turn.\n\n";
        }
        else if (turn == 'O' && board[board_choice][row][column] != "X" && board[board_choice][row][column] != "O")
        {
                board[board_choice][row][column] = "O"; //Same as above
                turn = 'X';
        }
        else if (turn == 'X')
        {
                cout << "The cell you chose is taken. Please try again.\n";
                player_turn();
        }
 
        else if (turn == 'O')
        {
                place_choice = rand() % 9 + 1;
                if (turn == '0' && board[board_choice][row][column] == "X" || board[board_choice][row][column] == "O")
                {
                        player_turn();
                }
        }
 
}
 
bool GameBoard::gameover() //Checks for the requirements to end the game
{
        for (int i = 0; i < 3; i++)//Check for a win
        {
        	for (int j = 0; j < 3; j++)
        	{
                if ((board[i][j][0] == board[i][j][1] && board[i][j][1] == board[i][j][2]) || (board[i][0][j] == board[i][1][j] && board[i][1][j] == board[i][2][j]) || (board[i][0][0] == board[i][1][1] && board[i][1][1] == board[i][2][2]) || (board[i][0][2] == board[i][1][1] && board[i][1][1] == board[i][2][0])) //Win on a single board
                {
                        return true;
                }        		
        	}

        }

        for (int i = 0; i < 3; i++)//Check for draw
        {
                for (int j = 0; j < 3; j++)
                {
                	for (int k = 0; k < 3; k++)
                	{
                		if (board[i][j][k] != "X" && board[i][j][k] != "O")
                        {
                            return false;
                        }
                	}

                }
        }
        draw = true;
        return true;
}
 
int main() //Main
{
        GameBoard game;
        srand(time(0));
        int firstTurn = rand() % 2;
 
        if (firstTurn == 0)
        {
                cout << "Welcome to the 3D Tic Tac Toe program!\n\n";
                cout << "The player is [X] and the computer is [O].\n" << endl << endl << "You move first!\n\n";
                turn = 'X';
        }
 
        else if (firstTurn == 1)
        {
                cout << "Welcome to the Tic Tac Toe program!\n\n";
                cout << "The player is [X] and the computer is [O]." << endl << endl << "The computer moves first.\n\n";
                turn = 'O';
        }
 
        while (game.gameover() != true)
        {
                game.display_board();
                game.player_turn();
                game.gameover();
        }
 
        if (turn == 'O' && !draw)
        {
                game.display_board();
                cout << "\n\nYou win! Congratulations!\n";
        }
        else if (turn == 'X' && !draw)
        {
                game.display_board();
                cout << "\n\nThe computer wins! Better luck next time!\n";
        }
        else
        {
                game.display_board();
                cout << "\n\nThe game is a draw! Try again!\n";
        }
return 0;
}
