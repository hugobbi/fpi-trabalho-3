#include <opencv2/opencv.hpp>
#include "video.hpp"

using namespace cv;
int main(int argc, char** argv)
{
    // Initialize video capture
    int camera = 0;
    VideoCapture cap;
    VideoWriter vw;
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
        //applyGaussianBlur(frame, outputFrame, 0); 
        // 3)
        //applyCanny(frame, outputFrame);
        // 4)
        //applySobel(frame, outputFrame);
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

        // 10)
        //VideoWriter vw = writeVideoToFile(cap, "outputVideo.avi", outputFrame, 10);

        // Display output frame  
        if( outputFrame.empty() ) break; // end of video stream
        imshow("Output video", outputFrame);

        if(waitKey(1) == 27)
        {
            vw.release();
            cap.release(); // release the VideoCapture object
            break; // stop capturing by pressing ESC
        } 
    }

    return 0;
}