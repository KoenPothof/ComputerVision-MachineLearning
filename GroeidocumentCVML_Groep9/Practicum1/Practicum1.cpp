#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void opdracht3();
void opdracht3();
void opdracht4();

void main() 
{
	opdracht4();
}

void opdracht3()
{
	// Afbeeldingen inlezen
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgResize, imgCrop;

	// Afbeelding resizen, de grootte van de afbeelding wordt verdubbeld
	resize(img, imgResize, Size(), 2, 2);

	// De afbeelding wordt bijgesneden (x, y, breedte, hoogte)
	Rect roi(50, 50, 200, 100);
	imgCrop = img(roi);

	// Afbeeldingen weergeven
	imshow("Original Image", img);
	imshow("Image Resize", imgResize);
	imshow("Image Crop", imgCrop);
	waitKey(0);
}

void opdracht3() 
{
	Mat img(512, 512, CV_8UC3, Scalar(0, 255, 0));

	circle(img, Point(256, 256), 155, Scalar(255, 0, 0), FILLED);

	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), 3);

	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);

	putText(img, "Opdracht 3", Point(137, 262), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 0, 255), 2);

	imshow("Image", img);

	waitKey(0);
}

void opdracht4()
{
	float width = 500, height = 750;
	Mat matrix, imgWarp, imgWarpResize;

	string path = "Resources/perspective.jpg";
	Mat image = imread(path);

	// Eerst punt linksboven, rechtsboven, linksonder, rechtsonder
	Point2f sources[4] = { {610, 1140}, {1541, 1319}, {136, 1878}, {1480, 2175} };
	Point2f destination[4] = { {0.0f, 0.0f}, {width, 0.0f}, {0.0f, height}, {width, height} };

	// Perspectief transformatie
	matrix = getPerspectiveTransform(sources, destination);
	warpPerspective(image, imgWarp, matrix, Point(width, height));

	imshow("Image", image);
	imshow("Image Warp", imgWarp);
	waitKey(0);
}

