#include  <iostream>

using namespace std;

class Complex
{
    private:
        double real, imaginary;

    public:
        
        Complex(double real, double imaginary) :  real(real), imaginary(imaginary){}
        void display() const
        {
            cout<<"Value: " << real << " + " << imaginary << "i" << endl;
        }

        friend Complex add2Complex(Complex c1, Complex c2);

};

Complex add2Complex(Complex c1, Complex c2)
{
    double realSum = c1.real + c2.real;
    double realImag = c1.imaginary + c2.imaginary;
    return Complex(realSum, realImag);
}


int main()
{
    Complex c1(3.00, 2.00);
    Complex c2(2.00, 1.00);
    Complex sum = add2Complex(c1, c2);

    cout<<"C1: ";   c1.display();
    cout<<"C2: ";   c2.display();
    cout<<"Sum: ";  sum.display();

}