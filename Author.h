#pragma once
#include <stdexcept>
#include <string>

class Author {
private:
	std::string name;
	int birthYear;
public:
	Author() 
	: name("Unknown"), birthYear(1900) {}//default

	Author(const std::string& name, int birthYear)
		: name(name) {
		setBirthYear(birthYear);
	}

	std::string to_string() const {
		return "Name: " + name + ", Birth year: " + std::to_string(birthYear);
	}


	const std::string& getName() const { 
		return name; 
	}
	int getBirthYear() const { 
		return birthYear; 
	}


	void setBirthYear(int year) {
		if (year > 2025) {
			throw std::out_of_range("Invalid birth year");
		}
		birthYear = year;
	}
};
