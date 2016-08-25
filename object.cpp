#include "object.h"

void initializeSystemList(struct listOfSystems* lst){
    lst->numberOfSystems = 0;
    lst->sentinel = new solarSystem;
    lst->sentinel->next = lst->sentinel;
    lst->sentinel->prev = lst->sentinel;
}

void addSystemToList(struct listOfSystems* lst, struct solarSystem* sS) {
    solarSystem* temp = new solarSystem;
    temp = lst->sentinel;

    while(temp->next != lst->sentinel)
        temp = temp->next;

    temp->next = sS;
    sS->next = lst->sentinel;
    lst->sentinel->prev = sS;

    lst->numberOfSystems++;
}

celestialBody* createCelestialBody(float mass, float radius, float xPosition, string name) {

    celestialBody *newCelestialBody = new celestialBody;

    newCelestialBody->mass = mass;
    newCelestialBody->radius = radius;
    newCelestialBody->xPosition = xPosition;
    newCelestialBody->name = name;

    return newCelestialBody;
}

void initializeSolarSystem(struct listOfSystems* lst, struct solarSystem* sS, string name) {
    sS->name = name;
    sS->numberOfBodies = 0;
    sS->centerOfMass = sS->totalMass = 0;

    sS->sentinel = new celestialBody;
    sS->sentinel->next = sS->sentinel;
    sS->sentinel->prev = sS->sentinel;

    addSystemToList(lst, sS);
}

solarSystem* createSolarSystem(struct listOfSystems* lst, string name){
    solarSystem *newSolarSystem = new solarSystem;
    initializeSolarSystem(lst, newSolarSystem, name);

    return newSolarSystem;
}



void addBodyToSystem(struct celestialBody* cB, struct solarSystem* sS){
    celestialBody* temp = new celestialBody;
    temp = sS->sentinel;

    while(temp->next != sS->sentinel)
        temp = temp->next;

    temp->next = cB;
    cB->next = sS->sentinel;
    sS->sentinel->prev = cB;

    sS->numberOfBodies++;
    sS->totalMass = sS->totalMass + cB->mass;

}

void solarSystemPrint(struct solarSystem* sS){
    celestialBody* temp = new celestialBody;
    temp = sS->sentinel->next;

    cout << "\nSystem " << sS->name <<":\n\n";
    cout << "Center of Mass: " << calculateCenterofMass(sS) <<" meters \n\n";

    while (temp != sS->sentinel){
        cout << "Name: " << temp->name;
        cout << "\nRadius: " << temp->radius << " meters\n";
        cout << "Mass: " << temp->mass << " kg\n";
        cout << "x-position: " << temp->xPosition << " meters\n\n";
        temp = temp->next;
    }
}

solarSystem* selectSystem(struct listOfSystems* lst){
    string systemChoice;
    solarSystem* temp = lst->sentinel->next;
        for (int i = 0; i < lst->numberOfSystems; i++) {
            cout << temp->name << endl;
            temp = temp->next;
        }
    
        
    cout << "\n";
   
    while (true){    
        cin >> systemChoice;
        temp = temp->next;
        
        for (int i = 0; i < lst->numberOfSystems; i++) {
            if (temp->name == systemChoice) 
                return temp;
                
            temp = temp->next;
            
        }
        
        cout << "Not a valid System! Tray again: ";
    }
    
}

float calculateCenterofMass(struct solarSystem* sS){
    float totalMoment = 0;
    
    if (sS->sentinel->next != sS->sentinel) {
        celestialBody* temp = sS->sentinel->next;
        
        while (temp != sS->sentinel) {
            totalMoment += temp->mass * temp->xPosition;
            temp = temp->next;
        }
        
        sS->centerOfMass = totalMoment / sS->totalMass;
        return sS->centerOfMass;
    }
    
    else cout << "There are no bodies in this system";
    
        
}