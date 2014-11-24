#include "ofApp.h"
#include "ofxScalableDraws.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofEnableSmoothing(); 
	ofSetCircleResolution(60);
	
	red = 100; blue = 100; green = 100;
	drawPadding = false; 
	
	gui0 = new ofxUISuperCanvas("SLIDER WIDGETS");
	//gui0->setColorBack(ofColor(0,0,0,0));
	gui0->setColorPadded(ofColor(0,0,0,0));
	gui0->setColorPaddedOutline(ofColor(0,0,0,0));
	//gui0->setColorBack(ofColor::white);
	gui0->setColorOutline(ofColor(255,255,255,255));
	gui0->setColorOutlineHighlight(ofColor::green);
	gui0->setColorFill(ofColor(255,255,255,255));
	gui0->setColorFillHighlight(ofColor::white);

	gui0->addSpacer();
	gui0->addFPSSlider("FPS SLIDER");

	gui0->addSpacer();
	gui0->addLabel("NORMAL SLIDER");
	gui0->addSlider("RED", 0.0, 255.0, &red);
	
	gui0->addSpacer();
	gui0->addLabel("MINIMAL SLIDER");
	gui0->addMinimalSlider("GREEN", 0.0, 255.0, &green);
	
	gui0->addSpacer();
	gui0->addLabel("BILABEL SLIDER");
	gui0->addBiLabelSlider("BLUE", "LESS BLUE", "MORE BLUE", 0.0, 255.0, &blue);

	gui0->addSpacer();
	gui0->addLabel("VERTICAL SLIDERS"); 
	gui0->addSlider("1", 0.0, 255.0, 100.0, 17, 64);
	gui0->setWidgetPosition(OFX_UI_WIDGET_POSITION_RIGHT);
	gui0->addSlider("2", 0.0, 255.0, 150.0, 17, 64);
	gui0->addSlider("3", 0.0, 255.0, 200.0, 17, 64);
	gui0->addSlider("4", 0.0, 255.0, 250.0, 17, 64);
	gui0->addSlider("5", 0.0, 255.0, 250.0, 17, 64);
	gui0->addSlider("6", 0.0, 255.0, 250.0, 17, 64);
	gui0->addSlider("7", 0.0, 255.0, 250.0, 17, 64);
	gui0->addSlider("8", 0.0, 255.0, 250.0, 17, 64);
	gui0->addSlider("9", 0.0, 255.0, 250.0, 17, 64);
	gui0->setWidgetPosition(OFX_UI_WIDGET_POSITION_DOWN);

	gui0->addSpacer();
	gui0->addLabel("RANGE SLIDER");
	gui0->addRangeSlider("RANGE", 0.0, 255.0, &blue, &green);

	gui0->addSpacer();
	gui0->addLabel("TEMPLATED SLIDERS");
	gui0->addIntSlider("INT SLIDER", 0, 100, 50);
	gui0->addSlider("FLOAT SLIDER", 0.0, 100.0, 50.0);
	gui0->addDoubleSlider("DOUBLE SLIDER", 0.0, 100.0, 50.0);

	gui0->addSpacer();
	gui0->addLabel("ROTARY SLIDER");
	gui0->addRotarySlider("ROTARY", 0.0, 255.0, &red);

	gui0->autoSizeToFitWidgets();
	ofAddListener(gui0->newGUIEvent,this,&ofApp::guiEvent);
		
	gui1 = new ofxUISuperCanvas("MORE SLIDERS");
	//gui1->setColorBack(ofColor(0,0,0,0));
	gui1->setColorPadded(ofColor(0,0,0,0));
	gui1->setPosition(212, 0);
	
	gui1->addSpacer();
	gui1->addLabel("2D PAD");
	gui1->add2DPad("PAD", ofVec2f(-100, 100), ofVec2f(-100, 100), ofVec2f(0, 0));
	gui1->addSpacer();
	gui1->addLabel("CIRCLE SLIDER");
	gui1->addCircleSlider("GREEN", 0.0, 255.0, &green);
	gui1->addSpacer();
	gui1->addLabel("IMAGE SLIDER");
	gui1->setGlobalSliderHeight(32);
	gui1->addImageSlider("IMAGE SLIDER", "slider.png", 0.0, 255.0, 100.0);
	gui1->autoSizeToFitWidgets();
	ofAddListener(gui1->newGUIEvent,this,&ofApp::guiEvent);
	

	SkinCan.reset(new Skin_RectFill("Corner.jpg","Edge.jpg","Fill.jpg"));
	SkinSliderFill.reset(new Skin_RectFill("SCorner.png","SEdge.png","SFill.jpg"));
	SkinSliderFill->Skin->setEdge(5.0f);
	ISliderOutline.reset(new ofImage);
	ISliderOutline->loadImage("SliderOutline.png");
	SkinSliderOutline.reset(
		new ofxSDRectFrame(ISliderOutline,8.0f,6.0f,
		ofxSDRectFrame::RECTFRAME_CENTER));

	ofxUICanvas* gui[2] = {gui0,gui1};
	for(int i=0;i<2;i++)
	{
		gui[i]->set_skin_padded(SkinCan->Skin);
		gui[i]->setDrawPadding(true);
		gui[i]->setPadding(40.0f);
		gui[i]->setColorPadded(ofColor(200,200,200,255));
		//gui[i]->setColorBack(ofColor(255,255,255,255));
		gui[i]->setColorOutline(ofColor::white);
		gui[i]->setColorFill(ofColor(255,255,255,255));
		gui[i]->setColorFillHighlight(ofColor(255,255,255,255));

		vector<ofxUIWidget*> wds = gui[i]->getWidgets();
		vector<ofxUIWidget*>::iterator it;
		for(it = wds.begin();it<wds.end();it++)
		{
			ofxUIWidget* wd = *it;

			//wd->setDrawFill(true);
			//wd->set_skin_fill(SkinSliderFill->Skin);

			ofxUISlider* sd = dynamic_cast<ofxUISlider*>(wd);
			if(sd!=NULL)
			{
				sd->setDrawFill(true);
				sd->set_skin_fill(SkinSliderFill->Skin);
				sd->setDrawOutline(true);
				sd->set_skin_outline(SkinSliderOutline);
				sd->set_skin_outLine_highlight(SkinSliderOutline);
			}			
		}
	}
	





	ofBackground(red, green, blue);
}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackground(red, green, blue, 255);
}
//--------------------------------------------------------------
void ofApp::guiEvent(ofxUIEventArgs &e)
{

}
//--------------------------------------------------------------
void ofApp::exit()
{
	delete gui0;
	delete gui1;
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	switch (key) 
	{
		case 'p':
		{
			drawPadding = !drawPadding; 
			gui0->setDrawWidgetPadding(drawPadding);          
		}
			break;
			
		case 'g':
		{
			gui0->toggleVisible(); 
		}
			break; 
		default:
			break;
	}
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{ 
//	gui0->getRect()->setHeight(y);
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
void ofApp::windowResized(int w, int h)
{
 

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

Skin_RectFill::Skin_RectFill( string imgCorner, string imgEdge, string imgFill )
{
	ICorner.reset(new ofImage);
	IEdge.reset(new ofImage);
	IFill.reset(new ofImage);

	ICorner->loadImage(imgCorner);
	IEdge->loadImage(imgEdge);
	IFill->loadImage(imgFill);

	TileEdge.reset(new ofxSDTile(IEdge,true,false));
	TileFill.reset(new ofxSDTile(IFill));

	Skin.reset(new ofxSDCornerEdgeFill(ICorner,TileEdge,TileFill,40));
}

Skin_RectFill::~Skin_RectFill()
{

}
