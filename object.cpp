#include "object.h"

celestialBody* createCelestialBody(float mass, float radius, float xPosition, string name) {

    celestialBody *newCelestialBody = new celestialBody;

    newCelestialBody->mass = mass;
    newCelestialBody->radius = radius;
    newCelestialBody->xPosition = xPosition;
    newCelestialBody->name = name;

    return newCelestialBody;
}

void initializeSolarSystem(struct solarSystem* sS, string name) {
    sS->name = name;
    sS->numberOfBodies = 0;
    sS->centerOfMass = sS->totalMass = 0;

    sS->sentinel = new celestialBody;
    sS->sentinel->next = sS->sentinel;
    sS->sentinel->prev = sS->sentinel;
}

solarSystem* createSolarSystem(string name){
    solarSystem *newSolarSystem = new solarSystem;
    initializeSolarSystem(newSolarSystem, name);

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

    delete(temp);
}

void solarSystemPrint(struct solarSystem* sS){
    celestialBody* temp = new celestialBody;
    temp = sS->sentinel->next;

    cout << "System " << sS->name <<":\n\n";

    while (temp != sS->sentinel){
        cout << "Name: " << temp->name;
        cout << "\nRadius: " << temp->radius << " meters\n";
        cout << "Mass: " << temp->mass << " kg\n";
        cout << "x-position: " << temp->xPosition << " meters\n\n";
        temp = temp->next;
    }
    delete(temp);
}
