#include "video.hpp"

using namespace cv;

void updateKernelSize(int* ksize, int ksizeTrackbarValue)
{
    *ksize = 2 * ksizeTrackbarValue - 1;
    if (ksizeTrackbarValue == 0)
        *ksize = 1;
}

void displayGaussianBlur(VideoCapture cap)
{
    namedWindow("Output video", WINDOW_NORMAL);
    int ksizeTrackbarValue = 0;
    createTrackbar("Kernel size", "Output video", &ksizeTrackbarValue, 100);

    for(;;)
    {
        Mat frame;
        cap >> frame;
        if( frame.empty() ) break; // end of video stream
        imshow("Input video", frame);

        // apply to operation to frame and display in new window
        Mat outputFrame;
        int ksize;
        updateKernelSize(&ksize, ksizeTrackbarValue);
        GaussianBlur(frame, outputFrame, Size(ksize, ksize), 0);
        
        // Display output frame  
        if( outputFrame.empty() ) break; // end of video stream
        imshow("Output video", outputFrame);

        if( waitKey(1) == 27 ) break; // stop capturing by pressing ESC
    }
}

void displayCannyEdgeDetection(VideoCapture cap)
{
    //namedWindow("Output video", WINDOW_NORMAL);

    for(;;)
    {
        Mat frame;
        cap >> frame;
        if( frame.empty() ) break; // end of video stream
        imshow("Input video", frame);

        // apply to operation to frame and display in new window
        Mat outputFrame;
        Canny(frame, outputFrame, 100, 200);
        
        // Display output frame  
        if( outputFrame.empty() ) break; // end of video stream
        imshow("Output video", outputFrame);

        if( waitKey(1) == 27 ) break; // stop capturing by pressing ESC
    }
}
