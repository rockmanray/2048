#include <iostream>
#include <sstream>
#include "Board.h"
using namespace std;

int main()
{
	Board board;
	board.showBoard();
	string line;	
	while(cin>>line) {
		bool bResult;
		if (line == "U" || line == "u" || line == "8") { 
			cout << "[Action: UP]" << endl;
			bResult = board.shift(Board::ACTION_UP); 
		}
		else if (line == "D" || line == "d" || line == "2") { 
			cout << "[Action: DOWN]" << endl;
			bResult = board.shift(Board::ACTION_DOWN); 
		}
		else if (line == "R" || line == "r" || line == "6") { 
			cout << "[Action: RIGHT]" << endl;
			bResult = board.shift(Board::ACTION_RIGHT); 
		}
		else if (line == "L" || line == "l" || line == "4") { 
			cout << "[Action: LEFT]" << endl;
			bResult = board.shift(Board::ACTION_LEFT); 
		}
		else if (line == "clear_board") {
			cout << "[Clear Board]" << endl;	
			board.reset();
			bResult = true;
		}
		else { 
			cout << "Invalid action: " << line << endl; 
			bResult = false;
		}
		
		if (!bResult) { cout << "Board not changed" << endl; }		
		
		board.showBoard();
		
		if (board.checkEndGame()) {
			cout << "You are dead!" << endl;
			cout << "Game restart." << endl;
			board.reset();	
			board.showBoard();
		}
	}

   return 0;
}

