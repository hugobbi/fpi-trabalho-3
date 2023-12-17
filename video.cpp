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

void displaySobel(VideoCapture cap)
{
    for(;;)
    {
        Mat frame;
        cap >> frame;
        if( frame.empty() ) break; // end of video stream
        imshow("Input video", frame);

        // apply to operation to frame and display in new window
        Mat outputFrame;
        Sobel(frame, outputFrame, -1, 1, 1);
        
        // Display output frame  
        if( outputFrame.empty() ) break; // end of video stream
        imshow("Output video", outputFrame);

        if( waitKey(1) == 27 ) break; // stop capturing by pressing ESC
    }
}

void displayBrightnessContrastNegative(VideoCapture cap)
{
    namedWindow("Output video", WINDOW_NORMAL);
    int brightness = 0;
    createTrackbar("Brightness", "Output video", &brightness, 255);
    setTrackbarMin("Brightness", "Output video", -255);
    int contrast = 1;
    createTrackbar("Contrast", "Output video", &contrast, 100);
    setTrackbarMin("Contrast", "Output video", -1);

    for(;;)
    {
        Mat frame;
        cap >> frame;
        if( frame.empty() ) break; // end of video stream
        imshow("Input video", frame);

        // apply to operation to frame and display in new window
        Mat outputFrame;
        frame.convertTo(outputFrame, -1, contrast, brightness);
        
        // Display output frame  
        if( outputFrame.empty() ) break; // end of video stream
        imshow("Output video", outputFrame);

        if( waitKey(1) == 27 ) break; // stop capturing by pressing ESC
    }
}

void displayGrayscale(VideoCapture cap)
{
    for(;;)
    {
        Mat frame;
        cap >> frame;
        if( frame.empty() ) break; // end of video stream
        imshow("Input video", frame);

        // apply to operation to frame and display in new window
        Mat outputFrame;
        cvtColor(frame, outputFrame, COLOR_BGR2GRAY);
        
        // Display output frame  
        if( outputFrame.empty() ) break; // end of video stream
        imshow("Output video", outputFrame);

        if( waitKey(1) == 27 ) break; // stop capturing by pressing ESC
    }
}

void displayHalfSize(VideoCapture cap)
{
    for(;;)
    {
        Mat frame;
        cap >> frame;
        if( frame.empty() ) break; // end of video stream
        imshow("Input video", frame);

        // apply to operation to frame and display in new window
        Mat outputFrame;
        resize(frame, outputFrame, Size(frame.cols/2, frame.rows/2), INTER_LINEAR);

        // Display output frame  
        if( outputFrame.empty() ) break; // end of video stream
        imshow("Output video", outputFrame);

        if( waitKey(1) == 27 ) break; // stop capturing by pressing ESC
    }
}

void displayRotate(VideoCapture cap, RotateFlags rotation)
{
    for(;;)
    {
        Mat frame;
        cap >> frame;
        if( frame.empty() ) break; // end of video stream
        imshow("Input video", frame);

        // apply to operation to frame and display in new window
        Mat outputFrame;
        rotate(frame, outputFrame, rotation);

        // Display output frame  
        if( outputFrame.empty() ) break; // end of video stream
        imshow("Output video", outputFrame);

        if( waitKey(1) == 27 ) break; // stop capturing by pressing ESC
    }
}

// direction=0 (vertical mirror) direction=1 (horizontal mirror)
void displayMirroredVideo(VideoCapture cap, int direction)
{
    for(;;)
    {
        Mat frame;
        cap >> frame;
        if( frame.empty() ) break; // end of video stream
        imshow("Input video", frame);

        // apply to operation to frame and display in new window
        Mat outputFrame;
        flip(frame, outputFrame, direction);

        // Display output frame  
        if( outputFrame.empty() ) break; // end of video stream
        imshow("Output video", outputFrame);

        if( waitKey(1) == 27 ) break; // stop capturing by pressing ESC
    }
}
