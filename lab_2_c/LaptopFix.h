#pragma once
#define LEN 30
#define MAXCPUFREQ 9.0 //�������� ����������� ��������� ������� ������� CPU
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

//� ������ cpu ������ name - �������� ����������, frequency - ��� �������� ������� � num_of_cores - ���������� ����
typedef struct CPU
{
	char *name;
	float frequency;
	int numOfCores;
};

//� ������ gpu ������ name - �������� ����������, frequency - �������� ������� �� ��������� � vram - ����� �����������
typedef struct GPU
{
	char *name;
	float frequency;
	int vram;
};

//������������ � ������ ����������� ������
typedef enum RAMTypes { DDR, DDR2, DDR3, DDR4, DDR5 };

//� ������ ram ������ name - �������� ������, type - ��� ������, frequency - �������� �������, capacity - ����� ����������� ������, 
typedef struct RAM
{
	char* name;
	RAMTypes type;
	float frequency;
	int capacity;
};

//� ������ motherboard ������ name - �������� ����������� �����, socket - �����, chipset - ������
typedef struct Motherboard
{
	char *name, *socket, *chipset;
};

//� ������ display ������ width - ���������� �������� �� �����������, height - �� ���������, refresh_rate - �������
typedef struct Display
{
	int width, height, refreshRate;
};

//��������� "�������", � ������� ������ cpu - ���������, gpu - ����������, ram - ����������� ������, motherboard - ����������� �����, display - ����� � name - �������� ������ ��������
typedef struct Laptop
{
	CPU cpu;
	GPU gpu;
	RAM ram;
	Motherboard motherboard;
	Display display;
	char* name;
};

//������������ �� ��������� ������
typedef enum StatusTypes { ONHOLD, INPROCCESS, FINISHED };

//����� �������� ��������� "�����", � ������� ������ num - ����� ������, laptop - ������������� �������, status - ��� ���������
typedef struct Order
{
	int num;
	Laptop laptop;
	StatusTypes status;
};

//��������������� �������

//������� ��� �������� RAMTypes � ������
char* RAMTypeToString(RAMTypes type) {
	char* strType = (char*)calloc(LEN, sizeof(char));

	switch (type)
	{
	case DDR:
		strcpy(strType, "DDR");
		break;
	case DDR2:
		strcpy(strType, "DDR2");
		break;
	case DDR3:
		strcpy(strType, "DDR3");
		break;
	case DDR4:
		strcpy(strType, "DDR4");
		break;
	case DDR5:
		strcpy(strType, "DDR5");
		break;
	default:
		break;
	}
	return strType;
}

//������� ��� �������� StatusTypes � ������
char* StatusTypeToString(StatusTypes status) {
	char* strStatus = (char*)calloc(LEN, sizeof(char));

	switch (status)
	{
	case ONHOLD:
		strcpy(strStatus, "� ��������");
		break;
	case INPROCCESS:
		strcpy(strStatus, "� �������");
		break;
	case FINISHED:
		strcpy(strStatus, "�����");
		break;
	default:
		break;
	}
	return strStatus;
}

//�������� �������

//������� �� ������������� ���� ��������
CPU CreateCPU(char *name, float frequency, int numOfCores) {
	if (strlen(name) != 0 && frequency > 0 && numOfCores > 0) {
		CPU cpu{ name, frequency, numOfCores };
		return cpu;
	} 
	else {
		printf("������������ ������ ������! ����� �� ���������...");
		exit(EXIT_SUCCESS);
	}
}

GPU CreateGPU(char* name, float frequency, int vram) {
	if (strlen(name) != 0 && frequency > 0 && vram > 0) {
		GPU gpu{ name, frequency, vram };
		return gpu;
	} 
	else {
		printf("������������ ������ ������! ����� �� ���������...");
		exit(EXIT_SUCCESS);
	}
}

