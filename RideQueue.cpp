#include "RideQueue.h"
#include <cstdlib>

// ================= ADD REQUEST =================

void RideQueue::addRequest(string rider,
                           string pickup,
                           string drop,
                           int priority) {

    RideRequest r(rider, pickup, drop, priority);
    pq.push(r);

    // ✅ LOCATION GROUPING
    locationCount[pickup]++;

    cout << "Ride Request Added Successfully\n";

    // ✅ HOTSPOT DETECTION
    if(locationCount[pickup] > 2) {
        cout << "[HOTSPOT] High demand at " << pickup << endl;
    }
}

// ================= PROCESS REQUEST =================

#include "BFS.h"
#include "Dijkstra.h"
#include "fraud.h"
#include "FileHandler.h"
#include "surgepricing.h"

void RideQueue::processRequest() {

    if(pq.empty()) {
        cout << "No Ride Requests Available\n";
        return;
    }

    RideRequest r = pq.top();
    pq.pop();

    cout << "\nProcessing Ride:\n";
    cout << "Rider: " << r.rider << endl;
    cout << "From: " << r.pickup << endl;
    cout << "To: " << r.drop << endl;

    // ================= DRIVER SEARCH =================
    cout << "\nFinding Nearby Drivers...\n";
    BFS(r.pickup);

    // ================= ROUTE =================
    cout << "\nCalculating Shortest Route...\n";
    dijkstra(r.pickup);

    // ================= SURGE PRICING =================
    double demand = rand() % 10 + 1;
    double supply = rand() % 10 + 1;

    cout << "\nApplying Surge Pricing...\n";
    surgePricing(demand, supply);

    // ================= FRAUD CHECK =================
    double amount = (rand() % 500) + 100;

    cout << "\nChecking Fraud...\n";
    detectFraud(amount);

    // ================= SAVE RECORD =================
    cout << "\nSaving Ride...\n";
    saveRideRecord(r.rider, r.pickup, r.drop, amount);

    cout << "\nRide Completed Successfully 🚖\n";
}

// ================= SHOW ALL REQUESTS =================

void RideQueue::showRequests() {

    if(pq.empty()) {
        cout << "No Ride Requests\n";
        return;
    }

    priority_queue<RideRequest,
                   vector<RideRequest>,
                   CompareRide> temp = pq;

    cout << "\nAll Ride Requests:\n";

    while(!temp.empty()) {

        RideRequest r = temp.top();
        temp.pop();

        cout << "Rider: " << r.rider
             << " | " << r.pickup
             << " -> " << r.drop
             << " | Priority: ";

        // ✅ FIXED PRIORITY LABEL
        if(r.priority == 2)
            cout << "Scheduled";
        else
            cout << "Immediate";

        cout << endl;
    }
}

// ================= CHECK EMPTY =================

bool RideQueue::isEmpty() {
    return pq.empty();
}