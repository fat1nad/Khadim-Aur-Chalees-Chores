#pragma once

#include "GameObject.h"
#include "Furniture.h"

class Player : public GameObject
{
///private:
///    bool isCarryingColdMilk;
///    bool isCarryingWarmMilk;
///    bool isHeatingMilk;   ///microwave
///    bool isFeedingToddler;
///    bool isChangingDiaper;
///    bool isRockingToddler;
///    bool isCarryingToddler;
///    bool isBathingToddler;
///    bool isCooking;
///    bool isCarryingFood;
///    bool isCarryingMedicine;
///    bool isFixingTV;
///    bool isWashingFeeder;
///    bool isWashingPlate;

///microwave
///fridge
///toddlerbed
///tub
///kitchenstovecounter
///TV
///kitchensinkcounter

public:
    Player();
    Player(const char*, int, int, int, int, int, int, int, int);
    ~Player();


    void Update();
    void HandleInput(SDL_Event&, Furniture*);   //Method to handle input for the Player
};
