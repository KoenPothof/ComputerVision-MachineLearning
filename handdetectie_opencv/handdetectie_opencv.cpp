#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;


void main()
{
	string path = "Resources/koentester.png";
	Mat img = imread(path);
	Mat imghand = imread(path);

	CascadeClassifier handCascade;
	handCascade.load("Resources/palm.xml");

	if (handCascade.empty()) { cout << "XML file not loaded" << endl; }

	vector<Rect> hands;
	handCascade.detectMultiScale(imghand, hands, 2, 10);

	for (int i = 0; i < hands.size(); i++)
	{
		rectangle(imghand, hands[i].tl(), hands[i].br(), Scalar(255, 0, 255), 3);
	}

	imshow("Image", img);
	imshow("Hand Detection", imghand);
	waitKey(0);

}
