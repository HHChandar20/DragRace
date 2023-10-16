#include "Tires.h"

Tires::Tires(Car* car) : car(car)
{
    Load();
    sourceRec = { 0.0f, 0.0f, (float)tire.width, (float)tire.height };
    frontDestRec = { GetScreenWidth() / 2.0f + 260, GetScreenHeight() / 2.0f + 70, (float)tire.width, (float)tire.height };
    rearDestRec = { GetScreenWidth() / 2.0f - 280, GetScreenHeight() / 2.0f + 70, (float)tire.width, (float)tire.height };
    rearRotation = 0.0f;
    frontRotation = 0.0f;
    origin = { (float)tire.width / 2.0f, (float)tire.height / 2.0f };
}

void Tires::Load()
{
    tire = LoadTexture("./assets/tire.png");
}

void Tires::DrawTires()
{
    DrawTexturePro(tire, sourceRec, rearDestRec, origin, rearRotation, WHITE);
    DrawTexturePro(tire, sourceRec, frontDestRec, origin, frontRotation, WHITE);
}

void Tires::RotateTires()
{
    frontDestRec.y = GetScreenHeight() / 2.0f + car->GetSide() + 68;
    rearDestRec.y = GetScreenHeight() / 2.0f + car->GetSide() + 68;

    rearRotation += car->GetSpeed() / 2.0f;
    frontRotation += (car->GetSpeed() / 2.0f) * !car->GetBurnout();
}

void Tires::UpdateTires()
{
    RotateTires();
    DrawTires();
}

Tires::~Tires()
{
    UnloadTexture(tire);
}