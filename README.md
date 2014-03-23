Artemis
=======

A Raspeberry Pi and Arduino powered robot

This is the repo for a pet project I'm working on to make a mobile robot. An Arduino is used for low-level activities
such as motor control whereas the more high-level aspects such as journey planning are handled by the Raspberry Pi.

The project is still early in development and currently on the arduino code works.

To build the arduino code you must have scons, avrdude and avr-g++ and the Arduino libraries installed
(I installed them with the arduino IDE)

To build the arduino code, cd in to the arduino directory and run 'scons'
To upload to an arduino you have plugged in, run 'scons upload' 
(you may need to change from /dev/ACM0 to /dev/ttyUSB0 in arduino/app/SConscript)

To run the unit tests just run the script in the root of the project.
