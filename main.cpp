//NAME: ALIM ISMAEL KAMARA
//STD NO: 32114194

#include "Person.h" // include header file for Person class
#include <iostream>

using namespace std;

int main()
{
    Person p;         // create an instance of Person class
    p.loadContacts(); // load any existing contacts from a file

    int choice;
    do
    {
        // print the main menu
        cout << "\n\n==================== MAIN MENU ====================" << endl
             << endl;
        cout << "Please choose one of the following options: " << endl
             << endl;
        cout << "    1- Add a new contact" << endl;
        cout << "    2- Delete a contact" << endl;
        cout << "    3- Search for a contact" << endl;
        cout << "    4- List of all contacts" << endl;
        cout << "    5- Exit" << endl
             << endl;

        cout << "Your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1: // if the user chooses option 1, add a new contact
            cout << "\n\n==================== ADD A NEW CONTACT ====================" << endl
                 << endl;
            p.addContact();
            break;

        case 2: // if the user chooses option 2, delete a contact
            cout << "\n\n==================== DELETE A CONTACT ====================" << endl
                 << endl;
            p.deleteContact();
            break;

        case 3: // if the user chooses option 3, search for a contact
            cout << "\n\n==================== SEARCH FOR A CONTACT ====================" << endl
                 << endl;
            p.searchContact();
            break;

        case 4: // if the user chooses option 4, display all contacts
            cout << "\n\n==================== LIST OF ALL CONTACTS ====================" << endl
                 << endl;
            p.displayContacts();
            break;

        case 5: // if the user chooses option 5, exit the program
            cout << "\n\n\n\t\t\tExiting program..." << endl
                 << endl;
            break;

        default: // if the user chooses an invalid option, display an error message
            cout << "Invalid choice, please choose a number between 1 and 5." << endl
                 << endl;
            break;
        }

    } while (choice != 5); // repeat the loop until the user chooses to exit

    return 0; // indicate successful program execution
}
