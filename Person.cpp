//NAME: ALIM ISMAEL KAMARA
//STD NO: 32114194

#include "Person.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// CONSTRUCTORS
Person ::Person() {}
Person ::Person(string n, string s, int a, string ad, string p)
{

    name = n;
    surname = s;
    age = a;
    address = ad;
    phoneNo = p;
}

// MUTATORS
void Person ::setName(string n)
{
    name = n;
}
void Person::setSurname(string s)
{
    surname = s;
}
void Person ::setAge(int a)
{
    age = a;
}
void Person ::setAddress(string ad)
{
    address = ad;
}
void Person ::setPhoneNo(string p)
{
    phoneNo = p;
}

// ACCESSORS
string Person ::getName() const
{
    return name;
}
string Person ::getSurname() const
{
    return surname;
}
int Person ::getAge() const
{
    return age;
}
string Person ::getAddress() const
{
    return address;
}
string Person ::getPhoneNo() const
{
    return phoneNo;
}

// METHODS OR MEMBER FUNCTIONS

void Person ::printInfo()
{
    cout << "Name: " << getName() << endl;
    cout << "Surname: " << getSurname() << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Address: " << getAddress() << endl;
    cout << "Phone No.: " << getPhoneNo() << endl;
}

istream &operator>>(istream &is, Person &p)
{
    is >> p.name >> p.surname >> p.age >> p.address >> p.phoneNo;
    return is;
}

vector<Person> contactList;

void Person ::saveContacts()
{
    ofstream file("contacts.txt");
    if (file.is_open())
    {
        for (Person p : contactList)
        {
            file << p.getName() << " " << p.getSurname() << " " << p.getAge() << " " << p.getAddress() << " " << p.getPhoneNo() << endl;
        }
        file.close();
    }
}

void Person ::loadContacts()
{
    ifstream file("contacts.txt");
    if (file.is_open())
    {
        Person p;
        while (file >> p)
        {
            contactList.push_back(p);
        }
        file.close();
    }
}

void Person ::addContact()
{
    string name, surname, address, phoneNo;
    int age;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter surname: ";
    cin >> surname;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter address: ";
    cin >> address;
    cout << "Enter phone number: ";
    cin >> phoneNo;
    Person p(name, surname, age, address, phoneNo);
    contactList.push_back(p);
    saveContacts();
    cout << "Contact Created.........." << endl;
}

void Person ::deleteContact()
{
    string phoneNo;
    bool deleted = false;
    int choice;
    string name;
    string surname;
    string address;
    cout << "You can delete using the following methods: " << endl;
    cout << "1-Delete By first name" << endl;
    cout << "2-Delete By last name" << endl;
    cout << "3-Delete By phone" << endl;
    cout << "4-Delete By address" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Enter the first name: ";
        cin >> name;
        while (true)
        {
            deleted = false;
            for (int i = 0; i < contactList.size(); i++)
            {
                if (contactList[i].getName() == name)
                {
                    contactList.erase(contactList.begin() + i);
                    deleted = true;
                    break;
                }
            }
            if (!deleted)
            {
                break;
            }
        }
        saveContacts();
        cout << "Phone number deleted......" << endl;
        break;

    case 2:
        cout << "Enter the last name: ";
        cin >> surname;
        while (true)
        {
            deleted = false;
            for (int i = 0; i < contactList.size(); i++)
            {
                if (contactList[i].getSurname() == surname)
                {
                    contactList.erase(contactList.begin() + i);
                    deleted = true;
                    break;
                }
            }
            if (!deleted)
            {
                break;
            }
        }
        saveContacts();
        cout << "Phone number deleted......" << endl;
        break;

    case 3:
        cout << "Enter the phone number: ";
        cin >> phoneNo;

        while (true)
        {
            deleted = false;
            for (int i = 0; i < contactList.size(); i++)
            {
                if (contactList[i].getPhoneNo() == phoneNo)
                {
                    contactList.erase(contactList.begin() + i);
                    deleted = true;
                    break;
                }
            }
            if (!deleted)
            {
                break;
            }
        }
        saveContacts();
        break;

    case 4:
        cout << "Enter the address: ";
        cin >> phoneNo;
        while (true)
        {
            deleted = false;
            for (int i = 0; i < contactList.size(); i++)
            {
                if (contactList[i].getAddress() == address)
                {
                    contactList.erase(contactList.begin() + i);
                    deleted = true;
                    break;
                }
            }
            if (!deleted)
            {
                break;
            }
        }
        saveContacts();
        cout << "Phone number deleted......" << endl;
        break;

    default:
        cout << "Invalid number...." << endl;
    }

    
}

void Person ::searchContact()
{
    string phoneNo;
    bool found = false;
    int choice;
    string name;
    string surname;
    string address;
    cout << "You can Search using the following methods: " << endl;
    cout << "1-Search By first name" << endl;
    cout << "2-Search By last name" << endl;
    cout << "3-Search By phone" << endl;
    cout << "4-Search By address" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Enter the first name: ";
        cin >> name;
        cout << endl;
        for (Person p : contactList)
        {
            if (p.getName() == name)
            {
                p.printInfo();
                found = true;
                cout << endl
                     << endl;
            }
        }

        if (!found)
        {
            cout << "No contacts found with the given first name." << endl;
        }
        break;

    case 2:

        cout << "Enter the last name: ";
        cin >> surname;
        cout << endl;
        for (Person p : contactList)
        {
            if (p.getSurname() == surname)
            {
                p.printInfo();
                found = true;
                cout << endl
                     << endl;
            }
        }

        if (!found)
        {
            cout << "No contacts found with the given last name." << endl;
        }
        break;

    case 3:

        cout << "Enter the phone number: ";
        cin >> phoneNo;
        cout << endl;
        for (Person p : contactList)
        {
            if (p.getPhoneNo() == phoneNo)
            {
                p.printInfo();
                found = true;
                cout << endl
                     << endl;
            }
        }

        if (!found)
        {
            cout << "No contacts found with the given phone number." << endl;
        }
        break;
    case 4:

        cout << "Enter the address: ";
        cin >> address;
        cout << endl;
        for (Person p : contactList)
        {
            if (p.getAddress() == address)
            {
                p.printInfo();
                found = true;
                cout << endl
                     << endl;
            }
        }

        if (!found)
        {
            cout << "No contacts found with the given address." << endl;
        }
        break;

    default:
        cout << "Invalid number" << endl;
    }
}

void Person ::displayContacts()
{
    cout <<"\n*******************************\n";
    cout <<"LIST OF CONTACTS";
    cout <<"\n*******************************\n";
    for (Person p : contactList)
    {
        p.printInfo();
        cout << endl
             << endl;
    }
    cout <<"\n*******************************\n";
}


/* int option;
    do
    {
        
        cout << "\n\n..::Enter the choice:\n[1] Main Menu\t\t[5] Exit\n";
        cin >> option;

        switch (option)
        {
        case 5:   
            cout << "\n\n\n\t\t\tExiting program..." << endl
                 << endl;
            break;
        default:
            continue;
        }
    } while (option !=5); */
