#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

struct RideNode {

    string rider;
    string from;
    string to;
    double amount;

    RideNode* next;

    RideNode(string r,
             string f,
             string t,
             double a) {

        rider = r;
        from = f;
        to = t;
        amount = a;

        next = NULL;
    }
};

class LinkedList {

    RideNode* head;

public:

    LinkedList();

    void addRide(string rider,
                 string from,
                 string to,
                 double amount);

    void showRides();
};

#endif