RAM CreateRAM(char* name, RAMTypes type, float frequency, int capacity) {
	if (strlen(name) != 0 && frequency > 0 && capacity > 0 && type >= DDR && type <= DDR5) {
		RAM ram{ name, type, frequency, capacity };
		return ram;
	} 
	else {
		printf("������������ ������ ������! ����� �� ���������...");
		exit(EXIT_SUCCESS);
	}
}

Motherboard CreateMotherboard(char* name, char *socket, char *chipset) {
	if (strlen(name) != 0 && strlen(socket) != 0 && strlen(chipset) != 0) {
		Motherboard motherboard{ name, socket, chipset };
		return motherboard;
	} 
	else {
		printf("������������ ������ ������! ����� �� ���������...");
		exit(EXIT_SUCCESS);
	}
}

Display CreateDisplay(int width, int height, int refreshRate) {
	if (width > 0 && height > 0 && refreshRate > 0) {
		Display display{ width, height, refreshRate };
		return display;
	}
	else {
		printf("������������ ������ ������! ����� �� ���������...");
		exit(EXIT_SUCCESS);
	}
}

Laptop CreateLaptop(CPU cpu, GPU gpu, RAM ram, Motherboard motherboard, Display display, char* name) {
	if (strlen(name) != 0) {
		Laptop laptop{ cpu, gpu, ram, motherboard, display, name };
		return laptop;
	}
	else {
		printf("������������ ������ ������! ����� �� ���������...");
		exit(EXIT_SUCCESS);
	}
}

Order CreateOrder(int num, Laptop laptop, StatusTypes status) {
	if (num > 0 && status >= ONHOLD && status <= FINISHED) {
		Order order{ num, laptop, status };
		return order;
	}
	else {
		printf("������������ ������ ������! ����� �� ���������...");
		exit(EXIT_SUCCESS);
	}
}

//������� �� ����� ��������
CPU InputCPU() {
	printf("\t���� ���������� ����������\n");

	char* name = (char*)calloc(LEN, sizeof(char)); 
	float frequency;
	int numOfCores;

	printf("������� �������� ����������: ");
	gets_s(name, LEN);
	printf("������� ��� �������� ������� (� ���): ");
	scanf("%f", &frequency);
	printf("������� ���������� ����: ");
	scanf("%d", &numOfCores);
	return CreateCPU(name, frequency, numOfCores);
}

GPU InputGPU() {
	printf("\t���� ���������� ����������\n");

	char* name = (char*)calloc(LEN, sizeof(char));
	float frequency;
	int vram;

	printf("������� �������� ����������: ");
	gets_s(name, LEN);
	printf("������� �������� ������� ������������ ���������� (� ���): ");
	scanf("%f", &frequency);
	printf("������� ����� ����������� (� ��): ");
	scanf("%d", &vram);
	return CreateGPU(name, frequency, vram);
}

RAM InputRAM() {
	printf("\t���� ���������� RAM\n");

	char* name = (char*)calloc(LEN, sizeof(char));
	RAMTypes type;
	float frequency;
	int capacity;

	printf("������� �������� RAM: ");
	gets_s(name, LEN);
	printf("������� ��� ������ (DDR - 0, DDR2 - 1, DDR3 - 2, DDR4 - 3, DDR - 4): ");
	scanf("%d", &type);
	printf("������� �������� ������� (� ���): ");
	scanf("%f", &frequency);
	printf("������� �����: ");
	scanf("%d", &capacity);
	return CreateRAM(name, type, frequency, capacity);
}

Motherboard InputMotherboard() {
	printf("\t���� ���������� ����������� �����\n");

	char *name = (char*)calloc(LEN, sizeof(char)), 
		*socket = (char*)calloc(LEN, sizeof(char)), 
		*chipset = (char*)calloc(LEN, sizeof(char));

	printf("������� �������� ����������� �����: ");
	gets_s(name, LEN);
	printf("������� �����: ");
	gets_s(socket, LEN);
	printf("������� ������: ");
	gets_s(chipset, LEN);
	return CreateMotherboard(name, socket, chipset);
}

