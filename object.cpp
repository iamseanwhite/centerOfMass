#include "object.h"

Object* createObject(float mass, float radius, float xPosition, string name) {

    Object *newObject = new Object;

    newObject->mass = mass;
    newObject->radius = radius;
    newObject->xPosition = xPosition;
    newObject->name = name;

    return newObject;
}

void addObjectToList(){

}
