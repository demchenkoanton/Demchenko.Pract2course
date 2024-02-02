#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void merge(int mas[], int l, int r, int x);

void mergeSort(int mas[], int l, int r)
{
	int x;
	if (l < r) {

		x = (l + r) / 2;
		mergeSort(mas, l, x);
		mergeSort(mas, x + 1, r);
		merge(mas, l, r, x);
	}
}
void merge(int mas[], int l, int r, int x)
{
	int mas1[100];
	int i, j, k;
	i = l;
	k = l;
	j = x + 1;

	while (i <= x && j <= r) {
		if (mas[i] < mas[j]) {
			mas1[k] = mas[i];
			k++;
			i++;
		}
		else {
			mas1[k] = mas[j];
			k++;
			j++;
		}
	}

	while (i <= x) {
		mas1[k] = mas[i];
		k++;
		i++;
	}

	while (j <= r) {
		mas1[k] = mas[j];
		k++;
		j++;
	}

	for (i = l; i < k; i++) {
		mas[i] = mas1[i];
	}
}

void quickSort(int mas[], int l, int r)
{
	int i = l;
	int j = r;
	int x = mas[(l + r) / 2];
	do {
		while (mas[i] < x) i++;
		while (mas[j] > x) j--;
		if (i < j)
		{
			int w = mas[i];
			mas[i] = mas[j];
			mas[j] = w;
			i++;
			j--;
		}
	} while(i < j);
	if (l < j) quickSort(mas, l, j);
	if (r < i) quickSort(mas, i, r);
}
int main()
{
	setlocale(LC_ALL, "Rus");
	int i = 0;
	
	const int r = 7;
	int mas[r];
	cout << "Введите цифры" << endl;
	for (int i = 0; i < r; i++)
	{
		cin >> mas[i];
	}
	cout << "Исходный массив" << endl;
	for (int i = 0; i < r; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;
	int q;
	cout << "Выберите метод сортировки :" << endl << "1 ) Быстрая сортировка" << endl << "2 ) Сортировка слиянием" << endl;
	cin >> q;
	if (q == 1) {
		quickSort(mas, i, r);
	}
	else if (q == 2) {
		mergeSort(mas, i, r);
	}
	else { 
		return 0;
	}

	cout << "Массив после сортировки" << endl;
	for (int i = 0; i < r; i++)
	{
		cout << mas[i] << " ";
	}
	return 0;
}




