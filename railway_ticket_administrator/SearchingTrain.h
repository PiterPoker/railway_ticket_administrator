#pragma once
class SearchingTrain
{
public:
	SearchingTrain();
	void SearchingTrain_p_lin1(FileWorking::TTrain train[], int nst, int hour);
	void SearchingTrain_p_dv(FileWorking::TTrain train[], int nst, int hour);
	~SearchingTrain();
};

