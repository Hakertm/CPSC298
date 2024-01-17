/// @file MusicalNoteImpl
/// @brief Musical Notes Application Programming Interface (API) Implementation File
/// CPSC-298-6 Programming in C++ Project Musical Note Frequencies with Functions
/// @author Erik Fryanov

#include <iostream>
#include <string>
#include <cmath>
#include "MusicalNoteApi.h"
using namespace std;


double computeFrequency(int nu, int k) {
	double freq = -1.0;

	if ((k >= 0) && (k < NUM_HALFTONES) && (nu >= 0)) {
		// Computed frequency in Hertz (Hz) 
		freq = REF_FREQ * pow(2.0, nu) * pow(TWELFTH_ROOT, k);
	}
	else {
		// Error check
		cerr << "ERROR: computeFrequency preconditions not satisfied; freq nu (" 
				<< nu << ") or k (" << k << ") invalid" << endl;
	}

	return freq;
}

double computeWavelengthInCm(double freqHz) {
	double waveLength = -1.0;

	if ((freqHz < 0.0) || (!isfinite(freqHz)) || (FP_ZERO == fpclassify(freqHz)))
	{
		cerr << "ERROR: computeWavelengthInCm preconditions not satisfied; freqHz invalid: " << freqHz << endl;
	}
	else {
		// Input satisfies all preconditions(see header), perform computation
		waveLength = (SPEED_OF_SOUND_CM / freqHz); // Computed wavelength(in cm)
	}

	return waveLength;
}

const string getNoteName(int nu, int k) {
	const static string a_strNotePrefix[] = {
			"C", "C#", "D","D#", "E", "F", "F#", "G", "G#", "A", "A#", "B",
	};

	string strNote = "UNK";

	if ((k >= 0) && (k < NUM_HALFTONES) && (nu >= 0))
	{
		strNote = a_strNotePrefix[k] + to_string(nu); //Concatenates nu to specific note
	}

	return strNote; 
}

int main() {
	int nOctaves = 11; // Number of octaves over which to compute frequencies.

	// Compute for Octaves 0 through 10 (previously you computed only zero through 8)
	for (int nu = 0; nu < nOctaves; nu++) {
		for (int k = 0; k < NUM_HALFTONES; k++) {
			//Call functions and assign values to variables
			double f = computeFrequency(nu, k);
			double dWavelengthCentimeters = computeWavelengthInCm(f);
			string strNote = getNoteName(nu, k);

			cout << "Note: " << strNote << "; nu: " << nu << "; k: " << k << "; frequency: " << f << " Hz; wavelength: " << dWavelengthCentimeters << " cm" << endl;

		}
	}

	cout << endl << endl;
	cout << "------------------------------------------------ CHECK ERROR HANDLING ---------------------------------------------------------------" << endl;

	//Error checking
	double f = computeFrequency(-1, -1);
	double dWavelengthCentimeters = computeWavelengthInCm(-16.35);
	string strNote = getNoteName(-1, -1);

	cout << "Note: " << strNote << "; nu: -1; k: -1; frequency: " << f << " Hz; wavelength: " << dWavelengthCentimeters << " cm" << endl;

	return 0;
}
