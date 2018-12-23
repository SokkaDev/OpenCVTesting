# OpenCV Face Detection + Pause Process by Name
Camera Recognition + Pausing Spotify


# Dependencies
Install OpenCv (linux) : https://docs.opencv.org/3.4/d7/d9f/tutorial_linux_install.html

Install OpenCv(Windows) : https://www.learnopencv.com/install-opencv3-on-windows/

## Compile

Download the Files into your directory.
Compile with g++ and link your openCv Libary:
```
g++ main.cpp -o FaceRecognition `pkg-config --cflags --libs opencv`
```


This Program uses the Face-Detection Algorithm from openCv ( haarcascade ) to recognize wheter the user is watching his Screen or not. If the User is not watching the Screen , the Programm automatically Stops Spotify.
When the Face is detected again it continues the Program.

### Here you can find the original xml Files which I used to detect a face:
https://github.com/opencv/opencv/tree/master/data/haarcascades

## 1. How to Pause/Continue Process by Name [Linux]
I used a system-based code line to pause the Spotify Process after the Check in *Step 2* :
`system("pkill -STOP spotify");`

 And another system based code line to continue the Process:
 `system("pkill -CONT spotify");`
 
## 2.) Be Sure that the Process exists

Before that we have to check , wheter the Process exists or not.
The Code creates a file (processinfo.txt) and overwrites it (as long as the programm is running):
`system("ps -a > ./processinfo.txt");`

Than a Loop goes through every single Word of that File and searches for the Process spotify (word):
```
while(myfile >> tmp ){
	        if(word.compare(tmp)==0){
                system("pkill -STOP spotify");
                process_pid=true;
            }
        else {
		  process_pid=false;
    }
 ```

### Program right now just for Linux based Systems

