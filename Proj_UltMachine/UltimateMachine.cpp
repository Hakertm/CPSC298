/// @file UltimateMachine
/// @brief THE ULTIMATE MACHINE! Turns itself on and then immediately off.
/// @author Erik Fryanov

#include <iostream>
using namespace std;

class CUltimateMachine
{
public:
    //Constructor
    CUltimateMachine(): m_bState(false)
    {
        cout << "CUltimateMachine constructor(ctor) called" << endl;
    }

    //Destructor
    ~CUltimateMachine()
    {
        cout << "CUltimateMachine destructor(dtor) called" << endl;
    }

    //Displays current state of the machine
    void displayState()
    {
        switch(m_bState) {
        case true:
            cout << "Ultimate Machine is ON" << endl;
            break;
        case false:
            cout << "Ultimate Machine is OFF" << endl;
            break;
        }
    }

    //Turns on the machine and then turns it off
    void turnOn()
    {
        m_bState = true;
        displayState();
        if (m_bState) {
            m_bState = false;
        }
        displayState();
    }

private:
    //ON + OFF State Indication
    bool m_bState;

};

int main () {
    cout << "The Ultimate Machine Simulation" << endl;

    CUltimateMachine ultmach;
    ultmach.displayState();
    ultmach.turnOn();

    return 0;
}
