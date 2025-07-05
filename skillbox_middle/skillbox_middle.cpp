#include <iostream>
#include <cmath>

class Vector
{
public:
    Vector()
    {
        x = 0;
        y = 0;
        z = 0;
    }
    Vector(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    operator float()
    {
        return sqrt(x * x + y * y + z * z);
    }

    void setX(float v) { x = v; }
    void setY(float v) { y = v; }
    void setZ(float v) { z = v; }

    friend Vector operator+(const Vector& a, const Vector& b);

    friend std::ostream& operator<<(std::ostream& out, const Vector& v);

    friend bool operator>(const Vector& a, const Vector& b);

    // * Перегрузка оператора умножения (на число)
    friend Vector operator*(const Vector& a, const float& b);
    friend Vector operator*(const float& a, const Vector& b);

    // * Перегрузка оператора разности (на вектор)
    friend Vector operator-(const Vector& a, const Vector& b);

    // * Перегрузка оператора ввода
    friend std::istream& operator>>(std::istream& in, const Vector& v);

    float operator[](int index)
    {
        switch (index)
        {
        case 0:
            return x;
            break;
        case 1:
            return y;
            break;
        case 2:
            return z;
            break;
        default:
            std::cout << "index error; zero returned";
            return 0;
            break;
        }
    }

private:
    float x;
    float y;
    float z;
};

Vector operator+(const Vector& a, const Vector& b)
{
    return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
    out << v.x << ' ' << v.y << ' ' << v.z;
    return out;
}

// * Перегрузка оператора умножения (на число)

Vector operator*(const Vector& a, const float& b)
{
    return Vector(a.x * b, a.y * b, a.z * b);
}
Vector operator*(const float& a, const Vector& b)
{
    return b * a;
}

// * Перегрузка оператора разности (на вектор)

Vector operator-(const Vector& a, const Vector& b)
{
    return Vector(a.x - b.x, a.y - b.y, a.z - b.z);
}

// * Перегрузка оператора вывода

std::istream& operator>>(std::istream& in, Vector& v)
{
    float x, y, z;

    std::cout << "X: ";
    in >> x;
    std::cout << "Y: ";
    in >> y;
    std::cout << "Z: ";
    in >> z;
       
    // Если ввод верен, то применяем изменения
    if (in)
    {
        v.setX(x);
        v.setY(y);
        v.setZ(z);
    }

    return in;
}

bool operator>(const Vector& a, const Vector& b)
{
    return false;
}

int main()
{
    setlocale(LC_ALL, "rus");
    
    Vector v1(0, 1, 2);
    Vector v2(3, 4, 5);
    Vector v3;
    v3 = v1 + v2;
    std::cout << v3 << '\n';
    std::cout << "v3 length: " << static_cast<float>(v3) << '\n';

    // * Проверка умножения
    std::wcout << L"Проверка умножения:\n";
    std::cout << "v2: " << v2 << '\n';
    std::cout << "v2 * 2: " << v2 * 2.f << '\n';
    std::cout << "2 * v2: " << 2.f * v2 << '\n';

    // * Проверка разности
    std::cout << "Проверка разности:\n";
    std::cout << "v1: " << v1 << '\n';
    std::cout << "v2: " << v2 << '\n';
    std::cout << "v2 - v1: " << v2 - v1 << '\n';
    std::cout << "v1 - v2: " << v1 - v2 << '\n';
    std::cout << "Меняем переменные вектора:\n";
    v1 = Vector(3, 2, 6);
    v2 = Vector(9, 1, 3);
    std::cout << "v1: " << v1 << '\n';
    std::cout << "v2: " << v2 << '\n';
    std::cout << "v2 - v1: " << v2 - v1 << '\n';
    std::cout << "v1 - v2: " << v1 - v2 << '\n';
    
    // * Проверяем оператор ввода
    // ! Если ввести строку/символ, то вектор не изменится
    std::cout << "Проверка ввода:\n";
    std::cin >> v3;
    std::cout << v3;
}