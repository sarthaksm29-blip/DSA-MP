#include <iostream>
#include <fstream>
#include "FileHandler.h"
using namespace std;

void saveRideRecord(string name,
                    string from,
                    string to,
                    double amount) {

    ofstream file("records.txt", ios::app);

    file << "Rider: " << name << endl;
    file << "From: " << from << endl;
    file << "To: " << to << endl;
    file << "Amount: " << amount << endl;
    file << "------------------" << endl;

    file.close();

    cout << "Record Saved Successfully" << endl;
}