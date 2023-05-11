#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "labelize.h"
#include <iostream>
#include "Dice.h"
#include "Kmean.h"
#include "RLC.h"
using namespace cv;
using namespace std;
// Main for black and white.
int main(int argc, char **argv)
{
    Mat segmented, labelled, ground, colored, km;

    const string path = samples::findFile("");
    const string path2 = samples::findFile("");
    const string path3 = samples::findFile("");

    segmented = imread(path); // Read the file
    ground = imread(path2);
    colored = imread(path3);

    int **labelled_img = new int *[segmented.rows];
    for (int i = 0; i < segmented.rows; i++)
        labelled_img[i] = new int[segmented.cols]{};

    cvtColor(segmented, segmented, COLOR_BGR2GRAY);
    cvtColor(ground, ground, COLOR_BGR2GRAY);
    cvtColor(colored, colored, COLOR_BGR2GRAY);
    imshow("Segmented image", segmented);
    imshow("Ground truth", ground);

    cout << "Labelling\n";
    labelled = labelize(segmented, labelled_img);
    cout << "Done with labelization\n";
    cout << "Dice of component labelling is " << calc_dice(ground, labelled, segmented.rows, segmented.cols) << '\n';
    cout << "Performing K mean\n";
    km = kmean(colored);
    cout << "Dice of k-mean clustering is " << calc_dice(ground, km, colored.rows, colored.cols) << '\n';
    calc_rlc(segmented);
    waitKey();
    return 0;
}

 /*
 Main for kmean.
 int main()
{
    Mat colored, labelled, ground;
    const string path = samples::findFile("C:\\Users\\Ahmad\\Desktop\\Data assigment 1\\Original Images\\IMD024.bmp");
    const string path2 = samples::findFile("C:\\Users\\Ahmad\\Desktop\\Data assigment 1\\Ground Truths\\IMD024_lesion.bmp");
    colored = imread(path);
    ground = imread(path2);
    cvtColor(colored, colored, COLOR_BGR2GRAY);
    cvtColor(ground, ground, COLOR_BGR2GRAY);
    labelled = kmean(colored);
    cout << calc_dice(ground, labelled, colored.rows, colored.cols);
    calc_rlc();
    waitKey();
}
*/
