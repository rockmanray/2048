#include "Board.h"
#include <iomanip>

void Board::reset() 
{
	m_score = 0;
	srand(time(NULL));

	int index1 = rand()%NUM_GRIDS;
	int index2 = rand()%NUM_GRIDS;
	while(index2==index1) { index2=rand()%NUM_GRIDS; }
	
	for (int i=0 ; i<NUM_GRIDS; i++) { m_grids[i] = 0;}	
	
	m_grids[index1] = 2;
	m_grids[index2] = 2;
		
	return;
}


void Board::showBoard() 
{
	cout << "Score: " << m_score << endl;
	cout << "-------------------------" << endl;
	for (int i=0; i<N_ROWS; i++) {
		for (int j=0; j<N_COLUMNS; j++) {
			if (j == 0) cout << "|" ;
			
			if (m_grids[getIndex(i,j)] == 0) { cout << "     |"; }
			else {			
				int valLength = to_string(m_grids[getIndex(i,j)]).length();
				int nSpaces = (5 - valLength)/2;
				for (int k=0; k<nSpaces; k++) { cout << " "; }
				cout << m_grids[getIndex(i,j)] ;
				for (int k=0; k<5-valLength-nSpaces; k++) { cout << " "; }
				cout << "|";
			}
		}	
		cout << std::endl;
		cout << "-------------------------" << endl;
	}
	
	return;
}

