#pragma once
#include<opencv2/core.hpp>
#include <cstdlib>
#include "check_neighbours.h"
using namespace cv;

int get_nearest_neighbour(int val, int cluster1, int cluster2)
{
	int distance1 = abs(cluster1 - val), distance2 = abs(cluster2 - val);
	if (distance1 < distance2)
		return 255;
	else
		return 0;
}

}
Mat& kmean(Mat img)
{
	srand(time(0));
	const int rows = img.rows, cols = img.cols;

	int** labelled = new int*[rows];
	for (int i = 0; i < rows; i++)
		labelled[i] = new int[cols]{};
	// Taking two random integers for clusters.

	int cluster1 = rand() % 127, cluster2 = (rand() % 127) + 127;
	int new_cluster1 = 0, new_cluster2 = 0, white_count = 0, black_count = 0;
	int i = 0, new_val;
	while (new_cluster1 != cluster1 || new_cluster2 != cluster2)
	{
		if (i++)
			cluster1 = new_cluster1, cluster2 = new_cluster2;
		new_cluster1 = 0, new_cluster2 = 0;
		// Starting for loop to populate labelled array.
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				new_val = get_nearest_neighbour((get_value(img, i, j)), cluster1, cluster2);
				labelled[i][j] = new_val;
				if (new_val == 255)
					white_count++;
				else if (new_val == 0)
					black_count++;
			}
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (labelled[i][j] == 255)
					new_cluster1 += get_value(img, i , j);
				else
					new_cluster2 += get_value(img, i , j);
			}
		}
		new_cluster1 /= white_count, new_cluster2 /= black_count;
		white_count = 0, black_count = 0;
	}
	Mat* ret = new Mat(img.rows, img.cols, img.type());
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			ret->at<uchar>(i, j) = labelled[i][j];
	}
	*ret = labelize(*ret, labelled);
	imshow("K means", *ret);
	cout << "returning\n";
	return *ret;
}