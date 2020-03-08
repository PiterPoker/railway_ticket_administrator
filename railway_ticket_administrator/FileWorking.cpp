#include "stdafx.h"
#include "FileWorking.h"
#include "SortingTrain.h"
#include "SearchingTrain.h"

FileWorking::FileWorking()
{
	
}

SortingTrain sorting = SortingTrain();
SearchingTrain searching = SearchingTrain();
int FileWorking::OpenFileTrain(char nameFile[30])
{
	if (fopen_s(&newFile, nameFile, "rb") != NULL)
	{
		cout << "Oshibka pri otcritii" << endl;
		//exit(1);
		return 0;
	}
	nst = 0; TTrain std;
	while (true)
	{
		int nwrt = fread(&std, sizeof(TTrain), 1, newFile);
		if (nwrt != 1)break;
		train[nst] = std;
		//cout << train[nst].numberTrain << " " << train[nst].punkt << " " << train[nst].date << " " << train[nst].mesta << endl;
		nst++;
	}
	fclose(newFile);
	SortingTrain::SortingTrain(train, nst);
	return 1;
}

int FileWorking::CreateFileTrain(char nameFile[30])
{
	if (fopen_s(&newFile, nameFile, "wb") != NULL)
	{
		cout << "Oshibka pri sozdanii" << endl;
		//exit(1);
		return 0;
	}
	cout << "Ok" << endl;
	fclose(newFile);
	return 1;
}

int FileWorking::ListTrain(char nameFile[30])
{
	int k = 0;
	int j = 0;
	FileWorking::TTrain tr;
	if (fopen_s(&newFile, nameFile, "ab+") != NULL)//"w"-удалить файл и создать новый с таким же именем
	{
		cout << "Oshibka pri sozdanii" << endl;
		return 0;
	}
	cout << "Vedite kol-vo poezdov" << endl;
	if (nst != 0)
		k = nst;
	cin >> nst;
	for (int i = k; i < nst + k; i++)
	{
		cout << "Vvedite nomer poezda: ";
		cin >> train[i].numberTrain;
		cout << "Vvedite punkt pribitiya: ";
		cin >> train[i].punkt;
		cout << "Vvedite date otpravki poezda: ";
		cin >> train[i].date;
		cout << "Vvedite kol-vo svobodnih mest: ";
		cin >> train[i].mesta;
		fwrite(&train[i], sizeof(TTrain), 1, newFile);
	}
	fclose(newFile);
	return 1;
}

int FileWorking::OutputingResult(char punkt[260])
{
	if (fopen_s(&resFile, "ResultFile.txt", "w") != NULL)
	{
		cout << "Oshibka pri sozdanii " << endl;
		return 0;
	}
	char str[260];
	for (int i = 0; i < nst; i++) 
	{
		sprintf_s(str, "%s", train[i].punkt);
		if (train[i].mesta != 0 
			&& strcmp(str, punkt)==NULL)
		{
			fwrite(&train[i], sizeof(TTrain), 1, resFile);
		}
	}
	fclose(resFile);
	cout << "The information was recorded in a file ResultFile.txt";
	return 1;
}

int FileWorking::ViewFileOnDisplay(char punkt[260])
{
	char str[260];
	for (int i = 0; i < nst; i++)
	{
		sprintf_s(str, "%s", train[i].punkt);
		if (train[i].mesta != 0
			&& strcmp(str, punkt) == NULL)
		{
			cout << train[i].numberTrain << " " << train[i].punkt << " " << train[i].date << " " << train[i].mesta << endl;
		}
	}
	return 1;
}

void FileWorking::s_qs()
{
	SortingTrain sorting = SortingTrain();
	sorting.InsertSorting(train, nst);
	sorting.ViewList(train, nst);
}

void FileWorking::View()
{
	sorting.ViewList(train, nst);
}

int FileWorking::Find(int hour)
{
	int i;
	cout << "Viberite sposob poiska (Pereborom - 1, Dvoichni - 2)?" << endl;
	cin >> i;
	system("cls");
	switch (i)
	{
	case 1:searching.SearchingTrain_p_lin1(train, nst, hour);
		break;
	case 2:searching.SearchingTrain_p_dv(train, nst, hour);
		break;
	default:"Vvedeno ne pravilnoe znachenija. Budet viveden ne otsortirovani spisok.";
		break;
	}
	return 1;
}


FileWorking::~FileWorking()
{
}
