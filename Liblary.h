#pragma once
#include "Book.h"
#include "Member.h"
#include "Loan.h"
#include <vector>
#include <string>
#include <algorithm>

class Liblary {
private:
    std::vector<Book> books;
    std::vector<Member> members;
    std::vector<Loan> loans;

public:
    void addBook(const Book& b) {
        books.push_back(b);
    }

    void addMember(const Member& m) {
        members.push_back(m);
    }

    bool hasBook(const std::string& isbn) const {
        return std::any_of(books.begin(), books.end(), [&](const Book& b) {
            return b.to_string().find(isbn) != std::string::npos;
            });
    }

    bool isBookAvailable(const std::string& isbn) const {
        for (const auto& loan : loans) {
            if (loan.to_string().find(isbn) != std::string::npos &&
                loan.to_string().find("Returned: No") != std::string::npos) {
                return false;
            }
        }
        return true;
    }

    bool loanBook(const std::string& isbn, const std::string& memberId, const std::string& start, const std::string& due) {
        if (!hasBook(isbn) || !isBookAvailable(isbn)) return false;
        loans.emplace_back(isbn, memberId, start, due, false);
        return true;
    }

    bool returnBook(const std::string& isbn, const std::string& memberId) {
        for (auto& loan : loans) {
            std::string loanStr = loan.to_string();
            if (loanStr.find(isbn) != std::string::npos &&
                loanStr.find(memberId) != std::string::npos &&
                loanStr.find("Returned: No") != std::string::npos) {
                loan.markReturned();
                return true;
            }
        }
        return false;
    }

    std::vector<Book> findByAuthor(const std::string& authorName) const {
        std::vector<Book> result;
        for (const auto& book : books) {
            if (book.to_string().find(authorName) != std::string::npos) {
                result.push_back(book);
            }
        }
        return result;
    }

    std::string to_string() const {
        int activeLoans = 0;
        for (const auto& loan : loans) {
            if (loan.to_string().find("Returned: No") != std::string::npos)
                activeLoans++;
        }

        return "Library info: Books: " + std::to_string(books.size()) +
            ", Members: " + std::to_string(members.size()) +
            ", Active Loans: " + std::to_string(activeLoans);
    }
};
