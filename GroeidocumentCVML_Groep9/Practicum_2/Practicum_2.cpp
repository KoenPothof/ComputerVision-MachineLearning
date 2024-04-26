#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void opdracht1e();
void opdracht1f();

void main()
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
