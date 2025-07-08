#include "DynamicArrayInt.h"

DynamicArrayInt::DynamicArrayInt(
    int r,
    int c,
    const std::string& name,
    float money,
    char prefix) : rows(r),cols(c)
{
    array2d = new int*[rows];
    for (int i = 0; i < rows; ++i)
    {
        array2d[i] = new int[cols]();   // ! Инициализация нулями
    }

    this->name = new std::string(name);
    this->money = new float(money);
    this->prefix = new char(prefix);
}

DynamicArrayInt::DynamicArrayInt(const DynamicArrayInt& other)
{
    deepCopy(other);
}

DynamicArrayInt::~DynamicArrayInt()
{
    std::cout << "clear!\n";
    clear();
}

DynamicArrayInt& DynamicArrayInt::operator=(const DynamicArrayInt& other)
{
    clear();
    deepCopy(other);
    return *this;
}

void DynamicArrayInt::printData()
{
    std::cout << "Name: " << *name << '\n';
    std::cout << "Money: " << *money << '\n';
    std::cout << "Prefix: " << *prefix << '\n';
    std::cout << "2D Array [" << rows << "x" << cols << "]\n";
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << array2d[i][j] << ", ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void DynamicArrayInt::setValue(int row, int col, int value)
{
    // Проверки
    if (row >= 0 && row < rows && col >= 0 && col < cols)
    {
        array2d[row][col] = value;
    }
}

void DynamicArrayInt::setName(const std::string& value)
{
    *name = value;
}

void DynamicArrayInt::setMoney(float value)
{
    *money = value;
}

void DynamicArrayInt::setPrefix(char value)
{
    *prefix = value;
}

// * Очистка
void DynamicArrayInt::clear()
{
    for (int i = 0; i < rows; ++i)
    {
        delete[] array2d[i];
    }
    delete[] array2d;

    delete name;
    delete money;
    delete prefix;
}


// * Глубокое копирование
void DynamicArrayInt::deepCopy(const DynamicArrayInt& other)
{
    // Копирование размеров
    rows = other.rows;
    cols = other.cols;

    // Копирование массива
    array2d = new int*[rows];
    for (int i = 0; i < rows; ++i)
    {
        array2d[i] = new int[cols];
        for (int j = 0; j < cols; ++j)
        {
            array2d[i][j] = other.array2d[i][j];
        }
    }

    // Копирование остальных параметров
    name = new std::string(*other.name);
    money = new float(*other.money);
    prefix = new char(*other.prefix);
}
