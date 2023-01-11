/*student ID:53044907
Student Name:Cheung Ho Lam
Lab:L02
*/
#include <iostream>
#include <ctime>
#include <limits>
using namespace std;
int main()
{
	//while loop checking
	int check = 0;

	//array for random numbers
	int  random[4];

	//count the steps
	int steps = 1;

	//array for user input guess
	int guess[4];

	//array for the result
	const char* checking[4];
	srand((unsigned int)time(NULL));

	//title
	cout << "MasterMind" << endl;
	cout << "Enter four digits (1-6) separated by a space" << endl;
	cout << "--------------------------------------------" << endl;

	//four radom number chose from computer 
	for (int i = 0; i < 4; i++)
		random[i] = rand() % 6 + 1;

	//checking for random number
	while (check == 0){
		//check random number repeat or not
		for (int i = 0; i < 4; i++){
			for (int j = i + 1; j < 4; j++)
				if (random[i] == random[j]){
					random[j] = rand() % 6 + 1;
					check = 0;
					break;
				}
		}

		//check the last random number repeat or not
		for (int i = 2; i >= 0; i--){
			if (random[3] == random[i] || random[2] == random[i - 1] || random[1] == random[i - 2]){
				random[i] = rand() % 6 + 1;
				check = 0;
				break;
			}
			else {
				check = 1;
			}
		}
	}
	check = 0;

	double epsilon = numeric_limits<double>::epsilon();

	//while the user input wrong number ,program keeps running
	while (check == 0){
		cout << "Round " << steps << ":" << endl;
		cout << "Enter Guess: ";

		//store input to array
		for (int i = 0; i < 4; i++)
			cin >> guess[i];

		//checking for the input which is correct number or not
		for (int i = 0; i < 4; i++){
				if (abs(guess[i] - random[i]) < epsilon)

					checking[i] = "O";

				//the number is in the answer ,but wrong position
				else if ((guess[i] == random[0])||
					(guess[i] == random[1]) ||
					(guess[i] == random[2]) ||
					(guess[i] == random[3]))
				{
					checking[i] = "#";
				}
				// wrong guess
				else
					checking[i] = "X";
		}

		//display the checking of numbers
		cout << "             ";
		for (int i = 0; i < 4; i++)
			cout << checking[i] << " ";
		cout << endl;
		cout << "-----------------------------------------------------------";
		cout << endl;

		//all numbers are correct
		if (checking[0] == "O"&&checking[1] == "O"&&checking[2] == "O"&&checking[3] == "O"){
			cout << "Congratulations! You win the game in " << steps << " steps" << endl;
			check = 1;
			break;
		}

		//steps increase when the user input wrong guess
		else
			check = 0;
		steps++;
	}
	// Hold the command window
	system("pause");
	return 0;
}