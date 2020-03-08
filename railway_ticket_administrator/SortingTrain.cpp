#include "stdafx.h"
#include "SortingTrain.h"


SortingTrain::SortingTrain()
{
}

SortingTrain::SortingTrain(FileWorking::TTrain train[], int nst)
{
	int i;
	cout << "Otsortirovat spisok (Yes - 1, No - 2)?" << endl;
	cin >> i;
	system("cls");
	switch (i)
	{
	case 1:SortingTrain_s_qs(train, nst);
		break;
	case 2:
		break;
	default:"Vvedeno ne pravilnoe znachenija. Budet viveden ne otsortirovani spisok.";
		break;
	}
	ViewList(train, nst);
}

void SortingTrain::ViewList(FileWorking::TTrain train[], int nst)
{
	for (int i = 0; i < nst; i++)
	{
		cout << train[i].numberTrain << " " << train[i].punkt << " " << train[i].date << " " << train[i].mesta << endl;
	}
}

#pragma region Lr11 
void SortingTrain::SortingTrain_s_qs(FileWorking::TTrain train[], int nst)
{
	int i, j, left, right, d, m, y, h, min, date=0, date2=0, date3=0,time=0,time2=0,time3=0, s = 0;
	FileWorking::TTrain tr;
	stack[s].l = 0; stack[s].r = nst - 1;

	while (s != -1)
	{
		left = stack[s].l; right = stack[s].r;
		s--;
		while (left < right)
		{
			i = left; j = right;
			if (sscanf_s(train[(left + right) / 2].date, "%d.%d.%d:%d.%d", &d, &m, &y, &h, &min) == 5)
			{
				date = y * 10000 + m * 100 + d;
				time = h * 100 + min;
			}
			else { right--; continue; }
			Up:
			if (sscanf_s(train[i].date, "%d.%d.%d:%d.%d", &d, &m, &y, &h, &min) == 5)
			{
				date2 = y * 10000 + m * 100 + d;
				time2 = h * 100 + min;
			}
			else { i++; continue; }
			Up2:
			if (sscanf_s(train[j].date, "%d.%d.%d:%d.%d", &d, &m, &y, &h, &min)==5)
			{
				date3 = y * 10000 + m * 100 + d;
				time3 = h * 100 + min;
			}
			else { j--; continue; }
			if (date2 < date || (date2 == date && time2<time)) { i++; goto Up; }
			if (date3 > date || (date3 == date && time3>time)) { j--; goto Up2; }
			if (i <= j)
			{
				tr = train[i]; train[i] = train[j]; train[j] = tr;
				i++; j--;
			}

			if ((j - left) < (right - i))
			{
				if (i < right)
				{
					s++; stack[s].l = i; stack[s].r = right;
				}
				right = j;
			}
			else
			{
				if (left < j) { s++; stack[s].l = left; stack[s].r = j; }
				left = i;
			}
		}
	}
}

void SortingTrain::InsertSorting(FileWorking::TTrain train[], int nst)
{
	int i, j=0,d, m, y, h, min, date = 0, date2 = 0, time=0,time2=0;
	FileWorking::TTrain tr;
	while (j<nst)
	{
		tr = train[j];
		int t = j;
		if (sscanf_s(tr.date, "%d.%d.%d:%d.%d", &d, &m, &y, &h, &min) == 5)
		{
			date = y * 10000 + m * 100 + d;
			time = h * 100 + min;
		}
		Up:
		if (sscanf_s(train[t - 1].date, "%d.%d.%d:%d.%d", &d, &m, &y, &h, &min) == 5)
		{
			date2 = y * 10000 + m * 100 + d;
			time2 = h * 100 + min;
		}
		while (t >= 0 && date < date2 || (date == date2 && time < time2))
		{
			train[t] = train[t - 1];
			t--;
			goto Up;
		}
		train[t] = tr;
		j++;
	}
}
#pragma endregion Lr11

SortingTrain::~SortingTrain()
{
}
