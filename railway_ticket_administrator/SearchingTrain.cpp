#include "stdafx.h"
#include "SearchingTrain.h"


SearchingTrain::SearchingTrain()
{
}

void SearchingTrain::SearchingTrain_p_lin1(FileWorking::TTrain train[], int nst, int hour)
{
	int d=0, m=0, y=0, h=0, min=0, time=0;
	for (int i = 0; i < nst; i++) 
	{
		sscanf_s(train[i].date, "%d.%d.%d:%d.%d", &d, &m, &y, &h, &min);
		time = h;
		if (time == hour)
			cout << train[i].numberTrain << " " << train[i].punkt << " " << train[i].date << " " << train[i].mesta << endl;
	}
}

void SearchingTrain::SearchingTrain_p_dv(FileWorking::TTrain train[], int nst, int hour)
{
	int i = 0, j = nst, m, d, mon, y, h, min, time = 0;;
	while (i < j)
	{
		m = (i + j) / 2;
		sscanf_s(train[i].date, "%d.%d.%d:%d.%d", &d, &mon, &y, &h, &min);
		if (hour >= h) { d = i; i = m; }
		else j = m + 1;
		if (h == hour)
		{
			cout << train[d].numberTrain << " " << train[d].punkt << " " << train[d].date << " " << train[d].mesta << endl; break;
		}
	}
	
	
}


SearchingTrain::~SearchingTrain()
{
}
