#include "video.hpp"

using namespace cv;
using namespace std;

// Trackbar method (not used)
void onTrackbarChange(int value, void* tbPointer)
{
    int* trackbarDataPointer = static_cast<int *>(tbPointer);
    *trackbarDataPointer = value;
}

// Kernel size has to be odd
void updateKernelSize(int* ksize, int ksizeTrackbarValue)
{
    *ksize = 2 * ksizeTrackbarValue - 1;
    if (ksizeTrackbarValue == 0)
        *ksize = 1;
}

void applyGaussianBlur(const Mat& frame, Mat& outputFrame, int sigmaX)
{
    static int ksizeTrackbarValue = 0;
    static bool runInitializationGauss = true;
    if (runInitializationGauss)
    {
        namedWindow("Output video", WINDOW_NORMAL);
        createTrackbar("Kernel size", "Output video", &ksizeTrackbarValue, 255);

        runInitializationGauss = false;
    }

    int ksize;
    updateKernelSize(&ksize, ksizeTrackbarValue);
    GaussianBlur(frame, outputFrame, Size(ksize, ksize), sigmaX);
}

void applyCanny(const Mat& frame, Mat& outputFrame)
{
    static int tmin = 150, tmax = 250;
    static bool runInitializationCanny = true;
    if (runInitializationCanny)
    {
        createTrackbar("Tmin", "Output video", &tmin, 255);
        createTrackbar("Tmax", "Output video", &tmax, 255);

        runInitializationCanny = false;
    }

    Mat grayscaleFrame;
    cvtColor(frame, grayscaleFrame, COLOR_BGR2GRAY);

    Mat denoisedFrame;
    GaussianBlur(frame, denoisedFrame, Size(5, 5), 2);
    Canny(frame, outputFrame, tmin, tmax);
}

void applySobel(const Mat& frame, Mat& outputFrame)
{
    Mat denoisedFrame;
    GaussianBlur(frame, denoisedFrame, Size(5, 5), 1);

    Mat grayscaleFrame;
    cvtColor(denoisedFrame, grayscaleFrame, COLOR_BGR2GRAY);

    Mat sobelX, sobelY;
    Sobel(grayscaleFrame, sobelX, CV_16S, 1, 0);
    Sobel(grayscaleFrame, sobelY, CV_16S, 0, 1);

    Mat sobelXAbs, sobelYAbs;
    convertScaleAbs(sobelX, sobelXAbs);
    convertScaleAbs(sobelY, sobelYAbs);

    Mat sobelResult;
    addWeighted(sobelXAbs, 0.5, sobelYAbs, 0.5, 0, sobelResult);

    sobelResult.copyTo(outputFrame);
}

// To get negative of image, set contrast=-1 brightness=255 in the trackbar
void adjustBrightnessContrast(const Mat& frame, Mat& outputFrame)
{
    static int brightness = 0, contrast = 1;
    static bool runInitializationBC = true;
    if (runInitializationBC)
    {
        createTrackbar("Brightness", "Output video", &brightness, 255);
        setTrackbarMin("Brightness", "Output video", -255);
        createTrackbar("Contrast", "Output video", &contrast, 100);
        setTrackbarMin("Contrast", "Output video", -1);

        runInitializationBC = false;
    }
    
    frame.convertTo(outputFrame, -1, contrast, brightness);
}

VideoWriter writeVideoToFile(const VideoCapture& cap, const String& filename, const Mat& frame, const int framesPerSecond)
{
    const int frameWidth = static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH)); 
    const int frameHeight = static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT));
    const Size frameSize(frameWidth, frameHeight);

    const bool isColor = true ? frame.channels() == 3 : false;

    static VideoWriter videoWriter(filename, VideoWriter::fourcc('M', 'J', 'P', 'G'), framesPerSecond, frameSize, isColor);

    if (!videoWriter.isOpened()) 
    {
        std::cout << "Error saving video to file :(" << std::endl;
        return videoWriter;
    }

    videoWriter.write(frame);

    return videoWriter;
}