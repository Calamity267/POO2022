#include "globals.h"
#include <cstring>

int compareByName(Student* s1, Student* s2) {
    int res = strcmp(s1->getName(), s2->getName());
    if (res == 0) return 0;
    if (res > 0) return 1;
    return -1;
}

int compareByMath(Student* s1, Student* s2) {
    if (s1->getMathGrade() == s2->getMathGrade()) return 0;
    if (s1->getMathGrade() > s2->getMathGrade()) return 1;
    return -1;
}

int compareByEnglish(Student* s1, Student* s2) {
    if (s1->getEnglishGrade() == s2->getEnglishGrade()) return 0;
    if (s1->getEnglishGrade() > s2->getEnglishGrade()) return 1;
    return -1;
}

int compareByHistory(Student* s1, Student* s2) {
    if (s1->getHistoryGrade() == s2->getHistoryGrade()) return 0;
    if (s1->getHistoryGrade() > s2->getHistoryGrade()) return 1;
    return -1;
}

int compareByAverage(Student* s1, Student* s2) {
    if (s1->getAverage() == s2->getAverage()) return 0;
    if (s1->getAverage() > s2->getAverage()) return 1;
    return -1;
}