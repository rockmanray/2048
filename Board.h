#ifndef H_BOARD
#define H_BOARD

#include <iostream>
#include <time.h>
#include "Weight.h"
using namespace std;

class Board
{

public: 

  enum Action {
	  ACTION_UP,
	  ACTION_DOWN,
	  ACTION_LEFT,
	  ACTION_RIGHT,
	  
	  ACTION_SIZE
  };

  int nTuples[17][4] = { 
	{0,1,2,3},{4,5,6,7}, {8,9,10,11}, {12,13,14,15},
	{0,4,8,12},{1,5,9,13}, {2,6,10,14}, {3,7,11,15},
	{0,1,4,5},{1,2,5,6}, {2,3,6,7}, 
	{4,5,8,9},{5,6,9,10},{6,7,10,11},
	{8,9,12,13},{9,10,13,14},{10,11,14,15}
   };

  static const int N_ROWS = 4;
  static const int N_COLUMNS = 4;
  static const int NUM_GRIDS = N_ROWS * N_COLUMNS;

  Board() { reset(); }

  void reset();
  void showBoard();
  bool shift(Action action);
  bool checkEndGame();
  int getTileEncode(int value) const;
  
  inline bool inBoard(int index) const { return index>=0 && index<NUM_GRIDS; }
  inline int getIndex(int i, int j) const { return N_COLUMNS*i+j; }  

private:
  // For example: 
  // 4x4 board
  //  0  1  2  3
  //  4  5  6  7
  //  8  9 10 11
  // 12 13 14 15

  int m_grids[NUM_GRIDS];
  int m_score;
  int m_nMoves;
  WeightManager m_weightManager; 	
};

#endif