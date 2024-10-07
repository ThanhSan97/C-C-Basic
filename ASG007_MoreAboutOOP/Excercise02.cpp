#include <iostream>
#include <cmath>

class POLYGON
{
protected:
    int numSides;
    int sides[5];
    double angles[10];

public:
    POLYGON(int n) : numSides(n)
    {
        for (int i = 0; i < numSides; i++)
        {
            sides[i] = 0;
            angles[i] = 0.0;
        }
    }

    virtual double perimeter() const
    {
        double sum = 0;
        for (int i = 0; i < numSides; i++)
        {
            sum += sides[i];
        }
        return sum;
    }

    void printSides() const
    {
        for (int i = 0; i < numSides; i++)
        {
            std::cout << "Cạnh " << i + 1 << ": " << sides[i] << std::endl;
        }
    }

    void printAngles() const
    {
        for (int i = 0; i < numSides; i++)
        {
            std::cout << "Góc " << i + 1 << ": " << angles[i] << std::endl;
        }
    }

    friend void setSides(POLYGON &poly, const int newSides[]);
    friend void setAngles(POLYGON &poly, const double newAngles[]);
};

void setSides(POLYGON &poly, const int newSides[])
{
    //  sides[3] = {AB, BC, CA} ~ {c, a, b};
    for (int i = 0; i < poly.numSides; i++)
    {
        poly.sides[i] = newSides[i];
    }
}

void setAngles(POLYGON &poly, const double newAngles[])
{
    for (int i = 0; i < poly.numSides; i++)
    {
        poly.angles[i] = newAngles[i];
    }
}

class TRIANGLE : public POLYGON
{
public:
    TRIANGLE() : POLYGON(3) {}

    double perimeter() const override
    {
        return sides[0] + sides[1] + sides[2];
    }

    double area() const
    {
        double p = perimeter() / 2;
        return std::sqrt(p * (p - sides[0]) * (p - sides[1]) * (p - sides[2]));
    }

    bool isPythagorean() const
    {
        int a = sides[0], b = sides[1], c = sides[2];
        return (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a);
    }

    friend void printPytagoreanTriangles(TRIANGLE *triangles, int n);
};

void printPytagoreanTriangles(TRIANGLE *triangles, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (triangles[i].isPythagorean())
        {
            std::cout << "Tam giac thu " << i + 1 << std::endl;
            triangles[i].printSides();
        }
    }
}

class QUADRILATERAL : public POLYGON
{
public:
    QUADRILATERAL() : POLYGON(4) {}

    double perimeter() const override
    {
        return sides[0] + sides[1] + sides[2] + sides[3];
    }

    double area() const
    {
        return 0.5 * sides[0] * sides[3] * sin(angles[0]) + 0.5 * sides[1] * sides[2] * sin(angles[2]);
    }
};

void inputTriangles(TRIANGLE *triangles, int n)
{
    for (int i = 0; i < n; i++)
    {
        int sides[3];
        double angles[3];

        do
        {
            std::cout << "Nhap cac canh cua tam giac " << i + 1 << ": ";
            std::cin >> sides[0] >> sides[1] >> sides[2];
            if ((sides[0] >= sides[1] + sides[2]) || (sides[1] >= sides[0] + sides[2]) || (sides[2] >= sides[0] + sides[1]))
            {
                std::cout << "Do dai 3 canh khong hop le. Tong cua 2 canh bat ky phai lon hon canh con lai.\nVui long nhap lai!" << std::endl;
            }
        } while ((sides[0] >= sides[1] + sides[2]) || (sides[1] >= sides[0] + sides[2]) || (sides[2] >= sides[0] + sides[1]));

        setSides(triangles[i], sides);

        //Su dung BAT DANG THUC TAM GIAC de tinh toan so do cac goc trong tam giac
        for (int i = 0; i < 3; i++)
        {
            double angle = acos((pow(sides[(i + 1) % 3], 2) + pow(sides[(i + 2) % 3], 2) - pow(sides[i], 2)) / (2 * sides[(i + 1) % 3] * sides[(i + 2) % 3]));
            angles[i] = angle * 180 / 3.14159;
        }

        setAngles(triangles[i], angles);
    }
}

void showTriangles(TRIANGLE *triangles, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout<< "Thong tin tam giac thu: " << i + 1 << std:: endl;
        triangles[i].printSides();
        triangles[i].printAngles();
        std::cout << "Chu vi: " << triangles[i].perimeter() << std::endl;
        std::cout << "Dien tich : " << triangles[i].area() << std::endl;
        std::cout << "----------------------------\n";
    }
}

int main()
{
    int n;
    std::cout << "Nhap so luong tam giac: ";
    std::cin >> n;

    TRIANGLE *triangles = new TRIANGLE[n];
    
    inputTriangles(triangles, n);

    std::cout << "==== Danh sach tam giac ===" << std::endl;
    showTriangles(triangles, n);

    std::cout << "Các tam giác thỏa mãn định lý Pitago:\n";
    printPytagoreanTriangles(triangles, n);

    return 0;
}
