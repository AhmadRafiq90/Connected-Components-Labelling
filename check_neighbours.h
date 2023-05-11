#pragma once
#include <iostream>
#include "Equivalence.h"
#include<opencv2/core.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;
using namespace std;
int get_value(const Mat& obj, int r, int c)
{
	if (r <= obj.rows && c <= obj.cols)
		return int(obj.at<uchar>(r, c));
	else
		cout << "out of bound\n";
}
bool is_labelled(int ** lab, const int row, const int col, int no_of_cols)
{
	/*return (get_value(lab, row - 1, col - 1) != 0 ||
		get_value(lab, row - 1, col + 1) != 0 ||
		get_value(lab, row - 1, col) != 0 ||
		get_value(lab, row, col - 1) != 0
		);*/
	if (row == 0 && col != 0)
		return (lab[row][col - 1] > 0);

	else if (row != 0 && col == 0)
	return(lab[row - 1][col] > 0 ||
			lab[row - 1][col + 1] > 0);

	else if (col == no_of_cols - 1)
	return(lab[row][col - 1] > 0 ||
			lab[row - 1][col] > 0 ||
			lab[row - 1][col - 1] > 0);

	else if (row > 0 && col > 0)
	return (lab[row - 1][col - 1] > 0 ||
			lab[row - 1][col + 1] > 0 ||
			lab[row - 1][col] > 0 ||
			lab[row][col - 1] > 0);

	else if (row == 0 && col == 0)
		return 0;
}
int get_smallest_neighbour(int** label, const int row, const int col,int no_of_cols, Equivalence* head)
{
	int neighbours[4] {}, loop_counter = 0;
	int smallest = INT_MAX, second_smallest = INT_MAX;
	if (row == 0 && col != 0)
	{
		neighbours[0] = label[row][col - 1];
		loop_counter = 1;
	}
	else if (row != 0 && col == 0)
	{
		neighbours[0] = label[row - 1][col];
		neighbours[1] = label[row - 1][col + 1];
		loop_counter = 2;
	}
	else if (col == no_of_cols - 1)
	{
		neighbours[0] = label[row][col - 1];
		neighbours[1] = label[row - 1][col];
		neighbours[2] = label[row - 1][col - 1];
		loop_counter = 3;
	}
	else if (row > 0 && col > 0)
	{
		neighbours[0] = label[row - 1][col - 1];
		neighbours[1] = label[row - 1][col + 1];
		neighbours[2] = label[row - 1][col];
		neighbours[3] = label[row][col - 1];
		loop_counter = 4;
	}
	for (int i = 0; i < loop_counter; i++)
	{
		if (neighbours[i] > 0 && neighbours[i] < smallest)
			second_smallest = smallest, smallest = neighbours[i];
		else if (neighbours[i] < second_smallest && neighbours[i] > smallest)
			second_smallest = neighbours[i];
	}
	if (second_smallest != INT_MAX)
		add(head,smallest, second_smallest);
	return smallest;
}