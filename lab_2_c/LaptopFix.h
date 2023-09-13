#pragma once
#define LEN 30 //возьмем условно длину строки

//самая основная структура "заказ", в которую входит num - номер заказа, laptop - ремонтируемый ноутбук, status - его состояние
struct Order
{
	int num;
	Laptop laptop;
	char status[LEN];
};

//структура "ноутбук", в которую входят cpu - процессор, gpu - видеокарта, ram - оперативная память, motherboard - материнская плата, display - экран и name - название модели ноутбука
struct Laptop
{
	CPU cpu;
	GPU gpu;
	RAM ram;
	Motherboard motherboard;
	Display display;
	char name[LEN];
};

//в состав cpu входят name - название процессора, frequency - его тактовая частота и num_of_cores - количество ядер
struct CPU
{
	char name[LEN];
	float frequency;
	int num_of_cores;
};

//в состав gpu входят name - название видеокарты, frequency - тактовая частота ее видеоядра и vram - объем видеопамяти
struct GPU
{
	char name[LEN];
	float frequency;
	int vram;
};

//в состав ram входят name - название модели, type - тип памяти, frequency - тактовая частота, capacity - объем оперативной памяти, 
struct RAM
{
	char name[LEN], type[LEN];
	float frequency;
	int capacity;
};

//в состав motherboard входят name - название материнской платы, socket - сокет, chipset - чипсет
struct Motherboard
{
	char name[LEN], socket[LEN], chipset[LEN];
};

//в состав display входят width - количество пиксклей по горизонтали, height - по вертикали, refresh_rate - частота
struct Display
{
	int width, height, refresh_rate;
};