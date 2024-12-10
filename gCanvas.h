 /*
 * gCanvas.h
 *
 *  Created on: May 6, 2020
 *      
 */

#ifndef GCANVAS_H_
#define GCANVAS_H_

#include "gBaseCanvas.h"
#include "gApp.h"
#include "gImage.h"
#include "gipOpenNN.h"
#include "gGUISizer.h"
#include "gGUIPanel.h"
#include "gGUIButton.h"
//#include "gGUIButton.h
#include "gGUITextbox.h"
#include "gGUItext.h"

class gCanvas : public gBaseCanvas {
public:
	gCanvas(gApp* root);
	virtual ~gCanvas();

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void charPressed(unsigned int codepoint);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseScrolled(int x, int y);
	void mouseEntered();
	void mouseExited();
	void windowResized(int w, int h);

	void showNotify();
	void hideNotify();

private:
	gApp* root;
	gImage logo;
	gipOpenNN ai;
	//main frame
	gGUIFrame mainframe;
	gGUISizer mainframesizer;
	void mainframeSetup();
	//Top panel
	gGUIPanel toppanel;
	gGUISizer toppanelsizer;
	gGUIButton trainbutton;
	void toppanelSetup();
	//calculate panel
	gGUIPanel calculatepanel;
	gGUISizer calculatepanelsizer;
	gGUIButton calculatebutton;
	void calculatepanelSetup();
	gGUITextbox textbox[9];
	gGUIText text[9];



};

#endif /* GCANVAS_H_ */
