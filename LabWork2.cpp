
/// Frist Task Aeroflot Flights
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

class Aeroflot {
private:
    int flightNumber;
    string departurePoint;
    string destinationPoint;
    string arrivalTime;
    string departureTime;
    string checkInLocation;

public:
    Aeroflot(int num, const string& dep, const string& dest,
             const string& arrTime, const string& depTime,
             const string& checkIn)
            : flightNumber(num), departurePoint(dep), destinationPoint(dest),
              arrivalTime(arrTime), departureTime(depTime), checkInLocation(checkIn) {}

    void displayFlightInfo() const {
        cout << setw(8) << flightNumber
             << setw(15) << departurePoint
             << setw(15) << destinationPoint
             << setw(15) << arrivalTime
             << setw(15) << departureTime
             << setw(20) << checkInLocation << endl;
    }

    int getFlightNumber() const { return flightNumber; }
    string getDeparturePoint() const { return departurePoint; }
    string getDestinationPoint() const { return destinationPoint; }
    string getArrivalTime() const { return arrivalTime; }
    string getDepartureTime() const { return departureTime; }
    string getCheckInLocation() const { return checkInLocation; }
};

bool compareFlights(const Aeroflot& flight1, const Aeroflot& flight2) {
    return flight1.getDestinationPoint() < flight2.getDestinationPoint();
}

bool isFlightNumberUnique(const vector<Aeroflot>& flights, int num) {
    for (const auto& flight : flights) {
        if (flight.getFlightNumber() == num) {
            return false; // Найден дубликат номера рейса
        }
    }
    return true;
}

bool isTimeUnique(const vector<Aeroflot>& flights, const string& depTime) {
    for (const auto& flight : flights) {
        if (flight.getDepartureTime() == depTime) {
            return false; // Найден дубликат времени отправления
        }
    }
    return true;
}

int main() {
    vector<Aeroflot> flights;

    int numFlights;
    cout << "Enter the number of flights: ";
    cin >> numFlights;

    for (int i = 0; i < numFlights; ++i) {
        int num;
        string dep, dest, arrTime, depTime, checkIn;

        // Проверка уникальности номера рейса
        do {
            cout << "Flight Number: ";
            cin >> num;
        } while (!isFlightNumberUnique(flights, num));

        // Проверка уникальности времени отправления
        do {
            cout << "Departure Time: ";
            cin >> depTime;
        } while (!isTimeUnique(flights, depTime));

        cout << "Departure Point: ";
        cin >> dep;
        cout << "Destination Point: ";
        cin >> dest;
        cout << "Arrival Time: ";
        cin >> arrTime;
        cout << "Check-In Location: ";
        cin >> checkIn;

        flights.emplace_back(num, dep, dest, arrTime, depTime, checkIn);
    }

    sort(flights.begin(), flights.end(), compareFlights);

    cout << "\nFlight Information Table:\n";
    cout << setw(8) << "Flight#"
         << setw(15) << "Departure"
         << setw(15) << "Destination"
         << setw(15) << "Arrival Time"
         << setw(15) << "Departure Time"
         << setw(20) << "Check-In Location\n";

    if (flights.empty()) {
        cout << "No flights available.\n";
    } else {
        for (const auto& flight : flights) {
            flight.displayFlightInfo();
        }
    }

    return 0;
}




/// Second Task  Students Class 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Student {
private:
    string lastName;
    string firstName;
    string dateOfBirth;
    string phoneNumber;

public:
  
    Student(const string& last, const string& first, const string& dob, const string& phone)
        : lastName(last), firstName(first), dateOfBirth(dob), phoneNumber(phone) {}

  
    const string& getLastName() const {
        return lastName;
    }

    void setLastName(const string& last) {
        lastName = last;
    }

    const string& getFirstName() const {
        return firstName;
    }

    void setFirstName(const string& first) {
        firstName = first;
    }

    const string& getDateOfBirth() const {
        return dateOfBirth;
    }

    void setDateOfBirth(const string& dob) {
        dateOfBirth = dob;
    }

    const string& getPhoneNumber() const {
        return phoneNumber;
    }

    void setPhoneNumber(const string& phone) {
        phoneNumber = phone;
    }
};


class StudentGroup {
private:
    vector<Student> students;

public:

    void addStudent(const Student& student) {

    for (const auto& s : students) {
        if (s.getPhoneNumber() == student.getPhoneNumber()) {
            cout << "Error: Student with the same phone number already exists." << endl;
            return;
        }
    }
    students.push_back(student);
}

    void removeStudent(const string& lastName) {
        students.erase(
            remove_if(students.begin(), students.end(),
                [&lastName](const Student& student) {
                    return student.getLastName() == lastName;
                }),
            students.end());
    }


    vector<Student> findStudentByLastName(const string& lastName) {
        vector<Student> foundStudents;
        for (const auto& student : students) {
            if (student.getLastName() == lastName) {
                foundStudents.push_back(student);
            }
        }
        return foundStudents;
    }

    void sortByLastName() {
        sort(students.begin(), students.end(),
            [](const Student& a, const Student& b) {
                return a.getLastName() < b.getLastName();
            });
    }

