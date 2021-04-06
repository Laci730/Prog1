#include <iostream>
#include <vector>
#include "check.h"

struct Person
{
	Person(std::string first_name = "-", std::string last_name = "-", int age = 1) 
	{ 
		char invalid[13] = ";:[]*&^%$#@!";
		
		bool is_valid = check(invalid, first_name);
		if (is_valid == true)
			this->first_name = first_name;
		else
			throw Wrong_name();
		
		is_valid = check(invalid, last_name);
		if (is_valid == true)
			this->last_name = last_name;
		else
			throw Wrong_name();

		if (age < 150 && age > 0)
			this->age = age;
		else
		{
			throw Wrong_age();
		}

	};
	const std::string get_name()
	{
		return first_name + " " + last_name;
	}
	const int get_age()
	{
		return age;
	}
	
	struct Wrong_name {};
	struct Wrong_age {};

private:
	std::string first_name;
	std::string last_name;
	int age = 1;
};

std::ostream& operator<<(std::ostream& os, Person& ps)
{
	return os << ps.get_name()
		<< ", " << ps.get_age();
}

Person operator>>(std::istream& is, Person& ps)
{
	std::string first_name, last_name;
	int age = 0;
	
	std::cout << "First name: ";
	is >> first_name;
	std::cout << "Last name: ";
	is >> last_name;
	std::cout << "Age: ";
	is >> age;
	ps = Person(first_name, last_name, age);
	return ps;
}

int main()
{	
	try {
		Person p("Goofy", "Boi", 63);
		Person q;
		Person r;

		vector<Person> people;
		int beker;
		std::cout << "Hany szemelyt tarolunk? ";
		std::cin >> beker;

		for (int i = 0; i < beker; i++)
		{
			cin >> r;
			people.push_back(r);
		}

		for (int i = 0; i < people.size(); i++)
			std::cout << people[i] << std::endl;

		std::cout << p << std::endl;
		std::cin >> q;
		std::cout << q << std::endl;

		return 0;
	}
	catch (Person::Wrong_name)
	{
		std::cout << "Wrong name" << std::endl;
	}
	catch (Person::Wrong_age)
	{
		std::cout << "Wrong age" << std::endl;
	}
	catch (...)
	{
		std::cout << "Error" << std::endl;
	}
}
