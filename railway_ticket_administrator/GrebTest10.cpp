// GrebTest10.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<windows.h>

int menu();
void nnf();
void newf();
void spisok();
void opf();
void resc();
void resf();
void s_sq();
int BeginApp();
void View();
void FindView();

char nameFile[260];

typedef struct
{
	char name[260];
} Directory;

Directory directory[250];
FileWorking workingFile = FileWorking();

int main()
{
	Begin:
	switch (BeginApp())
	{
	case 1:nnf();
		break;
	case 2:newf();
		break;
	default:
		break;
	}
	while (true)
	{
		switch (menu())
		{
		case 1:goto Begin;
			break;
		case 2:spisok();
			break;
		case 3:opf();
			break;
		case 4:resc();
			break;
		case 5:resf();
			break;
		case 6:s_sq();
			break;
		case 7:View();
			break;
		case 8:FindView();
			break;
		case 9:return 0;
		default:"Vibirite provilno!";
			break;
		}
		puts("Press any key to continue");
		_getch();
		system("cls");
	}
	return 0;
}

int menu()
{
	cout << "Viberite:" << endl;
	cout << "1. New file:" << endl;
	cout << "2. Vvesti spisok:" << endl;
	cout << "3. Open file:" << endl;
	cout << "4. Vivesti resultat:" << endl;
	cout << "5. Vivesti v fail:" << endl;
	cout << "6. Sorting viborka:" << endl;
	cout << "7. Vivesti list na Display:" << endl;
	cout << "8. Searching train:" << endl; 
	cout << "9. Exit:" << endl;
	int i;
	cin >> i;
	return i;
}

void nnf()
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hf;
	int i = 0;
	hf = FindFirstFile(TEXT("*.txt"), &FindFileData);
	if (hf != INVALID_HANDLE_VALUE) {
		do {
			for (int j = 0; j < 260; j++)
			{
				if (FindFileData.cFileName[j] != 0)
				{
					directory[i].name[j] = FindFileData.cFileName[j];
				}
				else
				{
					i++; cout << i << ". "; 
					i--; cout << directory[i].name << "\n";
					break;
				}
			}
			i++;
		} while (FindNextFile(hf, &FindFileData) != 0);
		FindClose(hf);

		cout << "Select file: ";
		cin >> i;
		i--;
		for (int l = 0; l < 260; l++)
		{
			if (directory[i].name[l] == 0)
				break;
			nameFile[l] = directory[i].name[l];
		}
		workingFile.OpenFileTrain(nameFile);
	}
}

void newf()
{
	cout << "Inputing file name" << endl;
	cin >> nameFile;
	workingFile.CreateFileTrain(nameFile);
	
}

int BeginApp()
{
	int i;
	cout << "Open file (1) or create new file (2)?" << endl;
	cin >> i;
	return i;
}

void spisok()
{
	workingFile.ListTrain(nameFile);
}

void opf()
{
	workingFile.OpenFileTrain(nameFile);
}

void resc()
{
	char punkt[260];
	cout << "Vvedite nazvanija goroda: ";
	cin >> punkt;
	workingFile.ViewFileOnDisplay(punkt);
}

void resf()
{
	char punkt[260];
	cout << "Vvedite nazvanija goroda: ";
	cin >> punkt;
	workingFile.OutputingResult(punkt);
}

void s_sq()
{
	workingFile.s_qs();
}

void View() 
{
	workingFile.View();
}

void FindView()
{
	int hous;
	cout << "Vvidite chas otpravlenija: ";
	cin >> hous;
	workingFile.Find(hous);
}
