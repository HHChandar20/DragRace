#pragma once
#include "Car.h"

class Tires
{
    public:
        Tires(Car* car);
        ~Tires();
        void Load();
        void RotateTires();
        void DrawTires();
        void UpdateTires();

    private:
        Texture2D tire;
        Rectangle sourceRec;
        Rectangle frontDestRec;
        Rectangle rearDestRec;
        float rearRotation;
        float frontRotation;
        Vector2 origin;
        Car* car;
};