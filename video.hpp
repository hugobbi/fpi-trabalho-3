#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

void displayGaussianBlur(VideoCapture cap);
void displayCannyEdgeDetection(VideoCapture cap);
void displaySobel(VideoCapture cap);
void displayBrightnessContrastNegative(VideoCapture cap);
void displayGrayscale(VideoCapture cap);
void displayHalfSize(VideoCapture cap);
void displayRotate(VideoCapture cap, RotateFlags rotation);
void displayMirroredVideo(VideoCapture cap, int direction);