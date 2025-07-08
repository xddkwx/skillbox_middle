#include "DynamicArrayInt.h"

int main() {
    setlocale(LC_ALL, "rus");
    // * Проверка конструктора с параметрами
    DynamicArrayInt d_original(3,4);
    d_original.setValue(1,1,7);
    d_original.setValue(2,2,3);
    d_original.setName("Hello");
    d_original.setMoney(999.f);
    d_original.setPrefix('-');
    std::cout << "! Оригинал:\n";
    d_original.printData();
    
    // * Проверка конструктора копирования
    DynamicArrayInt d_copy(d_original);
    std::cout << "! Конструктор копирования:\n";
    d_copy.printData();
    
    // * Меняем оригинал и проверяем массив, который скопировал массив
    std::cout << "Меняем данные, не трогаем копию:\n";
    d_original.setValue(1,1,3);
    d_original.setValue(2,2,3);
    d_original.setValue(0,0,1);
    d_original.setName("Original");
    d_original.setMoney(777.f);
    d_original.setPrefix('@');
    std::cout << "! Оригинал:\n";
    d_original.printData();
    std::cout << "! Копия:\n";
    d_copy.printData();
    
    // * Проверяем оператор присваивания
    d_copy.setValue(2,1,37);
    d_copy.setValue(3,3,73);
    d_original = d_copy;
    std::cout << "Проверяем оператор присваивания:\n";
    std::cout << "! Оригинал:\n";
    d_original.printData();
    std::cout << "! Копия:\n";
    d_copy.printData();
    
    // * Создаем массив с другим размером
    DynamicArrayInt d_original2(2,2);
    d_original2.setValue(1,1,777);
    d_original2.setValue(2,2,333);
    d_copy = d_original2;
    std::cout << "Проверяем другую размерность:\n";
    std::cout << "! Оригинал:\n";
    d_original2.printData();
    std::cout << "! Копия:\n";
    d_copy.printData();

    // * Еще одна проверка
    d_original2 = d_original;
    d_original2.setName("Ex-original");
    std::cout << "! Оригинал:\n";
    d_original.printData();
    std::cout << "! Копия:\n";
    d_original2.printData();
    
    return 0;
}