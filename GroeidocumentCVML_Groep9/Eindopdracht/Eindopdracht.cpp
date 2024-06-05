#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void extractCharacters(Mat& plate, const string& plateName) {
    cvtColor(plate, plate, COLOR_BGR2GRAY);
    GaussianBlur(plate, plate, Size(7, 7), 0);
    Canny(plate, plate, 50, 150);

    // Find contours of characters
    vector<vector<Point>> contours;
    findContours(plate, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    // Sort contours from left to right
    sort(contours.begin(), contours.end(), [](const vector<Point>& a, const vector<Point>& b) {
        return boundingRect(a).x < boundingRect(b).x;
        });

    // Extract and save each character
    for (size_t i = 0; i < contours.size(); i++) {
        Rect bbox = boundingRect(contours[i]);

        double contourArea = cv::contourArea(contours[i]);
        if (contourArea < 100 || contourArea > 1000)
            continue;

        Mat charImg = plate(bbox);
        string charFileName = "Resources/NumbersLetter/" + plateName + "_" + to_string(i + 1) + ".png";
        imwrite(charFileName, charImg);
    }
}

int main() {
    Mat img;
    VideoCapture cap(0);

    CascadeClassifier plateCascade;

    plateCascade.load("Resources/haarcascade_russian_plate_number.xml");

    if (plateCascade.empty()) {
        cout << "XML file not loaded" << endl;
        return -1;
    }

    vector<Rect> plates;

    while (true) {
        cap.read(img);

        plateCascade.detectMultiScale(img, plates, 1.1, 10);

        for (int i = 0; i < plates.size(); i++) {
            Mat plateImg = img(plates[i]);

            imwrite("Resources/plate" + to_string(i + 1) + ".png", plateImg);
            rectangle(img, plates[i].tl(), plates[i].br(), Scalar(255, 0, 255), 3);

            extractCharacters(plateImg, "nummerbord" + to_string(i + 1));
        }

        imshow("Image", img);

        if (waitKey(1) == 27)
            break;
    }

    return 0;
}
