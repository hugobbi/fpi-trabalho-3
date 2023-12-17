#include "video.hpp"

using namespace cv;

// Kernel size has to be odd
void updateKernelSize(int* ksize, int ksizeTrackbarValue)
{
    *ksize = 2 * ksizeTrackbarValue - 1;
    if (ksizeTrackbarValue == 0)
        *ksize = 1;
}

void applyGaussianBlur(const Mat& frame, Mat outputFrame)
{
    static int ksizeTrackbarValue;
    static bool runInitializationGauss = true;
    if (runInitializationGauss)
    {
        namedWindow("Output video", WINDOW_NORMAL);
        ksizeTrackbarValue = 0;
        createTrackbar("Kernel size", "Output video", &ksizeTrackbarValue, 255);

        runInitializationGauss = false;
    }

    int ksize;
    updateKernelSize(&ksize, ksizeTrackbarValue);
    GaussianBlur(frame, outputFrame, Size(ksize, ksize), 0);
}

// To get negative of image, set contrast=-1 brightness=255 in the trackbar
void adjustBrightnessContrast(const Mat& frame, Mat outputFrame)
{
    static int brightness, contrast;
    static bool runInitializationBC = true;
    if (runInitializationBC)
    {
        brightness = 0;
        createTrackbar("Brightness", "Output video", &brightness, 255);
        setTrackbarMin("Brightness", "Output video", -255);
        contrast = 1;
        createTrackbar("Contrast", "Output video", &contrast, 100);
        setTrackbarMin("Contrast", "Output video", -1);

        runInitializationBC = false;
    }
    
    frame.convertTo(outputFrame, -1, contrast, brightness);
}