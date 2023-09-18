#pragma once
#define LEN 30
#define MAXCPUFREQ 9.0 //условная максимально возможная частота разгона CPU
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

//в состав cpu входят name - название процессора, frequency - его тактовая частота и num_of_cores - количество ядер
typedef struct CPU
{
	char *name;
	float frequency;
	int numOfCores;
};

//в состав gpu входят name - название видеокарты, frequency - тактовая частота ее видеоядра и vram - объем видеопамяти
typedef struct GPU
{
	char *name;
	float frequency;
	int vram;
};

//перечисление с типами оперативной памяти
typedef enum RAMTypes { DDR, DDR2, DDR3, DDR4, DDR5 };

//в состав ram входят name - название модели, type - тип памяти, frequency - тактовая частота, capacity - объем оперативной памяти, 
typedef struct RAM
{
	char* name;
	RAMTypes type;
	float frequency;
	int capacity;
};

//в состав motherboard входят name - название материнской платы, socket - сокет, chipset - чипсет
typedef struct Motherboard
{
	char *name, *socket, *chipset;
};

//в состав display входят width - количество пиксклей по горизонтали, height - по вертикали, refresh_rate - частота
typedef struct Display
{
	int width, height, refreshRate;
};

//структура "ноутбук", в которую входят cpu - процессор, gpu - видеокарта, ram - оперативная память, motherboard - материнская плата, display - экран и name - название модели ноутбука
typedef struct Laptop
{
	CPU cpu;
	GPU gpu;
	RAM ram;
	Motherboard motherboard;
	Display display;
	char* name;
};

//перечисление со статусами заказа
typedef enum StatusTypes { ONHOLD, INPROCCESS, FINISHED };

//самая основная структура "заказ", в которую входит num - номер заказа, laptop - ремонтируемый ноутбук, status - его состояние
typedef struct Order
{
	int num;
	Laptop laptop;
	StatusTypes status;
};

//вспомогательные функции

//функция для перевода RAMTypes в строку
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

//функция для перевода StatusTypes в строку
char* StatusTypeToString(StatusTypes status) {
	char* strStatus = (char*)calloc(LEN, sizeof(char));

	switch (status)
	{
	case ONHOLD:
		strcpy(strStatus, "в ожидании");
		break;
	case INPROCCESS:
		strcpy(strStatus, "в ремонте");
		break;
	case FINISHED:
		strcpy(strStatus, "готов");
		break;
	default:
		break;
	}
	return strStatus;
}

//основные функции

//функции по инициализация всех структур
CPU *CreateCPU(char *name, float frequency, int numOfCores) {
	if (strlen(name) != 0 && frequency > 0 && numOfCores > 0) {
		CPU* cpu = (CPU*)calloc(1, sizeof(CPU));
		cpu->name = (char*)calloc(LEN, sizeof(char));
		strcpy(cpu->name, name);
		cpu->frequency = frequency;
		cpu->numOfCores = numOfCores;
		return cpu;
	} 
	else {
		printf("Неправильный формат данных! Выход из программы...");
		exit(EXIT_SUCCESS);
	}
}

GPU *CreateGPU(char* name, float frequency, int vram) {
	if (strlen(name) != 0 && frequency > 0 && vram > 0) {
		GPU *gpu = (GPU*)calloc(1, sizeof(GPU));
		gpu->name = (char*)calloc(LEN, sizeof(char));
		strcpy(gpu->name, name);
		gpu->frequency = frequency;
		gpu->vram = vram;
		return gpu;
	} 
	else {
		printf("Неправильный формат данных! Выход из программы...");
		exit(EXIT_SUCCESS);
	}
}

RAM *CreateRAM(char* name, RAMTypes type, float frequency, int capacity) {
	if (strlen(name) != 0 && frequency > 0 && capacity > 0 && type >= DDR && type <= DDR5) {
		RAM* ram = (RAM*)calloc(1, sizeof(RAM));
		ram->name = (char*)calloc(LEN, sizeof(char));
		strcpy(ram->name, name);
		ram->capacity = capacity;
		ram->frequency = frequency;
		ram->type = type;
		return ram;
	} 
	else {
		printf("Неправильный формат данных! Выход из программы...");
		exit(EXIT_SUCCESS);
	}
}

