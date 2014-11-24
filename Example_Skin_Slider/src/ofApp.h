#ifndef TESTAPP
#define TESTAPP

#include "ofMain.h"
#include "ofxUI.h"

class ofxSDTile;
class ofxSDRectFrame;
class ofxSDCornerEdgeFill;

class Skin_RectFill
{
public:
	Skin_RectFill(
		string imgCorner, 
		string imgEdge, 
		string imgFill);
	~Skin_RectFill();

	ofPtr<ofImage> ICorner;
	ofPtr<ofImage> IEdge;
	ofPtr<ofImage> IFill;
	ofPtr<ofxSDTile> TileEdge;
	ofPtr<ofxSDTile> TileFill;
	ofPtr<ofxSDCornerEdgeFill> Skin;
};



class ofApp : public ofBaseApp 
{
	public:
	void setup();
	void update();
	void draw();
	void exit(); 

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
	ofxUISuperCanvas *gui0;
	ofxUISuperCanvas *gui1;

	// skin
	ofPtr<Skin_RectFill> SkinCan;	
	ofPtr<Skin_RectFill> SkinSliderFill;
	ofPtr<ofImage> ISliderOutline;
	ofPtr<ofxSDRectFrame> SkinSliderOutline;
	
	void guiEvent(ofxUIEventArgs &e);

	bool drawPadding;
	float red, green, blue;    
};

#endif