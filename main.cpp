#include <iostream>
#include <vector>
#include "algorithms.h"
#include "raylib.h"
using namespace std;


int main()
{
	UltraVector v;
	const int width = v.getSize() * 3;
	const int height = 600;
	InitWindow(width, height, "Sorting algorithms");

	int i = 0;
	bool swapped = false;
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);
		v.bubbleSortNext(i, swapped);
		v.drawVector();
		EndDrawing();
	}

	return 0;
}
