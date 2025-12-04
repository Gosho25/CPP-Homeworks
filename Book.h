#pragma once
#include "Author.h"
#include <string>
#include <stdexcept>

class Book {
private:
	std::string title;
	Author author;
	int year;
	double price;
	std::string isbn;//barcode for books
	static int totalBooks;
public:
	Book()
		: title("Untitled"), author(), year(1900), price(0.0), isbn("") {

		totalBooks++;
	}
	
	Book(const std::string& title, const Author& author, int year,double price, const std::string& isbn)
		: title(title), author(author),year(year), price(price), isbn(isbn){
		setYear(year);
		setPrice(price);
		totalBooks++;
	};

	Book(const Book& other) = default;


	Book(Book&& other) noexcept = default;// &&- rvalue reference


	Book& operator=(const Book& other) = default;//за да направим обект и да зададем да има полетата на друг обект

    //взимаме ресурсите на обект и просто ги пренасяме(std::move()) в друг обект
	Book& operator=(Book&& other) noexcept = default;



	void setPrice(double p) {
		if (p < 0) throw std::invalid_argument("ERROR: Negative price is not possible !");
		price = p;
	}

	void setYear(int y) {
		if (y > 2025) throw std::invalid_argument("ERROR: is impossible the year to be >2025");
		year = y;
	}

	void setTitle(const std::string& t){
		title = t;
	}

	void setAuthor(const Author& a) {
		author = a;
	}

	void setISBN(const std::string& code) {
		isbn = code;
	}

	std::string to_string() const {
		return "Title: " + title
			+ ", author: " + author.to_string()
			+ ", year: " + std::to_string(year)
			+ ", price: " + std::to_string(price)
			+ ", ISBN: " + isbn;
	}

	static int getTotalBooks() {
		return totalBooks;
	}

	const std::string& getISBN() const { return isbn; }
	const Author& getAuthor() const { return author; }
	const std::string& getTitle() const { return title; }
	int getYear() const { return year; }
	double getPrice() const { return price; }



	~Book() {
		totalBooks--;
	}

};

inline int Book::totalBooks = 0;//za da se kompilira w .h
