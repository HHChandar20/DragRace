#include "Timer.h"

Timer::Timer(Car* car) : car(car)
{
    start = 0;
    finish = 0;
    timer = 0.0f;
    timeElapsed = 0.0f;
    timerMiliseconds = 0;
    timerSeconds = 0;
}

void Timer::DrawTimer()
{
    DrawRectangle(1500, 90, 175, 70, BLACK);

    DrawText(TextFormat("%02i.%02i", timerSeconds, timerMiliseconds), 1510, 100, 60, WHITE);
}

void Timer::UpdateTimer()
{
    start = car->GetGear();

    if (car->GetSpeed() > 100 || timerSeconds == 60 || car->CheckEngine()) finish = 1;

    if (start && !finish)
    {
        timer += 1.f; // Set timer increasing value

        if (timer >= 0.066f) // Make the timer slower
        {
            timer = 0.0f;

            timerMiliseconds++;
            if (timerMiliseconds == 60)
            {
                timerSeconds++;
                timerMiliseconds = 0;
            }
        }
    }

    DrawTimer();
}

void Timer::ResetTimer()
{
    start = 0;
    finish = 0;
    timer = 0.0f;
    timeElapsed = 0.0f;
    timerMiliseconds = 0;
    timerSeconds = 0;
}
Timer::~Timer()
{

}