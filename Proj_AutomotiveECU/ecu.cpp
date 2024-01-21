/// @file ecu
/// @brief Electronic control unit simulation of the Mach 5 car(only three buttons)
/// @author Erik Fryanov

#include <iostream>
#include <string>

using namespace std;

class ElectronicControlUnit {
public:
    ElectronicControlUnit(); //Constructor
    ~ElectronicControlUnit(); //Destructor
    void activateHydraulicJacks(); //Switches from false to true or vice versa, same for next 2
    void activateBeltTires();
    void activateIRIllumination();
    void handleCommand(char cCommand);

private:
    bool m_bActivatedHydraulicJacks; //Button A
    bool m_bActivatedBeltTires;      //Button B
    bool m_bActivatedIRIllumination; //Button E
};

//Default constructor
ElectronicControlUnit::ElectronicControlUnit() {
    this->m_bActivatedHydraulicJacks = false;
    this->m_bActivatedBeltTires = false;
    this->m_bActivatedIRIllumination = false;
}

//Destructor
ElectronicControlUnit::~ElectronicControlUnit() {
    cout << "De-structed!" << endl;
}

//Activates/Deactivates component
void ElectronicControlUnit::activateHydraulicJacks() {
    m_bActivatedHydraulicJacks = !(m_bActivatedHydraulicJacks);
}

//Activates/Deactivates component
void ElectronicControlUnit::activateBeltTires() {
    m_bActivatedBeltTires = !(m_bActivatedBeltTires);
}

//Activates/Deactivates component
void ElectronicControlUnit::activateIRIllumination() {
    m_bActivatedIRIllumination = !(m_bActivatedIRIllumination);
}

//Activates or deactivates specific component based on button pressed
void ElectronicControlUnit:: handleCommand(char cCommand) {
    switch(cCommand) {
        //Hydraulic jacks
        case 'A':
        case 'a':
            //Determines if component is to be activated or deactivated
            if(!(m_bActivatedHydraulicJacks)) {
                activateHydraulicJacks();
                cout << "Hydraulic Jacks Activated!" << endl;
                //Only deactivates belt tires if they are active and hydraulics are being activated
                if(m_bActivatedBeltTires && m_bActivatedHydraulicJacks) {
                    activateBeltTires();
                    cout << "Belt Tires Deactivated!" << endl;
                }
                break;
            } 
            else {
                activateHydraulicJacks();
                cout << "Hydraulic Jacks Deactivated!" << endl;
                break;
            }

        //Belt tires
        case 'B':
        case 'b':
            if(!(m_bActivatedBeltTires)) {
                activateBeltTires();
                cout << "Belt Tires Activated!" << endl;
                break;
            }
            else {
                activateBeltTires();
                cout << "Belt Tires Deactivated!" << endl;
                break;
            }

        //Infrared Illumination
        case 'E':
        case 'e':
            if(!(m_bActivatedIRIllumination)) {
                activateIRIllumination();
                cout << "IR-Illumintaton Activated!" << endl;
                break;
            }
            else {
                activateIRIllumination();
                cout << "IR-Illumintaton Deactivated!" << endl;
                break;
            }

        default:
            cout << "Invalid command." << endl;
            break;
    }
}


int main () {
    ElectronicControlUnit mach5;
    char userInput;

    cout << "Press X to turn off ignition or enter a steering wheel button(A, B, or E)" << endl;

    while(true) {
        cout << "       (A)    " << endl;
        cout << "   (F) (G) (B)" << endl;
        cout << "   (E)     (C)" << endl;
        cout << "       (D)    " << endl;
        
        cin >> userInput;
        
        //Exits while loop
        if(userInput == 'X'){
            break;
        }
        mach5.handleCommand(userInput);
    }

    return 0;
}
