#include "Point.h"
#include<iostream>
#include<fstream>

Point::Point()
{
	x = 0;
	y = 0;
	z = 0;
	std::cout << "Создана точка\n";
	name = new char[100] {"Point"};
	Show();
}

Point::Point(float dx, float dy, float dz)
{
	x = dx;
	y = dy;
	z = dz;
	std::cout << "Создана точка с ручными параметрами\n";
	name = new char[100] {"Point"};
	Show();
}

Point::~Point()
{
	std::cout << "Point delete\n";
	Show();
	delete [] name;
}

void Point::SetCoords(float dx, float dy, float dz)
{
	x = dx;
	y = dy;
	z = dz;
}

float* Point::GetCoords()
{
	float arrCoords[3] = { x, y, z };
	return arrCoords;
}

void Point::Input()
{
	std::cout << "введите: x, y, z ";
	std::cin >> x >> y >> z;
}

void Point::Show()
{
	std::cout << "X: " << x << std::endl;
	std::cout << "Y: " << y << std::endl;
	std::cout << "Z: " << z << std::endl;
}

//void Point::SaveFile(std::string path)
//{
//	std::ofstream file(path, std::ios::out);
//	file << x << " " << y << " " << z;
//}
//
//void Point::LoadFile(std::string path)
//{
//	std::ifstream file(path, std::ios::in);
//	file >> x >> y >> z;
//}

void Point::SaveFileBin(std::string path)
{
	std::ofstream file(path, std::ios::out | std::ios::binary);
	file.write((const char*)&x, sizeof(float));
	file.write((const char*)&y, sizeof(float));
	file.write((const char*)&z, sizeof(float));
}

void Point::LoadFileBin(std::string path)
{
	std::ifstream file(path, std::ios::in | std::ios::binary);
	file.read((char*)&x, sizeof(float));
	file.read((char*)&y, sizeof(float));
	file.read((char*)&z, sizeof(float));
}
