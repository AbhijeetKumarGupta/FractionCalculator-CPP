#include <iostream>
using namespace std;

// Function Declaration
void menu();
void addFractions(int nume1, int deno1, int nume2, int deno2, int numeFinal, int denoFinal);
void subtractFractions(int nume1, int deno1, int nume2, int deno2, int numeFinal, int denoFinal);
void multiplyFractions(int nume1, int deno1, int nume2, int deno2,  int numeFinal, int denoFinal);

int main() {

	// Variable Declaration
	int exit = 4, input = 0, nume1, nume2, deno1, deno2, numeFinal = 0, denoFinal = 0;

	// Calculator Loop
	do {

		menu();
		cin >> input;

		// Menu Choices
		if (input < exit) {
			if (input == 1) {
				cout << "\n\nFraction Addition (a/b + c/d = e/f) :-" << endl;

				// Taking user inputs
				cout << "\nPlease enter the numerator of first fraction i.e. 'a': ";
				cin >> nume1;
				cout << "Please enter the denominator of first fraction i.e. 'b': ";
				cin >> deno1;
				cout << "Please enter the numerator of second fraction i.e. 'c': ";
				cin >> nume2;
				cout << "Please enter the denominator of second fraction i.e. 'd': ";
				cin >> deno2;

				// Function call and output
				addFractions(nume1, deno1, nume2, deno2, numeFinal, denoFinal);

			} else if (input == 2) {
				cout << "\n\nFraction Subtraction (a/b - c/d = e/f) :-" << endl;

				// Taking user inputs
				cout << "\nPlease enter the numerator of first fraction i.e. 'a': ";
				cin >> nume1;
				cout << "Please enter the denominator of first fraction i.e. 'b': ";
				cin >> deno1;
				cout << "Please enter the numerator of second fraction i.e. 'c': ";
				cin >> nume2;
				cout << "Please enter the denominator of second fraction i.e. 'd': ";
				cin >> deno2;

				// Function call and output
				subtractFractions(nume1, deno1, nume2, deno2, numeFinal, denoFinal);

			} else if (input == 3) {
				cout << "\n\nFraction Multiplication (a/b * c/d = e/f) :-" << endl;

				// Taking user inputs
				cout << "\nPlease enter the numerator of first fraction i.e. 'a': ";
				cin >> nume1;
				cout << "Please enter the denominator of first fraction i.e. 'b': ";
				cin >> deno1;
				cout << "Please enter the numerator of second fraction i.e. 'c': ";
				cin >> nume2;
				cout << "Please enter the denominator of second fraction i.e. 'd': ";
				cin >> deno2;

				// Function call and output
				multiplyFractions(nume1, deno1, nume2, deno2, numeFinal, denoFinal);

			}

			cout << "\n\n";
		}
	} while (input < exit);

	// Ends with this message
	cout << "\n\nThank You!" << endl;

	return 0;
}

// Function Definitions

void menu(){
	// Menu Format
	cout << "#### MENU ####" << endl;
	cout << "[ 1 ] Add Fractions" << endl;
	cout << "[ 2 ] Subtract Fractions" << endl;
	cout << "[ 3 ] Multiply Fractions" << endl;
	cout << "[ 4 ] Exit" << endl;
	cout << "Please enter the option number to proceed : ";
}

void addFractions(int nume1, int deno1, int nume2, int deno2, int numeFinal, int denoFinal) {

	// Temporary Variable Declaration
	int divisor = 1, deno1temp = deno1, deno2temp = deno2;
	denoFinal = 1;

	// LCM Calculation
	while (deno1 > 1 || deno2 > 1) {

		divisor++;

		while (deno1 % divisor == 0 || deno2 % divisor == 0) {
			if (deno1 % divisor == 0) {
				deno1 = deno1 / divisor;
			}
			if (deno2 % divisor == 0) {
				deno2 = deno2 / divisor;
			}

			denoFinal *= divisor;
		}
	}

	// Final Numerator calculation
	numeFinal = (nume1 * (denoFinal / deno1temp))
			+ (nume2 * (denoFinal / deno2temp));

	// Output
	cout << "The sum is  : " << numeFinal << "/" << denoFinal << endl;

}

void subtractFractions(int nume1, int deno1, int nume2, int deno2, int numeFinal, int denoFinal) {

	// Temporary Variable Declaration
	int divisor = 1, deno1temp = deno1, deno2temp = deno2;
	denoFinal = 1;

	// LCM Calculation
	while (deno1 > 1 || deno2 > 1) {

		divisor++;

		while (deno1 % divisor == 0 || deno2 % divisor == 0) {
			if (deno1 % divisor == 0) {
				deno1 = deno1 / divisor;
			}
			if (deno2 % divisor == 0) {
				deno2 = deno2 / divisor;
			}

			denoFinal *= divisor;
		}
	}

	// Final Numerator calculation
	numeFinal = (nume1 * (denoFinal / deno1temp))
			- (nume2 * (denoFinal / deno2temp));

	// Output
	cout << "The difference is  : " << numeFinal << "/" << denoFinal << endl;
}

void multiplyFractions(int nume1, int deno1, int nume2, int deno2, int numeFinal, int denoFinal) {

	// Temporary Variable Declaration
	int smallerCheck = 0;

	// Numerator and Denominator multiplication
	numeFinal = nume1 * nume2;
	denoFinal = deno1 * deno2;

	// Check weather numerator is smaller or denominator
	if (numeFinal < denoFinal) {
		smallerCheck = numeFinal;
	} else if (numeFinal > denoFinal) {
		smallerCheck = denoFinal;
	}

	// Dividing Numerators and Denominator if further possible for simplification
	for (int i = 1; i <= smallerCheck; i++) {

		if ((numeFinal % i == 0) && (denoFinal % i == 0)) {
			numeFinal = numeFinal / i;
			denoFinal = denoFinal / i;
		}

	}

	// Output
	cout << "The product is : " << numeFinal << " / " << denoFinal << endl;
}
