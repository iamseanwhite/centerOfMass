#ifndef OBJECT_H_
#define OBJECT_H_

#include <iostream>
#include <string>
using namespace std;

struct celestialBody {
    float mass, radius, xPosition;
    string name;
    struct celestialBody* next;
    struct celestialBody* prev;

};

struct solarSystem {
    int numberOfBodies;
    string name;
    float totalMass;
    float centerOfMass;
    struct celestialBody* sentinel;
};

celestialBody* createCelestialBody(float mass, float radius, float xPosition, string name);
void initializeSolarSystem(struct solarSystem* sS, string name);
solarSystem* createSolarSystem(string name);
void addBodyToSystem(struct celestialBody* cB, struct solarSystem* sS);
void solarSystemPrint(struct solarSystem* sS);

#endif
