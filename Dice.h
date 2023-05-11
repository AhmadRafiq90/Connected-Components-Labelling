#pragma once
#include <opencv2/core.hpp>
#include "check_neighbours.h"
using namespace cv;
double calc_dice(const Mat& ground,const Mat& labelled, int rows, int cols)
{
	double true_positive = 0, false_positive = 0, false_negative = 0;
	int ground_val, label_val;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			ground_val = get_value(ground, i , j);
			label_val = get_value(labelled, i , j);
			if (ground_val == 255 && label_val == 255)
				true_positive++;
			else if (ground_val != 255 && label_val == 255)
				false_positive++;
			else if (label_val != 255 && ground_val == 255)
				false_negative++;
		}
	}
	double dice = (2 * true_positive) / (false_negative + (2 * true_positive) + false_positive);
	return dice * 100;
}