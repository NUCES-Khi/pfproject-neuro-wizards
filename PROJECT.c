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

// minimax algorithm which is recursive function, calculates the best input by checking the whole game (ARTIFICIAL INTELLIGENCE)
int minimax(char board[SIZE][SIZE], int depth, bool isMax)
{
    int score = evaluate(board);
    if (score != 2)
    {
        return score;
    }
    char ch;
    if (isMax)
    {
        int max = -1000;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (isValid(board, i, j))
                {
                    ch = board[i][j];
                    board[i][j] = 'X';
                    int current = minimax(board, depth + 1, !isMax);
                    max = (current > max) ? current : max;
                    board[i][j] = ch;
                }
            }
        }
        return max;
    }
    else
    {
        int min = 1000;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (isValid(board, i, j))
                {
                    ch = board[i][j];
                    board[i][j] = 'O';
                    int current = minimax(board, depth + 1, !isMax);
                    min = (current < min) ? current : min;
                    board[i][j] = ch;
                }
            }
        }
        return min;
    }
}

// the turn of the best_move which calls minimax algo to find its input
void best_move(char board[SIZE][SIZE])
{
    int best = -1000, row = -1, col = -1;
    char ch;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (isValid(board, i, j))
            {
                ch = board[i][j];
                board[i][j] = 'X';
                int move = minimax(board, 0, 0);
                board[i][j] = ch;

                if (move > best)
                {
                    row = i;
                    col = j;
                    best = move;
                }
            }
        }
    }
    printf("computer" RED " (X) " RESET "move: %d\n", (row * SIZE) + (col + 1));
    board[row][col] = 'X';
}

void easy_move(char board[SIZE][SIZE])
{
    int move, row, col;
    do
    {
        move = (rand() % 9) + 1;
        row = (move - 1) / 3;
        col = (move - 1) % 3;
    } while (isValid(board, row, col) == 0);

    board[row][col] = 'X';
    printf("Computer" RED " (x) " RESET "move %d\n", move);
}

void save(char board[SIZE][SIZE])
{
    FILE *fsave = fopen("Store.txt", "w+");
    if (fsave == NULL)
    {
        printf(RED "Error opening file\n" RESET);
        return;
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            fprintf(fsave, "%c ", board[i][j]);
        }
    }

    printf(GREEN "Game saved successfully!\n" RESET);
    Sleep(1000);
    fclose(fsave);
    return;
}

void load(char board[SIZE][SIZE])
{
    FILE *fresume = fopen("Store.txt", "r+");
    if (fresume == NULL)
    {
        printf(RED "Error opening file\n" RESET);
        return;
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            fscanf(fresume, "%c ", &board[i][j]);
        }
    }

    printf(GREEN "Previous game loaded successfully!\n" RESET);
    Sleep(1000);
    printBoard(board);
    return;
}
void reset(char board[SIZE][SIZE])
{
    save(board); // Save the current state before resetting

    for (int i = 0, k = 1; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++, k++)
        {
            board[i][j] = k + '0'; // Convert the integer to character
        }
    }
    printf(GREEN "Game reset successfully!\n" RESET);
    Sleep(1000);
    printBoard(board);
    return;
}

void tictac_name()
{
    printf(BLUE "^^^^^^^^^^" RESET " WELCOME TO " RED "TIC " BLUE "TAC " GREEN "BOARD" RESET " BATTLE " BLUE "^^^^^^^^^^^\n\n" RESET);
}

// when the player is playing with computer
void computer(char board[SIZE][SIZE], int mode)
{
    tictac_name();
    printBoard(board);
    while (1)
    {
        char move[10];
        int row, col;
        printf("Enter your" BLUE " (O) " RESET "move: ");
        scanf("%s", move);

        if (strcmp(move, "s") == 0)
        {
            save(board);
            continue;
        }
        else if (strcmp(move, "l") == 0)
        {
            load(board);
            continue;
        }
        else if (strcmp(move, "e") == 0)
        {
            return;
        }
        else if (strcmp(move, "r") == 0)
        {
            reset(board);
            continue;
        }

        int moveInt = atoi(move);
        row = (moveInt - 1) / 3;
        col = (moveInt - 1) % 3;

        if (isValid(board, row, col))
        {
            if (row < 0 || col < 0 || row >= SIZE || col >= SIZE)
            {
                printf(YELLOW "Invalid move. Try again. \n" RESET);
                continue;
            }

            board[row][col] = 'O';

            if (winner(board, 'O'))
            {
                system("cls");
                tictac_name();
                printBoard(board);
                printf(GREEN "Congratulations you won!\n " RESET);
                break;
            }

            if (isBoardFull(board))
            {
                printf(BLUE "Game is draw\n" RESET);
                break;
            }
            printBoard(board);
            printf("Computer loading...");
            Sleep(1000);

            system("cls");

            tictac_name();
