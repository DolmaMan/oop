#pragma once
#include<iostream>
#include<string>

class Point
{
private:
	float x;
	float y;
	float z;
	char* name;
public:
	Point();
	Point(float dx, float dy, float dz);

	~Point();

	void SetCoords(float dx, float dy, float dz);
	float* GetCoords();
	
	void Input();
	void Show();

	//void SaveFile(std::string path);
	//void LoadFile(std::string path);

	void SaveFileBin(std::string path);
	void LoadFileBin(std::string path);
};

