#ifndef OBJECT_H_
#define OBJECT_H_

#include <iostream>
#include <string>
using namespace std;

class Object {
    public:
    float mass = 0, radius = 0, xPosition = 0;
    string name;

};

Object* createObject(float mass, float radius, float xPosition, string name);

#endif
