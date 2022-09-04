#include "src/engine/physics_simulation.hpp"


void AddObject(Object* object)
{
    m_objects.push_back(object);
}

void RemoveObject(Object* object)
{
    m_objects.erase(object);
}

void Step(float dt)
{
    for (Object* obj : m_objects) {
        obj->Force += obj->Mass * m_gravity; 

        obj->Velocity += obj->Force / obj->Mass * dt;
        obj->Position += obj->Velocity * dt;

        obj->Force = vector3(0, 0, 0); 
    }
}