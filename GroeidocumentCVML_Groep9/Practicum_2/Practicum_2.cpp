#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void opdracht3();

int main()
{
	opdracht3();
	return 0;
}

void opdracht3()
{
	string path = "Resources/ballstripes.png";
	Mat img = imread(path);
	Mat imgBlur, imgClose, imgDilate;

	int kernelSize = 18;
	Mat kernel = getStructuringElement(MORPH_RECT, Size(kernelSize, kernelSize));
	morphologyEx(img, imgClose, MORPH_CLOSE, kernel);

	imshow("Image", img);
	imshow("Image Closed", imgClose);
	waitKey(0);
}

