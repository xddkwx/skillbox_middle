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

    explicit Vector(float num) = delete;
    
    Vector(float x, float y, float z)
    {
        std::cout<<"Constructor \n";
        this->x = x;
        this->y = y;
        this->z = z;
    }
    
    Vector(const Vector& other)
    {
        std::cout<<"Copy constructor \n";
        x = other.x;
        y = other.y;
        z = other.z;
    }

    ~Vector()
    {
        std::cout<<"destructor calling\n";
    }

    Vector& operator=(Vector& other)
    {
        std::cout << "operator=\n";
        x = other.x;
        y = other.y;
        z = other.z;
        // если бы был
        /*
         * if (other.Info)
         * {
         *      if (Info) delete Info;
         *      Info = new std::string(*other.Info);
         * }
         */
        return (*this);
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

// ! Запомнить
class A
{
public:
    A(int a)
    {
         test = a;
    }
    A(char a) = delete;
private:
    int test;
};

int main()
{
    setlocale(LC_ALL, "rus");
    Vector v1(1,2,3);
    Vector v2(3,4,5);
    v2 = v1;
}