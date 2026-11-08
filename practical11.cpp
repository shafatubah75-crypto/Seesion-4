
#include <iomanip>
#include <iostream>
const double PI = 3.14159265358979;
double area(double side) { return side * side; }                    // square
double area(double length, double width) { return length * width; } // rectangle
double circleArea(double radius) { return PI * radius * radius; }
void printResult(int v)    { std::cout << "Integer result: " << v << "\n"; }
void printResult(double v) { std::cout << "Result: " << std::fixed << std::setprecision(2) << v << "\n"; }

int main() {
    int choice;
    do {
        std::cout << "\n1 Square\n2 Rectangle\n3 Circle\n4 Exit\nChoice: ";
        if (!(std::cin >> choice)) { if (std::cin.eof()) return 0; std::cin.clear(); std::cin.ignore(1000, '\n'); choice = 0; }
        double x, y;
        switch (choice) {
            case 1:
                std::cout << "Side: ";
                if (std::cin >> x && x >= 0) printResult(area(x)); else { std::cout << "Invalid.\n"; return 1; }
                break;
            case 2:
                std::cout << "Length and width: ";
                if (std::cin >> x >> y && x >= 0 && y >= 0) printResult(area(x, y)); else { std::cout << "Invalid.\n"; return 1; }
                break;
            case 3:
                std::cout << "Radius: ";
                if (std::cin >> x && x >= 0) printResult(circleArea(x)); else { std::cout << "Invalid.\n"; return 1; }
                break;
            case 4: break;
            default: std::cout << "Invalid choice.\n";
        }
    } while (choice != 4);
    printResult(7);   // int overload
    return 0;
}
