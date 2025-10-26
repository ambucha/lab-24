// Goat.h

#ifndef GOAT_H
#define GOAT_H
#include <iostream>
using namespace std;

class Goat {
private:
    string name;
    int age;
    string color;
public: 
    Goat()                          { name = ""; age = 0; color = ""; }
    // write three more constructors
    // first one has just the name as the argument, then the next has both name and age as arguments, final one has all three as arguments
    Goat(string s) {
        name = s;
        age = 0;
        color = "";
    }

    Goat(string s, int a){
        name = s;
        age = a;
        color = "";
    }

    Goat(string s, int a, string c){
        name = s;
        age = a;
        color = c;
    }

    // setters and getters
    void set_name(string n)         { name = n; };
    string get_name() const         { return name; };
    void set_age(int a)             { age = a; };
    int get_age() const             { return age; }
    void set_color(string c)        { color = c; }
    string get_color() const        { return color; }

    // write overloaded < operator for the std::list
    bool operator< (const Goat &other) const {
        return name < other.name;
    }
};

#endif