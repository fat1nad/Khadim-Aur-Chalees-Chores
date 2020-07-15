#pragma once

class BasicUnit
{
//This class represents the most common functions shared among classes

public:
    virtual void Update() = 0;   //Method to update child class
    virtual void Render() = 0;   //Method to render child class
};
