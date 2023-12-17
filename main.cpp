#include <opencv2/opencv.hpp>
#include "video.hpp"

using namespace cv;
int main(int argc, char** argv)
{
    // Initialize video capture
    int camera = 0;
    VideoCapture cap;
    // Open the default camera, use something different from 0 otherwise;
    // Check VideoCapture documentation.
    if(!cap.open(camera))
        return -1;
    for(;;)
    {
        Mat frame;
        cap >> frame;
        if( frame.empty() ) break; // end of video stream
        imshow("Input video", frame);

        // Apply to operation to frame and display in new window
        namedWindow("Output video", WINDOW_NORMAL);
        Mat outputFrame;
        frame.copyTo(outputFrame);

        // 2)
        //applyGaussianBlur(frame, outputFrame); 
        // 3)
        //Canny(frame, outputFrame, 100, 200); 
        // 4)
        //Sobel(frame, outputFrame, -1, 1, 1); 
        // 5)
        //adjustBrightnessContrast(frame, outputFrame);
        // 6)
        //cvtColor(frame, outputFrame, COLOR_BGR2GRAY);
        // 7)
        //resize(frame, outputFrame, Size(frame.cols/2, frame.rows/2), INTER_LINEAR);
        // 8)
        //rotate(frame, outputFrame, ROTATE_90_CLOCKWISE);
        // 9)
        //flip(frame, outputFrame, 1); // 0: vertically 1: horizontally

        // Display output frame  
        if( outputFrame.empty() ) break; // end of video stream
        imshow("Output video", outputFrame);

        if( waitKey(1) == 27 ) break; // stop capturing by pressing ESC
    }

    cap.release(); // release the VideoCapture object
    return 0;
}