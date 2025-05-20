#include "contactManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

ContactManager::ContactManager(const std::string& filename)
    : dataFile(filename), nextId(1) {
    load();
}

ContactManager::~ContactManager() {
    save();
}

void ContactManager::addContact(const std::string& name,
                                const std::string& phone,
                                const std::string& email) {
    contacts.push_back({ nextId++, name, phone, email });
    std::cout << "Contact added." << std::endl;
}

void ContactManager::listContacts() const {
    if (contacts.empty()) {
        std::cout << "No contacts found." << std::endl;
        return;
    }
    std::cout << "ID\tName\tPhone\tEmail" << std::endl;
    for (const auto& c : contacts) {
        std::cout << c.id << '\t' << c.name << '\t'
                  << c.phone << '\t' << c.email << std::endl;
    }
}

bool ContactManager::deleteContact(int id) {
    auto it = std::find_if(contacts.begin(), contacts.end(),
        [id](const Contact& c) { return c.id == id; });
    if (it != contacts.end()) {
        contacts.erase(it);
        std::cout << "Contact deleted." << std::endl;
        return true;
    }
    std::cout << "Contact with ID " << id << " not found." << std::endl;
    return false;
}

void ContactManager::searchContacts(const std::string& term) const {
    bool found = false;
    for (const auto& c : contacts) {
        if (c.name.find(term) != std::string::npos ||
            c.phone.find(term) != std::string::npos ||
            c.email.find(term) != std::string::npos) {
            if (!found) {
                std::cout << "Found contacts:" << std::endl;
                std::cout << "ID\tName\tPhone\tEmail" << std::endl;
                found = true;
            }
            std::cout << c.id << '\t' << c.name << '\t'
                      << c.phone << '\t' << c.email << std::endl;
        }
    }
    if (!found)
        std::cout << "No matching contacts." << std::endl;
}

void ContactManager::save() const {
    std::ofstream out(dataFile);
    for (const auto& c : contacts) {
        out << c.id << '|' << escape(c.name)
            << '|' << escape(c.phone)
            << '|' << escape(c.email) << '\n';
    }
}

void ContactManager::load() {
    std::ifstream in(dataFile);
    if (!in) return;
    std::string line;
    while (std::getline(in, line)) {
        std::istringstream ss(line);
        std::string token;
        Contact c;
        if (std::getline(ss, token, '|')) c.id = std::stoi(token);
        if (std::getline(ss, token, '|')) c.name = unescape(token);
        if (std::getline(ss, token, '|')) c.phone = unescape(token);
        if (std::getline(ss, token, '|')) c.email = unescape(token);
        contacts.push_back(c);
        nextId = std::max(nextId, c.id + 1);
    }
}

std::string ContactManager::escape(const std::string& str) {
    std::string out;
    for (char ch : str) {
        if (ch == '|' || ch == '\n') out += '\\';
        out += ch;
    }
    return out;
}

std::string ContactManager::unescape(const std::string& str) {
    std::string out;
    bool esc = false;
    for (char ch : str) {
        if (esc) { out += ch; esc = false; }
        else if (ch == '\\') esc = true;
        else out += ch;
    }
    return out;
}