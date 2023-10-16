#pragma once
#include "Car.h"
#include "Timer.h"
#include "Tires.h"

class Game
	{
	public:
		Game();
		~Game();
		void UpdateBackground(Car* car);
		void DrawBackground();
		void DrawControls();
		void Restart(Car* car, Timer* timer);

	private:
		const int fps = 60;
		int screenWidth = GetScreenWidth();
		int screenHeight = GetScreenHeight();
		int moveBackground;
		Texture2D background;
};