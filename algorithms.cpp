#include "algorithms.h"

UltraVector::UltraVector()
{
	srand((unsigned)time(NULL));
	vec.resize(500);
	for (int i = 0; i < vec.size(); i++)
		vec[i] = rand() % 601;
	col = RAYWHITE;
}

void UltraVector::print()
{
	for (int i : vec) {
		cout << i << " ";
	}
	cout << endl << endl;
}

void UltraVector::bubbleSort()
{
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		for (int i = 0; i < vec.size() - 1; i++) {
			if (vec[i] > vec[i + 1]) {
				int temp = vec[i];
				vec[i] = vec[i + 1];
				vec[i + 1] = temp;
				sorted = false;
			}
		}
	}
}

void UltraVector::bubbleSortNext(int& i, bool& swapped)
{
	if (i == vec.size() - 1) {
		if (swapped == false) {
			col = GREEN;
			return;
		}
		i = 0;
		swapped = false;
	}
	if (vec[i] > vec[i + 1]) {
		int temp = vec[i];
		vec[i] = vec[i + 1];
		vec[i + 1] = temp;
		i++;
		swapped = true;
		return;
	}
	i++;
}

void UltraVector::selectionSort()
{
	for (int i = 0; i < vec.size() - 1; i++) {
		int min = i;
		for (int j = i + 1; j < vec.size(); j++) {
			if (vec[j] < vec[min]) min = j;
		}
		int temp = vec[i];
		vec[i] = vec[min];
		vec[min] = temp;
	}
}

void UltraVector::insertionSort()
{
	for (int i = 1; i < vec.size(); i++) {
		for (int j = i - 1, k = i; j >= 0; j--, k--) {
			if (vec[j] > vec[k]) {
				int temp = vec[k];
				vec[k] = vec[j];
				vec[j] = temp;
			} else
				break;
		}
	}
	// 1 2 3 5 6 2
}

void UltraVector::binSearch(int n)
{
	//pre-condition: array is sorted
	int start = 0, end = vec.size();
	int i = (start + end) / 2;
	while (vec[i] != n) {
		if (start >= end) {
			cout << "not found" << endl;
			return;
		}
		if (vec[i] < n) {
			start = i + 1;
			i = (start + end) / 2;
		} else {
			end = i - 1;
			i = (start + end) / 2;
		}
	}
	cout << "Index of " << n << " is " << i << endl;
}

void UltraVector::drawVector()
{
	for (int i = 0; i < vec.size(); i++) {
		DrawRectangle(i * 3, GetScreenHeight() - vec[i], 3, vec[i], col);
	}
}

int UltraVector::getSize()
{
	return vec.size();
}

void printMax(int arr[], int size)
{
	int max = arr[0];
	for (int i = 0; i < size; i++)
		if (arr[i] > max)
			max = arr[i];

	cout << "Max value: " << max << endl;
}

void printMajority(int arr[], int size)
{
	for (int i = 0; i < size; i++) {
		int count = 0;
		for (int j = i; j < size; j++)
			if (arr[j] == arr[i])
				count++;
		if (count > size / 2) {
			cout << "Majority value: " << arr[i] << endl;
			return;
		}
	}
	cout << "Majority value: NO MAJORITY" << endl;
}

void rotateMatrix(vector<vector<int>> mat)
{
	int rows = mat.size();
	int cols = mat[0].size();

	vector<vector<int>> newMat(cols);

	for (int i = rows - 1; i >= 0; i--)
		for (int j = 0; j < cols; j++)
			newMat[j].push_back(mat[i][j]);

	for (auto i : newMat) {
		for (int j : i)
			cout << j << ' ';
		cout << endl;
	}
}

void isSubset(int arr[], int sub[], int arrSize, int subSize)
{
	int count = 0;
	for (int i = 0; i < subSize; i++)
		for (int j = 0; j < arrSize; j++)
			if (arr[j] == sub[i]) {
				count++;
				break;
			}

	for (int i = 0; i < subSize; i++)
		cout << sub[i] << " ";
	if (count == subSize)
		cout << "is a subset of ";
	else
		cout << "is not a subset of ";
	for (int i = 0; i < arrSize; i++)
		cout << arr[i] << " ";
	cout << endl;

}