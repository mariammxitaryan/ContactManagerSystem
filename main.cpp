#include <iostream>
#include "contactManager.h"

void printHelp() {
    std::cout << "Commands:\n"
              << " add <name> <phone> <email>  - Add a new contact\n"
              << " list                       - List all contacts\n"
              << " delete <id>                - Delete contact by ID\n"
              << " search <term>              - Search contacts\n"
              << " help                       - Show this help\n"
              << " exit                       - Save and exit\n";
}

int main() {
    ContactManager mgr("contacts.db");
    std::string cmd;
    printHelp();
    while (true) {
        std::cout << ">> ";
        if (!(std::cin >> cmd)) break;
        if (cmd == "add") {
            std::string name, phone, email;
            std::cin >> std::ws;
            std::getline(std::cin, name, ' ');
            std::cin >> phone >> email;
            mgr.addContact(name, phone, email);
        } else if (cmd == "list") {
            mgr.listContacts();
        } else if (cmd == "delete") {
            int id;
            std::cin >> id;
            mgr.deleteContact(id);
        } else if (cmd == "search") {
            std::string term;
            std::cin >> term;
            mgr.searchContacts(term);
        } else if (cmd == "help") {
            printHelp();
        } else if (cmd == "exit") {
            break;
        } else {
            std::cout << "Unknown command. Type 'help' for list." << std::endl;
        }
    }
    return 0;
}