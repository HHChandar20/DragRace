#include "Car.h"
#include <iostream>

//Set default values
Car::Car()
{
    engine = 0;
    burnout = 0;
    side = 0;
    gear = 0;
    speed = 0;
    speedometer = 0;
    rpm = 0;
    carTorque = 1;
    carRPM = 1;
    Load();
}

void Car::Load()
{
    carTexture = LoadTexture("./assets/car.png");
}

void Car::BlownEngine()
{
    DrawText("Blown engine!", 750, 200, 70, DARKGRAY);
    DrawText("Press R to restart!", 775, 270, 40, DARKGRAY);
    speed = 0;

    if (IsKeyDown(KEY_R))
    {
        engine = 0;
        gear = 0;
        speedometer = 0;
        rpm = 0;
        carTorque = 1;
        carRPM = 1;
    }
}

bool Car::CheckEngine()
{
    return rpm > 10000;
}

void Car::ChangeGear()
{
    if (IsKeyPressed(KEY_SPACE) && gear != 5)
    {
        gear++;
    }
    else if (IsKeyPressed(KEY_LEFT_CONTROL) && gear != -1)
    {
        gear--;
    }
}

void Car::UpdateStatistics()
{
    speedometer = speed;

    if (gear != 0) rpm = speed * 60 * 2 / gear;

    if (rpm < 900) rpm = 900;


    carRPM = 0.8 + rpm - (gear / 1.8);
    carTorque = (carRPM - carTorque) / 3;
}

void Car::DrawStatistics()
{
    DrawText(TextFormat("%02i km/h", speedometer), 70, 50, 40, WHITE);
    DrawText(TextFormat("%03i RPM", rpm), 320, 50, 40, WHITE);
    DrawText(TextFormat("Gear: %01i", gear), 570, 50, 40, WHITE);
}

void Car::DrawCar()
{
    DrawTexture(carTexture, GetScreenWidth() / 2 - 500, GetScreenHeight() / 2 - 150 + side, WHITE);
}

int Car::GetSpeed()
{
    return speed;
}

int Car::GetGear()
{
    return gear;
}

int Car::GetSide()
{
    return side;
}

bool Car::GetBurnout()
{
    return burnout;
}

void Car::UpdateSpeed()
{
    
    if (speedometer == 0)
    {
        burnout = 0;
    }

    if (IsKeyDown(KEY_UP) && IsKeyDown(KEY_DOWN) && speedometer == 0)
    {
        burnout = 1;
    }
    
    if (IsKeyDown(KEY_UP) && gear != 0)
    {
        Accelerate();
    }
    else if (IsKeyDown(KEY_DOWN))
    {
        Brake();
    }
    else
    {
        Neutral();
    }
}

void Car::Accelerate()
{
    if (burnout)
    {
        speed += (1.f + (float)(rpm / 2000)) / (1 + (gear * 2));
    }
    else if (gear == -1)
    {
        if (speed > -20) speed += 1.2 / (1 + (gear * 3));
        else if (speed > 1) speed -= 0.40 / (1 + (gear * 3));
    }
    else if (speedometer < speedLimits[gear - 1])
    {
        speed += (1.f + (float)(rpm / 2000)) / (1 + (gear * 3));
    }
}

void Car::Brake()
{
    if (speed > 1) speed -= 0.5;
    else if (speed < -1) speed += 0.5;
}

void Car::Neutral()
{
    if (gear == -1)
    {
        if (speed < 0) speed += 0.05;
        else if (speed > 1) speed -= 0.40 / (1 + (gear * 3));
    }
    else if (speed > 1) speed -= 0.20 / (1 + (gear * 3));
}

void Car::ChangeSide()
{
    if (IsKeyDown(KEY_RIGHT) && (side < 200))
    {
        side += abs(speed / (5 * (gear + 2)));
    }
    else if (IsKeyDown(KEY_LEFT) && (side > 0))
    {
        side -= abs(speed / (5 * (gear + 2)));
    }
}

void Car::UpdateCar()
{
    if (CheckEngine())
    {
        BlownEngine();
    }
    else
    {
        if (speed == 0.0f) burnout = 0;
        UpdateStatistics();
        UpdateSpeed();
        ChangeGear();
        ChangeSide();
    }

    DrawCar();
    DrawStatistics();

}

void Car::ResetCar()
{
    speed = 0;
    engine = 0;
    gear = 0;
    speedometer = 0;
    rpm = 0;
    carTorque = 1;
    carRPM = 1;
}

Car::~Car()
{
    UnloadTexture(carTexture);
}