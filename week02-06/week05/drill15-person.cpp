#include <iostream>
#include <vector>

void error(std::string e) {
	throw std::runtime_error (e);
}

struct Person {
	Person(std::string ffirst_name = "", std::string ssecond_name = "", int aage = 0):
	first_name(ffirst_name), second_name(ssecond_name), age(aage) {
		checkData();
	};
	std::string getName() const { return first_name + " " + second_name; };
	int getAge() const { return age; };
	void checkData();
	bool ageIsValid();
	bool nameIsValid();

private:
	std::string first_name;
	std::string second_name;
	int age;
};

void Person::checkData() {
	if (!ageIsValid()) {
		error ("Age is out of range [0; 150].");
	}
	if (!nameIsValid()) {
		error ("Name contain non alpha character.");
	}
}

bool Person::ageIsValid() {
	if (age > 150 || age < 0)
		return false;
	return true;
}

bool Person::nameIsValid() {
	for (const char i : first_name) {
		if (!isalpha(i)) {
			return false;
		}
	}
	for (const char i : second_name) {
		if (!isalpha(i)) {
			return false;
		}
	}
	return true;
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
	return os << p.getName() << " is " << p.getAge() << " years old.";
};

std::istream& operator>>(std::istream& is, Person& p) {
	std::string name1;
	std::string name2;
	int age;
	is >> name1 >> name2 >> age;
	if (!is) return is;
	p = Person {name1, name2, age};
	return is;
};

int main () 
try {
	Person gof {"Goofy", "Brown", 63};
	std::cout << gof << std::endl;

	/*Person a {};
	std::cin >> a;
	std::cout << a << std::endl;*/

	std::vector<Person> people;
	Person actual;

	std::cin >> actual;
	while (std::cin && actual.getName() != "end end") {
		people.push_back(actual);
		// std::cout << actual << std::endl;
		std::cin >> actual;
	}

	std::cout << "Input data in the vector: \n";
	for (long unsigned int i = 0; i < people.size(); ++i)
	{
		std::cout << people[i] << std::endl;
	}

	return 0;
} catch (std::runtime_error& e) {
	std::cerr << "exception:\t" << e.what() << std::endl;
	return 1;
} catch (...) {
	std::cerr << "Error :(\n";
	return 2;
}