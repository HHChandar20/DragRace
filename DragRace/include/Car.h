#pragma once
#include <raylib.h>
#include <cmath>

class Car
{
	public:
		Car();
		~Car();

		void Load();
		void BlownEngine();
		bool CheckEngine();
		void ChangeGear();
		void UpdateStatistics();
		void DrawStatistics();
		void DrawCar();
		int GetSpeed();
		int GetGear();
		int GetSide();
		bool GetBurnout();
		void Accelerate();
		void Brake();
		void Neutral();
		void UpdateSpeed();
		void ChangeSide();
		void UpdateCar();
		void ResetCar();

	private:
		Texture2D carTexture;
		bool engine;
		bool burnout;
		int side;
		int gear;
		float speed;
		int speedometer;
		int rpm;
		int carTorque;
		int carRPM;
		int speedLimits[5] = { 38, 67, 98, 137, 217 };
};