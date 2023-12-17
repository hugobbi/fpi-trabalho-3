#include <opencv2/opencv.hpp>
#include "video.hpp"

using namespace cv;
int main(int argc, char** argv)
{
    // Initialize video capture
    int camera = 0;
    VideoCapture cap;
    // open the default camera, use something different from 0 otherwise;
    // Check VideoCapture documentation.
    if(!cap.open(camera))
        return -1;

    //displayGaussianBlur(cap);
    displayCannyEdgeDetection(cap);

    cap.release(); // release the VideoCapture object
    return 0;
}