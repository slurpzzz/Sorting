#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <vector>
#include <iostream>
#include "raylib.h"
using namespace std;

class UltraVector
{
public:
	UltraVector();
	void print();
	void bubbleSort();
	void bubbleSortNext(int& i, bool& sorted);
	void selectionSort();
	void insertionSort();
	void binSearch(int n);
	void drawVector();
	int getSize();
private:
	vector<int> vec;
	Color col;
};

void printMax(int arr[], int size);

void printMajority(int arr[], int size);

void rotateMatrix(vector<vector<int>> mat);

void isSubset(int arr[], int sub[], int arrSize, int subSize);

#endif /* ALGORITHMS_H */
