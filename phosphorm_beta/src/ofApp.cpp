


#include "ofApp.h"


#include <iostream>

float ff=1.01;
float xw=1.01;
float yw=1.01;
float jj=1.01;
float kk=1.01;
float ll=1;
float tt=1;



//midicontrols
//maybe make these chars instead?  check the bit depth to see if there will be a lot of
//data loss

float c1=0.0;
float c2=0.0;
float c3=0.0;
float c4=0.0;
float c5=0.0;
float c6=0.0;
float c7=0.0;
float c8=0.0;
float c9=0.0;
float c10=0.0;
float c11=0.0;
float c12=0.0;
float c13=0.0;
float c14=0.0;
float c15=.0;
float c16=.0;


//keyboard controls
//probbly shift all of these to a gui
float sx=0.0;
float dd=1;

float gg=1;
float hh=0;

float ee=1;
float pp=1;
float ii=.01;






float theta=0;





//can't really work with the dummis the same way here
float osc_l1_freq=0.0;
float osc_l1_midi=0.0;
float osc_l1_amp=0.5;
float frequency_l1=0.0;
int osc_l1_shape=0;

float osc_l2_freq=0.0;
float osc_l2_midi=0.0;
float osc_l2_amp=0.0;
float frequency_l2=0.0;
int osc_l2_shape=0;

float osc_r1_freq=0.0;
float osc_r1_midi=0.0;
float osc_r1_amp=0.5;
float frequency_r1=0.0;
int osc_r1_shape=0;

float osc_r2_freq=0.0;
float osc_r2_midi=0.0;
float osc_r2_amp=0.0;
float frequency_r2=0.0;
int osc_r2_shape=0;



int osc_l_switch=0;
int osc_r_switch=0;



//ampmod
int ampmod_osc_l_switch=0;
int ampmod_osc_r_switch=0;

float ampmod_osc_l1_freq=0.0;
float ampmod_osc_l1_midi=0.0;
float ampmod_osc_l1_amp=0.0;
float ampmod_frequency_l1=0.0;
int ampmod_osc_l1_shape=0;

float ampmod_osc_l2_freq=0.0;
float ampmod_osc_l2_midi=0.0;
float ampmod_osc_l2_amp=0.0;
float ampmod_frequency_l2=0.0;
int ampmod_osc_l2_shape=0;

float ampmod_osc_r1_freq=0.0;
float ampmod_osc_r1_midi=0.0;
float ampmod_osc_r1_amp=0.0;
float ampmod_frequency_r1=0.0;
int ampmod_osc_r1_shape=0;

float ampmod_osc_r2_freq=0.0;
float ampmod_osc_r2_midi=0.0;
float ampmod_osc_r2_amp=0.0;
float ampmod_frequency_r2=0.0;
int ampmod_osc_r2_shape=0;

//phasemod
int phasemod_osc_l_switch=0;
int phasemod_osc_r_switch=0;

float phasemod_osc_l1_freq=0.0;
float phasemod_osc_l1_midi=0.0;
float phasemod_osc_l1_amp=0.0;
float phasemod_frequency_l1=0.0;
int phasemod_osc_l1_shape=0;

float phasemod_osc_l2_freq=0.0;
float phasemod_osc_l2_midi=0.0;
float phasemod_osc_l2_amp=0.0;
float phasemod_frequency_l2=0.0;
int phasemod_osc_l2_shape=0;


float phasemod_osc_r1_freq=0.0;
float phasemod_osc_r1_midi=0.0;
float phasemod_osc_r1_amp=0.0;
float phasemod_frequency_r1=0.0;
int phasemod_osc_r1_shape=0;

float phasemod_osc_r2_freq=0.0;
float phasemod_osc_r2_midi=0.0;
float phasemod_osc_r2_amp=0.0;
float phasemod_frequency_r2=0.0;
int phasemod_osc_r2_shape=0;

//quantize
int quantize_osc_l_switch=0;
int quantize_osc_r_switch=0;

//switch between quantizing amp and phase mod
int quantize_mod_l_switch=0;
int quantize_mod_r_switch=0;


float quantize_mix_l1=0;
float quantize_amount_l1=1.0;

float quantize_mix_l2=0;
float quantize_amount_l2=1.0;

float quantize_mix_r1=0;
float quantize_amount_r1=1.0;

float quantize_mix_r2=0;
float quantize_amount_r2=1.0;

float quantize_mix_ampmod_l1=0;
float quantize_amount_ampmod_l1=1.0;

float quantize_mix_ampmod_l2=0;
float quantize_amount_ampmod_l2=1.0;

float quantize_mix_phasemod_l1=0;
float quantize_amount_phasemod_l1=1.0;

float quantize_mix_phasemod_l2=0;
float quantize_amount_phasemod_l2=1.0;

float quantize_mix_ampmod_r1=0;
float quantize_amount_ampmod_r1=1.0;

float quantize_mix_ampmod_r2=0;
float quantize_amount_ampmod_r2=1.0;

float quantize_mix_phasemod_r1=0;
float quantize_amount_phasemod_r1=1.0;

float quantize_mix_phasemod_r2=0;
float quantize_amount_phasemod_r2=1.0;



int overflow_switch=0;

//scale switches
//0=no quantizing, no scale
//1=5et, 2=7et, 3=12et, 4=carlos alpha, 5=carlos beta
int scale_switch=0;
bool frequency_quantize=1;






