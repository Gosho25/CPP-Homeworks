#pragma once
#include <string>
#include <stdexcept>


class Loan {
private:
	std::string isbn;
	std::string memberId;
	std::string startDate;
	std::string dueDate;
	bool returned;


public:
	Loan(const std::string& isbn, const std::string& memberId, const std::string& startDate, const std::string& dueDate, bool returned)
		: isbn(isbn), memberId(memberId), startDate(startDate), dueDate(dueDate), returned(returned) {

		if (dueDate < startDate) throw std::invalid_argument("dueDate must be >= startDate");
	};

	void markReturned() {
		returned = true;
	}

	bool isOverdue(const std::string& today) const {
		if (returned) return false;
		return today > dueDate;
	}

	std::string to_string() const {
		return "ISBN: " + isbn
			+ ", Member: " + memberId
			+ ", Start: " + startDate
			+ ", Due: " + dueDate
			+ ", Returned: " + (returned ? "Yes" : "No");
	}
};