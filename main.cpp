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

    // 2)
    //displayGaussianBlur(cap);
    // 3)
    //displayCannyEdgeDetection(cap);
    // 4)
    //displaySobel(cap);
    // 5)
    //displayBrightnessContrastNegative(cap);
    // 6)
    //convertToGrayscale(cap);
    // 7)
    //displayHalfSize(cap);
    // 8)
    //displayRotate(cap, ROTATE_90_CLOCKWISE);
    // 9)
    //displayMirroredVideo(cap, 1);

    cap.release(); // release the VideoCapture object
    return 0;
}