#include <iostream>
using namespace std;

class Exam 
{
    string* studentName;
    string* examDate;
    double* score;
public:

    Exam(string name, string date, float score) : studentName(new string(name)), examDate(new string(date)), score(new double(score)){}

    void setStudentName(string n) { *studentName = n;}
    void setExamDate(string ed) { *examDate = ed;}
    void setScore(double s) { *score = s;}

    void displayExamDetails() const 
    {
        cout << "Student Name : " << *studentName << endl;
        cout << "Exam Date :  " << *examDate << endl;
        cout << "Score : " << *score << endl;
    }

    Exam(const Exam& other) 
    {
        studentName = other.studentName;  
        examDate = other.examDate;        
        score = other.score;              
    }

    ~Exam()
    {
        delete score;
        delete examDate;
        delete score;
    }

};

int main() {
 
    Exam exam1("Danny", "23-08-2025", 88.5);

    cout << "Exam 1 Details :" << endl;
    exam1.displayExamDetails();

    Exam exam2 = exam1; 

    cout << "Exam 2 Details :" << endl;
    exam2.displayExamDetails();

    exam1.setScore(99.5);

    cout << "Updated Exam 1 Details :" << endl;
    exam1.displayExamDetails();

    cout << "Exam 2 Details After changing Exam 1 :" << endl;
    exam2.displayExamDetails();

    return 0;
}
