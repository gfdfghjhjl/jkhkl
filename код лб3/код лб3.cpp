#include <iostream>
#include <windows.h>
using namespace std;
void abstractSort(int arr[], int n)
{

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void merge(int arr[], int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int* L = new int[n1];
	int* R = new int[n2];
	for (int i = 0; i < n1; i++)
	{
		L[i] = arr[left + i];
	}
	for (int j = 0; j < n2; j++)
	{
		R[j] = arr[mid + 1 + j];
	}
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] >= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else

		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int N, first, diff, sum = 0;
	cout << "Введіть розмір масиву N (100<N<1000): ";

	cin >> N;
	cout << "Введіть перший елемент прогресії: ";
	cin >> first;
	cout << "Введіть різницю прогресії: ";
	cin >> diff;
	cout << endl;
	int* arr = new int[N];
	arr[0] = first;
	for (int i = 1; i < N; i++)
	{
		arr[i] = arr[i - 1] + diff;
	}
	cout << "Несортований масив: " << endl;
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
		sum += arr[i];
	}
	cout << endl << endl;
	cout << "Сортування методом двохшляхового злиття: " << endl;
	mergeSort(arr, 0, N - 1);
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << endl;
	cout << "Сортування абстрактним методом: " << endl;
	abstractSort(arr, N);
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << endl;

	cout << "Сума прогресії: " << sum << endl;
	return 0;
}
