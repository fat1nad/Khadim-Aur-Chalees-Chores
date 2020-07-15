#include <iostream>

#include "Furniture.h"

using namespace std;

//This class represents all the furniture
///Note: this might be modified or abandoned

Furniture :: Furniture()
{
    furniture = new GameObject[18];   //Creating a array of all the furniture

    furniture[0] = GameObject("OtherFurniture.png", 0, 0, 48, 48, 530, 78, 96, 96);   //ToddlerCupboard
    furniture[1] = GameObject("OtherFurniture.png", 48, 10, 38, 29, 627, 96, 76, 58);   //TeddyBear
    furniture[2] = GameObject("ToddlerBed.png", 0, 10, 72, 32, 730, 120, 144, 64);   //ToddlerBed
    furniture[3] = GameObject("OtherFurniture.png", 0, 0, 48, 48, 530, 375, 96, 96);   //GrandpaCupboard
    furniture[4] = GameObject("GrandpaBed.png", 0, 8, 74, 64, 666, 403, 148, 128);   //GrandpaBed
    furniture[5] = GameObject("OtherFurniture.png", 0, 62, 34, 32, 6, 321, 68, 64);   //KitchenSinkCounter
    furniture[6] = GameObject("OtherFurniture.png", 32, 64, 32, 32, 70, 325, 64, 64);   //KitchenEmptyStoveCounter
    furniture[7] = GameObject("OtherFurniture.png", 64, 62, 34, 32, 134, 321, 68, 64);   //KitchenStoveCounter
    furniture[8] = GameObject("OtherFurniture.png", 96, 56, 40, 24, 198, 309, 80, 48);   //MicrowaveCounter
    furniture[9] = GameObject("OtherFurniture.png", 120, 57, 39, 24, 246, 311, 78, 48);   //Fridge
    furniture[10] = GameObject("OtherFurniture.png", 233, 82, 14, 7, 300, 345, 28, 14);   //DustBin
    furniture[11] = GameObject("OtherFurniture.png", 144, 48, 48, 32, 198, 570, 96, 64);   //DiningTable
    furniture[12] = GameObject("OtherFurniture.png", 176, 69, 27, 14, 262, 594, 54, 28);   //Chair
    furniture[13] = GameObject("OtherFurniture.png", 204, 66, 30, 29, 70, 476, 60, 58);   //TV
    furniture[14] = GameObject("OtherFurniture.png", 88, 118, 54, 80, 39, 585, 81, 120);   //Sofa
    furniture[15] = GameObject("OtherFurniture.png", 0, 96, 76, 32, 6, 78, 114, 48);   //Sink
    furniture[16] = GameObject("OtherFurniture.png", 60, 126, 46, 28, 134, 134, 92, 56);   //Tub
    furniture[17] = GameObject("OtherFurniture.png", 32, 114, 58, 28, 262, 88, 87, 42);   //Flush
}

Furniture :: ~Furniture()
{
    delete furniture;
}

void Furniture :: Update()   //Method to update furniture
{

}

void Furniture :: Render()   //Method to render furniture
{

}

void Furniture :: Render(GameObject* player)   //Method to render furniture with respect to the player and vice versa
{
    GameObject furniturePlayer[19];
    int minIndex;   //Index with the smallest lowerside(y coordinate + height) value GameObject for selection sort

    //Creating an array that has both the furniture and player
    for(int i = 0; i < 18; i++)
    {
        furniturePlayer[i] = furniture[i];
    }
    furniturePlayer[18] = *player;

    //Selection sort for furniture and player according to their lowerside(y coordinate + height) values
    for(int i = 0; i < 19; i++)
    {
        minIndex = i;

        for(int j = i + 1; j < 19; j++)
        {
            if((furniturePlayer[minIndex].GetY() + furniturePlayer[minIndex].GetH()) > (furniturePlayer[j].GetY() + furniturePlayer[j].GetH()))
            {
                minIndex = j;
            }
        }
        if(i != minIndex)
        {
            swap(furniturePlayer[i], furniturePlayer[minIndex]);
        }
    }

    //Rendering after sorting furniture and player
    for(int i = 0; i < 19; i++)
    {
        furniturePlayer[i].Render();
    }
}

bool Furniture :: CollisionDetection(GameObject* player)   //Method to detect collision between any furniture item and player
{
    bool collision = false;   //Bool value for overall collision detection set to false by default
    bool collFurniture[18];   //Array of bool values, each representing a furniture item's own collision detection

    //The player collides with a different sized part of each furniture sprite hence its values had to be hardcoded for each furniture item
    collFurniture[0] = furniture[0].CollisionDetection(player, 530, 154, 20, 96);   //ToddlerCupboard
    collFurniture[1] = furniture[1].CollisionDetection(player, 627, 158, 14, 58);   //TeddyBear
    collFurniture[2] = furniture[2].CollisionDetection(player, 730, 170, 94, 64);   //ToddlerBed
    collFurniture[3] = furniture[3].CollisionDetection(player, 530, 451, 20, 96);   //GrandpaCupboard
    collFurniture[4] = furniture[4].CollisionDetection(player, 666, 463, 88, 128);   //GrandpaBed
    collFurniture[5] = furniture[5].CollisionDetection(player, 6, 357, 32, 64);   //KitchenSinkCounter
    collFurniture[6] = furniture[6].CollisionDetection(player, 70, 357, 32, 64);   //KitchenEmptyStoveCounter
    collFurniture[7] = furniture[7].CollisionDetection(player, 134, 357, 32, 64);   //KitchenStoveCounter
    collFurniture[8] = furniture[8].CollisionDetection(player, 198, 361, 28, 48);   //MicrowaveCounter
    collFurniture[9] = furniture[9].CollisionDetection(player, 246, 369, 20, 48);   //Fridge
    collFurniture[10] = furniture[10].CollisionDetection(player, 300, 357, 16, 14);   //DustBin
    collFurniture[11] = furniture[11].CollisionDetection(player, 198, 594, 72, 64);   //DiningTable
    collFurniture[12] = furniture[12].CollisionDetection(player, 262, 632, 16, 26);   //Chair
    collFurniture[13] = furniture[13].CollisionDetection(player, 70, 528, 8, 58);   //TV
    collFurniture[14] = furniture[14].CollisionDetection(player, 39, 667, 26, 120);   //Sofa
    collFurniture[15] = furniture[15].CollisionDetection(player, 6, 202, 28, 48);   //Sink
    collFurniture[16] = furniture[16].CollisionDetection(player, 134, 150, 76, 56);   //Tub
    collFurniture[17] = furniture[17].CollisionDetection(player, 262, 168, 36, 42);   //Flush

    for(int i = 0; i < 18; i++)
    {
        if(collFurniture[i])   //If there is a furniture item that the player is colliding with
        {
            collision = true;
        }
    }

    return collision;
}



