#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

struct Contact {
    int id;
    std::string name;
    std::string phone;
    std::string email;
};

class ContactManager {
public:
    ContactManager(const std::string& filename);
    ~ContactManager();

    void addContact(const std::string& name,
                    const std::string& phone,
                    const std::string& email);
    void listContacts() const;
    bool deleteContact(int id);
    void searchContacts(const std::string& term) const;

private:
    void save() const;
    void load();
    static std::string escape(const std::string& str);
    static std::string unescape(const std::string& str);

    std::vector<Contact> contacts;
    std::string dataFile;
    int nextId;
};

#endif 