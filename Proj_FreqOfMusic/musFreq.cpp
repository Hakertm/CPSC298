/// @file musFreq
/// @brief Outputs frequency and wavelength of specific music notes based on calculations
/// @author Erik Fryanov

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Formula for reference: f = fr * 2^(v) * 2^(k/12))
int main () {
    const double TWELFTH_ROOT = 1.059463094359;
    const double REF_FREQ = 16.35;
    const double SPEED_OF_SOUND  = 345.0; 
    double freq;
    double waveLength;

    cout << "Reference Frequency: " << REF_FREQ << " Hz" << endl;
    cout << "Speed of Sound: " << SPEED_OF_SOUND << " m/s" << endl;

    //C0
    freq = REF_FREQ * pow(2, 0) * pow(TWELFTH_ROOT, 0);
    waveLength = (SPEED_OF_SOUND / freq) * 100; //Times 100 to convert to cm

    cout << "Note: C0; nu: 0; k: 0; Frequency: " << freq << " Hz; ";
    cout << "Wavelength: " << waveLength << " cm/s" << endl;

    //C#0
    freq = REF_FREQ * pow(2, 0) * pow(TWELFTH_ROOT, 1);
    waveLength = (SPEED_OF_SOUND / freq) * 100;

    cout << "Note: C#0; nu: 0; k: 1; Frequency: " << freq << " Hz; ";
    cout << "Wavelength: "<< waveLength << " cm/s" << endl;

    //D0
    freq = REF_FREQ * pow(2, 0) * pow(TWELFTH_ROOT, 2);
    waveLength = (SPEED_OF_SOUND / freq) * 100;

    cout << "Note: D0; nu: 0; k: 2; Frequency: " << freq << " Hz; ";
    cout << "Wavelength: " << waveLength << " cm/s" << endl;

    //C4
    freq = REF_FREQ * pow(2, 4) * pow(TWELFTH_ROOT, 0);
    waveLength = (SPEED_OF_SOUND / freq) * 100;

    cout << "Note: C4; nu: 4; k: 0; Frequency: " << freq << " Hz; ";
    cout << "Wavelength: " << waveLength << " cm/s" << endl;

    //D#7
    freq = REF_FREQ * pow(2, 7) * pow(TWELFTH_ROOT, 3);
    waveLength = (SPEED_OF_SOUND / freq) * 100;

    cout << "Note: D#7; nu: 7; k: 3; Frequency: " << freq << " Hz; ";
    cout << "Wavelength: " << waveLength << " cm/s" << endl;

    //C8
    freq = REF_FREQ * pow(2, 8) * pow(TWELFTH_ROOT, 0);
    waveLength = (SPEED_OF_SOUND / freq) * 100;

    cout << "Note: C8; nu: 8; k: 0; Frequency: " << freq << " Hz; ";
    cout << "Wavelength: " << waveLength << " cm/s" << endl;

    return 0;

}