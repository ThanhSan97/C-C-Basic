#include <iostream>
#include <string>

using namespace std;

class Students
{
public:
    Students(string _name, string _coureseName)
    {
        name = _name;
        course.setData(_coureseName);   
    }

    void display()
    {
        cout << name << endl ; 
        course.display();
    }

    class Coures
    {
    public:
        string courseName;

        void setData(string _courseName)
        {
            courseName = _courseName;
        }

        void display()
        {
            cout << courseName << endl;
        }
    };

private:
    string name;
    Coures course;

};

int main()
{
    Students std("Toro", "AI");
    std.display();

    return 0;
}