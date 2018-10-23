/*
	File name:  FINALmain.cpp of Final Practical: Game of Life
	Final Problem: 1
	Jeffrey Berglund
	CPTR 141
	12/9/16

	Used http://www.cplusplus.com to find sleep.
	Google told me usleep.
	Wikipedia for glider gun design
	http://www.conwaylife.com/w/index.php?title=Methuselah for the Methuselah
	I remembered that a line of 10 is an Ocolator from a long time ago

*/////////////////////////////////////////////////////////


#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
// GLOBALS
const int Rows = 40;
const int Columns = 40;

//
// FUNCTION PROTOTYPES
//////////////////////////////////////////////////////////

// Function to prompt user for what life to watch
void menu(char board[Rows][Columns], int &gen);

// function displays the current field of life
void display(char board[Rows][Columns]);

// function that makes the two arrays equivilent
void equate(char board1[Rows][Columns], char board2[Rows][Columns]);

// Primary function that tests whether any given cell in the array lives or dies
void live(char board1[Rows][Columns], char board2[Rows][Columns]);

// Function spawns a glider gun
void gliderGun(char board[Rows][Columns]);
// Function spawns a Methuselah
void Methuselah(char board[Rows][Columns]);
// Function spawns a Ocolator
void Ocolations(char board[Rows][Columns]);
// Function spawns Chaos
void Chaos(char board[Rows][Columns]);


//
// MAIN
//////////////////////////////////////////////////////////

int main()
{
	srand(time(0));


	// declaring arrays
	int Generations;
	char matrix1[Rows][Columns];
	char matrix2[Rows][Columns];
	// blank the arrays
	for(int i=0; i<Rows; i++)
		for(int j=0; j<Columns; j++)
			matrix1[i][j] = ' ';
	for(int i=0; i<Rows; i++)
		for(int j=0; j<Columns; j++)
			matrix2[i][j] = ' ';


 // calling function menu to prompt user for inputs
	menu(matrix1, Generations);


	// running the game of life
	for(int i = 0; i < Generations; i++)
	{
		display(matrix1); // display current field
		live(matrix1,matrix2); // calling function live to see who lives and who dies
		equate(matrix2,matrix1); // making the arrays equal
		cout << "Gen: " << i+1; // displaying current generation
		usleep(17500); // delaying next generation
	}


	return 0;
}

//
// FUNCTIONS
//////////////////////////////////////////////////////////

// Function to prompt user for what life to watch
void menu(char board[Rows][Columns], int &gen)
{
	char select = '0';
	cout << "\nWelcome to The Game of Life! What would you like to see?:\n"
			"(1) Glider Gun\n"
			"(2) Methuselah\n"
			"(3) Ocolations\n"
			"(4) Chaos\n";
	cin >> select;
	//validating user input
	while((select != '1')&&(select !='2')&&(select !='3')&&(select !='4'))
	{
		cout << "Invalid, please choose from list.";
		cin >> select;
	}
	//seeding the field of life
	if(select == '1')
	{gliderGun(board);}
	else if(select == '2')
		Methuselah(board);
	else if(select == '3')
		Ocolations(board);
	else
	{
		Chaos(board);
	}
	//prompting for length of time to run
	cout << "\nHow many generations would you like to see?\n";
	cin >> gen;
	// ensuring larger positive numbers
	while(gen < 100)
	{
		cout << "\nInvalid, please enter value equal to or greater than 100. : ";
		cin >> gen;
	}
}

// function displays the current field of life
void display(char board[Rows][Columns])
{
	cout << endl;
	for(int i=0; i<Rows; i++)
			{for(int j=0; j<Columns; j++)
				cout <<  board[i][j] << ' ';
			cout << endl;
			}
	cout << endl;
}

