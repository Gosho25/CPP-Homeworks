# Проект мини "Библиотека"

## Описание
Проектът „Библиотека“ представлява малка C++ система за управление на книги, читатели и заеми.
### Тя демонстрира основни обектно-ориентирани концепции в C++:
    - Конструктори и деструктори
    - Капсулация и достъп чрез getters и setters
    - Const-коректност и валидация на данни
    - Статични членове и методи
    - Добри ООП практики в реалистичен контекст

## Структура
     dealership/
     ├── Autor.h
     ├── Book.h
     ├── DOMASHNOCPP.png
     ├── Liblary.h
     ├── Loan.h
     ├── Member.h
     ├── README.md
     └── main.cpp
## Компилация и изпълнение
### Отворете cmd.exe(Win + r), влезте в папката на проекта и изпълнете: 
          g++ -std=c++17 -Wall -Wextra main.cpp -o "imeto".exe
### След това:
          "imeto".exe

## Примерен изход: 
    Library info: Books: 2, Members: 2, Active Loans: 1

    Title: Harry Potter, author: Name: J.K. Rowling, Birth year: 1965, year: 1997, price: 20.000000, ISBN: 978-0747532699

    After returning book:
    Library info: Books: 2, Members: 2, Active Loans: 0
