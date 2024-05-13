#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void opdracht2();
void opdracht3();

int main()
{
	opdracht2();
	return 0;
}

void opdracht2()
{
	Mat imagePatrick = imread("Resources/cpatrick.png");
	Mat imageDababy = imread("Resources/dababycar.png");
	Mat imageCannyPatrick, imageCannyDababy;

	int threshold1 = 100;
	int threshold2 = 200;

	namedWindow("Trackbars", (640, 200));
	createTrackbar("Threshold 1", "Trackbars", &threshold1, 179);
	createTrackbar("Threshold 2", "Trackbars", &threshold2, 179);

	while(true)
	{
		Canny(imagePatrick, imageCannyPatrick, threshold1, threshold2);
		Canny(imageDababy, imageCannyDababy, threshold1, threshold2);

		imshow("Image patrick", imagePatrick);
		imshow("Image dababy", imageDababy);
		imshow("Image Canny Patrick", imageCannyPatrick);
		imshow("Image Canny Dababy", imageCannyDababy);
		waitKey(1);
	}

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

