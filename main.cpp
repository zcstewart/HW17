//Homework 17

/*
 *  Filename:           main.cpp
 * 
 *  Purpose:            The purpose of this program is to read an input
 *                      text file, and write to an output text file. The
 *                      program will allow the user to view statistics of
 *                      an NFL player, as well as manually search for 
 *                      statistics of any player.
 * 
 *  Author:             Zachary Charles Stewart
 *  Student ID:         105903414
 *  Date:               1/31/2017 15:34 PST
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


//Namespace
using namespace std;

//Const int for array size
const int N = 10;

//--------------------------------------------------------------------------//

//Structure footBallPlayerType

struct footBallPlayerType {
    string player_lastName; //Player Last Name
    string player_position; //Player Position
    int player_numTD; //Total Touchdowns
    int player_numRec; //Total Receptions
    int player_RushYd; //Total Rushing Yards
    int player_RecYd; //Total Receiving Yards
    int player_PassYd; //Total Passing Yards
};

//--------------------------------------------------------------------------//

//Function Prototypes

// Display the menu
void showMenu();

// Get team data from the input file
void getData(ifstream &inputFile,
        footBallPlayerType list[N]);

// Save current team data to output file
void saveData(ofstream &outputFile,
        footBallPlayerType list[N]);

// Print entire team data to the screen
void printData(footBallPlayerType list[N]);

// Print a single player’s data to the screen
void printPlayerData(footBallPlayerType list[N],
        int playerNum);

// Search the data for a player
int searchData(footBallPlayerType list[N], string n);

// Update the number of touchdowns for a player
void updateTouchDowns(footBallPlayerType list[N],
        int tDowns, int playerNum);

// Update the number of catches for a player
void updateCatches(footBallPlayerType list[N], int catches,
        int playerNum);

// Update the number of passing yards for a player
void updatePassingYards(footBallPlayerType list[N],
        int passYards, int playerNum);

// Update the number of receiving yards for a player
void updateReceivingYards(footBallPlayerType list[N],
        int recYards, int playerNum);

// Update the number of rushing yards for a player
void updateRushingYards(footBallPlayerType list[N],
        int rushYards, int playerNum);


//--------------------------------------------------------------------------//

//Main Function
//Inputs:   None
//Outputs:  None
//Purpose:  Execute program with supplied functions

int main(int argc, char** argv) {
    //Declare array of structures (footballPlayerType)
    footBallPlayerType player[N];
    //Variables for switch statement
    int input = 0;
    string inString;
    int inNum = 0;
    int inNum2 = 0;

    //Declare FileStream Variables
    ifstream inFile;
    ofstream outFile;

    //Open Files
    inFile.open("PackersData.txt");
    outFile.open("PackersOutput.txt");

    //Test if inFile is open
    if (!inFile.is_open()) {
        //If not, output error message and terminate program.
        cout << "Data file not found. Program terminating." << endl;
        exit(EXIT_FAILURE);
    }

    //Test if outFile is open
    if (!outFile.is_open()) {
        //If not, output error message and terminate program
        cout << "Data file not found. Program terminating." << endl;
        exit(EXIT_FAILURE);
    }
    
    //Call get Data function to load data from text file
    getData(inFile, player);

    //Switch statement to select menu option
    while (input != 99) 
    {
        //Display menu with various commands, prompt user for input
        showMenu();
        cin >> input;
        switch (input) 
        {
            case 1:
                //Call function to print player data
                printData(player);
                break;

            case 2:
                //Prompt user for name
                cout << "Enter player's name: " << endl;
                cin >> inString;
                //Search for player with matching  name
                //Return array index
                inNum = searchData(player, inString);
                //If no match, invalid player
                if (inNum == 100) 
                {
                    cout << "Invalid Player Number" << endl;
                }
                //Else, print player data
                else
                {
                    printPlayerData(player, inNum);
                }
                break;
            case 3:
                cout << "Enter player's name: " << endl << endl;
                cin >> inString;
                //Search for player with matching  name
                //Return array index
                inNum = searchData(player, inString);
                //If no match, invalid player
                cout << "Enter number of touchdowns added: " << endl;
                cin >> inNum2;
                if (inNum == 100) 
                {
                    cout << "Invalid Player Number" << endl;
                } 
                //Else, update touchdowns
                else 
                {
                    updateTouchDowns(player, inNum2, inNum);
                }
                break;

            case 4:
                cout << "Enter player's name: " << endl << endl;
                cin >> inString;
                //Search for player with matching  name
                //Return array index
                inNum = searchData(player, inString);
                //If no match, invalid player
                cout << "Enter number of catches added: ";
                cin >> inNum2;
                if (inNum == 100)
                {
                    cout << "Invalid Player Number" << endl;
                } 
                //Else, update catches
                else 
                {
                    updateCatches(player, inNum2, inNum);
                }
                break;

            case 5:
                cout << "Enter player's name: ";
                cin >> inString;
                //Search for player with matching  name
                //Return array index
                inNum = searchData(player, inString);
                //If no match, invalid player
                cout << "Enter number of passing yards added: ";
                cin >> inNum2;
                if (inNum == 100) 
                {
                    cout << "Invalid Player Number" << endl;
                } 
                //Else, update Passing Yards
                else
                {
                    updatePassingYards(player, inNum2, inNum);
                }
                break;


            case 6:
                cout << "Enter player's name: " << endl << endl;
                cin >> inString;
                //Search for player with matching  name
                //Return array index
                inNum = searchData(player, inString);
                //If no match, invalid player
                cout << "Enter number of receiving yards added: ";
                cin >> inNum2;
                if (inNum == 100) 
                {
                    cout << "Invalid Player Number" << endl;
                } 
                //Else, update Receiving Yards
                else
                {
                    updateReceivingYards(player, inNum2, inNum);
                }
                break;

            case 7:
                cout << "Enter player's name: ";
                cin >> inString;
                //Search for player with matching  name
                //Return array index
                inNum = searchData(player, inString);
                //If no match, invalid player
                cout << "Enter number of rushing yards added: ";
                cin >> inNum2;
                if (inNum == 100) 
                {
                    cout << "Invalid Player Number" << endl;
                } 
                //Else, update Rushing Yards
                else
                {
                    updateRushingYards(player, inNum2, inNum);
                    cout << endl;
                }
                break;

            default:
                //Exit switch structure if no matching input
                break;
        }
    }
    //Prompt user to save data
    cout << "Would you like to save data (Y/N): ";
    cin >> inString;
    //Save Data to output file
    if (inString == "Y" || inString == "y")
    {
        saveData(outFile, player);
    }
    //Close inFile and outFile
    inFile.close();
    outFile.close();
    //Terminate program upon successful execution
    exit(EXIT_SUCCESS);
}
//--------------------------------------------------------------------------//
//Function Definitions

// Display the menu
void showMenu() 
//Inputs:   None
//Output:   None, return type void
//Purpose:  Function outputs a menu to the user asking them to enter a 
//          number that correlates to a certain command. The list of these
//          commands will be displayed on the screen as well.

{
    {
        cout << "Select one of the following options." << endl;
        cout << "  (1)  Print the Team's Data" << endl;
        cout << "  (2)  Print a Player's Data" << endl;
        cout << "  (3)  Update a Player's Touchdowns" << endl;
        cout << "  (4)  Update a Player's Catches" << endl;
        cout << "  (5)  Update a Player's Passing Yards" << endl;
        cout << "  (6)  Update a Player's Receiving Yards" << endl;
        cout << "  (7)  Update a Player's Rushing Yards" << endl;
        cout << " (99)  Quit the Program" << endl;
        cout << "Input Selection: ";
    }
}

// Get team data from the input file
void getData(ifstream &inputFile, footBallPlayerType list[N])
//Inputs:   ifstream &inputFile
//          footBallPlayertype list[N]
//Output:   None, return type void
//Purpose:  The purpose of this function is to cycle through an array of
//          Structures (of type footBallPlayerType), and read in values
//          to the data members of the structure from a predetermined
//          text file.

{
    //Cycle through array
    for (int i = 0; i < N; i++) 
    {
        //Read in player data
        inputFile >> list[i].player_lastName;
        inputFile >> list[i].player_position;
        inputFile >> list[i].player_numTD;
        inputFile >> list[i].player_numRec;
        inputFile >> list[i].player_PassYd;
        inputFile >> list[i].player_RecYd;
        inputFile >> list[i].player_RushYd;
    }
}

// Save current team data to output file
void saveData(ofstream &outputFile, footBallPlayerType list[N]) 
{
//Inputs:   ofstream &outputFile
//          footBallPlayerType list[N]
//Outputs:  None, return type void
//Purpose:  The purpose of this function is to write an array of structures
//          (of type footBallPlayerType) to a predetermined output text file.
    
    //Cycle through array
    for (int i = 0; i < N; i++) 
    {
        //Read out player data
        outputFile << list[i].player_lastName << " ";
        outputFile << list[i].player_position << " ";
        outputFile << list[i].player_numTD << " ";
        outputFile << list[i].player_numRec << " ";
        outputFile << list[i].player_PassYd << " ";
        outputFile << list[i].player_RecYd << " ";
        outputFile << list[i].player_RushYd << endl;
    }
}

// Print entire team data to the screen
void printData(footBallPlayerType list[N]) 
{
//Inputs:   footBallPlayerType list[N]
//Outputs:  None, return type void
//Purpose:  The purpose of this function is to print out a full list
//          featuring the name, position, and relevant statistics of all
//          football players from a structure (of type footBallPlayerType)
//          to the output terminal
    
    //Print player data
    cout << "Name      Position Touchdowns Catches Passing";
    cout << " Receiving Rushing" << endl << endl;
    //Cycle through array
    for (int i = 0; i < N; i++)
    {
        cout << setw(10) << list[i].player_lastName;
        cout << setw(8) << list[i].player_position;
        cout << setw(11) << list[i].player_numTD;
        cout << setw(8) << list[i].player_numRec;
        cout << setw(8) << list[i].player_PassYd;
        cout << setw(10) << list[i].player_RecYd;
        cout << setw(8) << list[i].player_RushYd;
        cout << endl;
    }
    cout << endl << endl;
}

// Print a single player’s data to the screen
void printPlayerData(footBallPlayerType list[N], int playerNum)
{
//Inputs:   footBallPlayerType list[N]
//          int playerNum
//Outputs:  None, return type void
//Purpose:  The purpose of this function is to print the data of a
//          specific football player from a predetermined user input index
//          number. The function will print all the relevant data of that
//          player to the output terminal.
    
    cout << "Name = " << list[playerNum].player_lastName << endl;
    cout << "  Position = " << list[playerNum].player_position << endl;
    cout << "  Touchdowns = " << list[playerNum].player_numTD << endl;
    cout << "  Number of Catches = " << list[playerNum].player_numRec;
    cout << endl;
    cout << "  Passing Yards = " << list[playerNum].player_PassYd << endl;
    cout << "  Receiving Yards = " << list[playerNum].player_RecYd;
    cout << endl;
    cout << "  Rushing Yards = " << list[playerNum].player_RushYd << endl;
    cout << endl << endl;
}

//Search the data for a player
int searchData(footBallPlayerType list[N], string n) 
{
//Inputs:   footBallPlayerType list[N]
//          string n
//Outputs:  Returns an integer value from variable "index"
//Purpose:  The purpose of this function is to cycle through an array of
//          structures of type footBallPlayerType and search for a member
//          of the array "player_lastName" and compare it to the input
//          string parameter "n". If they are identical, the index of that
//          particular structure is saved to index and returned. Otherwise
//          The original arbitrary index of 100 is returned. 
    
    //Set arbitrary index if player isn't found
    int index = 100;

    //Cycle through array
    for (int i = 0; i < N; i++) 
    {
        //Check if valid player number
        if (list[i].player_lastName.compare(n) == 0)
        {
            //Update found player index
            index = i;
        }
    }
    //Return Index
    return index;
}

//Update the number of touchdowns for a player
void updateTouchDowns(footBallPlayerType list[N], int tDowns, int playerNum)
//Inputs:   footBallPlayerType list[N]
//          int tDowns
//          int playerNum
//Outputs:  None, return type void
//Purpose:  The purpose of this function is to take in the index of a player
//          and add an amount of touchdowns to be added to the particular
//          players statistics. Both the index and amount of touchdowns are
//          parameter arguments of the function, in addition to the array
//          of structures (of type footBallPlayerType). The function will
//          verify the user index is correct (to avoid out of bounds errors
//          with arrays, then find the player with the specified index and
//          modify the total amount of touchdowns.

{
    //Check if valid player number
    if (playerNum >= 0 && playerNum < N)
    {
        //Add to sum
        list[playerNum].player_numTD += tDowns;
    }
}

// Update the number of catches for a player
void updateCatches(footBallPlayerType list[N], int catches, int playerNum)
//Inputs:   footBallPlayerType list[N]
//          int catches
//          int playerNum
//Outputs:  None, return type void
//Purpose:  The purpose of this function is to take in the index of a player
//          and add an amount of catches to be added to the particular
//          players statistics. Both the index and amount of catches are
//          parameter arguments of the function, in addition to the array
//          of structures (of type footBallPlayerType). The function will
//          verify the user index is correct (to avoid out of bounds errors
//          with arrays, then find the player with the specified index and
//          modify the total amount of catches.
{
    //Check if valid player number
    if (playerNum >= 0 && playerNum < N) 
    {
        //Add to sum
        list[playerNum].player_numRec += catches;
    }

}

// Update the number of passing yards for a player
void updatePassingYards(footBallPlayerType list[N], int passYards,
                        int playerNum) 
{
    //Inputs:   footBallPlayerType list[N]
//          int passYards
//          int playerNum
//Outputs:  None, return type void
//Purpose:  The purpose of this function is to take in the index of a player
//          and add an amount of pass yards to be added to the particular
//          players statistics. Both the index and amount of pass yards are
//          parameter arguments of the function, in addition to the array
//          of structures (of type footBallPlayerType). The function will
//          verify the user index is correct (to avoid out of bounds errors
//          with arrays, then find the player with the specified index and
//          modify the total amount of pass yards.
    //Check if valid player number
    if (playerNum >= 0 && playerNum < N) 
    {
        //Add to sum
        list[playerNum].player_PassYd += passYards;
    }
}

// Update the number of receiving yards for a player
void updateReceivingYards(footBallPlayerType list[N], int recYards,
        int playerNum) 
{
    //Inputs:   footBallPlayerType list[N]
//          int recYards
//          int playerNum
//Outputs:  None, return type void
//Purpose:  The purpose of this function is to take in the index of a 
//          player and add an amount of receiving yards to be added to the 
//          particular players statistics. Both the index and amount of 
//          receiving yards are parameter arguments of the function, in 
//          addition to the array of structures (of type footBallPlayerType).
//          The function will verify the user index is correct (to avoid 
//          out of bounds errors with arrays, then find the player with the
//          specified index and modify the total amount of receiving yards.
    
    //Check if valid player number
    if (playerNum >= 0 && playerNum < N) 
    {
        //Add to sum
        list[playerNum].player_RecYd += recYards;
    }
}

// Update the number of rushing yards for a player
void updateRushingYards(footBallPlayerType list[N], int rushYards,
        int playerNum) 
{
    //Inputs:   footBallPlayerType list[N]
//          int rushYards
//          int playerNum
//Outputs:  None, return type void
//Purpose:  The purpose of this function is to take in the index of a player
//          and add an amount of rush yards to be added to the particular
//          players statistics. Both the index and amount of rush yards are
//          parameter arguments of the function, in addition to the array
//          of structures (of type footBallPlayerType). The function will
//          verify the user index is correct (to avoid out of bounds errors
//          with arrays, then find the player with the specified index and
//          modify the total amount of rush yards.
    
    //Check if valid player number
    if (playerNum >= 0 && playerNum < N)
    {
        //Add to sum
        list[playerNum].player_RushYd += rushYards;
    }
}
//--------------------------------------------------------------------------//