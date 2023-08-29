#include <iostream>
#include <string>
using namespace std;
class Address {
protected:
    std::string street;
    std::string city;
    std::string state;
    std::string zipCode;

public:
    Address();
    Address(string street, string city, string state, string zipCode);
        

    void displayAddress();
    void setStreet(const std::string& _street) {
        street = _street;
    }

    void setCity(const std::string& _city) {
        city = _city;
    }

    void setState(const std::string& _state) {
        state = _state;
    }

    void setZipCode(const std::string& _zipCode) {
        zipCode = _zipCode;
    }

    // Getter methods
    std::string getStreet() const {
        return street;
    }

    std::string getCity() const {
        return city;
    }

    std::string getState() const {
        return state;
    }

    std::string getZipCode() const {
        return zipCode;
    }
};
Address::Address(string street, string city, string state, string zipCode)
    : street(street), city(city), state(state), zipCode(zipCode) {}

void Address:: displayAddress() {
    std::cout << "Address: " << street << ", " << city << ", " << state << ", " << zipCode << std::endl;
}
/// --------------######################---------------------------------------------------------------------------------



class Person {
public:
    Person();
    string name;
    Person(string _name, Address _address, string _phoneNumber, string _emailAddress);
    void displayDetails(); 

   

    string getName() const {
        return name;
    }

    void setName(const string& _name) {
        name = _name;
    }

    Address getAddress() const {
        return address;
    }

    void setAddress(const Address& _address) {
        address = _address;
    }

    string getPhoneNumber() const {
        return phoneNumber;
    }

    void setPhoneNumber(const string& _phoneNumber) {
        phoneNumber = _phoneNumber;
    }

    string getEmailAddress() const {
        return emailAddress;
    }

    void setEmailAddress(const string& _emailAddress) {
        emailAddress = _emailAddress;
    }
protected:
    Address address;
    string phoneNumber;
    string emailAddress;
};
Person::Person(){}


Person::Person(string _name, Address _address, string _phoneNumber, string _emailAddress) 
    : name(_name), address(_address), phoneNumber(_phoneNumber), emailAddress(_emailAddress) {}
void Person:: displayDetails() {
    cout << "Name: " << name << endl;
    address.displayAddress();
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "Email Address: " << emailAddress << endl;
}







class Student : public Person {
private:
    string status;

public:
    Student();
    Student(string _name, const Address& _address, string _phoneNumber, string _emailAddress, string _status);
        

    void displayDetails();

};
Student::Student(string _name, const Address& _address, string _phoneNumber, string _emailAddress, string _status)
    : Person(_name, _address, _phoneNumber, _emailAddress), status(_status) {}

void Student :: displayDetails() {
    Person::displayDetails();
    cout << "Status: " << status << endl;
}

class Employee : public Person{
private:
    string officeNo;
    double salary;
    string dataHired;
public:
    Employee();
    Employee(string _name, Address address, string _phoneNumber, string _emailAddress,
        string _officeNo, double _salary, string _dateHiring);
    Employee(const Employee& other);

    // Setter methods
    void setOfficeNo(const string& _officeNo) {
        officeNo = _officeNo;
    }

    void setSalary(double _salary) {
        salary = _salary;
    }

    void setDateHiring(const string& _dateHiring) {
        dataHired = _dateHiring;
    }

    // Getter methods
    string getOfficeNo() const {
        return officeNo;
    }

    double getSalary() const {
        return salary;
    }

    string getDateHiring() const {
        return dataHired;
    }

    void displayDetails();
};
Employee::Employee(string _name, Address address, string _phoneNumber, string _emailAddress,
    string _officeNo, double _salary, string _dateHiring)
    : Person(_name, address, _phoneNumber, _emailAddress),
    officeNo(_officeNo), salary(_salary), dataHired(_dateHiring) {}

void Employee::displayDetails() {
    Person::displayDetails();
    cout << "Office No: " << officeNo << endl;
    cout << "Salary: $" << salary << endl;
    cout << "Date Hiring: " << dataHired << endl;
}

Employee::Employee(const Employee& other)
    : Person(other), officeNo("30"), salary(other.salary), dataHired(other.dataHired) {}









