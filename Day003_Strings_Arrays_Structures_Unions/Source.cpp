#include <iostream>
#include <string>
#include <cmath>

class Point
{

private:
    int x, y;

public:

    Point()
    {
        x = 0;
        y = 0;
    }

    Point(Point& other)
    {
        x = other.x;
        y = other.y;
    }

    ~Point()
    {
        std::cout << "Destructor point at (" << x << ", " << y << ")" << std::endl;
    }

    void setPoint(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    int getX() const
    {
        return x;
    }

    int getY() const
    {
        return y;
    }

    //Operator overload

    Point operator+(Point& other)
    {
        Point newPoint;
        newPoint.x = x + other.x;
        newPoint.y = y + other.y;

        return newPoint;
    }

    Point operator-(Point& other)
    {
        Point newPoint;
        newPoint.x = x - other.x;
        newPoint.y = y - other.y;

        return newPoint;
    }

    Point operator*(Point& other)
    {
        Point newPoint;
        newPoint.x = x * other.x;
        newPoint.y = y * other.y;

        return newPoint;
    }

    Point operator/(Point& other)
    {
        if (other.x == 0 || other.y == 0)
        {
            std::cout << "Invalid to divide 0" << std::endl;
            return *this;
        }
        Point newPoint;
        newPoint.x = x - other.x;
        newPoint.y = y - other.y;

        return newPoint;
    }

    Point operator+=(Point& other)
    {
        x = x + other.x;
        y = y + other.y;

        return *this;
    }

    Point operator-=(Point& other)
    {
        x = x - other.x;
        y = y - other.y;

        return *this;
    }

    Point operator*=(Point& other)
    {
        x = x * other.x;
        y = y * other.y;

        return *this;
    }

    Point operator/=(Point& other)
    {
        if (other.x == 0 || other.y == 0)
        {
            std::cout << "Invalid to divide 0" << std::endl;
            return *this;
        }
        x = x / other.x;
        y = y / other.y;

        return *this;
    }


    Point operator*(int scalar)
    {
        Point newPoint;
        newPoint.x = x * scalar;
        newPoint.y = y * scalar;
        return newPoint;
    }

    Point operator/(int scalar)
    {
        if (scalar == 0)
        {
            std::cout << "Invalid to divide 0" << std::endl;
            return *this;
        }

        Point newPoint;
        newPoint.x = x / scalar;
        newPoint.y = y / scalar;
        return newPoint;
    }

    double getDistance(Point& other)
    {
        return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
    }
};


class Shape
{

public:
    virtual double getPerimeter() = 0;
    virtual double getArea() = 0;
    virtual std::string fromString(FILE* f);
    virtual void toString(FILE* f);
};


class Triangle : public Point, public Shape
{
private:
    Point A, B, C;

public:

    Triangle()
    {
        A.setPoint(0, 0);
        B.setPoint(0, 0);
        C.setPoint(0, 0);
    }

    void setTriangle(Point _A, Point _B, Point _C)
    {
        A.setPoint(_A.getX(), _A.getY());
        B.setPoint(_B.getX(), _B.getY());
        C.setPoint(_C.getX(), _C.getY());
    }

    double getPerimeter() override
    {
        double a = B.getDistance(C); //BC
        double b = A.getDistance(C); //AC
        double c = A.getDistance(B); //AB

        return a + b + c;
    }

    double getArea() override
    {
        double a = B.getDistance(C); //BC
        double b = A.getDistance(C); //AC
        double c = A.getDistance(B); //AB

        return a + b + c;
    }

};

int main()
{
    // Point A, B;
    // A.setPoint(1, 2);
    // B.setPoint(2, 3);

    // double dis = A.getDistance(B);
    // std::cout << dis << std::endl;
    Point p1, p2, p3;
    p1.setPoint(1, 2);
    p2.setPoint(3, 4);
    p3.setPoint(5, 6);
    std::cout << "HI";
    //Triangle t1;
    std::cout << "HI";
    // tri.setTriangle(p1, p2, p3);
    // double peri = tri.getPerimeter();
    // std::cout << peri << std::endl;
    return 0;

}