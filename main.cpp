// COMSC-210 | Lab 24 | Andrei Buchatskiy
// IDE used : Visual Studio Code

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    list<Goat> trip;

    // create a while loop to go until the user chooses to stop
    int choice = 0;
    while(choice != 4){
        choice = main_menu();
        if(choice == 1){
            add_goat(trip, names, colors);
        }
        if(choice == 2){
            delete_goat(trip);
        }
        if(choice == 3){
            display_trip(trip);
        }
    }

    return 0;
}

int main_menu(){
    int choice;
    cout << "*** GOAT MANAGER 3001 ***" << endl;
    cout << "[1] Add a goat" << endl;
    cout << "[2] Delete a goat" << endl;
    cout << "[3] List goats" << endl;
    cout << "[4] Quit" << endl;
    cout << "Choice --> ";
    cin >> choice;
    cout << endl;
    return choice; 
}

void add_goat(list<Goat> &trip, string names[], string colors[]){
    // create a temportary Goat variable with random name, age, and color
    Goat temp(names[rand() % SZ_NAMES], rand() % MAX_AGE,colors[rand() % SZ_COLORS]);

    // add this temporary varaible to the list
    trip.push_back(temp);
}

void delete_goat(list<Goat> &trip){
    // start my displaying the goats in the trip atm
    // wait i lowk need to check if the list is mepty frist befiore deleting anything
    if(trip.empty()) {
        cout << "No goats on the trip right now" << endl;
        return;
    }

    display_trip(trip);
    int i;

    cout << "What goat would you like to eliminate: " << endl;
    cin >> i;
    cout << endl;

    // also need to check if it can even be taken out (if it is withijn the list bounds)
    while(i < 1 || i > trip.size()){
        cout << "This goat does not exist, try giving me a valid goat number: ";
        cin >> i;
        cout << endl;
    }

    // use .erase() with .begin() 
    auto it = trip.begin();
    for(int k = 0; k < i - 1; k++){
        it++;
    }

    // erase the goat at given choice
    trip.erase(it);
}

void display_trip(list<Goat> trip){
    // counter to display which goat you are on
    int count = 1;

    // for loop to go through each goat in the list and display its stats
    for(Goat g : trip){
        cout << "[" << count << "] " << g.get_name() << " (" << g.get_age() << ", " << g.get_color() << ")" << endl;
        count++;
    }

    cout << endl;
}
