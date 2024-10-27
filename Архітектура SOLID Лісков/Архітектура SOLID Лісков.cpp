#include <iostream>
#include <windows.h>
using namespace std;

class Rectan {
protected:
    double width;
    double height;

public:
    Rectan(double w, double h) : width(w), height(h) {}

    void setWidth(double w) {
        width = w;
    }

    void setHeight(double h) {
        height = h;
    }

    double getArea() const {
        return width * height;
    }
};

class Square {
private:
    double side;

public:
    Square(double s) : side(s) {}

    void setSide(double s) {
        side = s;
    }

    double getArea() const {
        return side * side;
    }
};

void printRectanArea(const Rectan& rect) {
    cout << "Площа прямокутника: " << rect.getArea() << endl;
}

void printSquareArea(const Square& square) {
    cout << "Площа квадрата: " << square.getArea() << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Rectan rect(5, 10);
    Square square(5);

    printRectanArea(rect);   // Площа: 50
    printSquareArea(square);    // Площа: 25

}

//Неправильний код!!! знизу
/*
#include <iostream>

class Rectangle {
protected:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    virtual void setWidth(double w) {
        width = w;
    }

    virtual void setHeight(double h) {
        height = h;
    }

    double getArea() const {
        return width * height;
    }
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}


    void setWidth(double side) override {
        width = side;
        height = side;
    }

    void setHeight(double side) override {
        width = side;
        height = side;
    }
};

void printArea(Rectangle& rect) {                   <-------- !!!!
    rect.setWidth(5);
    rect.setHeight(10);
     cout << "Площа: " << rect.getArea() << endl;
}

int main() {
    Rectangle rect(2, 3);
    Square square(5);

    printArea(rect);    // Очікувана площа: 50 (5 * 10)
    printArea(square);  // Некоректна площа: 100 (5 * 5 замість 5 * 10)

    return 0;
}

*/
