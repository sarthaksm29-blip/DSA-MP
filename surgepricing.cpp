#include <iostream>
#include "surgepricing.h"
using namespace std;

void surgePricing(double demand, double supply) {

    double baseFare = 100;

    double multiplier = 1 + (demand / supply);

    double finalFare = baseFare * multiplier;

    cout << "Demand: " << demand << endl;
    cout << "Supply: " << supply << endl;
    cout << "Final Fare: " << finalFare << endl;
}