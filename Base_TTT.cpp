#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ctype.h>

using std::cout;
using std::cin;
using std::srand;
using std::time;
using std::rand;
using std::endl;

void display_board();
void player_turn();
bool gameover();

char turn;
bool draw = false;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

int main()
{
	srand(time(0));
	int firstTurn = rand() % 2;
	
	if (firstTurn == 0)
	{	
    	cout << "Welcome to the Tic Tac Toe program!\n\n";
   		cout << "The player is [X] and the computer is [O].\n" << endl << endl << "You move first!\n\n";
   		turn = 'X';
	}
	
	else if (firstTurn == 1)
	{
		cout << "Welcome to the Tic Tac Toe program!\n\n";
		cout << "The player is [X] and the computer is [O]." << endl << endl << "The computer moves first.\n\n";
		turn = 'O';
	}
	
    while (!gameover())
    {
        display_board();
        player_turn();
        gameover();
    }
    
    if (turn == 'O' && !draw)
    {
        display_board();
        cout <<"\n\nYou win! Congratulations!\n";
    }
    else if (turn == 'X' && !draw)
    {
        display_board();
        cout <<"\n\nThe computer wins! Better luck next time!\n";
    }
    else
    {
        display_board();
        cout <<"\n\nThe game is a draw! Try again!\n";
    }
}

void display_board()
{
    cout << "---------------------\n\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "     |     |     \n\n";
}

void player_turn()
{
    int choice;
    int row = 0, column = 0;
    
    if (turn == 'X')
    {
        cout << "Player 1 turn [X]: ";
        cin >> choice;
    }
    else if (turn == 'O')
    {
        cout << "The computer's turn.\n\n";
        choice = rand() % 9 + 1;
        if(turn == '0' && board[row][column] == 'X' || board[row][column] == 'O')
        {
        	player_turn();
        }
    }
    
    switch (choice)
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
            cout << "You did not enter a correct number. Please try again.\n\n";
            player_turn();
    }
    
    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'O';
        turn = 'X';
    }
    else if (turn == 'X')
    {
        cout << "The cell you chose is taken. Please try again.\n";
        player_turn();
    }
    
    else if (turn == 'O')
    {
    	choice = rand() % 9 + 1;
        if(turn == '0' && board[row][column] == 'X' || board[row][column] == 'O')
        {
        	player_turn();
        }
    }

}

bool gameover()
{
    for (int i = 0; i < 3; i++)//Check for a win
    {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || (board[0][i] == board[1][i] && board[1][i] == board[2][i]) || (board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        {
            return true;
        }
    }
    
    for (int i = 0; i < 3; i++)//Check for draw
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return false;
            }
        }
    }
    draw = true;
    return true;
}
