//#include<iostream>
//
//int main()
//{
//	std::string firstName, lastName, pid, employeeNumber;
//	int age;
//	bool gender;
//
//	firstName = "Van"; lastName = "Nguyen"; age = 29; gender = 1;
//	pid = "012345678"; employeeNumber = "11223344";
//
//	std::cout << "First name: " << firstName << std::endl << "Last name: " << lastName
//		<< std::endl << "Age: " << age << std::endl << "Gender: " << ((gender == 0) ? "Fermale" : "Male") << std::endl
//		<< "Personal ID: " << pid << std::endl << "Unique Employee number: " << employeeNumber << std::endl;
//}
#include <iostream>
#include <string>

int main()
{
    std::string name;
    std::cin >> name;

    std::cout << "Hello, " << name.length() << '\n';

    return 0;
}