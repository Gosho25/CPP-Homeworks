#pragma once
#include <iostream>
#include <stdexcept>
#include <cctype>

class Member {
private:
	std::string name;
	std::string memberId;
	int yearJoined;
public:
	Member() = default;

	Member(const std::string& name, const std::string& memberId, int yearJoined)
		: name(name), memberId(memberId), yearJoined(yearJoined){};


	void setName(const std::string& n) {
		if (n.empty())
			throw std::invalid_argument("ERROR: The name can't be empty!");

		// Проверка дали целият низ е число
		bool allDigits = true;
		for (char c : n) {
			if (!isdigit(c)) {
				allDigits = false;
				break;
			}
		}

		if (allDigits)
			throw std::invalid_argument("ERROR: The name can't be a number!");

		name = n;
	}

	void setMemberID(const std::string& mI) {
		if (mI.empty()) throw std::invalid_argument("ERROR: The memberId cant be empty");
		memberId =  mI;
	}

	void setYearJoined(int yJoin) {
		if(yJoin > 2025) throw std::invalid_argument("ERROR: Invalid year");
		yearJoined = yJoin;
	}

	std::string to_string() const {
		return "Name: " + name
			+ ", Member ID: (" + memberId + ")"
			+ ", Year Joined: " + std::to_string(yearJoined);
	}


	~Member()= default;
};