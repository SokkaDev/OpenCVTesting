#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

String eyes_cascade_name = "haarcascade_eye.xml";
CascadeClassifier eyes_cascade;

string window_name = "Frame";

int main( int argc, char** argv ) {
  
  VideoCapture capture;
    // Window Name --> Frame 
    // --> every other image function should work on Frame
    // --> have to put Frame in a variable
    const char * p = window_name.c_str();
    cvNamedWindow(p);
    moveWindow(p,1500,2000);

    ///0 öffnet die default cam
    if(!capture.open(0))
        return 0;
    for(;;)
    {
          Mat frame;
          capture >> frame;
          if( frame.empty() ) break; // Ende vom stream
          imshow(p, frame);
          
          if( waitKey(10) == 27 ) break; // Stopp über Escape
    }
  return 0;
}
