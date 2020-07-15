#pragma once

#include "BasicUnit.h"
#include "GameObject.h"

class Furniture : public BasicUnit
{
//This class represents all the furniture
///Note: this might be modified or abandoned

private:
    GameObject* furniture;

public:
    Furniture();
    ~Furniture();

    void Update();   //Method to update GameObject
    void Render();
    void Render(GameObject*);   //Method to render furniture with respect to the player
    bool CollisionDetection(GameObject*);
};
