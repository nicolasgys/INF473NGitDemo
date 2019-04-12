#pragma once 

#include "SBDApp.hpp"
#include "SEEnergyConverterAppGUI.hpp"


/// This class implements the functionality of the app

// SAMSON Element generator pro tip: add non-GUI functionality in this class. The GUI functionality should go in the SEEnergyConverterAppGUI class

class SEEnergyConverterApp : public SBDApp {

	SB_CLASS

public :

	/// \name Constructors and destructors
	//@{

	SEEnergyConverterApp();																													///< Constructs an app
	virtual ~SEEnergyConverterApp();																											///< Destructs the app

	//@}

	/// \name GUI
	//@{

	SEEnergyConverterAppGUI*											getGUI() const;															///< Returns a pointer to the GUI of the app

	//@}

    /// \name Conversion
    //@{
    double  convert(double sourceEnergy, const unsigned int sourceUnit, const unsigned int destinationUnit);
    //@}


};


SB_REGISTER_TARGET_TYPE(SEEnergyConverterApp, "SEEnergyConverterApp", "89031EEB-E1A8-F69A-CE07-AD16031C1A94");
SB_DECLARE_BASE_TYPE(SEEnergyConverterApp, SBDApp);
