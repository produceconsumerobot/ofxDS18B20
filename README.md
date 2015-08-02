# ofxDS18B20
OpenFrameworks 1-wire interface to DS18B20 temperature sensor for RaspberryPi

Setup:
-------------
- Configure your hardware (see links below)

- edit /boot/config.txt
> - sudo nano /boot/config.txt
> - Add to the end of the file:
> - dtoverlay=w1-gpio

- edit /etc/modules
> - sudo nano /etc/modules
> - Add to the end of the file:
> - w1-gpio
> - w1-therm

- Reboot
- Add ofxDS18B20 folder to your OF Addons folder
- Compile, run and measure temperature!

- See these links for additional information:
> - https://learn.adafruit.com/downloads/pdf/adafruits-raspberry-pi-lesson-11-ds18b20-temperature-sensing.pdf
> - http://bradsrpi.blogspot.com/2013/12/c-program-to-read-temperature-from-1.html
> - https://www.raspberrypi.org/forums/viewtopic.php?t=54238&p=431812