Motherboard *CreateMotherboard(char* name, char *socket, char *chipset) {
	if (strlen(name) != 0 && strlen(socket) != 0 && strlen(chipset) != 0) {
		Motherboard* motherboard = (Motherboard*)calloc(1, sizeof(Motherboard));
		motherboard->name = (char*)calloc(LEN, sizeof(char));
		motherboard->socket = (char*)calloc(LEN, sizeof(char));
		motherboard->chipset = (char*)calloc(LEN, sizeof(char));
		strcpy(motherboard->name, name);
		strcpy(motherboard->socket, socket);
		strcpy(motherboard->chipset, chipset);
		return motherboard;
	} 
	else {
		printf("Неправильный формат данных! Выход из программы...");
		exit(EXIT_SUCCESS);
	}
}

Display *CreateDisplay(int width, int height, int refreshRate) {
	if (width > 0 && height > 0 && refreshRate > 0) {
		Display* display = (Display*)calloc(1, sizeof(Display));
		display->width = width;
		display->height = height;
		display->refreshRate = refreshRate;
		return display;
	}
	else {
		printf("Неправильный формат данных! Выход из программы...");
		exit(EXIT_SUCCESS);
	}
}

Laptop *CreateLaptop(CPU cpu, GPU gpu, RAM ram, Motherboard motherboard, Display display, char* name) {
	if (strlen(name) != 0) {
		Laptop *laptop = (Laptop*)calloc(1, sizeof(Laptop));
		laptop->name = (char*)calloc(LEN, sizeof(char));
		strcpy(laptop->name, name);
		laptop->cpu = cpu;
		laptop->gpu = gpu;
		laptop->ram = ram;
		laptop->motherboard = motherboard;
		laptop->display = display;
		return laptop;
	}
	else {
		printf("Неправильный формат данных! Выход из программы...");
		exit(EXIT_SUCCESS);
	}
}

Order *CreateOrder(int num, Laptop laptop, StatusTypes status) {
	if (num > 0 && status >= ONHOLD && status <= FINISHED) {
		Order* order = (Order*)calloc(1, sizeof(Order));
		order->num = num;
		order->laptop = laptop;
		order->status = status;
		return order;
	}
	else {
		printf("Неправильный формат данных! Выход из программы...");
		exit(EXIT_SUCCESS);
	}
}

//функции по вводу структур
CPU *InputCPU() {
	printf("\tВвод параметров процессора\n");

	char* name = (char*)calloc(LEN, sizeof(char)); 
	float frequency;
	int numOfCores;

	printf("Введите название процессора: ");
	gets_s(name, LEN);
	printf("Введите его тактовую частоту (в ГГц): ");
	scanf("%f", &frequency);
	printf("Введите количество ядер: ");
	scanf("%d", &numOfCores);
	while (getchar() != '\n');
	return CreateCPU(name, frequency, numOfCores);
}

GPU *InputGPU() {
	printf("\tВвод параметров видеокарты\n");

	char* name = (char*)calloc(LEN, sizeof(char));
	float frequency;
	int vram;

	printf("Введите название видеокарты: ");
	gets_s(name, LEN);
	printf("Введите тактовую частоту графического процессора (в МГц): ");
	scanf("%f", &frequency);
	printf("Введите объем видеопамяти (в ГБ): ");
	scanf("%d", &vram);
	while (getchar() != '\n');
	return CreateGPU(name, frequency, vram);
}

RAM *InputRAM() {
	printf("\tВвод параметров RAM\n");

	char* name = (char*)calloc(LEN, sizeof(char));
	RAMTypes type;
	float frequency;
	int capacity;

	printf("Введите название RAM: ");
	gets_s(name, LEN);
	printf("Введите тип памяти (DDR - 0, DDR2 - 1, DDR3 - 2, DDR4 - 3, DDR5 - 4): ");
	scanf("%d", &type);
	printf("Введите тактовую частоту (в МГц): ");
	scanf("%f", &frequency);
	printf("Введите объем (в ГБ): ");
	scanf("%d", &capacity);
	while (getchar() != '\n');
	return CreateRAM(name, type, frequency, capacity);
}

Motherboard *InputMotherboard() {
	printf("\tВвод параметров материнской платы\n");

	char *name = (char*)calloc(LEN, sizeof(char)), 
		*socket = (char*)calloc(LEN, sizeof(char)), 
		*chipset = (char*)calloc(LEN, sizeof(char));

	printf("Введите название материнской платы: ");
	gets_s(name, LEN);
	printf("Введите сокет: ");
	gets_s(socket, LEN);
	printf("Введите чипсет: ");
	gets_s(chipset, LEN);
	return CreateMotherboard(name, socket, chipset);
}

