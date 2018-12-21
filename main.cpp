#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <iostream>
#include <fstream>
using namespace std;
using namespace cv;

/** Function Headers */
void detectAndDisplay( Mat frame );
void readProcess_Stop();
void readProcess_Start();
/** Global variables */
String face_cascade_name = "haarcascade_frontalface_alt.xml";
String eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";
CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;
bool process_pid=false;

//Window Title
String window_name = "Frame";
int main( void )
{
    VideoCapture capture;
    Mat frame;

    const char * p = window_name.c_str();
    cvNamedWindow(p);

    //Move Window right bottom
    moveWindow(p,2000,2000);

    //-- 1. Load the cascades
    if( !face_cascade.load( face_cascade_name ) ){ cout << "--(!)Error loading face cascade\n"; return -1; };
    if( !eyes_cascade.load( eyes_cascade_name ) ){ cout << "--(!)Error loading eyes cascade\n"; return -1; };

    //-- 2. Read the video stream
    capture.open( -1 );
    if ( ! capture.isOpened() ) { cout << "--(!)Error opening video capture\n"; return -1; }
    while (  capture.read(frame) )
    {
        if( frame.empty() )
        {
            cout << " --(!) No captured frame -- Break!";
            break;
        }
        //-- 3. Apply the classifier to the frame
        detectAndDisplay( frame );
        int c = waitKey(10);
        if( (char)c == 27 ) { break; } // escape
    }
    return 0;
}
/* DetectAndDisplay*/
void detectAndDisplay( Mat frame )
{
    std::vector<Rect> faces;
    Mat frame_gray;
    cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );
    //Detect faces
    face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );
    //if no face was DETECTED -->stop process
    if(faces.empty()){
        readProcess_Stop();
    }
    else 
      {
    for( size_t i = 0; i < faces.size(); i++ )
    {
        Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
        ellipse( frame, center, Size( faces[i].width/2, faces[i].height/2), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
        Mat faceROI = frame_gray( faces[i] );
        std::vector<Rect> eyes;

        // Filter eyes from face
        eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CASCADE_SCALE_IMAGE, Size(30, 30) );
        
        for( size_t j = 0; j < eyes.size(); j++ )
        {
            Point eye_center( faces[i].x + eyes[j].x + eyes[j].width/2, faces[i].y + eyes[j].y + eyes[j].height/2 );
            int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
            circle( frame, eye_center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
            readProcess_Start();          
        }
    }
      }
    // Display Frame
    imshow( window_name, frame );
}

void readProcess_Stop(){
    //erstellt im Ordner eine ProcessInfo Datei
    system("ps -a > ./processinfo.txt");
    string word="spotify";
    string tmp="";
    ifstream myfile("processinfo.txt");

if (myfile.is_open())
  {
      while(myfile >> tmp ){
	        if(word.compare(tmp)==0){
                system("pkill -STOP spotify");
                process_pid=true;
            }
        else {
		  // Process Spotify not found
    }
}
    myfile.close();
  }
}

void readProcess_Start(){
    if(process_pid){
        system("pkill -CONT spotify");
    }
}