// COMSC-210 | Lab 24 | Andrei Buchatskiy
// IDE used : Visual Studio Code

#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(set<Goat> trip);
void delete_goat(set<Goat> &trip);
void add_goat(set<Goat> &trip, string [], string []);
void display_trip(const set<Goat>& trip);
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

    set<Goat> trip;

    // create a while loop to go until the user chooses to stop
    /*
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
    */

    add_goat(trip, names, colors);
    display_trip(trip);

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

void add_goat(set<Goat> &trip, string names[], string colors[]){
    Goat temp(names[rand() % SZ_NAMES], rand() % MAX_AGE,colors[rand() % SZ_COLORS]);
    trip.insert(temp);
}

void delete_goat(set<Goat> &trip){
    
}

void display_trip(const set<Goat>& trip){
    // counter to display which goat you are on
    int count = 1;

    // for loop to go through each goat in the list and display its stats
    for(auto it = trip.begin(); it != trip.end(); it++){
        cout << "[" << count << "] " << it->get_name() << " (" << it->get_age() << ", " << it->get_color() << ")" << endl;
        count++;
    }

    cout << endl;
}