// Function spawns a glider gun
void gliderGun(char board[Rows][Columns])
{
	// left block
	board[6][2] = '*';
	board[6][3] = '*';
	board[7][2] = '*';
	board[7][3] = '*';

	// middle circle thing
	board[6][12] = '*';
	board[7][12] = '*';
	board[8][12] = '*';
	board[9][13] = '*';
	board[10][14] = '*';
	board[10][15] = '*';
	board[9][17] = '*';
	board[8][18] = '*';
	board[7][18] = '*';
	board[7][16] = '*';
	board[7][19] = '*';
	board[6][18] = '*';
	board[5][17] = '*';
	board[4][15] = '*';
	board[4][14] = '*';
	board[5][13] = '*';

	// middle half circle thing

	board[3][24] = '*';
	board[3][26] = '*';
	board[2][26] = '*';
	board[6][22] = '*';
	board[5][22] = '*';
	board[4][22] = '*';
	board[6][23] = '*';
	board[5][23] = '*';
	board[4][23] = '*';
	board[7][24] = '*';
	board[7][26] = '*';
	board[8][26] = '*';

	// right block

	board[4][36] = '*';
	board[4][37] = '*';
	board[5][36] = '*';
	board[5][37] = '*';

}
// Function spawns a Methuselah
void Methuselah(char board[Rows][Columns])
{
	board[10][10] = '*';
	board[10][11] = '*';
	board[11][9] = '*';
	board[11][10] = '*';
	board[12][10] = '*';
}
// Function spawns a Ocolator
void Ocolations(char board[Rows][Columns])
{
	// simple line of 10 for an ocolator
	board[10][10] = '*';
	board[10][11] = '*';
	board[10][12] = '*';
	board[10][13] = '*';
	board[10][14] = '*';
	board[10][15] = '*';
	board[10][16] = '*';
	board[10][17] = '*';
	board[10][18] = '*';
	board[10][19] = '*';
	// I might add more later
}
// Function spawns Chaos
void Chaos(char board[Rows][Columns])
{
	// randomly assigns a cell to living or dead
	for(int i=0; i<Rows; i++)
		for(int j=0; j<Columns; j++)
			{
				int lv = rand() % 3;
				if(lv == 0)
					board[i][j] = '*';
				else
					board[i][j] = ' ';

			}
}

// function that makes the two arrays equivilent
void equate(char board1[Rows][Columns], char board2[Rows][Columns])
{
	for(int i=0; i<Rows; i++)
		for(int j=0; j<Columns; j++)
			board2[i][j] = board1[i][j];
}

