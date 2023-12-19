#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 3
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

// Rock paper scissor
int generateComputerChoice();
int determineWinner(int userChoice, int computerChoice);
void printChoices();
void rock_paper();

// Guess the number game
void guessing_the_number();
int RandomNumber();
int isCorrect(int numberToGuess, int userGuess);

// Tic tac toe
void printBoard(char board[SIZE][SIZE]);
int isBoardFull(char board[SIZE][SIZE]);
int winner(char board[SIZE][SIZE], char ch);
int isValid(char board[SIZE][SIZE], int row, int col);
int evaluate(char board[SIZE][SIZE]);
int minimax(char board[SIZE][SIZE], int depth, bool isMax);
void best_move(char board[SIZE][SIZE]);
void save(char board[SIZE][SIZE]);
void reload(char board[SIZE][SIZE]);
void easy_move(char board[SIZE][SIZE]);
void computer(char board[SIZE][SIZE], int mode);
void multiplayer(char board[SIZE][SIZE]);
void file_func();
void tictac_name();

int main()
{
    char any[2];
    int choice;
    printf("Enter any key to continue: ");
    scanf("%s", any);
    system("cls");
    do
    {
        printf(CYAN "^^^^^^^^^" YELLOW " WELCOME" RESET " TO " RESET RED " T " GREEN "R " BLUE "I " YELLOW "P " GREEN "L " RED "E " RESET YELLOW " CHAL" GREEN "LENGE" CYAN " SHOW" RED "DOWN " CYAN "^^^^^^^^^\n" RESET);

        printf("\nChoose your interest: "
               "\n\t1. Tic Tac Toe (Multiplayer/Solo) "
               "\n\t2. Guessing the number "
               "\n\t3. Rock, paper, scissors, lizard, spock"
               "\n\t4. Exit game\n");
        scanf("%d", &choice);

        system("cls");

        if (choice == 1)
        {
            int cont, level, mode;
            srand(time(0));
            tictac_name();
            do
            {
                char board[SIZE][SIZE] = {
                    {'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};
                file_func();
                printf("1.Want to play with friend\n"
                       "2.Want to play with computer in easy mode\n"
                       "3.Want to play with computer in hard mode\n"
                       "4.EXIT\n");
                scanf("%d", &mode);

                system("cls");

                if (mode == 1)
                {
                    multiplayer(board);
                }
                else if (mode == 2)
                {
                    computer(board, mode); // easy mode
                }
                else if (mode == 3)
                {
                    computer(board, mode); // hard mode
                }
                else
                    break;

                printf("Do you want to play again\n"
                       "1. To continue\n"
                       "0. To go back\n");
                scanf("%d", &cont);

                system("cls");
            } while (cont);
        }
        else if (choice == 2)
        {
            guessing_the_number();
        }
        else if (choice == 3)
        {
            rock_paper();
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            printf("\nMake a valid choice");
        }
    } while (1);

    printf("\n\n\t\tTHANKS FOR PLAYING! SEE YOU AGAIN");
    Sleep(3000);
    return 0;
}

// to print the board of tic tac toe
void printBoard(char board[SIZE][SIZE])
{
    printf(YELLOW "******\n" RESET);
    for (int i = 0; i < SIZE; i++)
    {

        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 'X')
            {
                printf(YELLOW "|" RESET RED " %c " RESET YELLOW "|" RESET, board[i][j]);
            }
            else if (board[i][j] == 'O')
            {
                printf(YELLOW "|" RESET BLUE " %c " RESET YELLOW "|" RESET, board[i][j]);
            }
            else
                printf(YELLOW "|" RESET " %c " YELLOW "|" RESET, board[i][j]);
        }
        printf("\n");
        if (i < SIZE - 1)
            printf(YELLOW "---------------\n" RESET);
    }
    printf(YELLOW "******\n" RESET);
}

// check whether the board have available inputs or not
int isBoardFull(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] >= '1' && board[i][j] <= '9')
            {
                return 0; // board is not full
            }
        }
    }
    return 1; // board is full
}

// to check whether player wins or not
int winner(char board[SIZE][SIZE], char ch)
{
    // checking for rows and columns
    for (int i = 0; i < SIZE; i++)
    {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == ch) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == ch))
        {
            return 1; // Player wins
        }
    }

    // checking for horizontals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == ch) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == ch))
    {
        return 1; // Player wins
    }

    return 0;
}

// to check whether the move is valid or it is already input before
int isValid(char board[SIZE][SIZE], int row, int col)
{
    if (board[row][col] >= '1' && board[row][col] <= '9')
    {
        return 1; // yes position valid
    }
    return 0; // position not valid
}

// evaluation funciton used for minimax algorithm
int evaluate(char board[SIZE][SIZE])
{
    if (winner(board, 'X'))
    {
        return 1; // computer wins
    }
    else if (winner(board, 'O'))
    {
        return -1; // player wins
    }
    else if (isBoardFull(board))
    {
        return 0; // its a draw
    }
    else
    {
        return 2; // game is going on
    }
}
