#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void opdracht1e();
void opdracht1f();
void opdracht2();
void opdracht3();
void opdracht4a();

Mat imgHSV, mask;
int hmin = 0, smin = 110, vmin = 153;
int hmax = 19, smax = 130, vmax = 255;

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

void opdracht4a() {
	string path = "Resources/bal.png";
	Mat img = imread(path);
	Mat imgHSV;

	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	namedWindow("Trackbars", (640, 200));
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);

	while (true) 
	{
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, mask);

		imshow("Image", img);
		imshow("ImageHSV", imgHSV);
		imshow("ImageMask", mask);
		waitKey(1);
	}
}

void opdracht1e()
{
	string path = "Resources/test.png";
	Mat img = imread(path);

	Mat imgBlur;
	Mat imgBlur2;
	Mat imgBlur3;

	GaussianBlur(img, imgBlur, Size(7, 7), 0, 0);
	GaussianBlur(img, imgBlur2, Size(9, 9), 5, 0);
	GaussianBlur(img, imgBlur3, Size(11, 11), 5, 5);

	imshow("BlurImage", imgBlur);
	imshow("BlurImage2", imgBlur2);
	imshow("BlurImage3", imgBlur3);
	imshow("Image", img);
	waitKey(0);
}

void opdracht1f()
{
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgCanny, imgDilate, imgErode;

	GaussianBlur(img, img, Size(7, 7), 0, 0);
	Canny(img, imgCanny, 50, 150);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	dilate(imgCanny, imgDilate, kernel);
	erode(imgDilate, imgErode, kernel);


	imshow("Image", img);
	imshow("CannyImage", imgCanny);
	imshow("DilateImage", imgDilate);
	imshow("ErodeImage", imgErode);
	waitKey(0);
}

