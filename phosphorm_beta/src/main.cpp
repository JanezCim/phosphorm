/*
 * Copyright (c) 2013 Dan Wilcox <danomatika@gmail.com>
 *
 * BSD Simplified License.
 * For information on usage and redistribution, and for a DISCLAIMER OF ALL
 * WARRANTIES, see the file, "LICENSE.txt," in this distribution.
 *
 * See https://github.com/danomatika/ofxMidi for documentation
 *
 */
#include "ofMain.h"
#include "ofApp.h"

int main(int argc, char *argv[]){

	// #ifdef TARGET_RASPBERRY_PI 
	ofGLESWindowSettings settings;
	settings.glesVersion=2;
	settings.setSize(720,480);
	// #else
	// ofGLFWWindowSettings settings;
	// // ofGLWindowSettings settings;
	// settings.setGLVersion(3,2);
	// settings.setSize(720,480);
	// #endif
	settings.windowMode = OF_FULLSCREEN; //if fullscreen is wanted
	ofCreateWindow(settings);

	ros::init(argc, argv, "phosphorm_ros"); 

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());
}