    void displayStudents() {
        for (const auto& student : students) {
            cout << "Last Name: " << student.getLastName() << ", "
                 << "First Name: " << student.getFirstName() << ", "
                 << "Date of Birth: " << student.getDateOfBirth() << ", "
                 << "Phone Number: " << student.getPhoneNumber() << endl;
        }
    }

    void editStudentInfo(const string& lastName) {
        auto it = find_if(students.begin(), students.end(),
            [&lastName](const Student& student) {
                return student.getLastName() == lastName;
            });
        if (it != students.end()) {
    cout << "Editing student: " << it->getLastName() << endl;

    string newLastName, newFirstName, newDateOfBirth, newPhoneNumber;
    cout << "Enter new Last Name: ";
    cin >> newLastName;
    cout << "Enter new First Name: ";
    cin >> newFirstName;
    cout << "Enter new Date of Birth: ";
    cin >> newDateOfBirth;
    cout << "Enter new Phone Number: ";
    cin >> newPhoneNumber;

    it->setLastName(newLastName);
    it->setFirstName(newFirstName);
    it->setDateOfBirth(newDateOfBirth);
    it->setPhoneNumber(newPhoneNumber);

    cout << "Student information updated." << endl;
} else {
    cout << "Student with last name " << lastName << " not found." << endl;
}

    }
};

Student inputStudentData() {
    string lastName, firstName, dateOfBirth, phoneNumber;
    cout << "Enter Last Name: ";
    cin >> lastName;
    cout << "Enter First Name: ";
    cin >> firstName;
    cout << "Enter Date of Birth: ";
    cin >> dateOfBirth;
    cout << "Enter Phone Number: ";
    cin >> phoneNumber;
    return Student(lastName, firstName, dateOfBirth, phoneNumber);
}

int main() {
    StudentGroup group;
    char choice;

    do {
        cout << "\nMain Menu:" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Find Student by Last Name" << endl;
        cout << "3. Remove Student" << endl;
        cout << "4. Sort Students by Last Name" << endl;
        cout << "5. Display All Students" << endl;
        cout << "6. Edit Student Information" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                group.addStudent(inputStudentData());
                break;
            }
            case '2': {
                string lastName;
                cout << "Enter Last Name to search: ";
                cin >> lastName;
                vector<Student> foundStudents = group.findStudentByLastName(lastName);
                if (!foundStudents.empty()) {
                    cout << "Found students:" << endl;
                    for (const auto& student : foundStudents) {
                        cout << "Last Name: " << student.getLastName() << ", "
                             << "First Name: " << student.getFirstName() << ", "
                             << "Date of Birth: " << student.getDateOfBirth() << ", "
                             << "Phone Number: " << student.getPhoneNumber() << endl;
                    }
                } else {
                    cout << "No students found with last name " << lastName << endl;
                }
                break;
            }
            case '3': {
                string lastName;
                cout << "Enter Last Name to remove: ";
                cin >> lastName;
                group.removeStudent(lastName);
                break;
            }
            case '4': {
                group.sortByLastName();
                cout << "Students sorted by last name." << endl;
                break;
            }
            case '5': {
                cout << "All students in the group:" << endl;
                group.displayStudents();
                break;
            }
            case '6': {
                string lastName;
                cout << "Enter Last Name of student to edit: ";
                cin >> lastName;
                group.editStudentInfo(lastName);
                break;
            }
            case '7': {
                cout << "Exiting program." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please enter a number from 1 to 7." << endl;
            }
        }
    } while (choice != '7');

    return 0;
}




/// Third Task Train Wagon
#include <iostream>
#include <stack>
#include <fstream>
#include <string>

using namespace std;

class Stack {
private:
    stack<int> data;

public:
    void push(int value) {
        data.push(value);
    }

    int pop() {
        int top_value = data.top();
        data.pop();
        return top_value;
    }

    bool isEmpty() {
        return data.empty();
    }
};

int main() {
    Stack stack1, stack2;

    ifstream file("train.txt");
    if (file.is_open()) {
        int wagon;
        while (file >> wagon) {
            if (wagon == 1) {
                stack1.push(wagon);
            } else if (wagon == 2) {
                stack2.push(wagon);
            } else {
                cout << "Invalid wagon type: " << wagon << endl;
            }
        }
        file.close();
    } else {
        cout << "Failed to open file." << endl;
    }

    // Inputting wagons from the keyboard
    cout << "Enter wagon numbers (1 for type A, 2 for type B) or -1 to finish input:" << endl;
    int wagon;
    while (true) {
        cin >> wagon;
        if (wagon == -1) {
            break;
        } else if (wagon == 1) {
            stack1.push(wagon);
        } else if (wagon == 2) {
            stack2.push(wagon);
        } else {
            cout << "Invalid wagon type: " << wagon << endl;
        }
    }

    // Outputting wagons in both directions
    cout << "Wagons in direction A:" << endl;
    while (!stack1.isEmpty()) {
        cout << stack1.pop() << endl;
    }

    cout << "Wagons in direction B:" << endl;
    while (!stack2.isEmpty()) {
        cout << stack2.pop() << endl;
    }

    return 0;
}


