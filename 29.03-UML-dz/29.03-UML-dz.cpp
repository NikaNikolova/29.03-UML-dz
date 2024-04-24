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

    PersonalDetails(const string& fn, const string& ln, Date* bd, Address* ha)
        : firstName(fn), lastName(ln), birthDate(bd), homeAddress(ha) {}

    virtual void displayDetails() const = 0;
};

// Concrete implementation for Student's personal details
class StudentPersonalDetails : public PersonalDetails {
public:
    StudentPersonalDetails(const string& fn, const string& ln, Date* bd, Address* ha)
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

    EducationDetails(const Date& sd, int cc, const string& gn, const string& sp)
        : startDate(sd), currentCourse(cc), groupName(gn), specialization(sp) {}

    void displayEducation() const {
        cout << "Start Date: " << startDate.day << "/" << startDate.month << "/" << startDate.year << endl;
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
    StudentPersonalDetails personalDetails;
    EducationDetails educationDetails;
    Grades grades;

public:
    Student(const string& fn, const string& ln, Date* bd, Address* ha, const Date& sd, int cc, const string& gn, const string& sp)
        : personalDetails(fn, ln, bd, ha),
          educationDetails(sd, cc, gn, sp) {}

    void displayStudentInfo() const {
        personalDetails.displayDetails();
        educationDetails.displayEducation();
    }

    void addGrade(int grade, bool isExam) {
        grades.addGrade(grade, isExam);
    }
};

int main() {
    // Create date and address information
    Date* birthDate = new Date(15, 10, 1998);
    Address* address = new Address("USA", "California", "Los Angeles", "Sunset Blvd", 101, 'B');
    
    // Instantiate the Student class using constructor with parameters
    Student student("John", "Doe", birthDate, address, Date(1, 9, 2018), 2, "CS202", "Computer Science");
    
    // Display the student information
    student.displayStudentInfo();
    
    // Add a grade to the student's records
    student.addGrade(88, true); // Add an exam grade

    delete birthDate;
    delete address;
    return 0;
}