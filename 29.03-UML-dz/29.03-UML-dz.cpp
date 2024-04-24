#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Date {
public:
    int day;
    int month;
    int year;

    Date() : Date(1, 1, 1900) {}  // Делегирование конструктора
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
};

class Address {
public:
    string country;
    string region;
    string city;
    string street;
    int houseNumber;
    char buildingSection;

    Address() : Address("Not specified", "Not specified", "Not specified", "Not specified", 0, 'A') {}
    Address(string cn, string rg, string ct, string st, int hn, char bs)
        : country(cn), region(rg), city(ct), street(st), houseNumber(hn), buildingSection(bs) {}
};

class PersonalDetails {
public:
    string firstName;
    string lastName;
    Date* birthDate;
    Address* homeAddress;

    PersonalDetails() : firstName(""), lastName(""), birthDate(new Date()), homeAddress(new Address()) {}

    void setDetails(const string& fn, const string& ln, Date* bd, Address* ha) {
        firstName = fn;
        lastName = ln;
        birthDate = bd;
        homeAddress = ha;
    }

    virtual void displayDetails() const {
        cout << "Student Name: " << firstName << " " << lastName << endl;
        cout << "Birth Date: " << birthDate->day << "/" << birthDate->month << "/" << birthDate->year << endl;
        cout << "Address: " << homeAddress->street << ", " << homeAddress->city << ", " << homeAddress->country << endl;
    }
};

class EducationDetails {
public:
    Date startDate;
    int currentCourse;
    string groupName;
    string specialization;

    EducationDetails() : startDate(Date()), currentCourse(1), groupName("None"), specialization("None") {}

    void setEducationDetails(const Date& sd, int cc, const string& gn, const string& sp) {
        startDate = sd;
        currentCourse = cc;
        groupName = gn;
        specialization = sp;
    }

    void displayEducation() const {
        cout << "Start Date: " << startDate.day << "/" << startDate.month << "/" << startDate.year << endl;
        cout << "Course: " << currentCourse << endl;
        cout << "Group: " << groupName << endl;
        cout << "Specialization: " << specialization << endl;
    }
};

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

class Student {
private:
    PersonalDetails personalDetails;
    EducationDetails educationDetails;
    Grades grades;

public:
    Student(const string& fn, const string& ln, Date* bd, Address* ha, const Date& sd, int cc, const string& gn, const string& sp) {
        personalDetails.setDetails(fn, ln, bd, ha);
        educationDetails.setEducationDetails(sd, cc, gn, sp);
    }

    void displayStudentInfo() const {
        personalDetails.displayDetails();
        educationDetails.displayEducation();
    }

    void addGrade(int grade, bool isExam) {
        grades.addGrade(grade, isExam);
    }
};

int main() {
    Date* birthDate = new Date(15, 10, 1998);
    Address* address = new Address("USA", "California", "Los Angeles", "Sunset Blvd", 101, 'B');
    
    Student student("John", "Doe", birthDate, address, Date(1, 9, 2018), 2, "CS202", "Computer Science");
    
    student.displayStudentInfo();
    
    student.addGrade(88, true); // Add an exam grade

    delete birthDate;
    delete address;
    return 0;
}
