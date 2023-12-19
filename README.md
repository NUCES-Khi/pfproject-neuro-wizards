[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/j0WbCUcA)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=13059279&assignment_repo_type=AssignmentRepo)
# PF semester project Fall 2023

# Project Final Report:

## Group members:

■ Abdul Rehman Azam [23K-0061]

■ Adina Faraz [23K-0008]

■ Syeda Sara Ali [23K-0070]

### Course title: Programming fundamentals [CS1002]
### Course instructor: Farooq Zaidi.
### Date of submission: 06-10-2023

# Project Illustration:

The project aims to create a classic game named as "TRIPLE CHALLENGE SHOWDOWN" using C programming language which includes three games, Tic Tac Toe, Guessing The Number and Rock Paper Scissors Lizard Spork. Firstly, and most importantly, the user will be asked to choose any 1 of the tree mentioned games.

## TIC TAC TOE:
First and foremost, in Tic Tac Toe the user can play against a computer or against a person which is based upon the user's choice. After that, the user can choose the difficulty level to determine how easy or hard they want the game to be. While playing against a computer if he picks an easy level, there will be a possibility that he might win, However, if he chooses hard then either he will lose, or the game will be drawn.
Moreover, if the game is being played against the computer, the user will make their choice, and the computer will. The computer's move completely depends upon some functions and the mini-max algorithm. In this case, either the computer will win the game, or it will end in a draw. However, when the game is being played between two people, both of them will make their choices sequentially, and one of them will win the game. 

## ROCK PAPER SCISSOR LIZARD SPOCK:
Basically, in this game, the user can choose among these 5 options (mainly Rock, Paper, Scissors, Lizard, Spork). Afterward, the user will make his choice, and then accordingly the computer will choose using a random function. Then the winner will be chosen using some functions. Either user will win or lose.

## GUESSIG THE NUMBER:
Firstly, the computer will generate a number between 1-100 randomly using a function. Thereafter, the user will be asked to input his guesses this process will continue untill the user guesses correctly. When the user successfully guesses the 
number, he'll win the game. The screen will also display the number of attempts made by the user in order to guess the number.

# Project Proposal:

This project focuses on providing an interactive and engaging gaming experience, making it suitable for beginners in programming.
### Objectives:

Develop three games within a single functional game with a user-friendly interface.
Implement game rules to allow users to play against a computer opponent. First the user will be asked if he/she wants a multiplayer game or single player vs. computer game. Then an option will be provided to the user to choose the difficulty level. If the user chooses easy level, he/she may have the probability to win but if the user chooses hard level, then the user has no chances to win, either he/she will lose or the game will be drawn simply. (only for tic tac toe).
Ensure error handling to prevent crashes and handle invalid user input.

### Methods:

#### Decision Structures (if-else statements or switch-case):
It would be used to check for win conditions, draw scenarios, and validate user input. All the moves of the computer will be based on the game state. Also, for the selected level whether hard or easy, otherwise it will generate random guesses. Appropriate messages to the user, such as "Player wins", "It's a draw." Or "Computer won"
#### Loops (for/while loops):
Implement the main game loop that allows players to take turns until the game ends. loops for input validation, ensuring that users enter valid moves. Check for win conditions and draws within loops after each move.
#### Arrays:
The 2D arrays would be used in the tic tac toe game as the major part of this game will use2D array. Iteration of arrays would have occurred to update and display the game board. If needed array will be used to keep track of the performance of the computer and the player.
#### Filing:
File can be used for input and output to save and load game states, allowing players to resume previous games. Store player scores or game statistics in files for long-term tracking.
#### Functions:
Functions will be made to improve readability and to avoid repetition of same code. They will also make the code precise and handle specific tasks. In all the three games functions will be made for each and every task.
#### Enhanced UI:
We'll try to make our games look more attractive and user friendly by using some keywords. A colorfull game would be made in order to grasp user's attention and interest.

## Main Modes Used:

Functions (recursive, user defined).

Artificial Intelligence algorithm.

Conditional structures.

Filing.

Enhancing UI.


## Data Structure and Main Logic and Algorithm used:

Implementation of AI algorithm to make our work more efficient. Minimax algo is applied to the game which is a backtracking algorithm that recursively checks all the possible moves that the computer can make during the game and then the best move will be chosen among those steps. Thereafter the computer will make its move based on the best move suggested by minimax algo. This algo is used in our tic tac toe game (player vs computer) to make the game systematic.

## Major Problem Faced:

Overall the problem was faced in the implimentation of MiniMax Algorithm as it is an AI Algorithm therefore we all faced problem firstly, in understanding this algorithm. Then how to apply this algorithm in our game and then the error handling problem. Some times we were even not getting the desired results. IN nutshell the use of AI algorithm was the main difficul and major problem we faced in this project. 
Moreover, we also faced problem while dealing with the ivalid inputs. On pressing many other characters the output is not showing invalid input or somthing like that in all three games or if in tic tac toe the number entered by user is not availible then too it has to show invalid input. So basically in our overall project the major problem faced by us were these two.

## Contributions:

#### Abdul Rehman Azam: 
	Implementation of AI algorithm in TIC TAC TOE that includes functions: 
1. computer.
2.  bestmove.
3. Minimax.
4. Evaluate.
5. Isvalid.
6. Winner.

	Making UI to look more attractive and user friendly.

#### S. Sara Ali: 
	Made Guessing The Number Game using functions: 
1. guessing_the_number.
2.  RandomNumber.
3.  isCorrect. 

	Functions in TIC TAC TOE: 
1. Multiplayer.
2. isBoardFull. 
3. printBoard. 
4. save.
5. tictac_name.

#### Adina Faraz:
	Made Rock Paper Scissor that includes functions: 
1. generateComputerChoice.
2. determineWinner.
3. printChoices
4. rock_paper.   

	Functions in TIC TAC TOE: 
1. file_func.
2. easy_move.
3. reset.


