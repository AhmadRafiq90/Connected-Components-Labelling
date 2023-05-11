#pragma once
#include <opencv2/core.hpp>
#include <future>
using namespace cv;
int most_occured(int** labelled, int rows, int cols)
{
	int max = INT_MIN, max_index = 0, max_count = 0;

	// get max from array to declare count array.
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			if (labelled[i][j] > max)
				max = labelled[i][j];
	}
	int* count = new int[max] {};

	// Populate frequency array.

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			count[labelled[i][j]]++;
	}

	// Get index with maximum frequency.
	for (int i = 0; i < max; i++)
		if (count[max_index] > max_count)
		{
			max_index = i;
			max_count = count[max_index];
		}

	return max_index;

}
void Equalize(const Mat& original, int** labelled, Equivalence* list)
{
	const int rows = original.rows, cols = original.cols;
	for (int a = 1; a <= 3; a++)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				// Checking if the label is derived from another label.
				int child = labelled[i][j], parent = ischild(list, child);
				if (parent != -1)
					labelled[i][j] = parent;
			}
		}
	}
	
	int ms = most_occured(labelled, rows, cols);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (labelled[i][j] == 0 && get_smallest_neighbour(labelled, i, j, cols, list) == ms)
				labelled[i][j] = 255;
			 else if (labelled[i][j] == ms)
				labelled[i][j] = 255;
			else
				labelled[i][j] = 0;
		}
	}

}