#pragma once
class FileWorking
{
private:
	FILE *newFile, *resFile;
	char nameFile[30];
public:
	typedef struct
	{
		int numberTrain;
		unsigned char punkt[260];
		char date[260];
		int mesta;
	} TTrain;
	TTrain train[30];
	int nst = 0;

	FileWorking();
	int OpenFileTrain(char nameFile[30]);
	int CreateFileTrain(char nameFile[30]);
	int ListTrain(char nameFile[30]);
	int OutputingResult(char punkt[260]);
	int ViewFileOnDisplay(char punkt[260]);
	void s_qs();
	void View();
	int Find(int hour);
	~FileWorking();
};

