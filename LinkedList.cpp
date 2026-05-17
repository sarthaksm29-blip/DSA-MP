#include "LinkedList.h"

LinkedList::LinkedList() {
    head = NULL;
}

void LinkedList::addRide(string rider,
                         string from,
                         string to,
                         double amount) {

    RideNode* newNode =
    new RideNode(rider, from, to, amount);

    if(head == NULL) {

        head = newNode;
        return;
    }

    RideNode* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void LinkedList::showRides() {

    RideNode* temp = head;

    cout << "\nRide Records\n";

    while(temp != NULL) {

        cout << "Rider: "
             << temp->rider
             << endl;

        cout << "Route: "
             << temp->from
             << " -> "
             << temp->to
             << endl;

        cout << "Amount: "
             << temp->amount
             << endl;

        cout << "-------------------"
             << endl;

        temp = temp->next;
    }
}