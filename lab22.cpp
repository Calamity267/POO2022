#include <iostream>
#include "Student.h"
#include "globals.h"

int main() {
    Student s1, s2;

    s1.setName("Andrei");
    s1.setMathGrade(9.5);
    s1.setEnglishGrade(8.0);
    s1.setHistoryGrade(10.0);

    s2.setName("Bogdan");
    s2.setMathGrade(8.5);
    s2.setEnglishGrade(9.0);
    s2.setHistoryGrade(9.0);

    std::cout << "Student 1: " << s1.getName() << " | Medie: " << s1.getAverage() << "\n";
    std::cout << "Student 2: " << s2.getName() << " | Medie: " << s2.getAverage() << "\n";

    std::cout << "\nComparare dupa medie: " << compareByAverage(&s1, &s2) << "\n";
    std::cout << "Comparare dupa mate: " << compareByMath(&s1, &s2) << "\n";
    std::cout << "Comparare dupa nume: " << compareByName(&s1, &s2) << "\n";

    return 0;
}