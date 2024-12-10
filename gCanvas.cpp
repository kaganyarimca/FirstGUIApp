/*
* gCanvas.cpp
*
*  Created on: May 6, 2020
*      
*/


#include "gCanvas.h"


gCanvas::gCanvas(gApp* root) : gBaseCanvas(root) {
	this->root = root;
}

gCanvas::~gCanvas() {
}

void gCanvas::setup() {
	logo.loadImage("glistengine_logo.png");
	ai.loadDatasetFile("breast_cancer.csv", ';', true);
	mainframeSetup();
	toppanelSetup();
	calculatepanelSetup();
}

void gCanvas::update() {
}

void gCanvas::draw() {
	logo.draw((getWidth() - logo.getWidth()) / 2, (getHeight() - logo.getHeight()) / 2);
}

void gCanvas::keyPressed(int key) {
//	gLogi("gCanvas") << "keyPressed:" << key;
}

void gCanvas::keyReleased(int key) {
//	gLogi("gCanvas") << "keyReleased:" << key;
}

void gCanvas::charPressed(unsigned int codepoint) {
//	gLogi("gCanvas") << "charPressed:" << gCodepointToStr(codepoint);
}

void gCanvas::mouseMoved(int x, int y) {
//	gLogi("gCanvas") << "mouseMoved" << ", x:" << x << ", y:" << y;
}

void gCanvas::mouseDragged(int x, int y, int button) {
//	gLogi("gCanvas") << "mouseDragged" << ", x:" << x << ", y:" << y << ", b:" << button;
}

void gCanvas::mousePressed(int x, int y, int button) {
//	gLogi("gCanvas") << "mousePressed" << ", x:" << x << ", y:" << y << ", b:" << button;
}

void gCanvas::mouseReleased(int x, int y, int button) {
//	gLogi("gCanvas") << "mouseReleased" << ", button:" << button;
}

void gCanvas::mouseScrolled(int x, int y) {
//	gLogi("gCanvas") << "mouseScrolled" << ", x:" << x << ", y:" << y;
}

void gCanvas::mouseEntered() {

}

void gCanvas::mouseExited() {

}

void gCanvas::windowResized(int w, int h) {

}

void gCanvas::showNotify() {

}

void gCanvas::hideNotify() {

}

void gCanvas::mainframeSetup() {
	//main frame'i ana pencere(frame)olarak atiyoruz
	root->getAppManager()->getGUIManager()->setCurrentFrame(&mainframe);
	root->getAppManager()->getGUIManager()->setTheme(gGUIManager::GUITHEME_LIGHT);
	//sizer(ayar dosyasi eklenecek)
	mainframe.setSizer(&mainframesizer);
	//mainframe'in ayarlar� sizer'a (ayar dosyasi) eklenecek.
	mainframesizer.setSize(3, 1);
	mainframesizer.enableBorders(true);
	mainframesizer.enableResizing(true);
	//satir boyutlari toplami 1.0f olacak(%100)
	float satirboyutu[3] = {0.15f, 0.7f, 0.15f};
	mainframesizer.setLineProportions(satirboyutu);
}

void gCanvas::toppanelSetup() {
	//panel ayarlari
	toppanelsizer.setSize(1, 1);
	toppanelsizer.enableBorders(true);
	//panel'e atandi.
	toppanel.setSizer(&toppanelsizer);
	//panel'i frame'e yerlestiriyoruz.
	mainframesizer.setControl(0, 0, &toppanel);
	//train button
	toppanelsizer.setControl(0, 0, &trainbutton);
	trainbutton.setTitle("Train");
}

void gCanvas::calculatepanelSetup(){
	//panelin ayarlari
	calculatepanelsizer.setSize(5, 6);
	calculatepanelsizer.enableBorders(true);
	float sutunboyutu[] ={0.05f, 0.19f, 0.19f, 0.19f, 0.19f, 0.19f};
	calculatepanelsizer.setColumnProportions(sutunboyutu);
	//sizer'i panele ekle
	calculatepanel.setSizer(&calculatepanelsizer);

	//panelin ayarlarini sizer'a ekle

	//panel'i mainframe'e ekle.
	mainframesizer.setControl(1, 0, &calculatepanel);
	//calculatebutton
	calculatepanelsizer.setControl(4, 4, &calculatebutton);
	calculatebutton.setTitle("calculate");
	//textbox'lar ayarlaniyor

	for (int var = 0; var < 9; ++var) {
		calculatepanelsizer.setControl(var % 5, 2 + (var/5)*2, &textbox[var] );
		calculatepanelsizer.setControl(var % 5, 1 + (var/5)*2, &text[var] );

	}
	textbox[0].setText("5");
		textbox[1].setText("7");
		textbox[2].setText("4");
		textbox[3].setText("1");
		textbox[4].setText("6");
		textbox[5].setText("1");
		textbox[6].setText("7");
		textbox[7].setText("10");
		textbox[8].setText("3");





}



