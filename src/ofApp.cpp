#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetWindowTitle("COMpooter");
    ofSetFrameRate(60);
    ofxGuiSetFont("SourceCodePro-Regular.ttf", 24, true, true);
    ofxGuiSetTextPadding(4);
    ofxGuiSetDefaultWidth(450);
    ofxGuiSetDefaultHeight(36);

    // Allocate the rendering buffer
    m_fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);

    // GUI 
    m_gui.setup("Parameters", "settings.xml");
    m_gui.add(m_countX.setup("countX", 50, 0, 200));
    m_gui.add(m_stepX.setup("stepX", 20, 0, 200));
    m_gui.add(m_twistX.setup("twistX", 5, -45, 45));

    m_gui.add(countY.setup("countY", 0, 0, 50));
    m_gui.add(stepY.setup("stepY", 20, 0, 200));
    m_gui.add(twistY.setup("twistY", 0, -30, 30));
    m_gui.add(pinchY.setup("pinchY", 0, 0, 1));

    m_globalGroup.setup("Global");
    m_globalGroup.add(m_scale.setup("Scale", 1, 0.0, 1));
    m_globalGroup.add(m_rotateGlobal.setup("rotate", 0, -180, 180));
    m_globalGroup.add(m_background.setup("Background", 255, 0, 255));
    m_gui.add(&m_globalGroup);

    m_primitiveGroup.setup("Primitive");
    m_primitiveGroup.add(m_lineWidth.setup("lineWidth", 1, 0, 7.5f));
    m_primitiveGroup.add(m_shiftY.setup("shiftY", 0.0, -1000.0, 1000.0));
    m_primitiveGroup.add(m_rotate.setup("rotate", 0.0, -180.0, 180.0));
    m_primitiveGroup.add(m_size.setup("size", 
        ofVec2f(6, 6),
        ofVec2f(0, 0),
        ofVec2f(20, 20)));
    m_primitiveGroup.add(m_backgroundColor.setup("backgroundColor",
        ofColor::black,
        ofColor(0, 0, 0, 0),
        ofColor::white));
    m_primitiveGroup.add(m_primitiveColor.setup("primitiveColor",
        ofColor::black,
        ofColor(0, 0, 0, 0),
        ofColor::white));
    m_primitiveGroup.add(m_filled.setup("filled", false));
    m_primitiveGroup.add(m_type.setup("type", false));
    m_gui.add(&m_primitiveGroup);

    m_fileGroup.setup("File");
    m_fileGroup.add(m_fileNumber.setup("fileNumber", 0, 0, 100000));
    m_gui.add(&m_fileGroup);

    m_gui.loadFromFile("settings.xml");
}

//--------------------------------------------------------------
void ofApp::update()
{
    m_fbo.begin();
    m_fbo.end();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofClear(255, 255, 255, 255);
    ofBackground(m_backgroundColor);
    ofSetColor(m_primitiveColor);
    ofSetLineWidth(m_lineWidth);
    {
        ofPushMatrix();
        ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
        float scale = pow(m_scale, 4.0f);
        ofScale(scale, scale);
        ofRotate(m_rotateGlobal);
        matrixPattern();
        ofPopMatrix();
    }

    // Take a screenshot without the GUI
    if (m_screenshotQueued)
    {
        takeScreenshot();
    }

    if (m_drawGui)
    {
        m_gui.draw();
        // Take a screenshot with the GUI
        if (m_screenshotQueued)
        {
            takeScreenshot();
        }
    }

    m_screenshotQueued = false;
}

void ofApp::takeScreenshot()
{
    int fileNumber = m_fileNumber;
    ofSaveScreen("screenshot" + ofToString(fileNumber, 0) + ".png");
    m_fileNumber = fileNumber + 1;
}

void ofApp::exit()
{
    m_gui.saveToFile("settings.xml");
}

void ofApp::stripePattern()
{
    m_filled ? ofFill() : ofNoFill();
    for (int i = -1 * m_countX; i <= m_countX; i++)
    {
        ofPushMatrix();
        ofTranslate(i * m_stepX, 0);
        ofRotate(i * m_twistX);
        ofTranslate(0, m_shiftY);
        ofRotate(m_rotate);
        ofScale(m_size->x, m_size->y);
        if (m_type)
        {
            ofRect(-50, -50, 100, 100);
        }
        else
        {
            ofTriangle(0, 0, -50, 100, 50, 100);
        }

        ofPopMatrix();
    }
}

void ofApp::matrixPattern()
{
    for (int y = -countY; y <= countY; y++)
    {
        ofPushMatrix();
        //---------------------
        if (countY > 0)
        {
            float scl = ofMap(y, -countY, countY, 1 - pinchY, 1);
            ofScale(scl, scl);
        }
        ofTranslate(0, y * stepY);
        ofRotate(y * twistY);
        stripePattern();
        //---------------------
        ofPopMatrix();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == 'z')
    {
        m_drawGui = !m_drawGui;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    if (key == OF_KEY_RETURN)
    {
        m_screenshotQueued = true;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}
