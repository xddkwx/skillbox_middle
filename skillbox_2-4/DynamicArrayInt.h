#pragma once

#include <iostream>
#include <string>

class DynamicArrayInt
{
private:
    int** array2d;
    int rows, cols;
    std::string* name;
    float* money;
    char* prefix;

public:
    // Конструктор с параметрами
    DynamicArrayInt(
        int r = 2,
        int c = 2, 
        const std::string& name = "Default",
        float money = 100.0f,
        char prefix = '$'
        );
    // Конструктор копирования
    DynamicArrayInt(const DynamicArrayInt& other);
    // Дестркутор
    ~DynamicArrayInt();

    // Операторы
    DynamicArrayInt& operator=(const DynamicArrayInt& other);
    
    // Вывод содержимого
    void printData();
    // Изменение данных
    void setValue(int row, int col, int value);
    void setName(const std::string& value);
    void setMoney(float value);
    void setPrefix(char value);
private:
    // т.к. мы будем это использовать несколько раз, создадим отдельные функции
    // где: в деструкторе и при операторе присваивания
    void clear();
    // где: в копирующем конструкторе и при операторе присваивания
    void deepCopy(const DynamicArrayInt& other);
};