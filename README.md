# OpenCVTesting
Camera Recognition + Pausing Spotify


# Dependencies
Install OpenCv (linux) : https://docs.opencv.org/3.4/d7/d9f/tutorial_linux_install.html

Install OpenCv(Windows) : https://www.learnopencv.com/install-opencv3-on-windows/


This Program uses the Face-Detection Algorithm from openCv ( haarcascade ) to recognize wheter the user is watching his Screen
or not.

###Here you can find the original xml Files which I used to detect a face:
https://github.com/opencv/opencv/tree/master/data/haarcascades

## 1. How to Pause/Continue Process by Name [Linux]
I used system-based code line to pause the Spotify Process **but only when** *process_pid **is true**
(*process_pid is a boolean and turn true when the spotify Process is running. --> Step 2*)
:
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

## Program right now just for Linux based Systems

Should Pause Spotify if no face was detected.


