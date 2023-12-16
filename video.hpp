#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

void applyGaussianBlurSlider(InputArray inputFrame, OutputArray outputFrame, Size ksize, double sigmaX);