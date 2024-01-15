/// @file musFreqLoopsArrays
/// @brief Computes musical frequencies and wavelengths for notes C0-B8 using an array and loop
/// @author Erik Fryanov

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Formula for reference: f = fr * 2^(v) * 2^(k/12))
int main () {
    const double TWELFTH_ROOT = 1.059463094359;
    const double SPEED_OF_SOUND  = 345.0;
    const double REF_FREQ = 16.35;
    const int NUM_OCTAVES = 9; // Number of octaves to consider
    const int NUM_HALFTONES = 12; // Number of Half-tones in an octave
    double freq = 16.35;
    double waveLength = 0;
    string strNote;
    string a_Notes[] = {
        "C0", "C#0", "D0","D#0", "E0", "F0", "F#0", "G0", "G#0", "A0", "A#0", "B0",
        "C1", "C#1", "D1","D#1", "E1", "F1", "F#1", "G1", "G#1", "A1", "A#1", "B1",
        "C2", "C#2", "D2","D#2", "E2", "F2", "F#2", "G2", "G#2", "A2", "A#2", "B2",
        "C3", "C#3", "D3","D#3", "E3", "F3", "F#3", "G3", "G#3", "A3", "A#3", "B3",
        "C4", "C#4", "D4","D#4", "E4", "F4", "F#4", "G4", "G#4", "A4", "A#4", "B4",
        "C5", "C#5", "D5","D#5", "E5", "F5", "F#5", "G5", "G#5", "A5", "A#5", "B5",
        "C6", "C#6", "D6","D#6", "E6", "F6", "F#6", "G6", "G#6", "A6", "A#6", "B6",
        "C7", "C#7", "D7","D#7", "E7", "F7", "F#7", "G7", "G#7", "A7", "A#7", "B7",
        "C8", "C#8", "D8","D#8", "E8", "F8", "F#8", "G8", "G#8", "A8", "A#8", "B8",
    };

    //Calculates frequency and wavelengths for respective notes of octaves and halftones
    for (int nu = 0; nu < NUM_OCTAVES; ++nu) {
        for (int k = 0; k < NUM_HALFTONES; ++k) {
            // Calculate frequency
            freq = REF_FREQ * pow(2, nu) * pow(TWELFTH_ROOT, k);

            // Calculate wavelength
            waveLength = (SPEED_OF_SOUND / freq) * 100.0; //Times 100 to convert to cm

            //Output frequency and wavelength for respective note, octave, and halftone.
            strNote = a_Notes[(12 * nu) + k];
            cout << "Note: " << strNote << "; nu: " << nu << "; ";
            cout << "k: " << k << "; frequency: " << freq << " Hz; ";
            cout << "wavelength: " << waveLength << " cm" << endl;
        }
    }

    return 0;

}