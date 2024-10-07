#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <sstream>
#include <list>

#define PI 3.14

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

    Point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    Point(Point &other)
    {
        x = other.x;
        y = other.y;
    }

    // ~Point()
    // {
    //     std::cout<<"Destructor point at (" << x <<", " << y <<")" << std::endl;
    // }

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

    void display() const
    {
        std::cout << "(" << x << ", " << y << ")";
    }

    // Operator overload
    Point operator+(Point &other)
    {
        Point newPoint;
        newPoint.x = x + other.x;
        newPoint.y = y + other.y;

        return newPoint;
    }

    Point operator-(Point &other)
    {
        Point newPoint;
        newPoint.x = x - other.x;
        newPoint.y = y - other.y;

        return newPoint;
    }

    Point operator*(Point &other)
    {
        Point newPoint;
        newPoint.x = x * other.x;
        newPoint.y = y * other.y;

        return newPoint;
    }

    Point operator/(Point &other)
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

    Point operator+=(Point &other)
    {
        x = x + other.x;
        y = y + other.y;

        return *this;
    }

    Point operator-=(Point &other)
    {
        x = x - other.x;
        y = y - other.y;

        return *this;
    }

    Point operator*=(Point &other)
    {
        x = x * other.x;
        y = y * other.y;

        return *this;
    }

    Point operator/=(Point &other)
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

    double getDistance(Point &other)
    {
        return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
    }

    std::string toString() const
    {
        return std::to_string(x) + " " + std::to_string(y);
    }
};

class Shape
{

public:
    virtual double getPerimeter() = 0;
    virtual double getArea() = 0;
    virtual void fromString(std::string str)
    {
        std::cout << "Shape";
    }
    virtual std::string toString()
    {
        return "";
    }
    virtual void display()
    {
        std::cout << "Shape";
    }
};

class Triangle : public Shape
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
    Triangle(Point _A, Point _B, Point _C) : A(_A), B(_B), C(_C) {}

    double getPerimeter() override
    {
        double a = B.getDistance(C); // BC
        double b = A.getDistance(C); // AC
        double c = A.getDistance(B); // AB

        return a + b + c;
    }

    double getArea() override
    {
        double p = getPerimeter() / 2;
        double a = B.getDistance(C); // BC
        double b = A.getDistance(C); // AC
        double c = A.getDistance(B); // AB

        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    void display() override
    {
        std::cout << "Triangle with points: ";
        A.display();
        std::cout << ", ";
        B.display();
        std::cout << ", ";
        C.display();
        std::cout << std::endl;
        std::cout << "Perimeter: " << getPerimeter() << std::endl;
        std::cout << "Area: " << getArea() << std::endl;
    }

    std::string toString() override
    {
        return "0 " + A.toString() + " " + B.toString() + " " + C.toString();
    }

    void fromString(std::string str) override
    {
        std::istringstream iss(str);

        int type;
        iss >> type; 
        int x1, y1, x2, y2, x3, y3;
        iss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        A = Point(x1, y1);
        B = Point(x2, y2);
        C = Point(x3, y3);
    }
};

class Rectangle : public Shape
{
private:
    Point center;
    int width, height;

public:
    Rectangle()
    {
        center.setPoint(0, 0);
        width = 0;
        height = 0;
    }
    Rectangle(Point p, int w, int h) : center(p), width(w), height(h) {}

    double getPerimeter() override
    {
        return (height + width) / 2;
    }

    double getArea() override
    {
        return height * width;
    }

    void display() override
    {
        std::cout << "Rectangle with center: ";
        center.display();
        std::cout << ", width = " << width << ", height = " << height << std::endl;
        std::cout << "Perimeter: " << getPerimeter() << std::endl;
        std::cout << "Area: " << getArea() << std::endl;
    }

    std::string toString() override
    {
        return "1 " + center.toString() + " " + std::to_string(width) + " " + std::to_string(height);
    }

