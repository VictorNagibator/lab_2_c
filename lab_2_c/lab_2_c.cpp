#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <malloc.h>
#include "LaptopFix.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //пример работы со статической переменной
    Order staticExample = *InputOrder();
    PrintOrderInfo(staticExample);
    PrintLaptopInfo(staticExample.laptop);
    BoostRAM(&staticExample.laptop); 
    PrintLaptopInfo(staticExample.laptop);

    //и с динамической
    Order* dynamicExample = (Order*)calloc(1, sizeof(Order));
    dynamicExample = CreateOrder(2, *InputLaptop(), ONHOLD);
    PrintOrderInfo(*dynamicExample);
    PrintLaptopInfo(dynamicExample->laptop);
    BoostCPU(&dynamicExample->laptop);
    ChangeType(dynamicExample, FINISHED);
    PrintOrderInfo(*dynamicExample);
    PrintLaptopInfo(dynamicExample->laptop);
    FreeLaptopMemory(&dynamicExample->laptop);
    free(dynamicExample);
}