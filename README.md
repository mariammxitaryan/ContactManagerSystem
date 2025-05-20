# Contact Manager CLI

A simple command-line Contact Manager application in C++.

## Description

This project provides a basic CLI program to manage contacts. Users can add, list, delete, and search contacts. All data is persisted in a local file (`contacts.db`) and automatically loaded on startup and saved on exit.

## Features

* Add a new contact with name, phone, and email.
* List all saved contacts.
* Delete a contact by its ID.
* Search contacts by name, phone, or email.
* Automatic persistence: data is loaded from `contacts.db` on startup and saved on exit.

## Prerequisites

* A C++17 compatible compiler (e.g., `g++`, `clang++`).
* CMake (optional, for building with CMake).

## File Structure

```
project-root/
├── contactManager.h      # Declarations of Contact and ContactManager
├── contactManagerImplementation.cpp    # Definitions for persistence and contact operations
├── main.cpp              # CLI interface and command loop
├── contacts.db           # Data file (auto-generated)
└── README.md             # Project documentation
```

## Build & Run

### Using g++ directly

```bash
# Compile
g++ -std=c++17 ContactManager.cpp main.cpp -o contact_manager

# Run
./contact_manager
```

### Using CMake

```bash
mkdir build && cd build
cmake ..
make
./contact_manager
```

## Usage

After running the program, use the following commands:

```text
add <name> <phone> <email>   Add a new contact
list                         List all contacts
delete <id>                  Delete the contact with the given ID
search <term>                Search contacts by name, phone, or email
help                         Show available commands
exit                         Save contacts and exit
```

Type `help` at any time to display this list.
