#include <iostream>
#include <string>
#include <map>
#include <utility> 
#include <vector>
using namespace std;


// will need some type of traversal algorithm
// using stack, and a set to keep track of visited


void display2DArray(int *arr[], const int numRows, const int numColumns);

void initializeQueries(int *arr[], const int numRows, const int numColumns);


// Represents a point on the grid, gives it's coordinates
class Cell {
	public:
		int x, y;

		Cell() {
			x = 0;
			y = 0;
		}	
		
		Cell(int theX, int theY) {
			x = theX;
			y = theY;
		}
		
		friend ostream& operator << (ostream& out, const Cell& cell) {
			out << '(' << cell.x << ',' << cell.y << ')';
			
			return out;
			
		}
};

// Used to display staring and ending coordinates
// Composed of two Cells
class Route {
	
	public:
	
		Cell start;
		Cell end;
			
		Route() {
			
			start = Cell();
			end = Cell();
		
		}
		

		
		friend ostream& operator << (ostream& out, const Route& route) {
			out << "Start: " << route.start << " " << "End: " << route.end;
			
			return out;
			
		}

};


// Will hold our maze
class Maze {

	public:
		int numRows;
		int numColumns;
		int **contents;
		
		// read input from keyboard
		void initMaze() {
			string s;
			contents = new int*[numRows];
			for(int i = 0; i < numRows; i++) {
				contents[i] = new int[numColumns];

				cin >> s;

				for(int j = 0; j < numColumns; j++) {

					int value = (s[j] == '1' ? 1 : 0);
					contents[i][j] = value;

				}

			}
		}
		
		void displayMaze() {
			display2DArray(contents,numRows,numColumns);
		}
		
		
	
	  // Get contents of current item at that position
	   int  getCell( int x,  int y) const {
			return contents[x][y];
		}
		
		// check if starting and ending makes sense
		bool validStartAndEnd(const Route& r) {
			
			Cell start = r.start;
			Cell end = r.end;
						
			return contents[start.x][start.y] == contents[end.x][end.y];
		}
		

};

bool validMove(const Maze &myMaze, const int x, const int y, const int icon);
vector< Cell > getPossibleMoves(const Maze &maze, const Cell& cell);
void displayMoves(const vector<Cell> &cells);

int main() {

	Maze maze;
	int numOfQueries;
	Route *queries;
	
	cin >> maze.numRows >> maze.numColumns;
	maze.initMaze();
	    
    cin >> numOfQueries;
    queries = new Route[numOfQueries];
	for(int i = 0; i < numOfQueries; i++) {
		
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		queries[i].start = Cell(x1 - 1,y1 - 1);
		queries[i].end = Cell(x2 - 1,y2 - 1);
		
	}

	
	
	for(int i = 0; i < numOfQueries; i++) {
	
		if( !(maze.validStartAndEnd(queries[i]) ) ) {
			cout << "neither" << endl;
		}
		else
		{
			vector< Cell > moves = getPossibleMoves(maze, queries[i].start);
			if(moves.size() == 0) {
				cout << "neither" << endl;
			} 
			else 
			{
			
			}
		}

	
	}
	cout << endl;
	
	maze.displayMaze();



}

void displayMoves(const vector<Cell> &cells) {

	for(auto cell : cells) {
		cout << cell << ' ';
	}
	
	cout << endl;
}

vector< Cell > getPossibleMoves(const Maze &maze, const Cell& cell) {

	vector< Cell > moves;
	
	int i = cell.x;
	int j = cell.y;
	int current = maze.getCell(i,j);
	
	if( validMove(maze,i + 1,j,current) ) {
	
	moves.push_back( Cell(i +1, j) );
	
	} 
	
	 if( validMove(maze,i - 1,j ,current) ) {
					moves.push_back( Cell(i - 1, j) );

	}
	
	if( validMove(maze,i,j + 1,current) ) {
					moves.push_back( Cell(i, j+1) );

	}
	if ( validMove(maze,i,j - 1,current) ) {
		moves.push_back( Cell(i, j -1) );

	}
	
	return moves;
}

bool validMove(const Maze &maze, const int x, const int y, const int target) {

	if ((x >= 0 && x < maze.numRows) && ( y >= 0 && y < maze.numColumns) && maze.getCell(x,y) == target) {
		return true;
	}
	
	return false;

}



void display2DArray(int *arr[], const int numRows, const int numColumns) {

    for(int i = 0; i < numRows; i++) {

        for(int j = 0; j < numColumns; j++) {
            cout <<  arr[i][j] <<  ' ';
        }

        cout << endl;
    }
}