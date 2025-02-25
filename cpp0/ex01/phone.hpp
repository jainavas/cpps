#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#define MAX_CONTACTS 8

class Contact {
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

public:
    void setContact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds) {
        first_name = fn;
        last_name = ln;
        nickname = nn;
        phone_number = pn;
        darkest_secret = ds;
    }

    void displayShort(int index) {
        std::cout << std::setw(10) << index << "|";
        std::cout << std::setw(10) << formatField(first_name) << "|";
        std::cout << std::setw(10) << formatField(last_name) << "|";
        std::cout << std::setw(10) << formatField(nickname) << "|" << std::endl;
    }

    void displayFull() {
        std::cout << "First name: " << first_name << std::endl;
        std::cout << "Last name: " << last_name << std::endl;
        std::cout << "Nickname: " << nickname << std::endl;
        std::cout << "Phone number: " << phone_number << std::endl;
        std::cout << "Darkest secret: " << darkest_secret << std::endl;
    }

private:
    std::string formatField(std::string field) {
        if (field.length() > 10)
            return field.substr(0, 9) + ".";
        return field;
    }
};

class PhoneBook {
private:
    Contact contacts[MAX_CONTACTS];
    int count;
    int oldest;

public:
    PhoneBook() {
        count = 0;
        oldest = 0;
    }

    void addContact() {
        std::string fn, ln, nn, pn, ds;
        std::cout << "Enter First Name: "; std::getline(std::cin, fn);
        std::cout << "Enter Last Name: "; std::getline(std::cin, ln);
        std::cout << "Enter Nickname: "; std::getline(std::cin, nn);
        std::cout << "Enter Phone Number: "; std::getline(std::cin, pn);
        std::cout << "Enter Darkest Secret: "; std::getline(std::cin, ds);

        if (fn.empty() || ln.empty() || nn.empty() || pn.empty() || ds.empty()) {
            std::cout << "All fields must be filled. Contact not added." << std::endl;
            return;
        }

        contacts[oldest].setContact(fn, ln, nn, pn, ds);
        if (count < MAX_CONTACTS)
            count++;
        oldest = (oldest + 1) % MAX_CONTACTS;
        std::cout << "Contact added successfully!" << std::endl;
    }

    void searchContact() {
        if (count == 0) {
            std::cout << "PhoneBook is empty!" << std::endl;
            return;
        }

        std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|"
                  << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << "|"
                  << std::endl;
        for (int i = 0; i < count; i++) {
            contacts[i].displayShort(i);
        }

        std::cout << "Enter index of contact to view: ";
        std::string input;
        std::getline(std::cin, input);

        int index;
        std::istringstream iss(input);
        if (!(iss >> index) || index < 0 || index >= count) {
            std::cout << "Invalid index!" << std::endl;
            return;
        }

        contacts[index].displayFull();
    }
};
