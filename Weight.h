#ifndef H_WEIGHT
#define H_WEIGHT

class WeightManager
{
public:
static const int MAX_ENCODE_INDEX = 15;
static const int MAX_NUM_WEIGHT = MAX_ENCODE_INDEX*MAX_ENCODE_INDEX*MAX_ENCODE_INDEX*MAX_ENCODE_INDEX;

public:
	WeightManager() { clear(); } 	
	
	void clear() { 
		for(int i=0; i<MAX_NUM_WEIGHT; ++i) { 
			weights[i] = 0.0;
		} 
	}
	bool loadWeight() {}
	bool saveWeight() {}

private:	
	double weights[MAX_NUM_WEIGHT];	
};

#endif
