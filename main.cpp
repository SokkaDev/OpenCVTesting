#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;


int main( int argc, char** argv ) {
  
  VideoCapture capture;

    

    
    // Window Name --> Frame 
    // --> every other image function should work on Frame
    // --> have to put Frame in a variable

    cvNamedWindow("Frame");
    moveWindow("Frame",1500,2000);

    ///0 öffnet die default cam
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
