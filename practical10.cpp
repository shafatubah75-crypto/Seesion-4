// Practical 10 - Modular grade engine
#include <iostream>
#include <string>
enum class Status { PASS, FAIL };
struct Student { int id; std::string name; double marks[3]; double average; Status status; };

double average(double a, double b, double c) { return (a + b + c) / 3.0; }
bool isPass(double avg) { return avg >= 50.0; }
char grade(double avg) {
    if (avg >= 80) return 'A';
    if (avg >= 70) return 'B';
    if (avg >= 60) return 'C';
    if (avg >= 50) return 'D';
    return 'F';
}
void printReport(const Student& s) {   // const reference: no copy, no modification
    std::cout << "ID " << s.id << " | " << s.name << " | marks " << s.marks[0] << ", " << s.marks[1]
              << ", " << s.marks[2] << " | average " << s.average << " | grade " << grade(s.average)
              << " | " << (s.status == Status::PASS ? "PASS" : "FAIL") << "\n";
}
// Scope demo: 'localValue' exists only inside this function.
void scopeDemo() {
    int localValue = 42;
    std::cout << "Inside scopeDemo: localValue = " << localValue << "\n";
}   // localValue is destroyed here; using it in main() gives "error: 'localValue' was not declared in this scope"

int main() {
    Student s{1, "Demo", {60, 70, 80}, 0, Status::FAIL};
    s.average = average(s.marks[0], s.marks[1], s.marks[2]);
    s.status = isPass(s.average) ? Status::PASS : Status::FAIL;
    printReport(s);                      // average 70, grade B

    double a, b, c;
    std::cout << "Enter three marks: ";
    if (std::cin >> a >> b >> c) {
        Student t{2, "You", {a, b, c}, average(a, b, c), Status::FAIL};
        t.status = isPass(t.average) ? Status::PASS : Status::FAIL;
        printReport(t);
    }
    scopeDemo();
    // std::cout << localValue;   // <- uncomment to see the scope error
    return 0;
}
