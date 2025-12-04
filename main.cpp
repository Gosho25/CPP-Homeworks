#include <iostream>
#include "Liblary.h"

int main() {
    Liblary lib;

    Author a1("J.K. Rowling", 1965);
    Author a2("George Orwell", 1903);

    Book b1("Harry Potter", a1, 1997, 20.0, "978-0747532699");
    Book b2("1984", a2, 1949, 15.0, "978-0451524935");

    lib.addBook(b1);
    lib.addBook(b2);

    Member m1("Alice", "M001", 2020);
    Member m2("Bob", "M002", 2021);

    lib.addMember(m1);
    lib.addMember(m2);

    lib.loanBook("978-0747532699", "M001", "2025-12-01", "2025-12-15");

    std::cout << lib.to_string() << "\n\n";

    for (const auto& book : lib.findByAuthor("J.K. Rowling")) {
        std::cout << book.to_string() << "\n";
    }

    lib.returnBook("978-0747532699", "M001");

    std::cout << "\nAfter returning book:\n";
    std::cout << lib.to_string() << "\n";

    return 0;
}
