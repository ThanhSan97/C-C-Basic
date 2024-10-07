#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <fstream> 


int Sum(int a, int b)
{
	return a + b;
}

int Diff(int a, int b)
{
	return a - b;
}


int main()
{
	int a, b;

	/*freopen("Text.txt", "r", stdin);

	std::cin >> a >> b;*/

	std::ifstream file;
	file.open("Text.txt");
	file >> a >> b;

	file.close();

	std::cout << "Sum(a, b) = " << Sum(a,b) << std::endl;
	std::cout << "Diff(a, b) = " << Diff(a, b) << std::endl;

}