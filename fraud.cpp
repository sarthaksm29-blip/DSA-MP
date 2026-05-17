#include <iostream>
#include <vector>
#include "fraud.h"

using namespace std;

// Store past ride amounts
vector<double> rideHistory;

void detectFraud(double amount) {

    // Add current amount to history
    rideHistory.push_back(amount);

    cout << "Ride Amount: " << amount << endl;

    // If not enough data
    if(rideHistory.size() < 3) {
        cout << "Not enough data for fraud detection\n";
        return;
    }

    // Calculate average of previous rides
    double sum = 0;
    for(int i = 0; i < rideHistory.size() - 1; i++) {
        sum += rideHistory[i];
    }

    double avg = sum / (rideHistory.size() - 1);

    cout << "Average Previous Fare: " << avg << endl;

    // Pattern-based fraud detection
    if(amount > 2 * avg) {
        cout << "⚠️ Fraud Ride Detected (Abnormal Spike!)\n";
    }
    else {
        cout << "Ride Safe\n";
    }
}