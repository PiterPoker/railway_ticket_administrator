#include "FileWorking.h"


#pragma once
class SortingTrain
{
private:
	struct
	{
		int l;
		int r;
	}stack[20];
public:
	SortingTrain();
	SortingTrain(FileWorking::TTrain train[], int nst);
	void ViewList(FileWorking::TTrain train[], int nst);
	void SortingTrain_s_qs(FileWorking::TTrain train[], int nst);
	void InsertSorting(FileWorking::TTrain train[], int nst);
	~SortingTrain();
};