Display InputDisplay() {
	printf("\t���� ���������� ������\n");

	int width, height, refreshRate;

	printf("������� ������ � ������ ������ (� ��������): ");
	scanf("%d %d", &width, &height);
	printf("������� ������� ���������� ������ (� ��): ");
	scanf("%d", &refreshRate);
	return CreateDisplay(width, height, refreshRate);
}

Laptop InputLaptop() {
	printf("\t���� ���������� ��������\n");

	char* name = (char*)calloc(LEN, sizeof(char));
	printf("������� �������� ��������: ");
	gets_s(name, LEN);
	return CreateLaptop(InputCPU(), InputGPU(), InputRAM(), InputMotherboard(), InputDisplay(), name);
}

Order InputOrder() {
	printf("\t���� ������ ������\n");

	int num;
	printf("������� ����� ������: ");
	scanf("%d", &num);
	StatusTypes status;
	printf("������� ������ ������ (0 - � ��������, 1 - � �������, 2 - ��������������): ");
	scanf("%d", &status);
	return CreateOrder(num, InputLaptop(), status);
}

//������� �� ������ ��������

void PrintLaptopInfo(Laptop laptop) {
	printf("\t���������� � ��������\n");
	printf("�������� ������: %s\n", laptop.name);
	printf("CPU: %s, %.1f ���, %d-�������\n", laptop.cpu.name, laptop.cpu.frequency, laptop.cpu.numOfCores);
	printf("GPU: %s, %.1f ���, %d ��\n", laptop.gpu.name, laptop.gpu.frequency, laptop.gpu.vram);
	printf("GPU: %s, %.1f ���, %d ��\n", laptop.gpu.name, laptop.gpu.frequency, laptop.gpu.vram);
	printf("RAM: %s, %s, %d ��, %.1f ���\n", laptop.ram.name, RAMTypeToString(laptop.ram.type), laptop.ram.capacity, laptop.ram.frequency);
	printf("����������� �����: %s, %s, %s\n", laptop.motherboard.name, laptop.motherboard.socket, laptop.motherboard.chipset);
	printf("�����: %dx%d, %d ��\n", laptop.display.width, laptop.display.height, laptop.display.refreshRate);
}

void PrintOrderInfo(Order order) {
	printf("\t���������� � ������\n");
	printf("%d.\t%s\t%s\n", order.num, order.laptop.name, StatusTypeToString(order.status));
}

//�������������� ���������� �������

//������ ����������
Laptop BoostCPU(Laptop laptop) {
	if (laptop.cpu.frequency + 0.2 <= MAXCPUFREQ) laptop.cpu.frequency += 0.2;
	else if (laptop.cpu.frequency < MAXCPUFREQ) laptop.cpu.frequency = MAXCPUFREQ;
	else printf("������ CPU ������ ����������!\n");
	return laptop;
}

//������ ������������ �������� ������� ��� ram
static int DDRFreqMax[]{ 400, 1066, 2400, 3333, 6400 };

//������ ����������� ������
Laptop BoostRAM(Laptop laptop) {
	if (laptop.ram.frequency + 50 <= DDRFreqMax[laptop.ram.type]) laptop.ram.frequency += 50;
	else if (laptop.ram.frequency < DDRFreqMax[laptop.ram.type]) laptop.ram.frequency = DDRFreqMax[laptop.ram.type];
	else printf("������ RAM ������ ����������!\n");
	return laptop;
}

//��������� ������� ������
Order ChangeType(Order order, StatusTypes newType) {
	if (newType >= ONHOLD && newType <= FINISHED) {
		order.status = newType;
		printf("��������� ������ ������� ��������!\n");
		return order;
	}
	else {
		printf("������������ ������ ������! ����� �� ���������...");
		exit(EXIT_SUCCESS);
	}
}