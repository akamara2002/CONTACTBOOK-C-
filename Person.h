//NAME: ALIM ISMAEL KAMARA
//STD NO: 32114194

#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include <vector>

using namespace std;

class Person
{
private:
    string name, surname, address, phoneNo;
    int age;

public:
    //CONSTRUCTORS
    Person();
    Person(string n, string s, int a, string ad, string p);

    //MUTATORS
    void setName(string n);
    void setSurname(string s);
    void setAge(int a);
    void setAddress(string ad);
    void setPhoneNo(string p);


    //ACCESSORS
    string getName() const;
    string getSurname() const;
    int getAge() const;
    string getAddress() const;
    string getPhoneNo() const;


    //METHODS OR MEMBER FUNCTIONS
    void printInfo();
    friend istream& operator>>(istream& is, Person& p);
    vector<Person> contactList;
    void saveContacts();//Write to the file
    void loadContacts();//Read from file
    void addContact();
    void deleteContact();
    void searchContact();
    void displayContacts();
};

#endif