Display *InputDisplay() {
	printf("\tВвод параметров экрана\n");

	int width, height, refreshRate;

	printf("Введите ширину и высоту экрана (в пикселях): ");
	scanf("%d %d", &width, &height);
	printf("Введите частоту обновления экрана (в Гц): ");
	scanf("%d", &refreshRate);
	while (getchar() != '\n');
	return CreateDisplay(width, height, refreshRate);
}

Laptop *InputLaptop() {
	printf("\tВвод параметров ноутбука\n");

	char* name = (char*)calloc(LEN, sizeof(char));
	printf("Введите название ноутбука: ");
	gets_s(name, LEN);
	return CreateLaptop(*InputCPU(), *InputGPU(), *InputRAM(), *InputMotherboard(), *InputDisplay(), name);
}

Order *InputOrder() {
	printf("\tВвод данных заказа\n");

	int num;
	printf("Введите номер заказа: ");
	scanf("%d", &num);
	StatusTypes status;
	printf("Введите статус заказа (0 - в ожидании, 1 - в ремонте, 2 - отремонтирован): ");
	scanf("%d", &status);
	while (getchar() != '\n');
	return CreateOrder(num, *InputLaptop(), status);
}

//функции по выводу структур

void PrintLaptopInfo(Laptop laptop) {
	printf("\tИнформация о ноутбуке\n");
	printf("Название модели: %s\n", laptop.name);
	printf("CPU: %s, %.1f ГГц, %d-ядерный\n", laptop.cpu.name, laptop.cpu.frequency, laptop.cpu.numOfCores);
	printf("GPU: %s, %.1f МГц, %d ГБ\n", laptop.gpu.name, laptop.gpu.frequency, laptop.gpu.vram);
	printf("RAM: %s, %s, %d ГБ, %.1f МГц\n", laptop.ram.name, RAMTypeToString(laptop.ram.type), laptop.ram.capacity, laptop.ram.frequency);
	printf("Материнская плата: %s, %s, %s\n", laptop.motherboard.name, laptop.motherboard.socket, laptop.motherboard.chipset);
	printf("Экран: %dx%d, %d Гц\n\n", laptop.display.width, laptop.display.height, laptop.display.refreshRate);
}

void PrintOrderInfo(Order order) {
	printf("\tИнформация о заказе\n");
	printf("%d. %s\t%s\n\n", order.num, order.laptop.name, StatusTypeToString(order.status));
}

//дополнительные прикладные функции

//разгон процессора
void BoostCPU(Laptop *laptop) {
	if (laptop->cpu.frequency + 0.2 <= MAXCPUFREQ) laptop->cpu.frequency += 0.2;
	else if (laptop->cpu.frequency < MAXCPUFREQ) laptop->cpu.frequency = MAXCPUFREQ;
	else printf("Разгон CPU больше невозможен!\n");
}

//массив максимальных значений частоты для ram
static int DDRFreqMax[]{ 400, 1066, 2400, 3333, 6400 };

//разгон оперативной памяти
void BoostRAM(Laptop *laptop) {
	if (laptop->ram.frequency + 50 <= DDRFreqMax[laptop->ram.type]) laptop->ram.frequency += 50;
	else if (laptop->ram.frequency < DDRFreqMax[laptop->ram.type]) laptop->ram.frequency = DDRFreqMax[laptop->ram.type];
	else printf("Разгон RAM больше невозможен!\n");
}

//изменение статуса заказа
void ChangeType(Order *order, StatusTypes newType) {
	if (newType >= ONHOLD && newType <= FINISHED) {
		order->status = newType;
		printf("Состояние заказа успешно изменено!\n");
	}
	else {
		printf("Неправильный формат данных! Выход из программы...");
		exit(EXIT_SUCCESS);
	}
}

//освобождение памяти для объектов внутри laptop
void FreeLaptopMemory(Laptop *laptop) {
	free(laptop->name);
	free(laptop->cpu.name);
	free(laptop->gpu.name);
	free(laptop->ram.name);
	free(laptop->motherboard.name);
	free(laptop->motherboard.socket);
	free(laptop->motherboard.chipset);
}