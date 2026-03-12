#pragma once

class Student {
    char name[50];
    float mathGrade;
    float englishGrade;
    float historyGrade;

public:
    void setName(const char* studentName);
    const char* getName();

    void setMathGrade(float grade);
    float getMathGrade();

    void setEnglishGrade(float grade);
    float getEnglishGrade();

    void setHistoryGrade(float grade);
    float getHistoryGrade();

    float getAverage();
};