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
}

void opdracht3() {
	Mat img(512, 512, CV_8UC3, Scalar(0, 255, 0));

	circle(img, Point(256, 256), 155, Scalar(255, 0, 0), FILLED);

	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), 3);

	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);

	putText(img, "Opdracht 3", Point(137, 262), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 0, 255), 2);

	imshow("Image", img);
	
	waitKey(0);
}
