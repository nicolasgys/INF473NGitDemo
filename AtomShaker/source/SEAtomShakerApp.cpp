#include "SEAtomShakerApp.hpp"
#include "SEAtomShakerAppGUI.hpp"
#include"SBAtom.hpp"
#include "SAMSON.hpp"
#include "SBRandom.hpp"

SEAtomShakerApp::SEAtomShakerApp() {

	setGUI(new SEAtomShakerAppGUI(this));
	getGUI()->loadDefaultSettings();

}

SEAtomShakerApp::~SEAtomShakerApp() {

	getGUI()->saveDefaultSettings();
	delete getGUI();

}

SEAtomShakerAppGUI* SEAtomShakerApp::getGUI() const { return static_cast<SEAtomShakerAppGUI*>(SBDApp::getGUI()); }

void SEAtomShakerApp::shakeAtoms(const SBQuantity::angstrom &distance){

    SBRandom randomGenerator(SAMSON::getTime());

    SBNodeIndexer atomIndexer;
    SAMSON::getActiveDocument()->getNodes(atomIndexer,
                                           SBNode::IsType(SBNode::Atom)
                                          && SBNode::IsSelected());

    SAMSON::beginHolding("Shake atoms");

    SB_FOR(SBNode* node, atomIndexer){

        SBAtom* atom = static_cast<SBAtom*>(node);
        SBPosition3 position = atom->getPosition();
        position.v[0] += distance*
                (randomGenerator.randDouble1()-0.5);
        position.v[1] += distance*
                (randomGenerator.randDouble1()-0.5);
        position.v[2] += distance*
                (randomGenerator.randDouble1()-0.5);
        atom->setPosition(position);
    }

    SAMSON::endHolding();

}
