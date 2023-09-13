#pragma once
#define LEN 30 //������� ������� ����� ������

//����� �������� ��������� "�����", � ������� ������ num - ����� ������, laptop - ������������� �������, status - ��� ���������
struct Order
{
	int num;
	Laptop laptop;
	char status[LEN];
};

//��������� "�������", � ������� ������ cpu - ���������, gpu - ����������, ram - ����������� ������, motherboard - ����������� �����, display - ����� � name - �������� ������ ��������
struct Laptop
{
	CPU cpu;
	GPU gpu;
	RAM ram;
	Motherboard motherboard;
	Display display;
	char name[LEN];
};

//� ������ cpu ������ name - �������� ����������, frequency - ��� �������� ������� � num_of_cores - ���������� ����
struct CPU
{
	char name[LEN];
	float frequency;
	int num_of_cores;
};

//� ������ gpu ������ name - �������� ����������, frequency - �������� ������� �� ��������� � vram - ����� �����������
struct GPU
{
	char name[LEN];
	float frequency;
	int vram;
};

//� ������ ram ������ name - �������� ������, type - ��� ������, frequency - �������� �������, capacity - ����� ����������� ������, 
struct RAM
{
	char name[LEN], type[LEN];
	float frequency;
	int capacity;
};

//� ������ motherboard ������ name - �������� ����������� �����, socket - �����, chipset - ������
struct Motherboard
{
	char name[LEN], socket[LEN], chipset[LEN];
};

//� ������ display ������ width - ���������� �������� �� �����������, height - �� ���������, refresh_rate - �������
struct Display
{
	int width, height, refresh_rate;
};