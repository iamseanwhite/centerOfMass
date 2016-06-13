#include "object.h"
#include "object.cpp"



int main() {
    cout << "Press 1 to create and place an object in your space!\n" <<endl;

    int userInput;
    float mass, radius, xPosition;
    string name;

    cin >> userInput;

    if(userInput == 1) {
        cout << "What is the name of your object? ";
        cin >> name;
        cout << "What is the radius of your object? ";
        cin >> radius;
        cout << "What is the mass of your object? ";
        cin >> mass;
        cout << "What is the x-position of your object? ";
        cin >> xPosition;


        Object *newObject = createObject(mass, radius, xPosition, name);

        cout << "\nObject added: \n" << newObject->name;
        cout << "\nRadius: " << newObject->radius << " meters\n";
        cout << "Mass: " << newObject->mass << " kg\n";
        cout << "x-position: " << newObject->xPosition << " meters\n";

    }

}
