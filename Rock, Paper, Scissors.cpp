/* 
Name: Gayvalin Sujaritchai (Tammy)
Class: CS 2 
Project name: Programming Project 4 
Last modified: 9/30/22
*/

#include <iostream>
#include <cctype>
using namespace std;

int roundNum, playerPoint, pcPoint;
string winner;
char userChoice, computer;

char computerChoice();

int main() {
  //Prompt for no. of round user wants to play
  cout << "Welcome to Rock Paper Scissors game!\n" 
  << "\nHow many rounds do you want to play?\n";
  cin >> roundNum;

  /*Prompt for user input [(R)ock, (P)aper, or (S)cissors] then compare the result to computer generated result using computerChoice function */
  for (int i = 0; i < roundNum; i++){
    cout << "\nEnter your choice: (R)ock, (P)aper, or (S)cissors" << endl;
    cin >> userChoice;

    /*convert computer and user's input into upper case so that all of
    the choices from both the computer and the user are compared as
    uppercase letters*/
    computer = toupper(computerChoice());
    userChoice = toupper(userChoice); 

    //First, compare if computer's output and user's input is identical, else, compare to each scenerio
    if (computer == userChoice){
      cout << "Oops! Tie" << endl;
    } 
    else if (computer != userChoice){
      
      //Scissors vs paper
      if ((computer == 'S' ) && (userChoice == 'P')){
        cout << "Computer won!" << endl;
        pcPoint += 1;
      } 
      else if (computer == 'P' && userChoice == 'S'){
        cout << "You won!" << endl;
        playerPoint += 1;
      }
      //Paper vs rock
      if (computer == 'P' && userChoice == 'R'){
        cout << "Computer won!" << endl;
        pcPoint += 1;
      } 
      else if (computer == 'R' && userChoice == 'P'){
        cout << "You won!" << endl;
        playerPoint += 1;
      }

      //Scissors vs rock
      if (computer == 'R' && userChoice == 'S'){
        cout << "Computer won!" << endl;
        pcPoint += 1;
      }
      else if (computer == 'S' && userChoice == 'R'){
        cout << "You won!" << endl;
        playerPoint += 1;
      }
    }
  }//end of for loop

  //Display points and announce winner
  cout << "\nPlayer's point(s) = " << playerPoint << endl;
  cout << "Computer's point(s) = " << pcPoint << endl;
  
  winner = (playerPoint > pcPoint) ? "You!" : "The computer!";

  cout << "\nAnd the winner is....." << winner << endl;
  
  
}

char computerChoice() {
    int random = (rand() % 6);
    char possibleChoices[] = {'R', 'r', 'P', 'p', 'S', 's'};
    char choice = possibleChoices[random];
    return choice;
}

//Credit: CIS 12 and https://www.programiz.com/cpp-programming/library-function/cctype/toupper#:~:text=The%20toupper()%20function%20in,in%20the%20cctype%20header%20file.
