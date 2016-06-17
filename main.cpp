#include "object.h"
#include "object.cpp"
#include <windows.h>



int main() {
    int menuChoice;
    solarSystem* currentSystem = new solarSystem;
    currentSystem = NULL;

    listOfSystems *systemList = new listOfSystems;
    initializeSystemList(systemList);

    while(true){
    Sleep( 500 );
    cout << "What would you like to do?\n 1. Create a new Solar System\n 2. Add a new object to current System\n 3. View objects in current System\n 4. Change current System\n" <<endl;
    cin >> menuChoice;

    switch (menuChoice){
        case 1:
        {
            string solarSystemName;
            cout << "\nSolar System name: ";
            cin >> solarSystemName;
            solarSystem* newSolarSystem = createSolarSystem(systemList, solarSystemName);
            currentSystem = newSolarSystem;                                 //to hold the system the user is currently using

            cout << "\nNew solar system created:\n\n";
            cout << "Name: " << newSolarSystem->name << " \n";
            cout << "Size: " << newSolarSystem->numberOfBodies << " bodies\n";
            cout << "Total Mass: " << newSolarSystem->totalMass << " kg \n";
            cout << "Center of Mass: " << newSolarSystem->centerOfMass << " meters \n\n";
            break;
        }

        case 2:
        {

            if (currentSystem == NULL) {
                cout << "\nYou don't have any solar systems!\n\n";
                break;
            }

            float mass, radius, xPosition;
            string name;

            cout << "What is the name of your object? ";
            cin >> name;
            cout << "What is the radius of your object? ";
            cin >> radius;
            cout << "What is the mass of your object? ";
            cin >> mass;
            cout << "What is the x-position of your object? ";
            cin >> xPosition;


            celestialBody *newCelestialBody = createCelestialBody(mass, radius, xPosition, name);
            addBodyToSystem(newCelestialBody, currentSystem);

            cout << "\nObject added:\n\n" << newCelestialBody->name;
            cout << "\nRadius: " << newCelestialBody->radius << " meters\n";
            cout << "Mass: " << newCelestialBody->mass << " kg\n";
            cout << "x-position: " << newCelestialBody->xPosition << " meters\n\n";
            break;
        }
        case 3:
            if (currentSystem == NULL) {
                cout << "\nYou don't have any solar systems!\n\n";
                break;
            }
            if (currentSystem->numberOfBodies == 0) {
                cout << "\nYour system is empty!\n\n";
                break;
            }
            solarSystemPrint(currentSystem);
            break;

        case 4:


        default:
            cout << "\nNot a valid option!\n\n";
            break;



    }

    }


}
