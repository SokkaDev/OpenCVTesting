#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;


int main( int argc, char** argv ) {
  
  VideoCapture capture;

    ///0 öffnet die default cam

    

  cvNamedWindow("Frame");
  moveWindow("Frame",1500,2000);
    if(!capture.open(0))
        return 0;
    for(;;)
    {
          Mat frame;
          capture >> frame;
          
          
          if( frame.empty() ) break; // Ende vom stream
          imshow("Frame", frame);
          
          if( waitKey(10) == 27 ) break; // Stopp über Escape
    }
  return 0;
}
