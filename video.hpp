#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

void applyGaussianBlur(const Mat& frame, Mat outputFrame);
void adjustBrightnessContrast(const Mat& frame, Mat outputFrame);