// Primary function that tests whether any given cell in the array lives or dies
void live(char board1[Rows][Columns], char board2[Rows][Columns])
{
	for(int i=0; i<Rows; i++) // going through the array
		for(int j=0; j<Columns; j++)
		{
			int counter = 0;

			// conditions if cell in question is in a corner, such that only cells in the array are counted for living conditions
			if(i==0 && j==0) // upper left
			{
				for(int x=i; x<i+2; x++)
					for(int y=j; y<j+2; y++)
					{
						if((x==i)&&(y==j))
						{}
						else
						{
							if(board1[x][y]=='*')
							counter++;
						}
					}
				if(counter < 2)
					board2[i][j] = ' ';
				else if(counter > 3)
					board2[i][j] = ' ';
				else
				{
					if(board1[i][j] == '*')
						board2[i][j] = '*';
					else if((board1[i][j] == ' ') && (counter == 3))
						board2[i][j] = '*';
					else
						board2[i][j] = ' ';
				}
			}
			else if(i==Rows-1 && j==0) // lower left
			{
				for(int x=i; x<i+1; x++)
					for(int y=j; y<j+2; y++)
					{
						if((x==i)&&(y==j))
						{}
						else
						{
							if(board1[x][y]=='*')
							counter++;
						}
					}
				if(counter < 2)
					board2[i][j] = ' ';
				else if(counter > 3)
					board2[i][j] = ' ';
				else
				{
					if(board1[i][j] == '*')
						board2[i][j] = '*';
					else if((board1[i][j] == ' ') && (counter == 3))
						board2[i][j] = '*';
					else
						board2[i][j] = ' ';
				}
			}
			else if(i==0 && j==Columns-1) // upper right
			{
				for(int x=i-1; x<i+2; x++)
					for(int y=j-1; y<j+1; y++)
					{
						if((x==i)&&(y==j))
						{}
						else
						{
							if(board1[x][y]=='*')
							counter++;
						}
					}
				if(counter < 2)
					board2[i][j] = ' ';
				else if(counter > 3)
					board2[i][j] = ' ';
				else
				{
					if(board1[i][j] == '*')
						board2[i][j] = '*';
					else if((board1[i][j] == ' ') && (counter == 3))
						board2[i][j] = '*';
					else
						board2[i][j] = ' ';
				}
			}
			else if(i==Rows-1 && j==Columns-1) // lower right
			{
				for(int x=i-1; x<i+1; x++)
					for(int y=j-1; y<j+1; y++)
					{
						if((x==i)&&(y==j))
						{}
						else
						{
							if(board1[x][y]=='*')
							counter++;
						}
					}
				if(counter < 2)
					board2[i][j] = ' ';
				else if(counter > 3)
					board2[i][j] = ' ';
				else
				{
					if(board1[i][j] == '*')
						board2[i][j] = '*';
					else if((board1[i][j] == ' ') && (counter == 3))
						board2[i][j] = '*';
					else
						board2[i][j] = ' ';
				}
			}

			// conditions if cell in question on a side, such that only cells in the array are counted for living conditions
			else if(i==0) // top
			{
				for(int x=i; x<i+2; x++)
					for(int y=j-1; y<j+2; y++)
					{
						if((x==i)&&(y==j))
						{}
						else
						{
							if(board1[x][y]=='*')
							counter++;
						}
					}
				if(counter < 2)
					board2[i][j] = ' ';
				else if(counter > 3)
					board2[i][j] = ' ';
				else
				{
					if(board1[i][j] == '*')
						board2[i][j] = '*';
					else if((board1[i][j] == ' ') && (counter == 3))
						board2[i][j] = '*';
					else
						board2[i][j] = ' ';
				}
			}
			else if(i==Rows-1) // bottom
			{
				for(int x=i-1; x<i+1; x++)
					for(int y=j-1; y<j+2; y++)
					{
						if((x==i)&&(y==j))
						{}
						else
						{
							if(board1[x][y]=='*')
							counter++;
						}
					}
				if(counter < 2)
					board2[i][j] = ' ';
				else if(counter > 3)
					board2[i][j] = ' ';
				else
				{
					if(board1[i][j] == '*')
						board2[i][j] = '*';
					else if((board1[i][j] == ' ') && (counter == 3))
						board2[i][j] = '*';
					else
						board2[i][j] = ' ';
				}
			}
			else if(j==0) // left
			{
				for(int x=i-1; x<i+2; x++)
					for(int y=j; y<j+2; y++)
					{
						if((x==i)&&(y==j))
						{}
						else
						{
							if(board1[x][y]=='*')
							counter++;
						}
					}
				if(counter < 2)
					board2[i][j] = ' ';
				else if(counter > 3)
					board2[i][j] = ' ';
				else
				{
					if(board1[i][j] == '*')
						board2[i][j] = '*';
					else if((board1[i][j] == ' ') && (counter == 3))
						board2[i][j] = '*';
					else
						board2[i][j] = ' ';
				}
			}
			else if(j==Columns-1) // right
				{
				for(int x=i-1; x<i+2; x++)
					for(int y=j-1; y<j+1; y++)
					{
						if((x==i)&&(y==j))
						{}
						else
						{
							if(board1[x][y]=='*')
							counter++;
						}
					}
				if(counter < 2)
					board2[i][j] = ' ';
				else if(counter > 3)
					board2[i][j] = ' ';
				else
				{
					if(board1[i][j] == '*')
						board2[i][j] = '*';
					else if((board1[i][j] == ' ') && (counter == 3))
						board2[i][j] = '*';
					else
						board2[i][j] = ' ';
				}
			}

			//  conditions for all cells in middle of the array, such that surrounding cells in the array are counted for living conditions
			else
			{
				for(int x=i-1; x<i+2; x++)
					for(int y=j-1; y<j+2; y++)
					{
						if((x==i)&&(y==j))
						{}
						else
						{
							if(board1[x][y]=='*')
							counter++;
						}
					}
				if(counter < 2)
					board2[i][j] = ' ';
				else if(counter > 3)
					board2[i][j] = ' ';
				else
				{
					if(board1[i][j] == '*')
						board2[i][j] = '*';
					else if((board1[i][j] == ' ') && (counter == 3))
						board2[i][j] = '*';
					else
						board2[i][j] = ' ';
				}
			}
		}
}
