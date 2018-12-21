# OpenCVTesting
Camera Recognition + Pausing Spotify


# Dependencies
Install OpenCv (linux) : https://docs.opencv.org/3.4/d7/d9f/tutorial_linux_install.html

Install OpenCv(Windows) : https://www.learnopencv.com/install-opencv3-on-windows/


This Program uses the Face-Detection Algorithm from openCv ( haarcascade ) to recognize wheter the user is watching his Screen
or not.

###Here you can find the original xml Files which I used to detect a face:
https://github.com/opencv/opencv/tree/master/data/haarcascades

I used system-based code lines to pause the spotify Process:

`system("pkill -STOP spotify");`


## Program right now just for Linux based Systems

Should Pause Spotify if no face was detected.


