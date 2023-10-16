#include "Game.h"

Game::Game()
{
	InitWindow(screenWidth, screenHeight, "Drag Race");
	SetTargetFPS(fps);
    ToggleFullscreen();

    background = LoadTexture("assets/bg.png");
    moveBackground = 0;

    Car* car = new Car();
    Timer* timer = new Timer(car);
    Tires* tires = new Tires(car);

	while (!WindowShouldClose())
	{
        BeginDrawing();
        ClearBackground(DARKGRAY);

        UpdateBackground(car);
        DrawBackground();

        timer->UpdateTimer();
        car->UpdateCar();
        tires->UpdateTires();

        DrawControls();

        if (IsKeyPressed(KEY_R))
            Restart(car, timer);


        EndDrawing();
	}
}

void Game::UpdateBackground(Car* car)
{
    moveBackground += car->GetSpeed() / 2.0f * !car->GetBurnout();

    if (moveBackground >= 1920)
    {
        moveBackground -= 1920;
    }
    else if (moveBackground <= -1920)
    {
        moveBackground += 1920;
    }
}

void Game::DrawBackground()
{

    DrawTexture(background, -moveBackground, 0, WHITE);
    if (moveBackground < 0)
    {
        DrawTexture(background, -1920 - moveBackground, 0, WHITE);
    }
    else
    {
        DrawTexture(background, 1920 - moveBackground, 0, WHITE);
    }
}

void Game::DrawControls()
{
    DrawText("Controls:", 70, 910, 35, RAYWHITE);
    DrawText("UP - Gas                       RIGHT - Turn Right", 70, 950, 25, WHITE);
    DrawText("DOWN - Brake                LEFT - Turn Left", 70, 975, 25, WHITE);
    DrawText("SPACE - Gear up            R - Restart", 70, 1000, 25, WHITE);
    DrawText("CTRL - Gear down           UP + DOWN - Burnout", 70, 1025, 25, WHITE);
}

void Game::Restart(Car* car, Timer* timer)
{
    car->ResetCar();
    timer->ResetTimer();
}

Game::~Game()
{
    CloseWindow();
}