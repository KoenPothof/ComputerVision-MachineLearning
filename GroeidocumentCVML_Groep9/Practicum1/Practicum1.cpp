#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void opdracht2();
void opdracht4();

void main() 
{
	opdracht4();
}

void opdracht2()
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

