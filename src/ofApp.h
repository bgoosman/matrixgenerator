#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp
{

public:
    void setup();
    void update();
    void draw();
    void stripePattern();
    void exit();
    void matrixPattern();
    void takeScreenshot();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    bool m_drawGui = true;
    bool m_screenshotQueued = false;
    ofFbo m_fbo;
    ofxPanel m_gui;
    ofxIntSlider m_countX;
    ofxFloatSlider m_stepX;
    ofxFloatSlider m_twistX;
    ofxGuiGroup m_globalGroup;
    ofxFloatSlider m_scale;
    ofxFloatSlider m_rotateGlobal;
    ofxFloatSlider m_background;
    ofxGuiGroup m_primitiveGroup;
    ofxFloatSlider m_rotate;
    ofxFloatSlider m_shiftY;
    ofxFloatSlider m_lineWidth;
    ofxVec2Slider m_size;
    ofxColorSlider m_primitiveColor;
    ofxColorSlider m_backgroundColor;
    ofxToggle m_filled;
    ofxToggle m_type;
    ofxGuiGroup m_fileGroup;
    ofxIntSlider m_fileNumber;
    ofxIntSlider countY;
    ofxFloatSlider stepY, twistY, pinchY;
};
