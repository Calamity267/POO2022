#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include <cstring>

void Student::setName(const char* studentName) {
    strcpy(this->name, studentName);
}

const char* Student::getName() {
    return this->name;
}

void Student::setMathGrade(float grade) {
    if (grade >= 1.0f && grade <= 10.0f) {
        this->mathGrade = grade;
    }
}

float Student::getMathGrade() {
    return this->mathGrade;
}

void Student::setEnglishGrade(float grade) {
    if (grade >= 1.0f && grade <= 10.0f) {
        this->englishGrade = grade;
    }
}

float Student::getEnglishGrade() {
    return this->englishGrade;
}

void Student::setHistoryGrade(float grade) {
    if (grade >= 1.0f && grade <= 10.0f) {
        this->historyGrade = grade;
    }
}

float Student::getHistoryGrade() {
    return this->historyGrade;
}

float Student::getAverage() {
    return (this->mathGrade + this->englishGrade + this->historyGrade) / 3.0f;
}