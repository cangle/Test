/*
Author: Chris Angle, Dan Griffin
Program Name: Craps
Assignment: C++ Lab 3 Problem 2
Date Submitted: 3/10/14
Program function: Simulate a game of craps  


*****************************************************************/

#include <iostream>  //stream objects (cin, cout...)
#include <cmath>     //math libraries
#include <fstream>   //file streaming objects (fstream...)
#include <string>    //string manipulation
#include <iomanip>   //formatting of output
#include <cstdlib>   // need for rand(), srand()
#include <time.h>

using namespace std;

const double PI = acos(-1); //creates a constant for pi

void instructions();

int roll();

int main()
{
	string ofname = ("craps_out.txt");
	ofstream fout;
	fout.open(ofname.c_str());  //open output

    if(fout.fail()) {            //test for successful open
        cout<<"Failed to open output file, "<<ofname<<".  Exiting";               
        while(true);
    }
    
	char response, ifRoll, ifRoll_1;
	int first_roll, point, new_roll;
	cout << "LET'S PLAY CRAPS!\n\n";
	fout << "LET'S PLAY CRAPS!\n\n";
	cout << "Do you need instructions (y/n)?";
	fout << "Do you need instructions (y/n)?";
	cin >> response;
	if(response == 'y')
	{
		instructions();
	}
	cout << "Push 'r' to roll.\n";
	fout << "Push 'r' to roll.\n";
	cin >> ifRoll;
	while(ifRoll == 'r')
	{
		first_roll = roll();
		cout << "You rolled a " << first_roll << endl;
		fout << "You rolled a " << first_roll << endl;
		if(first_roll == (7||11))
		{
			cout << "You win!\n";
			fout << "You win!\n";
			cout << "Would you like to roll again (r)?\n";
			fout << "Would you like to roll again (r)?\n";
			cin >> ifRoll;
		}
		else if(first_roll == (2||3||12))
		{
			cout << "You lose!\n";
			fout << "You lose!\n";
			cout << "Would you like to roll again (r)?\n";
			fout << "Would you like to roll again (r)?\n";
			cin >> ifRoll;
		}
		else
		{
			point = first_roll;
			cout << first_roll << " is your point\n";
			fout << first_roll << " is your point\n.";
			cout << "See if you can roll your point again before getting a 7\n";
			fout << "See if you can roll your point again before getting a 7\n";
			cout << "Push 'r' to roll.\n";
			fout << "Push 'r' to roll.\n";
			cin >> ifRoll_1;
			while(ifRoll_1 == 'r')
			{
				new_roll = roll();
				cout << "You rolled a " << new_roll;
				fout << "You rolled a " << new_roll;
				if(new_roll == 7)
				{
					cout << "You lose!\n";
					fout << "You lose!\n";
					cout << "Would you like to roll again (r)?\n";
					fout << "Would you like to roll again (r)?\n";
					cin >> ifRoll;
				}
				else if(new_roll == point)
				{
					cout << "You win!\n";
					fout << "You win!\n";
					cout << "Would you like to roll again (r)?\n";
					fout << "Would you like to roll again (r)?\n";
					cin >> ifRoll;
				}
				else
				{
					cout << "Push 'r' to roll.\n";
					fout << "Push 'r' to roll.\n";
					cin >> ifRoll_1;
				}
			}
		}
		
	}
	return 0;
}
	
void instructions()
{
	cout << "Roll two six-sided dice.\n";
	cout << "a. On the first roll, if you get a 7 or 11 you win!\n";
	cout << "b. on the first roll, if you get a 2, 3, or 12 you lose!\n";
	cout << "c. If you roll any other number you don't win or lose. The die roll becomes your point.\n";
	cout << "Keep rolling the dice again until:\n";
	cout << "a. You roll the point again and win!\n";
	cout << "b. you roll a 7 and lose.\n";
	cout << "Good luck!\n";
}

int roll()
{
	
	int roll_num;
	roll_num = roll();
	int num1, num2, result;
	srand(time(0));
	num1 = rand()%(6 - 1 + 1) + 1;
	num2 = rand()%(6 - 1 + 1) + 1;
	result = num1 + num2;
	return result;
	
}

	
