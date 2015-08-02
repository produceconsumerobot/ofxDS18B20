#include "ofxDS18B20.h"

//---------------------------------------------------//
// ofxDS18B20 constructor
//---------------------------------------------------// 
ofxDS18B20::ofxDS18B20()
{
	_devicesDir = "/sys/bus/w1/devices/";
	
	// Look in the devices directory for ofxDS18B20 devices
	ofDirectory dir(_devicesDir);
	if (dir.exists() && dir.isDirectory()) { // if the directory exists
		// Get the files
		dir.listDir();
		vector< ofFile > files = dir.getFiles();
		for (unsigned int j=0; j<files.size(); j++) {
			// Get the file names
			string fileName = files.at(j).getFileName();
			if (fileName.substr(0,3).compare("28-") == 0) {
				// ofxDS18B20 device dirs start with 28-
				_deviceNames.push_back(fileName);
			}
		}		
	} else {
		// _devicesDir doesn't exist :-(
		ofLog(OF_LOG_ERROR, "ofxDS18B20: Directory " + _devicesDir + " missing");
	}	
	return;
}

//---------------------------------------------------//
// listDevices
// Lists the devices found
//---------------------------------------------------//
int ofxDS18B20::listDevices()
{
	for (unsigned int j=0; j<_deviceNames.size(); j++) {
		cout << "[" << j << "] - " << _deviceNames.at(j) << endl;
	}
	return _deviceNames.size();
}
	
//---------------------------------------------------//
// read
// Reads the temperature value from the specified device
//---------------------------------------------------//
float ofxDS18B20::read(int deviceNumber)
{
	if (deviceNumber < _deviceNames.size()) { 
		// Look for the specified device data file
		string dataPath = _devicesDir + _deviceNames.at(deviceNumber) + "/w1_slave";
		ofFile dataFile = ofFile(dataPath);
		
		if (dataFile.doesFileExist(dataPath) && dataFile.canRead()) {
			// If the file is found read the text
			ofBuffer dataBuffer = dataFile.readToBuffer();
			string dataStr = dataBuffer.getText();
			int pos = dataStr.find("t=");	// Find the start of the temp data
			if (pos > 0 && (pos+7 < dataStr.size())) {
				// Check that the temp data was found
				string data = dataStr.substr(pos+2, pos+7); // Extract the temp data
				float temp = atoi(data.c_str());
				temp = temp / 1000;
				return temp;
			} else {
				ofLogWarning() << "ofxDS18B20: Data missing for " << deviceNumber;
				return -1;
			}
		} else {
			ofLogError() << "ofxDS18B20: Device " << deviceNumber << " not found";
			return -1;
		}
	} else {
		ofLogError() << "ofxDS18B20: Device " << deviceNumber << " not found";
		return -1;
	}
	return -1;
}
	
//---------------------------------------------------//
// getDeviceName
// Get the name of the specified device
//---------------------------------------------------//
string ofxDS18B20::getName(int deviceNumber)
{
	if (deviceNumber < _deviceNames.size()) {
		return _deviceNames.at(deviceNumber);
	} else {
		ofLogError() << "ofxDS18B20: Device " << deviceNumber << " not found";
	}
	return "";
}
