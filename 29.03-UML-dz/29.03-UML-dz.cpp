#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Data class to store date information
class Date {
public:
    int day;
    int month;
    int year;

    Date(int d, int m, int y) : day(d), month(m), year(y) {}
};

// Data class for storing address information
class Address {
public:
    string country;
    string region;
    string city;
    string street;
    int houseNumber;
    char buildingSection;

    Address(string cn, string rg, string ct, string st, int hn, char bs)
        : country(cn), region(rg), city(ct), street(st), houseNumber(hn), buildingSection(bs) {}
};

// Abstract base class for personal details
class PersonalDetails {
public:
    string firstName;
    string lastName;
    Date* birthDate;
    Address* homeAddress;

    PersonalDetails(string fn, string ln, Date* bd, Address* ha)
        : firstName(fn), lastName(ln), birthDate(bd), homeAddress(ha) {}

    virtual void displayDetails() const = 0;
};

// Concrete implementation for Student's personal details
class StudentPersonalDetails : public PersonalDetails {
public:
    StudentPersonalDetails(string fn, string ln, Date* bd, Address* ha)
        : PersonalDetails(fn, ln, bd, ha) {}

    void displayDetails() const override {
        cout << "Student Name: " << firstName << " " << lastName << endl;
        cout << "Birth Date: " << birthDate->day << "/" << birthDate->month << "/" << birthDate->year << endl;
        cout << "Address: " << homeAddress->street << ", " << homeAddress->city << endl;
    }
};

// Class to manage educational details
class EducationDetails {
public:
    Date startDate;
    int currentCourse;
    string groupName;
    string specialization;

    EducationDetails(Date sd, int cc, string gn, string sp)
        : startDate(sd), currentCourse(cc), groupName(gn), specialization(sp) {}

    void displayEducation() const {
        cout << "Start Date: " << startDate.year << endl;
        cout << "Course: " << currentCourse << endl;
        cout << "Group: " << groupName << endl;
        cout << "Specialization: " << specialization << endl;
    }
};

// Class to store and manage grades
class Grades {
public:
    vector<int> homeworkGrades;
    vector<int> examGrades;

    void addGrade(int grade, bool isExam) {
        if (isExam) {
            examGrades.push_back(grade);
        } else {
            homeworkGrades.push_back(grade);
        }
    }
};

// Class representing a student combining personal and educational details
class Student {
private:
    StudentPersonalDetails* personalDetails;
    EducationDetails* educationDetails;
    Grades* grades;

public:
    Student(StudentPersonalDetails* spd, EducationDetails* ed, Grades* g)
        : personalDetails(spd), educationDetails(ed), grades(g) {}

    void displayStudentInfo() {
        personalDetails->displayDetails();
        educationDetails->displayEducation();
    }

    void addGrade(int grade, bool isExam) {
        grades->addGrade(grade, isExam);
    }
};

int main() {
    Date* birthDate = new Date(15, 10, 1998);
    Address* address = new Address("USA", "California", "Los Angeles", "Sunset Blvd", 101, 'B');
    StudentPersonalDetails* personalDetails = new StudentPersonalDetails("John", "Doe", birthDate, address);
    EducationDetails* eduDetails = new EducationDetails(Date(2018, 9, 1), 2, "CS202", "Computer Science");
    Grades* grades = new Grades();
    Student* student = new Student(personalDetails, eduDetails, grades);

    student->displayStudentInfo();
    student->addGrade(88, true); // Add an exam grade

    delete student; // Assuming proper deletions in destructors
    return 0;
}