//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	//ofSetVerticalSync(true);
	ofBackground(0);
	ofHideCursor();
	//ofSetLogLevel(OF_LOG_VERBOSE);
	
    
    /**MIDIBIX***/
    
	// print input ports to console
	midiIn.listInPorts();
	
	// open port by number (you may need to change this)
	midiIn.openPort(1);
	//midiIn.openPort("IAC Pure Data In");	// by name
	//midiIn.openVirtualPort("ofxMidiIn Input"); // open a virtual port
	
	// don't ignore sysex, timing, & active sense messages,
	// these are ignored by default
	midiIn.ignoreTypes(false, false, false);
	
	// add ofApp as a listener
	midiIn.addListener(this);
	
	// print received messages to the console
	midiIn.setVerbose(true);
    
    /*******/
    
    
    /**audiobiz***/
    
    
    
    
    int bufferSize		= 512;
    sampleRate 			= 48000;
    
     //audio
    phase_l1= 0;
    phaseAdder_l1= 0.0f;
    phaseAdderTarget_l1= 0.0f;
    
    phase_l2= 0;
    phaseAdder_l2= 0.0f;
    phaseAdderTarget_l2= 0.0f;
    
    phase_r1= 0;
    phaseAdder_r1= 0.0f;
    phaseAdderTarget_r1= 0.0f;
    
    phase_r2= 0;
    phaseAdder_r2= 0.0f;
    phaseAdderTarget_r2= 0.0f;
    
    //ampmod
    ampmod_phase_l1= 0;
    ampmod_phaseAdder_l1= 0.0f;
    ampmod_phaseAdderTarget_l1= 0.0f;
    
    ampmod_phase_l2= 0;
    ampmod_phaseAdder_l2= 0.0f;
    ampmod_phaseAdderTarget_l2= 0.0f;
    
    
    ampmod_phase_r1= 0;
    ampmod_phaseAdder_r1= 0.0f;
    ampmod_phaseAdderTarget_r1= 0.0f;
    
    ampmod_phase_r2= 0;
    ampmod_phaseAdder_r2= 0.0f;
    ampmod_phaseAdderTarget_r2= 0.0f;
    
    //phasemod
    phasemod_phase_l1= 0;
    phasemod_phaseAdder_l1= 0.0f;
    phasemod_phaseAdderTarget_l1= 0.0f;
    
    phasemod_phase_l2= 0;
    phasemod_phaseAdder_l2= 0.0f;
    phasemod_phaseAdderTarget_l2= 0.0f;
    
    
    phasemod_phase_r1= 0;
    phasemod_phaseAdder_r1= 0.0f;
    phasemod_phaseAdderTarget_r1= 0.0f;
    
    phasemod_phase_r2= 0;
    phasemod_phaseAdder_r2= 0.0f;
    phasemod_phaseAdderTarget_r2= 0.0f;
    
    
    volume				= 0.1f;
    bNoise 				= false;
    
    lAudio.assign(bufferSize, 0.0);
    rAudio.assign(bufferSize, 0.0);
    
    lAudio_c.assign(bufferSize, 0.0);
    rAudio_c.assign(bufferSize, 0.0);
    
   
    
    soundStream.printDeviceList();
    
   // soundStream.setDeviceID(3);
    
    ofSoundStreamSettings settings;
    
    
    
    settings.setOutListener(this);
    settings.sampleRate = sampleRate;
    settings.numOutputChannels = 2;
    settings.numInputChannels = 0;
    settings.bufferSize = bufferSize;
    soundStream.setup(settings);
    
    
    shader_phosphor.load("shadersES2/shader_phosphor");
    // ofSetBackgroundAuto(true);
    fb0.allocate(ofGetWidth(),ofGetHeight());
    fb0.begin();
    ofClear(0,0,0,255);
    fb0.end();
    
    fb1.allocate(ofGetWidth(),ofGetHeight());
    fb1.begin();
    ofClear(0,0,0,255);
    fb1.end();
    
    #ifdef ROS
        ros_sub_ = nh_.subscribe<std_msgs::Int16MultiArray>("/phosporm_midi_input", 10, &ofApp::ros_callback, this);
    #endif
}

// #ifdef ROS
void ofApp::ros_callback(const std_msgs::Int16MultiArray::ConstPtr& ros_msg){
    if(ros_msg->data.size()!=2){
        ROS_WARN("Recieved ROS message data array length must be 2, it is instead %d", int(ros_msg->data.size()));
        return;
    }
    
    // convert from ros message to midi message - first int is control, second is value
    ofxMidiMessage msg;
    msg.control = ros_msg->data[0];
    msg.value = ros_msg->data[1];
    msg.status = MIDI_CONTROL_CHANGE;

    // ROS_INFO("Recieved a message %d, %d", ros_msg->data[0], ros_msg->data[1]);

    // add the latest message to the message queue
	midiMessages.push_back(msg);

	// remove any old messages if we have too many
	while(midiMessages.size() > maxMessages) {
		midiMessages.erase(midiMessages.begin());
	}
    return;
}
// #endif

//--------------------------------------------------------------
void ofApp::update() {
    midibiz();
    #ifdef ROS
        ros::spinOnce();
    #endif
    
}

//--------------------------------------------------------------
void ofApp::draw() {
    
  
    
    
    ofBackground(0);
    
/*midimessagesbiz**/
    
    
    
    
 
	
    
    
   /******* endmidimessagesbiz*********/
   
    
    
   
    fb0.begin();
    
    shader_phosphor.begin();
    // shader_phosphor.setUniform1f("test",sx);
    fb1.draw(0,0);
    shader_phosphor.end();
    
    
    /***AUDIODRAWBIXZ******/

    
    int scaleshape=2;
    
    ofBeginShape();
    
    ofSetColor(255);
        
    ofSetLineWidth(1);
    ofNoFill();
    
    for (unsigned int i = 0; i < rAudio.size(); i+=2){
        
        
        
        
        float x =  scaleshape*(lAudio[i]*180.0f)+ofGetWidth()/2.0;
        float y = scaleshape*(rAudio[i]*180.0f)+ofGetHeight()/2.0;
        
        
        
        
        ofCurveVertex(x,y);
        
    }//endifor
    ofEndShape(false);
    
    
    fb0.end();
    
    fb0.draw(0,0);
    
    
   
    fb1.begin();
    fb0.draw(0,0);
    

    fb1.end();
    
    
    fb0.begin();
    ofClear(0,0,0,255);
    fb0.end();
    fb1.begin();
    ofClear(0,0,0,255);
    fb1.end();
    
    ofSetHexColor(0xFFFFFF);
    ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate(),2)+"fade: "+ofToString(sx,2), 10, ofGetHeight()-5 );
    
    




/********endaudiodrawbiz****/
   
}

