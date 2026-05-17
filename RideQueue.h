#ifndef RIDEQUEUE_H
#define RIDEQUEUE_H

#include <iostream>
#include <map>
#include <string>

using namespace std;

// ================= STRUCT =================

struct RideRequest {
    string rider;
    string pickup;
    string drop;
    int priority; // 1 = scheduled, 2 = immediate

    RideRequest(string r, string p, string d, int pr) {
        rider = r;
        pickup = p;
        drop = d;
        priority = pr;
    }
};

// ================= COMPARATOR =================

struct CompareRide {
    bool operator()(RideRequest a, RideRequest b) {
        return a.priority < b.priority;
    }
};

// ================= CLASS =================

class RideQueue {

    priority_queue<RideRequest,
                   vector<RideRequest>,
                   CompareRide> pq;

public:

    void addRequest(string rider,
                    string pickup,
                    string drop,
                    int priority);

    void processRequest();

    void showRequests();

    bool isEmpty();
    map<string, int> locationCount;
};

#endif