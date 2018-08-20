#include<iostream>
using namespace std;

void createMenuRegistration(string name, string address, long long int phone, long long int mobile) {
    cout << "enter user name : " << endl;
    cin >> name;
    cout << "enter address :" << endl;
    cin >> address;
    cout << "enter phone number :" << endl;
    cin >> phone;
    cout << "enter mobile number :" << endl;
    cin >> mobile;
}

int createMenuOptions() {
    cout << "Press 1 for login" << endl;
    cout << "Press 2 for new registrations" << endl;
    int option;
    cin >> option;
    return option;
}
