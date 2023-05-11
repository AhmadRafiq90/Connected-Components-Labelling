#pragma once
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "check_neighbours.h"
#include "Equivalence.h"
#include "Equalize.h"
#include "Dice.h"
using namespace cv;
Mat& labelize(const Mat& obj, int ** labelled_img)
{

	Equivalence* list = new Equivalence;
	// Making copy of original image.
	int label_no = 1;

	const int rows = obj.rows, cols = obj.cols;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (get_value(obj,i,j) == 255 && !is_labelled(labelled_img, i, j, cols))
			{
				labelled_img[i][j] = label_no++;
			}
			else if (get_value(obj, i , j) == 255)
			{
				int equalizer = get_smallest_neighbour(labelled_img, i, j, cols, list);
				labelled_img[i][j] = equalizer;
			}
		}
	}

	Equalize(obj, labelled_img, list);
	Mat* img = new Mat (obj.rows, obj.cols, obj.type());
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			img->at<uchar>(i, j) = labelled_img[i][j];
	}
	imshow("Processed image", *img);
	return *img;
}