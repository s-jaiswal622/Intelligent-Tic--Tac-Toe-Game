#include <bits/stdc++.h>
using namespace std;
char matrix[3][3] = { '_', '_', '_', '_', '_', '_', '_', '_', '_' };    // Making matrix(matrix) of (3*3) for the game
bool vis[3][3];                                                         // For storing which cells have been occupied.
char player;													        // defining and declaring player and set 'x' as default

/*
suppose matrix is 	00 01 02
					10 11 12
					20 21 22
*/
// Function to mark all cells as unvisited.
void reset()
{
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			vis[i][j] == false;
		}
	}
}

// Funtion to print game matrix
void Draw()
{
    system("cls");                                                      // To clear console/screen
	cout<<"TIC TAC TOE \n";
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<matrix[i][j]<< " ";
        }
        cout<<endl;
    }
}

// Function to check whether selected cell is occupied or not.
bool isValidMove(int row, int col)
{
	if(vis[row][col] == true)
	{
		return false;
	}
	return true;
}

// Function to check if input is valid or not.
bool isValidInput(int row, int col)
{
    if(row<0 || row>2 || col<0 || col>2)
    {
        return false;
    }
    return true;
}

// Function to generate a random number.
int randomNum(int lower, int upper)
{
	int num = (rand() % upper) + lower;
	return num;
}

// Function to make the computer turn.
void computerTurn()
{
	int row = randomNum(0,3);                       // Generating random number for row.
	int col = randomNum(0,3);                       // Generating random number for column.
	char opp;
	if(player == 'X')                               // Finding opponent symbol.
	{
		opp = 'O';
	}
	else
	{
		opp = 'X';
	}

	if(isValidMove(row, col))                      // Checking if user move is valid or not.
	{
		vis[row][col] = true;                      // Marking the cell as it is selected by computer.
		matrix[row][col] = opp;                    // Placing the computer character at that position.
		Draw();                                    // Redrawing the matrix with the computer move.
	}
	else                                           // Selected cell is already occupied.
	{
		computerTurn();                            // Selecting a new cell.
	}
}


// Input of the first player
void firstPlayer()
{
    int row,col;
    cout<<endl;
	cout<<"Please Enter the row of the cell you want to select(1-3): ";
    cin>>row;
    cout<<"Please Enter the column of the cell you want to select(1-3): ";
    cin>>col;

    // As indexes start from 0 so we have to subtract 1 from user inputted row and column.
    row--;
    col--;

    if(isValidInput(row,col) == false)                  // To validate user input.
    {
        cout<<"Please select a valid row and column number and try again!"<<endl;
        firstPlayer();
    }

    if(isValidMove(row, col))                           // Checking if the selected is empty or not.
    {
    	matrix[row][col]=player;                        // Marking the selected cell if empty.
    	vis[row][col]=true;                             // Marking the selected cell as occupied.
    	Draw();                                         // Redrawing the matrix with user input.
	}
	else
	{
		cout<<"The selected cell is already occupied!!! PLEASE TRY AGAIN!!!"<<endl;
		firstPlayer();                                  // Asking user to again select some cell.
	}

}

char Win()
{
    //Condition for winning through row
    for(int i=0; i<3; i++)
    {
        if( matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2] && matrix[i][0]!='_')
        {
            return matrix[i][0];
        }
    }

    //Condition for winning through column
    for(int i=0; i<3; i++)
    {
        if( matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i] && matrix[0][i]!='_')
        {
            return matrix[0][i];
        }
    }

    //checking the win for both diagonal
    if((matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2] && matrix[1][1]!='_') || (matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0] && matrix[1][1]!='_'))
    {
        return matrix[1][1];
    }

    // If no one has yet won!
    return '/';
}

// Function to check if any player has won the game or not.
bool gameFinished(int moves)
{
    if(Win() == player)                             // If win then printing winner as player.
    {
        cout<<"YOU WINS!!!"<<endl;
        return true;
    }
    if(Win() != player && Win()!= '/')              // If win printing winner as computer.
    {
        cout<<"COMPUTER WINS!!!"<<endl;
        return true;
    }
    if (Win()=='/' && moves == 9)                   // Condition to check draw.
    {
        cout<<"GAME IS DRAW!!!"<<endl;
        return true;
    }
    return false;
}

int main()
{
    srand (time(NULL));

	reset();                                                    // To unmark all cells at start of game.
	int n = 0;
	cout<<"Select your character \n1 - X\n2 - O"<<endl;         // To select the user character.
	cin>>n;
	if(n == 1)
	{
		player = 'X';
	}
	else
	{
		player = 'O';
	}

    Draw();                                                     // Drawing the matrix.
    int moves = 0;
    while(1)
    {
    	moves++;
        firstPlayer();                                          // calling player input function
        if(gameFinished(moves))
            break;
        moves++;
        computerTurn();                                         // calling computer function
        if(gameFinished(moves))
            break;
    }
    cout<<"\nHave a Good Day!";
    return 0;
}
