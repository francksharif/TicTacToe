#include <iostream>

using namespace std;


char A[9] = {};

// Initialize the array with blank
void Initialize() {
	for (size_t i = 0; i < 9; i++)
	{
		A[i] = ' ';
	}
}



//Put player value in the array
void Allow(int pos,char player)
{
	A[pos] = player;
}


//Display the game on the screen 
void Display()
{
	cout << "----------------------------\n";
	cout << "|   " << A[0] << "    |   " << A[1] << "    |   " << A[2] << "    |" << endl;
	cout << "----------------------------\n";
	cout << "|   " << A[3] << "    |   " << A[4] << "    |   " << A[5] << "    |" << endl;
	cout << "----------------------------\n";
	cout << "|   " << A[6] << "    |   " << A[7] << "    |   " << A[8] << "    |" << endl;
	cout << "----------------------------\n";
}


//check if one the player won 
bool Verify()
{

	// Rows 
	if ( (A[0] == A[1]) && (A[1] == A[2]) && A[0] != ' ')
	{
		return true;
	}

	else if ((A[3] == A[4]) && (A[4] == A[5]) && A[3] != ' ')
	{
		return true;
	}
	
	if ((A[6] == A[7]) && (A[7] == A[8]) && A[6] != ' ')
	{
		return true;
	}


	//Columns 
	if ((A[0] == A[3]) && (A[3] == A[6]) && A[0] != ' ')
	{
		return true;
	}

	else if ((A[1] == A[4]) && (A[4] == A[7]) && A[1] != ' ')
	{
		return true;
	}

	else if ((A[2] == A[5]) && (A[5] == A[8]) && A[2] != ' ')
	{
		return true;
	}



	//Diagonals
	if ((A[0] == A[4]) && (A[4] == A[8]) && A[0] != ' ')
	{
		return true;
	}
	else if ((A[2] == A[4]) && (A[4] == A[6]) && A[2] != ' ')
	{
		return true;
	}
	


	return false;
}





int main()
{
	// Initialize the game 

	Initialize();


	// Play the game 
	char player1 = 'X';
	char player2 = '0';

	int cnt = 9; // numbers of plays during the game 
	int pos;

	bool check = false;


	while (cnt > 0 || check != false)
	{
		// player 1
		if (cnt % 2 != 0 )
		{
			pos = -1;
			system("CLS");
			Display(); // display the screen for player
			cout << endl << endl;
			cout << "Player 1 ( X ) play  (choose a empty position) position (0 to 8) :";
			cin >> pos;

			while (A[pos] != ' ')
			{
				cout << "Choose an empty position !!\n";
				cin >> pos;
			}
			Allow(pos, player1); // set the postion of player 1
			Verify();
			if (check != Verify())
			{
				system("CLS");
				Display();
				cout << "Player 1 is the winner !!\n";
				return true;
			}
			cout << endl << endl;
			--cnt;
		}

		


		// player 2
		else if (cnt % 2 == 0)
		{
			pos = -1;
			system("CLS");
			Display();
			cout << endl << endl;
			cout << "Player 2 ( 0 ) play  (choose a empty position) position (0 to 8) :";
			cin >> pos;

			while (A[pos] != ' ')
			{
				cout << "Choose an empty position !!\n";
				cin >> pos;
			}
			Allow(pos,player2);
			Verify();
			if (check != Verify())
			{
				system("CLS");
				Display();
				cout << "Player 2 is the winner !!\n";
				return true;
			}
			cout << endl << endl;
			--cnt;
		}
	}
	
	system("CLS");
	Display();
	cout << "Tied game lets start a new game....." << endl;


	return 0;
}