    void fromString(std::string str) override
    {
        std::istringstream iss(str);
        int type;
        iss >> type; 
        int x, y, w, h;
        iss >> x >> y >> w >> h;
        center = Point(x, y);
        width = w;
        height = h;
    }
};

class Circle : public Shape
{
private:
    Point center;
    int r;

public:
    Circle()
    {
        center.setPoint(0, 0);
        r = 0;
    }

    Circle(Point p, int _r) : center(p), r(_r) {}

    double getPerimeter() override
    {
        return 2 * PI * r;
    }

    double getArea() override
    {
        return PI * r * r;
    }

    void display() override
    {
        std::cout << "Circle with center: ";
        center.display();
        std::cout << ", r = " << r << std::endl;
        std::cout << "Perimeter: " << getPerimeter() << std::endl;
        std::cout << "Area: " << getArea() << std::endl;
    }

    std::string toString() override
    {
        return "2 " + center.toString() + " " + std::to_string(r);
    }

    void fromString(std::string str) override
    {
        std::istringstream iss(str);
        int type;
        iss >> type; 
        int x, y, _r;
        iss >> x >> y >> _r;
        center = Point(x, y);
        r = _r;
    }
};

class Ellipse : public Shape
{
private:
    Point center;
    int rx, ry;

public:
    Ellipse()
    {
        center.setPoint(0, 0);
        rx = 0;
        ry = 0;
    }

    Ellipse(Point p, int r1, int r2) : center(p), rx(r1), ry(r2) {}

    double getPerimeter() override
    {
        return PI * (3 * (rx + ry) - sqrt((3 * rx + ry) * (rx + 3 * ry)));
    }

    double getArea() override
    {
        return PI * rx * ry;
    }

    void display() override
    {
        std::cout << "Ellipse with center: ";
        center.display();
        std::cout << ", rx = " << rx << ", ry = " << ry << std::endl;
        std::cout << "Perimeter: " << getPerimeter() << std::endl;
        std::cout << "Area: " << getArea() << std::endl;
    }

    std::string toString() override
    {
        return "3 " + center.toString() + " " + std::to_string(rx) + " " + std::to_string(ry);
    }

    void fromString(std::string str) override
    {
        std::istringstream iss(str);
        int type;
        iss >> type; 
        int x, y, r1, r2;
        iss >> x >> y >> r1 >> r2;
        center = Point(x, y);
        rx = r1;
        ry = r2;
    }
};

class ShapeFactory
{

private:
    std::list<Shape*> l;

public:
    std::list<Shape*> readShapesFromFile(const std::string &filename)
    {
        std::ifstream inFile(filename);
        if (!inFile)
        {
            std::cout << "Can not open this file to read data!" << std::endl;
            return l;
        }

        std::string line;
        int i = 0;
        while (std::getline(inFile, line))
        {
            int type;
            std::istringstream iss(line);
            iss >> type;

            Shape *shape = nullptr;

            switch (type)
            {
            case 0:
            { // Triangle
                shape = new Triangle();
                shape->fromString(line);
                break;
            }
            case 1:
            { // Rectangle
                shape = new Rectangle();
                shape->fromString(line);
                break;
            }
            case 2:
            { // Circle
                shape = new Circle();
                shape->fromString(line);
                break;
            }
            case 3:
            { // Ellipse
                shape = new Ellipse();
                shape->fromString(line);
                break;
            }
            default:
                std::cout << "Shape invaldi!" << std::endl;
                continue;
            }

            l.push_back(shape);
            std::cout << i + 1 << ".";
            shape->display();
            std::cout<< std::endl;
            i++;
            delete shape;
        }

        inFile.close();
    }

    void writeToFile(const std::string &filename, std::string &shapeInfo)
    {
        std::ofstream outFile(filename);
        if (!outFile)
        {
            std::cout << "Can not open this file to write data!" << std::endl;
            return;
        }

        outFile << shapeInfo;
        std::cout << "Shape infor added!" << std::endl;
        outFile.close();
    }
};

int main()
{
    ShapeFactory sp;
    sp.readShapesFromFile("data.txt");
    return 0;
}