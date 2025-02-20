#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Game
{
private:
    vector<vector<char>> board;
    char currentPlayer;
    char otherPlayer;

public:
    Game()
    {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
        otherPlayer = 'O';
    }

    void drawBoard()
    {
        cout << "Game display:\n";
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << board[i][j] << " ";
                if (j < 2)
                {
                    cout << "| ";
                }
            }
            cout << endl;
            if (i < 2)
            {
                cout << "---------";
            }
            cout << endl;
        }
    }

    bool check()
    {
        // Check rows
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            {
                return true;
            }
        }

        // Check columns
        for (int i = 0; i < 3; i++)
        {
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            {
                return true;
            }
        }

        // Check diagonals
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        {
            return true;
        }
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        {
            return true;
        }

        return false;
    }

    void start()
    {
        int turn = 1;
        while (true)
        {
            drawBoard();
            int row, column;
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> column;
            if (row <= 3 && column <= 3 && row > 0 && column > 0 && board[row - 1][column - 1] == ' ')
            {
                board[row - 1][column - 1] = currentPlayer;
                cout << "Player " << currentPlayer << " moved to (" << row << ", " << column << ")" << endl;

                if (check())
                {
                    drawBoard();
                    cout << "Player " << currentPlayer << " won!" << endl;
                    break;
                }

                if (turn == 9)
                {
                    drawBoard();
                    cout << "The match is a draw." << endl;
                    break;
                }

                turn++;
                // Swap players
                if (currentPlayer == 'X')
                {
                    currentPlayer = 'O';
                }
                else
                {
                    currentPlayer = 'X';
                }
            }
            else
            {
                cout << "Invalid move. Try again." << endl;
            }
        }
    }
};

int main()
{
    Game g1;
    g1.start();
    return 0;
}

