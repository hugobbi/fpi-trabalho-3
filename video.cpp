#include "video.hpp"

using namespace cv;

int sliderValue = 0;

void onTrackbarChange(int value, void* userData) {
    // Update the global variable with the current slider value
    sliderValue = value;

    // You can perform any actions based on the slider value here
    // For example, update the displayed image with a processed version

    // For demonstration purposes, just print the current value
    std::cout << "Slider Value: " << sliderValue << std::endl;
}


void applyGaussianBlurSlider(InputArray inputFrame, OutputArray outputFrame, Size ksize, double sigmaX)
{
    createTrackbar("Slider", "Kernel Size", &sliderValue, 100, onTrackbarChange);
    GaussianBlur(inputFrame, outputFrame, Size(9, 9), 0);
}