bool Board::shift(Action action)
{	
	int backup[NUM_GRIDS];
	for (int i=0; i<NUM_GRIDS; i++) { backup[i] = m_grids[i]; }

	bool bFreeze[NUM_GRIDS];
	for (int s=0; s<NUM_GRIDS; s++) { bFreeze[s] = false; }
	// Step 1: 
	switch (action) {
		case ACTION_UP:
			for (int j=0; j < N_COLUMNS; j++) {				
				for (int i=1; i < N_ROWS; i++) {					
					int currentIndex = getIndex(i,j);					
					if (m_grids[currentIndex] == 0) { continue; }					
					int limit = i-1;
					while (limit >= 0) {						
						int nextBumpIndex = currentIndex - N_COLUMNS;
						if (!inBoard(nextBumpIndex)) { break; }
						
						if (m_grids[nextBumpIndex] !=0 ) {
							if (bFreeze[nextBumpIndex]) { break; }
							
							if (m_grids[nextBumpIndex] == m_grids[currentIndex]) { 
								m_grids[nextBumpIndex] = 2*m_grids[nextBumpIndex];		
								m_score += 2*m_grids[currentIndex];								
								bFreeze[nextBumpIndex] = true;
								m_grids[currentIndex] = 0;		
								break;
							}							

							bFreeze[nextBumpIndex] = true;		
						}
						else if (m_grids[nextBumpIndex] == 0) { 						
							m_grids[nextBumpIndex] = m_grids[currentIndex];
							m_grids[currentIndex] = 0;								
						}	
												
						currentIndex = nextBumpIndex;				
						limit--;
					}
				}
			}		
			break;
		case ACTION_DOWN: 
			for (int j=0 ; j < N_COLUMNS ; j++) {				
				for (int i = N_ROWS-2; i >= 0; i--) {
					int currentIndex = getIndex(i,j);				
					if (m_grids[currentIndex] == 0) { continue; }				
					
					int limit = (N_ROWS-2)-i;
					while (limit >= 0) {
						int nextBumpIndex = currentIndex + N_COLUMNS;
						if (!inBoard(nextBumpIndex)) { break; }
						
						if (m_grids[nextBumpIndex] !=0 ) {
							if (bFreeze[nextBumpIndex]) { break; }
							
							if (m_grids[nextBumpIndex] == m_grids[currentIndex]) { 
								m_grids[nextBumpIndex] = 2*m_grids[nextBumpIndex];	
								m_score += 2*m_grids[currentIndex];								
								bFreeze[nextBumpIndex] = true;
								m_grids[currentIndex] = 0;		
								break;
							}							

							bFreeze[nextBumpIndex] = true;		
						}
						else if (m_grids[nextBumpIndex] == 0) { 						
							m_grids[nextBumpIndex] = m_grids[currentIndex];
							m_grids[currentIndex] = 0;								
						}	
												
						currentIndex = nextBumpIndex;				
						limit--;
					}
				}
			}
			break;
		case ACTION_LEFT: 
			for (int i=0 ; i < N_ROWS ; i++) {				
				for (int j = 1 ; j < N_COLUMNS ; j++) {
					int currentIndex = getIndex(i,j);				
					if (m_grids[currentIndex] == 0) { continue; }				
					
					int limit=j-1;
					while (limit >= 0) {
						int nextBumpIndex = currentIndex -1;
						if (!inBoard(nextBumpIndex)) { break; }
						
						if (m_grids[nextBumpIndex] !=0 ) {
							if (bFreeze[nextBumpIndex]) { break; }
							
							if (m_grids[nextBumpIndex] == m_grids[currentIndex]) { 
								m_grids[nextBumpIndex] = 2*m_grids[nextBumpIndex];		
								m_score += 2*m_grids[currentIndex];								
								bFreeze[nextBumpIndex] = true;
								m_grids[currentIndex] = 0;		
								break;
							}							

							bFreeze[nextBumpIndex] = true;		
						}
						else if (m_grids[nextBumpIndex] == 0) { 						
							m_grids[nextBumpIndex] = m_grids[currentIndex];
							m_grids[currentIndex] = 0;								
						}	
												
						currentIndex = nextBumpIndex;				
						limit--;
					}
				}
			}
			break;
		case ACTION_RIGHT: 
			for (int i=0 ; i < N_ROWS ; i++) {				
				for (int j = N_COLUMNS-2 ; j >= 0 ; j--) {
					int currentIndex = getIndex(i,j);				
					if (m_grids[currentIndex] == 0) { continue; }				
					
					int limit=(N_ROWS-2)-j;					
					while (limit >= 0) {
						int nextBumpIndex = currentIndex + 1;
						if (!inBoard(nextBumpIndex)) { break; }
						
						if (m_grids[nextBumpIndex] !=0 ) {
							if (bFreeze[nextBumpIndex]) { break; }
							
							if (m_grids[nextBumpIndex] == m_grids[currentIndex]) { 
								m_grids[nextBumpIndex] = 2*m_grids[nextBumpIndex];		
								m_score += 2*m_grids[currentIndex];
								bFreeze[nextBumpIndex] = true;
								m_grids[currentIndex] = 0;		
								break;
							}							

							bFreeze[nextBumpIndex] = true;		
						}
						else if (m_grids[nextBumpIndex] == 0) { 						
							m_grids[nextBumpIndex] = m_grids[currentIndex];
							m_grids[currentIndex] = 0;								
						}	
												
						currentIndex = nextBumpIndex;				
						limit--;
					}
				}
			}
			break;
		default: 
			cerr << "[WARNING]: Unknown Action"; 
			break;
	}
	
	// check a changed move
	bool bAllEqual = true;
	for (int i=0; i<NUM_GRIDS; i++) { 
		if (backup[i] != m_grids[i]) {
			bAllEqual = false;
			break;
		}
	}
		
	if (bAllEqual) { return false; }
	
	// Step 2: Either a tile-2 or a tile-4 is generated on a randomly selected 0 cells 
	int nEmptyCells = 0;
	for (int i=0; i<NUM_GRIDS; i++) {		
		if (m_grids[i]==0) { ++nEmptyCells; } 
	}
	
	int nextIndex = rand() % nEmptyCells;	
	int nextGeneratedTile = rand()%10==0 ? 4 : 2; 
	
	int currentIndex = 0;
	for (int i=0; i<NUM_GRIDS; i++) {		
		if (m_grids[i] == 0) {
			if (currentIndex == nextIndex) { 				
				m_grids[i] = nextGeneratedTile;
				break;
			}else {
				++currentIndex;	
			}
		} 		
	}
		
	return true;
}


bool Board::checkEndGame()
{
	// no empty && no merge
	for (int i=0 ; i<NUM_GRIDS; i++) { 
		if (m_grids[i] == 0) { return false; }
	}	
	
	for (int i=0 ; i<NUM_GRIDS; i++) { 
		// up && down
		int upperIndex = i-N_COLUMNS;
		int downIndex = i+N_COLUMNS;		
		if (inBoard(upperIndex) && m_grids[i]==m_grids[upperIndex]) { return false; }
		if (inBoard(downIndex) && m_grids[i]==m_grids[downIndex]) { return false; }

		// left && right	
		int rightIndex = i+1;
		int leftIndex = i-1;	
		if (i%N_COLUMNS != N_COLUMNS-1 && m_grids[i] == m_grids[rightIndex] ) { return false; }
		if (i%N_COLUMNS != 0 && m_grids[i] == m_grids[leftIndex] ) { return false; }
	}	
	
	return true;		
}

int Board::getTileEncode(int value) const
{
	if (value == 0) { return 0; }
	
	int encodeIndex = 0;	
	while (value != 1) {
		value /= 2;
		++encodeIndex;
	}
	
	return encodeIndex;
}