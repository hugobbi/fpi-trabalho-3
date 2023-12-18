#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

void applyGaussianBlur(const Mat& frame, Mat& outputFrame, int sigmaX);
void applyCanny(const Mat& frame, Mat& outputFrame);
void applySobel(const Mat& frame, Mat& outputFrame);
void adjustBrightnessContrast(const Mat& frame, Mat& outputFrame);
VideoWriter writeVideoToFile(const VideoCapture& cap, const String& filename, const Mat& frame, const int framesPerSecond);