//--------------------------------------------------------------
//--------------------------------------------------------------
void ofApp::audioOut(ofSoundBuffer & buffer){
    
    //scaling amplitude as a fucntion of frequency
    // cout <<" c1="<<c1<< endl;
    
    
    //heres some settings for standard combinations of tunings
    //just a regular kind of scalling
    //middle_frequency=440
    //f_scale=63
    
    
    
    pan = 0.5f;
    float leftScale = 1 - pan;
    float rightScale = pan;
    
    
    ///carlos scales
    //alpha - octave ratio 1.5, equal semitones 9
    //beta  - octave ratio 1.5, equal semitones 11
    //gamma - octave ratio 1.5, equal semitones 20
    //for carlos scales need to maek the total span larger i think...
    
    //a standard octave is a ratio of 2:1.
    //how to make a non repeating scale...
    float octave_ratio=1.5;
    
    //a standard equal temperament tuning is 12 equal semitones
    //remember that changing equal semitones
    float equal_semitones=11.0;
    
    //the middle frequecny is what note will play when the slider is at mid point
    //for standard tuning would be 440hz for middle a
    float middle_frequency=220;
    
    //total span is how many octaves we go up and down from ,
    float total_span=4.0;
    
    
    
    float pm_scalar=3.0;
    float am_scalar=3.0;
    
    
    //5et is the default
    if(scale_switch==0){
        octave_ratio=2.0;
        equal_semitones=5.0;
        frequency_quantize=1;
    }
    
    //7et
    if(scale_switch==1){
        octave_ratio=2.0;
        equal_semitones=7.0;
        frequency_quantize=1;
        //pm_scalar=3.0;
       // am_scalar=3.0;
    }
    
    //12et
    if(scale_switch==2){
        octave_ratio=2.0;
        equal_semitones=12.0;
        frequency_quantize=1;
        pm_scalar=4.0;
        am_scalar=4.0;
    }
    
    //carlos alpha
    if(scale_switch==3){
        octave_ratio=1.5;
        equal_semitones=9.0;
        frequency_quantize=1;
        pm_scalar=4.0;
        am_scalar=4.0;

    }
    
    //carlos beta
    if(scale_switch==4){
        octave_ratio=1.5;
        equal_semitones=11.0;
        frequency_quantize=1;
        pm_scalar=4.0;
        am_scalar=4.0;
    }
    
    //no quantization
    if(scale_switch==5){
        octave_ratio=2.0;
        equal_semitones=12.0;
        frequency_quantize=0;
        total_span=8.0;
        am_scalar=1.0;
        pm_scalar=1.0;
    }
    //f-scaling is the map from 0-1 into whatever range you want
    //usual midi keyboard piano notes go from 0-127, if you want
    //to rescale things like that set middle frequency to 440 and
    //the slider to bipolar and f_scale to 63
    //if you just want to have like a scale of one octave up and one octave down
    //set it to 12
    
    float f_scale=equal_semitones*total_span;
    
    //ampmod
    float middle_frequency_am=middle_frequency/8.0f;
    float f_scale_am=f_scale*am_scalar;
    
    //phasemod
    float middle_frequency_pm=middle_frequency/8.0f;
    float f_scale_pm=f_scale*pm_scalar;
    
    //here you can also add quantisation from midi->freq values
    //add (int) to the arguments to only allow for integer values
    
    
    //audio
    osc_l1_freq=f_scale*osc_l1_midi;
    osc_r1_freq=f_scale*osc_r1_midi;
    osc_l2_freq=f_scale*osc_l2_midi;
    osc_r2_freq=f_scale*osc_r2_midi;
    
    
    //ampmods
    ampmod_osc_l1_freq=f_scale_am*ampmod_osc_l1_midi;
    ampmod_osc_r1_freq=f_scale_am*ampmod_osc_r1_midi;
    ampmod_osc_l2_freq=f_scale_am*ampmod_osc_l2_midi;
    ampmod_osc_r2_freq=f_scale_am*ampmod_osc_r2_midi;
    
    //phasemods
    phasemod_osc_l1_freq=f_scale_pm*phasemod_osc_l1_midi;
    phasemod_osc_r1_freq=f_scale_pm*phasemod_osc_r1_midi;
    phasemod_osc_l2_freq=f_scale_pm*phasemod_osc_l2_midi;
    phasemod_osc_r2_freq=f_scale_pm*phasemod_osc_r2_midi;
    
    if(frequency_quantize==1){
        
        //we can also quantize to different kinds of scales
        //note that the relationship between quantize_scale and equal_semitone is important
        //or maybe just rework the math on this doggg
        float quantize_scale=1.0;
        
        osc_l1_freq=int(quantize_scale*osc_l1_freq);
        osc_r1_freq=int(quantize_scale*osc_r1_freq);
        osc_l2_freq=int(quantize_scale*osc_l2_freq);
        osc_r2_freq=int(quantize_scale*osc_r2_freq);
        
        ampmod_osc_l1_freq=int(quantize_scale*ampmod_osc_l1_freq);
        ampmod_osc_r1_freq=int(quantize_scale*ampmod_osc_r1_freq);
        ampmod_osc_l2_freq=int(quantize_scale*ampmod_osc_l2_freq);
        ampmod_osc_r2_freq=int(quantize_scale*ampmod_osc_r2_freq);
        
        phasemod_osc_l1_freq=int(quantize_scale*phasemod_osc_l1_freq);
        phasemod_osc_r1_freq=int(quantize_scale*phasemod_osc_r1_freq);
        phasemod_osc_l2_freq=int(quantize_scale*phasemod_osc_l2_freq);
        phasemod_osc_r2_freq=int(quantize_scale*phasemod_osc_r2_freq);
    }
    
    
    
    
    
    frequency_l1=pow(octave_ratio,osc_l1_freq/equal_semitones)*middle_frequency;
    frequency_l2=pow(octave_ratio,osc_l2_freq/equal_semitones)*middle_frequency;
    
    frequency_r1=pow(octave_ratio,osc_r1_freq/equal_semitones)*middle_frequency;
    //frequency_r1=pow(3.0f,osc_r1_freq/equal_semitones)*middle_frequency;
    
    frequency_r2=pow(octave_ratio,osc_r2_freq/equal_semitones)*middle_frequency;
    
    //ampmod
    ampmod_frequency_l1=pow(octave_ratio,ampmod_osc_l1_freq/equal_semitones)*middle_frequency_am;
    ampmod_frequency_l2=pow(octave_ratio,ampmod_osc_l2_freq/equal_semitones)*middle_frequency_am;

    
    ampmod_frequency_r1=pow(octave_ratio,ampmod_osc_r1_freq/equal_semitones)*middle_frequency_am;
    ampmod_frequency_r2=pow(octave_ratio,ampmod_osc_r2_freq/equal_semitones)*middle_frequency_am;
    
    //phasemod
    phasemod_frequency_l1=pow(octave_ratio,phasemod_osc_l1_freq/equal_semitones)*middle_frequency_pm;
    phasemod_frequency_l2=pow(octave_ratio,phasemod_osc_l2_freq/equal_semitones)*middle_frequency_pm;
    
    
    phasemod_frequency_r1=pow(octave_ratio,phasemod_osc_r1_freq/equal_semitones)*middle_frequency_pm;
    phasemod_frequency_r2=pow(octave_ratio,phasemod_osc_r2_freq/equal_semitones)*middle_frequency_pm;
        
    //this is to keep phase from just incrementing absurdly
    //for some reaason if the mod is just twopi then it restarts phase in rythmic glitchy bits
    //maybe i can turn this on and off or swtich values?
    
    
    //not positive why the 50000 yet, lower values make the base note lower, higher-higher
    float p_a_t=50000.0;
    //audio
    phase_l1=fmod(phase_l1,8*TWO_PI);
    phaseAdderTarget_l1=(frequency_l1/p_a_t ) * TWO_PI;
    phaseAdder_l1 = 0.05f * phaseAdder_l1 + 0.95f *phaseAdderTarget_l1;
    
    phase_r1=fmod(phase_r1,8*TWO_PI);
    phaseAdderTarget_r1=(frequency_r1/p_a_t ) * TWO_PI;
    phaseAdder_r1 = 0.05f * phaseAdder_r1 + 0.95f *phaseAdderTarget_r1;
    
    phase_l2=fmod(phase_l2,8*TWO_PI);
    phaseAdderTarget_l2=(frequency_l2/50000.0 ) * TWO_PI;
    phaseAdder_l2 = 0.05f * phaseAdder_l2 + 0.95f *phaseAdderTarget_l2;
    
    
    
    phase_r2=fmod(phase_r2,8*TWO_PI);
    phaseAdderTarget_r2=(frequency_r2/50000.0 ) * TWO_PI;
    phaseAdder_r2 = 0.05f * phaseAdder_r2 + 0.95f *phaseAdderTarget_r2;
    
    //ampmods
    ampmod_phase_l1=fmod(ampmod_phase_l1,8*TWO_PI);
    ampmod_phaseAdderTarget_l1=(ampmod_frequency_l1/50000.0 ) * TWO_PI;
    ampmod_phaseAdder_l1 = 0.05f * ampmod_phaseAdder_l1 + 0.95f *ampmod_phaseAdderTarget_l1;
    
    ampmod_phase_l2=fmod(ampmod_phase_l2,8*TWO_PI);
    ampmod_phaseAdderTarget_l2=(ampmod_frequency_l2/50000.0 ) * TWO_PI;
    ampmod_phaseAdder_l2 = 0.05f * ampmod_phaseAdder_l2 + 0.95f *ampmod_phaseAdderTarget_l2;

    
    ampmod_phase_r1=fmod(ampmod_phase_r1,8*TWO_PI);
    ampmod_phaseAdderTarget_r1=(ampmod_frequency_r1/50000.0 ) * TWO_PI;
    ampmod_phaseAdder_r1 = 0.05f * ampmod_phaseAdder_r1 + 0.95f *ampmod_phaseAdderTarget_r1;
    
    ampmod_phase_r2=fmod(ampmod_phase_r2,8*TWO_PI);
    ampmod_phaseAdderTarget_r2=(ampmod_frequency_r2/50000.0 ) * TWO_PI;
    ampmod_phaseAdder_r2 = 0.05f * ampmod_phaseAdder_r2 + 0.95f *ampmod_phaseAdderTarget_r2;
    
    //phasemods
    phasemod_phase_l1=fmod(phasemod_phase_l1,8*TWO_PI);
    phasemod_phaseAdderTarget_l1=(phasemod_frequency_l1/50000.0 ) * TWO_PI;
    phasemod_phaseAdder_l1 = 0.05f * phasemod_phaseAdder_l1 + 0.95f *phasemod_phaseAdderTarget_l1;
    
    phasemod_phase_l2=fmod(phasemod_phase_l2,8*TWO_PI);
    phasemod_phaseAdderTarget_l2=(phasemod_frequency_l2/50000.0 ) * TWO_PI;
    phasemod_phaseAdder_l2 = 0.05f * phasemod_phaseAdder_l2 + 0.95f *phasemod_phaseAdderTarget_l2;
    
    
    phasemod_phase_r1=fmod(phasemod_phase_r1,8*TWO_PI);
    phasemod_phaseAdderTarget_r1=(phasemod_frequency_r1/50000.0 ) * TWO_PI;
    phasemod_phaseAdder_r1 = 0.05f * phasemod_phaseAdder_r1 + 0.95f *phasemod_phaseAdderTarget_r1;
    
    phasemod_phase_r2=fmod(phasemod_phase_r2,8*TWO_PI);
    phasemod_phaseAdderTarget_r2=(phasemod_frequency_r2/50000.0 ) * TWO_PI;
    phasemod_phaseAdder_r2 = 0.05f * phasemod_phaseAdder_r2 + 0.95f *phasemod_phaseAdderTarget_r2;

    
    
        for (size_t i = 0; i < buffer.getNumFrames(); i++){
            phase_l1 += phaseAdder_l1;
            phase_l2 += phaseAdder_l2;
            
            phase_r1 += phaseAdder_r1;
            phase_r2 += phaseAdder_r2;
            
            
          
            //ampmod
            ampmod_phase_l1 += ampmod_phaseAdder_l1;
            ampmod_phase_l2 += ampmod_phaseAdder_l2;
            
            ampmod_phase_r1 += ampmod_phaseAdder_r1;
            ampmod_phase_r2 += ampmod_phaseAdder_r2;
            
            //phasemod
            phasemod_phase_l1 += phasemod_phaseAdder_l1;
            phasemod_phase_l2 += phasemod_phaseAdder_l2;
            
            phasemod_phase_r1 += phasemod_phaseAdder_r1;
            phasemod_phase_r2 += phasemod_phaseAdder_r2;
            /*basic waveforms*/
            
            /*samplel and sampler are what get fed into the buffer at the end*/
            float sample_l1=0;
            float sample_l2=0;
            
            float sample_r1=0;
            float sample_r2=0;
            
           
            
         
            
            
            
            
            //ampmod initialize and quantize
            
            //lefts
            float ampmod_l1=osc(ampmod_phase_l1,ampmod_osc_l1_amp,ampmod_osc_l1_shape);

            ampmod_l1=quantize(ampmod_l1,quantize_amount_ampmod_l1, quantize_mix_ampmod_l1);
            
            float ampmod_l2=osc(ampmod_phase_l2,ampmod_osc_l2_amp,ampmod_osc_l2_shape);
            
            ampmod_l2=quantize(ampmod_l2,quantize_amount_ampmod_l2, quantize_mix_ampmod_l2);
            
            //rights
            float ampmod_r1=osc(ampmod_phase_r1+PI/2.0f,ampmod_osc_r1_amp,ampmod_osc_r1_shape);
            
            ampmod_r1=quantize(ampmod_r1,quantize_amount_ampmod_r1, quantize_mix_ampmod_r1);
            
            float ampmod_r2=osc(ampmod_phase_r2+PI/2.0f,ampmod_osc_r2_amp,ampmod_osc_r2_shape);
            
            ampmod_r2=quantize(ampmod_r2,quantize_amount_ampmod_r2, quantize_mix_ampmod_r2);
            
            
            //phasemod initialize and quantize
            
            //lefts
            float phasemod_l1=osc(phasemod_phase_l1,phasemod_osc_l1_amp,phasemod_osc_l1_shape);
            
            phasemod_l1=quantize(phasemod_l1,quantize_amount_phasemod_l1, quantize_mix_phasemod_l1);
            
            float phasemod_l2=osc(phasemod_phase_l2,phasemod_osc_l2_amp,phasemod_osc_l2_shape);
            
            phasemod_l2=quantize(phasemod_l2,quantize_amount_phasemod_l2, quantize_mix_phasemod_l2);
           
            //rights
            float phasemod_r1=osc(phasemod_phase_r1+PI/2.0f,phasemod_osc_r1_amp,phasemod_osc_r1_shape);
            
            phasemod_r1=quantize(phasemod_r1,quantize_amount_phasemod_r1, quantize_mix_phasemod_r1);
            
            float phasemod_r2=osc(phasemod_phase_r2+PI/2.0f,phasemod_osc_r2_amp,phasemod_osc_r2_shape);
            
            phasemod_r2=quantize(phasemod_r2,quantize_amount_phasemod_r2, quantize_mix_phasemod_r2);
            
            
            //audio samples
            
            sample_l1=osc(phase_l1+phasemod_l1,osc_l1_amp+ampmod_l1,osc_l1_shape);
            sample_l2=osc(phase_l2+phasemod_l2,osc_l2_amp+ampmod_l2,osc_l2_shape);
            sample_r1=osc(phase_r1+PI/2.0f+phasemod_r1,osc_r1_amp+ampmod_r1,osc_r1_shape);
            sample_r2=osc(phase_r2+PI/2.0f+phasemod_r2,osc_r2_amp+ampmod_r2,osc_r2_shape);
            
            
            sample_l1=quantize(sample_l1,quantize_amount_l1, quantize_mix_l1);
            sample_l2=quantize(sample_l2,quantize_amount_l2, quantize_mix_l2);
            sample_r1=quantize(sample_r1,quantize_amount_r1, quantize_mix_r1);
            sample_r2=quantize(sample_r2,quantize_amount_r2, quantize_mix_r2);
            
            
            
           
            
            
            float summed_l=sample_l1+sample_l2;
            
            float summed_r=sample_r1+sample_r2;
            
            //overflows!
           
            if(overflow_switch==0){
                summed_l=ofClamp(summed_l,-1,1);
                summed_r=ofClamp(summed_r,-1,1);
            }
            
            if(overflow_switch==1){
                summed_l=fmod(summed_l,1);
                summed_r=fmod(summed_r,1);
            }
            
            if(overflow_switch==2){
                if(summed_l>1.0){
                    summed_l=1.0-fmod(summed_l,1);
                }
                if(summed_r>1.0){
                    summed_r=1.0-fmod(summed_r,1);
                }
                
                if(summed_l<-1.0){
                    summed_l=-(1.0-fmod(abs(summed_l),1));
                }
                if(summed_r<-1.0){
                    summed_r=-(1.0-fmod(abs(summed_r),1));
                }
                
            }
            
            if(overflow_switch==3){
                if(abs(summed_l)>1){summed_l=0;}
                if(abs(summed_r)>1){summed_r=0;}
            }
            
            /*
            if(overflow_switch==4){
                if(abs(summed_l)>1){summed_l=ofClamp(summed_l/summed_r,-1,1);}
                
                
                if(abs(summed_r)>1){summed_r=ofClamp(summed_r/summed_l,-1,1);}
            }
            
            if(overflow_switch==5){
                if(abs(summed_l)>1){summed_l=fmod(pow(summed_l,abs(summed_r)),1);}
                
                
                if(abs(summed_r)>1){summed_r=fmod(pow(summed_r,abs(summed_l)),1);}
            }
            */
            
            lAudio[i] = buffer[i*buffer.getNumChannels()    ] = summed_l  * leftScale;
            rAudio[i] = buffer[i*buffer.getNumChannels() + 1] = summed_r  * rightScale;
            
            
            
            float smooth=.5;
            if(i>0){
                lAudio[i]=lAudio[i]*smooth+(1.0f-smooth)*lAudio[(i-1)];
                rAudio[i]=rAudio[i]*smooth+(1.0f-smooth)*rAudio[(i-1)];
            }
            
            if(i==0){
                lAudio[i]=lAudio[i]*smooth+(1.0f-smooth)*lAudio[buffer.getNumFrames()-1];
                rAudio[i]=rAudio[i]*smooth+(1.0f-smooth)*rAudio[buffer.getNumFrames()-1];
            }
            
          


            
            
            
        }
    
    
    
    
    
  
}
   
