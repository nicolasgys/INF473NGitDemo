#include "SEAtomShakerAppGUI.hpp"
#include "SEAtomShakerApp.hpp"
#include "SAMSON.hpp"
#include "SBGWindow.hpp"

SEAtomShakerAppGUI::SEAtomShakerAppGUI( SEAtomShakerApp* t ) : SBGApp( t ) {

	ui.setupUi( this );

}

SEAtomShakerAppGUI::~SEAtomShakerAppGUI() {

}

SEAtomShakerApp* SEAtomShakerAppGUI::getApp() const { return static_cast<SEAtomShakerApp*>(SBGApp::getApp()); }

void SEAtomShakerAppGUI::loadSettings( SBGSettings *settings ) {

	if ( settings == NULL ) return;
	
	// SAMSON Element generator pro tip: complete this function so your app can save its GUI state from one session to the next

}

void SEAtomShakerAppGUI::saveSettings( SBGSettings *settings ) {

	if ( settings == NULL ) return;

	// SAMSON Element generator pro tip: complete this function so your app can save its GUI state from one session to the next

}

SBCContainerUUID SEAtomShakerAppGUI::getUUID() const { return SBCContainerUUID( "9D17A9A2-E86B-DB95-EA96-0963F2CBABEA" );}

QPixmap SEAtomShakerAppGUI::getLogo() const { 
	
	// SAMSON Element generator pro tip: this icon will be visible in the GUI title bar. 
	// Modify it to better reflect the purpose of your app.

    return QPixmap(QString::fromStdString(SB_ELEMENT_PATH + "/resource/icons/SEAtomShakerAppIcon.png"));

}

QString SEAtomShakerAppGUI::getName() const { 

	// SAMSON Element generator pro tip: this string will be the GUI title. 
	// Modify this function to have a user-friendly description of your app inside SAMSON

    return "Atom shaker";

}

int SEAtomShakerAppGUI::getFormat() const { 
	
	// SAMSON Element generator pro tip: modify these default settings to configure the window
	//
	// SBGWindow::Savable : let users save and load interface settings (implement loadSettings and saveSettings)
	// SBGWindow::Lockable : let users lock the window on top
	// SBGWindow::Resizable : let users resize the window
	// SBGWindow::Citable : let users obtain citation information (implement getCitation)
	
	return (SBGWindow::Savable | SBGWindow::Lockable | SBGWindow::Resizable | SBGWindow::Citable);

}

QString SEAtomShakerAppGUI::getCitation() const {

	// SAMSON Element generator pro tip: modify this function to add citation information

	return
		"If you use this app in your work, please cite: <br/>"
		"<br/>"
		"[1] <a href=\"https://www.samson-connect.net\">https://www.samson-connect.net</a><br/>";
	
}

void SEAtomShakerAppGUI::onShakeAtoms(){

    getApp()->shakeAtoms(
                SBQuantity::angstrom(ui.doubleSpinBoxAmplitude->value()));
}