class FaclutyMember : protected Employee {
private :
    double officeHours;
    string rank;
public:
    FaclutyMember();
    FaclutyMember(string _name, Address address, string _phoneNumber, string _emailAddress,
        string _officeNo, double _salary, string _dateHiring, double Officehours, string rank);


    void setOfficeHours(double _officeHours) {
        officeHours = _officeHours;
    }

    void setRank(const string& _rank) {
        rank = _rank;
    }

    double getOfficeHours() const {
        return officeHours;
    }

    string getRank() const {
        return rank;
    }
    void displayDetails();

};

FaclutyMember::FaclutyMember(string _name, Address address, string _phoneNumber, string _emailAddress,
    string _officeNo, double _salary, string _dateHiring, double Officehours, string rank) 
    : Employee(_name, address, _phoneNumber, _emailAddress, _officeNo, _salary, _dateHiring), officeHours(Officehours), rank(rank){}
 
void FaclutyMember::displayDetails() {
    Employee::displayDetails();
    cout << "Office Hours: " << officeHours << endl;
    cout << "Rank: " << rank << endl;
}



class Staff : public Employee {
private:
    string title;

public:
    Staff();
    Staff(string _name, Address address, string _phoneNumber, string _emailAddress,
        string _officeNo, double _salary, string _dateHiring, string _title);
   
    void setTitle(const string& _title) {
        title = _title;
    }

    string getTitle() const {
        return title;
    }

};
Staff::Staff() {};

Staff::Staff(string _name, Address address, string _phoneNumber, string _emailAddress,
    string _officeNo, double _salary, string _dateHiring, string _title)
    : Employee(_name, address, _phoneNumber, _emailAddress, _officeNo, _salary, _dateHiring),
    title(_title) {};
int main() {
    // Create objects
    Address personAddress("123 Street", "City", "State", "12345");
    Person person("John Doe", personAddress, "123-456-7890", "john@example.com");

    Address studentAddress("456 Avenue", "City", "State", "67890");
    Student student("Jane Smith", studentAddress, "987-654-3210", "jane@example.com", "Junior");

    Address employeeAddress("789 Road", "City", "State", "54321");
    Employee employee("Alex Johnson", employeeAddress, "111-222-3333", "alex@example.com",
        "Office123", 5000.0, "2022-01-01");

    Address facultyAddress("321 Boulevard", "City", "State", "09876");
    FaclutyMember faculty("Sarah Adams", facultyAddress, "444-555-6666", "sarah@example.com",
        "Office456", 6000.0, "2022-02-01", 40.0, "Professor");

    Address staffAddress("654 Lane", "City", "State", "13579");
    Staff staff("Mike Davis", staffAddress, "777-888-9999", "mike@example.com",
        "Office789", 4000.0, "2022-03-01", "Manager");

    // Create pointers to objects
    Person* personPtr = &person;
    Person* studentPtr = &student;
    Employee* employeePtr = &employee;
    FaclutyMember* facultyPtr =  &faculty;
    Person* staffPtr = &staff;

    // Set values using functions
    personPtr->setPhoneNumber("999-888-7777");
    studentPtr->setEmailAddress("student@example.com");
    employeePtr->setOfficeNo("OfficeXYZ");
    facultyPtr->setSalary(7000.0);
    staffPtr->setPhoneNumber("666-555-4444");

    // Call displayDetails() function for each object
    cout << "--- Displaying Object Data ---" << endl;
    person.displayDetails();
    cout << endl;
    student.displayDetails();
    cout << endl;
    employee.displayDetails();
    cout << endl;
    faculty.displayDetails();
    cout << endl;
    staff.displayDetails();
    cout << endl;

    // Call displayDetails() function for each pointer to objects
    cout << "--- Displaying Pointer Object Data ---" << endl;
    personPtr->displayDetails();
    cout << endl;
    studentPtr->displayDetails();
    cout << endl;
    employeePtr->displayDetails();
    cout << endl;
    facultyPtr->displayDetails();
    cout << endl;
    staffPtr->displayDetails();
    cout << endl;

    return 0;
}