//--------------------------------------------------------------
float ofApp::osc(float arg,float amp, int shape) {
    
    float o=0.0;
    
    if(shape==0){o=amp*sin(arg);}
    
    //test this on the scope
    if(shape==1){
        
        //o=amp*tan(arg);
    
        o=amp*(ofMap(fmod(arg/3.14,1.0),0.0,1.0,-1.0,1.0));
    
    }
    
    if(shape==2){o=amp*(abs(ofMap(fmod(arg/3.14,1.0),0.0,1.0,-1.0,1.0))*2.0f-1.0);}
    
    return o;
    
}//endosc


//----------------------------------------------------------------
float ofApp::quantize(float sample, float quantize_amount, float quantize_mix){
    float quantized=(ceil(sample*quantize_amount)+floor(sample*quantize_amount))/(2.0f*quantize_amount);
    
    return quantize_mix*quantized+(1.0f-quantize_mix)*sample;
}

//--------------------------------------------------------------
void ofApp::exit() {
	
	// clean up
	midiIn.closePort();
	midiIn.removeListener(this);
}

//--------------------------------------------------------------
void ofApp::newMidiMessage(ofxMidiMessage& msg) {

	// add the latest message to the message queue
	midiMessages.push_back(msg);

	// remove any old messages if we have too many
	while(midiMessages.size() > maxMessages) {
		midiMessages.erase(midiMessages.begin());
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

    
    
   
    //if(key=='q'){sw1==0;}
    
    if(key=='s'){sx+=0.01;}
    if(key=='x'){sx-=0.01;}
    
    if(key=='d'){dd+=0.01;}
    if(key=='c'){dd-=0.01;}
    
    if(key=='f'){ff+=0.1;}
    if(key=='v'){ff-=0.1;}
    
    if(key=='g'){xw+=0.01;}
    if(key=='b'){xw-=0.01;}
    if(key=='h'){yw+=0.01;}
    if(key=='n'){yw-=0.01;}
    
    
    if(key=='j'){jj+=0.1;}
    if(key=='m'){jj-=0.1;}
    if(key=='k'){kk+=0.1;}
    if(key==','){kk-=0.1;}
    
    if(key=='l'){ll+=0.01;}
    if(key=='.'){ll-=0.01;}
    
    if(key=='t'){tt+=0.01;}
    if(key=='y'){tt-=0.01;}
    
    if(key=='e'){ee+=0.1;}
    if(key=='r'){ee-=0.1;}
    
    
    if(key=='1'){overflow_switch=0;}
    if(key=='2'){overflow_switch=1;}
    if(key=='3'){overflow_switch=2;}
    if(key=='4'){overflow_switch=3;}
    if(key=='5'){overflow_switch=4;}
    if(key=='6'){overflow_switch=5;}
    
    
    
    
    /*
    if(key=='s'){ss+=.1;cout << "ss="<< ss<< endl;}
    if(key=='x'){ss-=.1;cout << "ss="<< ss<< endl;}
    
    if(key=='d'){dd+=.1;}
    if(key=='c'){dd-=.1;}
    
    if(key=='f'){ff+=.01;cout << "ff="<< ff<< endl;}
    if(key=='v'){ff-=.01;cout << "ff="<< ff<< endl;}
    
    
    if(key=='g'){gg+=.1;}
    if(key=='b'){gg-=.1;}
    if(key=='h'){hh+=.1;}
    if(key=='n'){hh-=.1;}
    
    if(key=='k'){kk+=.1;}
    if(key==','){kk-=.1;}
    
    if(key=='p'){pp+=.01;}
    if(key=='['){pp-=.01;}
    if(key=='i'){ii+=.1;}
    if(key=='o'){ii-=.1;}
    
    
    if(key=='1'){sw1=1;}
    if(key=='q'){sw1=0;}
    if(key=='2'){sw2=1;}
    if(key=='w'){sw2=0;}
    
    if(key=='l'){ll+=1; cout << "ll="<< ll<< endl;}
    if(key=='.'){ll-=1; cout << "ll="<< ll<< endl;}
     
     */
}
//-------------------------------
void ofApp::midibiz(){

    for(unsigned int i = 0; i < midiMessages.size(); ++i) {
        
        ofxMidiMessage &message = midiMessages[i];
        
        //cout << "envcount="<< envcount<< endl;
        
        if(message.status < MIDI_SYSEX) {
            //text << "chan: " << message.channel;
            if(message.status == MIDI_CONTROL_CHANGE) {

                ROS_INFO("Got message %d", int(message.control));
                //  cout << "message.control"<< message.control<< endl;
                //  cout << "message.value"<< message.value<< endl;
                
               
                //distortion switches
                
                if(message.control==60){
                    if(message.value==127) {overflow_switch=1;}
                    if(message.value==0) {overflow_switch=0;}
                }
                if(message.control==61){
                    if(message.value==127) {overflow_switch=2;}
                    if(message.value==0) {overflow_switch=0;}
                }
                if(message.control==62){
                    if(message.value==127) {overflow_switch=3;}
                    if(message.value==0) {overflow_switch=0;}
                }
                
                //scale switches
                if(message.control==43){
                    if(message.value==127) {scale_switch=1;}
                    if(message.value==0) {scale_switch=0;}
                }
                if(message.control==44){
                    if(message.value==127) {scale_switch=2;}
                    if(message.value==0) {scale_switch=0;}
                }
                if(message.control==42){
                    if(message.value==127) {scale_switch=3;}
                    if(message.value==0) {scale_switch=0;}
                }
                if(message.control==41){
                    if(message.value==127) {scale_switch=4;}
                    if(message.value==0) {scale_switch=0;}
                }
                if(message.control==45){
                    if(message.value==127) {scale_switch=5;}
                    if(message.value==0) {scale_switch=0;}
                }
                
                
                
                //audio oscillator switches
                if(message.control==32){
                    if(message.value==127){
                        osc_l_switch=1;
                    }
                    
                    if(message.value==0){
                        osc_l_switch=0;
                    }
                }
                
                if(message.control==33){
                    if(message.value==127){
                        osc_r_switch=1;
                    }
                    
                    if(message.value==0){
                        osc_r_switch=0;
                    }
                }
                
                //ampmod switches
                if(message.control==34){
                    if(message.value==127){
                        ampmod_osc_l_switch=1;
                    }
                    
                    if(message.value==0){
                        ampmod_osc_l_switch=0;
                    }
                }
                
                
                if(message.control==35){
                    if(message.value==127){
                        ampmod_osc_r_switch=1;
                    }
                    
                    if(message.value==0){
                        ampmod_osc_r_switch=0;
                    }
                }
                
                //phasemod switches
                if(message.control==36){
                    if(message.value==127){
                        phasemod_osc_l_switch=1;
                    }
                    
                    if(message.value==0){
                        phasemod_osc_l_switch=0;
                    }
                }
                
                if(message.control==37){
                    if(message.value==127){
                        phasemod_osc_r_switch=1;
                    }
                    
                    if(message.value==0){
                        phasemod_osc_r_switch=0;
                    }
                }
                
                
                //quantize switches
                
                if(message.control==38){
                    if(message.value==127){
                        quantize_osc_l_switch=1;
                    }
                    if(message.value==0){
                        quantize_osc_l_switch=0;
                    }
                }
                
                if(message.control==39){
                    if(message.value==127){
                        quantize_osc_r_switch=1;
                    }
                    if(message.value==0){
                        quantize_osc_r_switch=0;
                    }
                }

                //quantize mod oscs
                //left
                if(message.control==54){
                    if(message.value==127){
                        quantize_mod_l_switch=1;
                        
                    }
                    if(message.value==0){
                        quantize_mod_l_switch=0;
                       
                    }
                }
                
                if(message.control==70){
                    if(message.value==127){
                        quantize_mod_l_switch=2;
                        
                    }
                    if(message.value==0){
                        quantize_mod_l_switch=0;
                        
                    }
                }
                
                //right
                if(message.control==55){
                    if(message.value==127){
                        quantize_mod_r_switch=1;
                        
                    }
                    if(message.value==0){
                        quantize_mod_r_switch=0;
                        
                    }
                }
                
                if(message.control==71){
                    if(message.value==127){
                        quantize_mod_r_switch=2;
                        
                    }
                    if(message.value==0){
                        quantize_mod_r_switch=0;
                        
                    }
                }

                //oscilltor shapes
                
                //left audio shapes
                if(message.control==48){
                    if(message.value==127){
                        if(osc_l_switch==0){
                            osc_l1_shape=1;
                        }
                        
                        if(osc_l_switch==1){
                            osc_l2_shape=1;
                        }
                        
                    }
                    
                    if(message.value==0){
                        if(osc_l_switch==0){
                            osc_l1_shape=0;
                        }
                        
                        if(osc_l_switch==1){
                            osc_l2_shape=0;
                        }
                    }
                    
                }
                
                if(message.control==64){
                    if(message.value==127){
                        if(osc_l_switch==0){
                            osc_l1_shape=2;
                        }
                        
                        if(osc_l_switch==1){
                            osc_l2_shape=2;
                        }
                        
                    }
                    
                    if(message.value==0){
                        if(osc_l_switch==0){
                            osc_l1_shape=0;
                        }
                        
                        if(osc_l_switch==1){
                            osc_l2_shape=0;
                        }
                    }
                    
                }
                
                //right audio shapes
                if(message.control==49){
                    if(message.value==127){
                        if(osc_r_switch==0){
                            osc_r1_shape=1;
                        }
                        
                        if(osc_r_switch==1){
                            osc_r2_shape=1;
                        }
                        
                    }
                    
                    if(message.value==0){
                        if(osc_r_switch==0){
                            osc_r1_shape=0;
                        }
                        
                        if(osc_r_switch==1){
                            osc_r2_shape=0;
                        }
                    }
                    
                }
                
                if(message.control==65){
                    if(message.value==127){
                        if(osc_r_switch==0){
                            osc_r1_shape=2;
                        }
                        
                        if(osc_r_switch==1){
                            osc_r2_shape=2;
                        }
                        
                    }
                    
                    if(message.value==0){
                        if(osc_r_switch==0){
                            osc_r1_shape=0;
                        }
                        
                        if(osc_r_switch==1){
                            osc_r2_shape=0;
                        }
                    }
                    
                }
                
                //left ampmod shapes
                if(message.control==50){
                    if(message.value==127){
                        if(ampmod_osc_l_switch==0){
                            ampmod_osc_l1_shape=1;
                        }
                        
                        if(ampmod_osc_l_switch==1){
                            ampmod_osc_l2_shape=1;
                        }
                        
                    }
                    
                    if(message.value==0){
                        if(ampmod_osc_l_switch==0){
                            ampmod_osc_l1_shape=0;
                        }
                        
                        if(ampmod_osc_l_switch==1){
                            ampmod_osc_l2_shape=0;
                        }
                    }
                    
                }
                
                if(message.control==66){
                    if(message.value==127){
                        if(ampmod_osc_l_switch==0){
                            ampmod_osc_l1_shape=2;
                        }
                        
                        if(ampmod_osc_l_switch==1){
                            ampmod_osc_l2_shape=2;
                        }
                        
                    }
                    
                    if(message.value==0){
                        if(ampmod_osc_l_switch==0){
                            ampmod_osc_l1_shape=0;
                        }
                        
                        if(ampmod_osc_l_switch==1){
                            ampmod_osc_l2_shape=0;
                        }
                    }
                    
                }
                
                //right ampmod shapes
                if(message.control==51){
                    if(message.value==127){
                        if(ampmod_osc_r_switch==0){
                            ampmod_osc_r1_shape=1;
                        }
                        
                        if(ampmod_osc_r_switch==1){
                            ampmod_osc_r2_shape=1;
                        }
                        
                    }
                    
                    if(message.value==0){
                        if(ampmod_osc_r_switch==0){
                            ampmod_osc_r1_shape=0;
                        }
                        
                        if(ampmod_osc_r_switch==1){
                            ampmod_osc_r2_shape=0;
                        }
                    }
                    
                }
                
                if(message.control==67){
                    if(message.value==127){
                        if(ampmod_osc_r_switch==0){
                            ampmod_osc_r1_shape=2;
                        }
                        
                        if(ampmod_osc_r_switch==1){
                            ampmod_osc_r2_shape=2;
                        }
                        
                    }
                    
                    if(message.value==0){
                        if(ampmod_osc_r_switch==0){
                            ampmod_osc_r1_shape=0;
                        }
                        
                        if(ampmod_osc_r_switch==1){
                            ampmod_osc_r2_shape=0;
                        }
                    }
                    
                }
                
                //left phasemod shapes
                if(message.control==52){
                    if(message.value==127){
                        if(phasemod_osc_l_switch==0){
                            phasemod_osc_l1_shape=1;
                        }
                        
                        if(phasemod_osc_l_switch==1){
                            phasemod_osc_l2_shape=1;
                        }
                        
                    }
                    
                    if(message.value==0){
                        if(phasemod_osc_l_switch==0){
                            phasemod_osc_l1_shape=0;
                        }
                        
                        if(phasemod_osc_l_switch==1){
                            phasemod_osc_l2_shape=0;
                        }
                    }
                    
                }
                
                if(message.control==68){
                    if(message.value==127){
                        if(phasemod_osc_l_switch==0){
                            phasemod_osc_l1_shape=2;
                        }
                        
                        if(phasemod_osc_l_switch==1){
                            phasemod_osc_l2_shape=2;
                        }
                        
                    }
                    
                    if(message.value==0){
                        if(phasemod_osc_l_switch==0){
                            phasemod_osc_l1_shape=0;
                        }
                        
                        if(phasemod_osc_l_switch==1){
                            phasemod_osc_l2_shape=0;
                        }
                    }
                    
                }
                
                //right phasemod shapes
                if(message.control==53){
                    if(message.value==127){
                        if(phasemod_osc_r_switch==0){
                            phasemod_osc_r1_shape=1;
                        }
                        
                        if(phasemod_osc_r_switch==1){
                            phasemod_osc_r2_shape=1;
                        }
                        
                    }
                    
                    if(message.value==0){
                        if(phasemod_osc_r_switch==0){
                            phasemod_osc_r1_shape=0;
                        }
                        
                        if(phasemod_osc_r_switch==1){
                            phasemod_osc_r2_shape=0;
                        }
                    }
                    
                }
                
                if(message.control==69){
                    if(message.value==127){
                        if(phasemod_osc_r_switch==0){
                            phasemod_osc_r1_shape=2;
                        }
                        
                        if(phasemod_osc_r_switch==1){
                            phasemod_osc_r2_shape=2;
                        }
                        
                    }
                    
                    if(message.value==0){
                        if(phasemod_osc_r_switch==0){
                            phasemod_osc_r1_shape=0;
                        }
                        
                        if(phasemod_osc_r_switch==1){
                            phasemod_osc_r2_shape=0;
                        }
                    }
                    
                }


                
                //knobby bits
                if(message.control==16){
                    // c1=(message.value-63.0)/63.0;
                   // c1=(message.value)/127.0f;
                    
                    
                    if(osc_l_switch==0){
                        osc_l1_amp=2*message.value/127.0f;
                    }
                    
                    if(osc_l_switch==1){
                        osc_l2_amp=message.value/127.0f;
                    }
                    
                }
                
                
                if(message.control==17){
                     //c2=(message.value-63.0)/63.0;
                   // c2=(message.value)/127.0f;
                    
                    if(osc_r_switch==0){
                        osc_r1_amp=2*message.value/127.0f;
                    }
                    
                    if(osc_r_switch==1){
                        osc_r2_amp=message.value/127.0f;
                    }
                    
                }
                
                
                if(message.control==18){
                    //c3=(message.value-63.0)/63.0f;
                    //c3=(message.value)/127.0f;
                    if(ampmod_osc_l_switch==0){
                        ampmod_osc_l1_amp=message.value/127.0f;
                    }
                    
                    if(ampmod_osc_l_switch==1){
                        ampmod_osc_l2_amp=message.value/127.0f;
                    }
                }
                
                
                if(message.control==19){
                   // c4=(message.value-63.0)/63.0f;
                    // c4=(message.value)/127.0f;
                    
                    if(ampmod_osc_r_switch==0){
                        ampmod_osc_r1_amp=message.value/127.0f;
                    }
                    
                    if(ampmod_osc_r_switch==1){
                        ampmod_osc_r2_amp=message.value/127.0f;
                    }
                    
                }
                
                
                float pm_amp=16.0;
                
                if(message.control==20){
                   // c5=(message.value-63.0)/63.0f;
                    //  c5=(message.value)/127.0f;
                    if(phasemod_osc_l_switch==0){
                        phasemod_osc_l1_amp=pm_amp*message.value/127.0f;
                    }
                    
                    if(phasemod_osc_l_switch==1){
                        phasemod_osc_l2_amp=pm_amp*message.value/127.0f;
                    }
                    
                }
                
                
                
                
                if(message.control==21){
                   // c6=(message.value-63.0)/63.0;
                    // c6=(message.value)/127.0f;
                    
                    if(phasemod_osc_r_switch==0){
                        phasemod_osc_r1_amp=pm_amp*message.value/127.0f;
                    }
                    
                    if(phasemod_osc_r_switch==1){
                        phasemod_osc_r2_amp=pm_amp*message.value/127.0f;
                    }
                }
                
                
                if(message.control==22){
                   // c7=(message.value-63.0)/63.0;
                     //  c7=(message.value)/127.0f;
                    //ampmod switching
                     if(quantize_osc_l_switch==0){
                         if(quantize_mod_l_switch==0){
                             quantize_mix_l1=(message.value)/127.0f;
                         }
                         if(quantize_mod_l_switch==1){
                             quantize_mix_ampmod_l1=(message.value)/127.0f;
                         }
                         
                         if(quantize_mod_l_switch==2){
                             quantize_mix_phasemod_l1=(message.value)/127.0f;
                         }
                     }
                    if(quantize_osc_l_switch==1){
                        if(quantize_mod_l_switch==0){
                            quantize_mix_l2=(message.value)/127.0f;
                        }
                        if(quantize_mod_l_switch==1){
                            quantize_mix_ampmod_l2=(message.value)/127.0f;
                        }
                        
                        if(quantize_mod_l_switch==2){
                            quantize_mix_phasemod_l2=(message.value)/127.0f;
                        }
                    }
                    
                    
                    
                }
                
                
                if(message.control==23){
                    // c8=(message.value-63.0)/63.0f;
                   // c8=(message.value)/127.0;
                    if(quantize_osc_r_switch==0){
                        if(quantize_mod_r_switch==0){
                            quantize_mix_r1=(message.value)/127.0f;
                        }
                        if(quantize_mod_r_switch==1){
                            quantize_mix_ampmod_r1=(message.value)/127.0f;
                        }
                        
                        if(quantize_mod_r_switch==2){
                            quantize_mix_phasemod_r1=(message.value)/127.0f;
                        }
                    }
                    if(quantize_osc_r_switch==1){
                        if(quantize_mod_r_switch==0){
                            quantize_mix_r2=(message.value)/127.0f;
                        }
                        if(quantize_mod_r_switch==1){
                            quantize_mix_ampmod_r2=(message.value)/127.0f;
                        }
                        
                        if(quantize_mod_r_switch==2){
                            quantize_mix_phasemod_r2=(message.value)/127.0f;
                        }
                    }

                }
                
                
                
                if(message.control==120){
                    //  c9=(message.value-63.0)/63.0;
                   // c9=(message.value)/127.0f;
                    
                    if(osc_l_switch==0){
                        osc_l1_midi=(message.value-63.0)/63.0;
                    }
                    
                    if(osc_l_switch==1){
                        osc_l2_midi=(message.value-63.0)/63.0;
                    }
                    
                }
                
                if(message.control==121){
                    //c10=(message.value-63.0)/63.0;
                   // c10=(message.value)/127.0f;
                    
                    if(osc_r_switch==0){
                        osc_r1_midi=(message.value-63.0)/63.0;
                    }
                    
                    if(osc_r_switch==1){
                        osc_r2_midi=(message.value-63.0)/63.0;
                    }
                    
                }
                
                if(message.control==122){
                    //c11=(message.value-63.0)/63.0f;
                   // c11=(message.value)/127.0f;
                    
                    if(ampmod_osc_l_switch==0){
                        ampmod_osc_l1_midi=(message.value-63.0)/63.0;
                    }
                    
                    if(ampmod_osc_l_switch==1){
                        ampmod_osc_l2_midi=(message.value-63.0)/63.0;
                    }
                }
                
                
                if(message.control==123){
                    // c12=(message.value-63.0)/63.0f;
                   // c12=(message.value)/127.0f;
                    
                    if(ampmod_osc_r_switch==0){
                        ampmod_osc_r1_midi=(message.value-63.0)/63.0;
                        
                    }
                    
                    if(ampmod_osc_r_switch==1){
                        ampmod_osc_r2_midi=(message.value-63.0)/63.0;
                    }
                }
                
                if(message.control==124){
                    //c13=(message.value-63.0)/63.0f;
                    //c13=(message.value)/127.0f;
                    
                    if(phasemod_osc_l_switch==0){
                        phasemod_osc_l1_midi=(message.value-63.0)/63.0;
                        
                        //phasemod_osc_l1_midi=(message.value)/127.0f-1.0f;

                    }
                    
                    if(phasemod_osc_l_switch==1){
                        
                        phasemod_osc_l2_midi=(message.value-63.0)/63.0;
                        //phasemod_osc_l2_midi=(message.value)/127.0f-1.0f;
                    }
                    
                }
                
                if(message.control==125){
                    //c14=(message.value-63.0)/63.0;
                    //c14=(message.value)/127.0f;
                    
                    if(phasemod_osc_r_switch==0){
                        phasemod_osc_r1_midi=(message.value-63.0)/63.0;
                        //phasemod_osc_r1_midi=(message.value)/127.0-1.0f;
                    }
                    
                    if(phasemod_osc_r_switch==1){
                        phasemod_osc_r2_midi=(message.value-63.0)/63.0;
                        //phasemod_osc_r2_midi=(message.value)/127.0-1.0f;
                    }
                }
                
                if(message.control==126){
                    //c15=(message.value-63.0)/63.0;
                    //c15=(message.value)/127.0f;
                    
                   
                    if(quantize_osc_l_switch==0){
                        
                        if(quantize_mod_l_switch==0){
                            quantize_amount_l1=24.0f*(message.value)/127.0f+1.0f;
                        }
                        if(quantize_mod_l_switch==1){
                            quantize_amount_ampmod_l1=24.0f*(message.value)/127.0f+1.0f;
                        }
                        
                        if(quantize_mod_l_switch==2){
                            quantize_amount_phasemod_l1=24.0f*(message.value)/127.0f+1.0f;
                        }
                    }
                
                    if(quantize_osc_l_switch==1){
                        if(quantize_mod_l_switch==0){
                            quantize_amount_l2=24.0f*(message.value)/127.0f+1.0f;
                        }
                        if(quantize_mod_l_switch==1){
                            quantize_amount_ampmod_l2=24.0f*(message.value)/127.0f+1.0f;
                        }
                    }
                    
                    
                }
                
                if(message.control==127){
                    //c16=(message.value-63.0)/63.0f;
                    //c16=(message.value)/127.0;
                    if(quantize_osc_r_switch==0){
                        
                        if(quantize_mod_r_switch==0){
                            quantize_amount_r1=24.0f*(message.value)/127.0f+1.0f;
                        }
                        if(quantize_mod_r_switch==1){
                            quantize_amount_ampmod_r1=24.0f*(message.value)/127.0f+1.0f;
                        }
                        
                        if(quantize_mod_r_switch==2){
                            quantize_amount_phasemod_r1=24.0f*(message.value)/127.0f+1.0f;
                        }
                    }
                    
                    if(quantize_osc_r_switch==1){
                        if(quantize_mod_r_switch==0){
                            quantize_amount_r2=24.0f*(message.value)/127.0f+1.0f;
                        }
                        if(quantize_mod_r_switch==1){
                            quantize_amount_ampmod_r2=24.0f*(message.value)/127.0f+1.0f;
                        }
                    }

                }


                
                //text << "\tctl: " << message.control;
                //ofDrawRectangle(x + ofGetWidth()*0.2, y + 12,
                //	ofMap(message.control, 0, 127, 0, ofGetWidth()*0.2), 10);
            }
            
            
            //text << " "; // pad for delta print
        }//
        
        
    }
    midiMessages.clear(); //clear the queue once processing all of it
    
}
                    
   

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    
}

//--------------------------------------------------------------




//--------------------------------------------------------------




//--------------------------------------------------------------


