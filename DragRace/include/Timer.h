#pragma once
#include "Car.h"

class Timer
{
    public:
        Timer(Car* car);
        ~Timer();
        void DrawTimer();
        void UpdateTimer();
        void ResetTimer();

    private:
        bool start;
        bool finish;
        float timer;
        float timeElapsed;
        int timerMiliseconds;
        int timerSeconds;
        Car* car;
};