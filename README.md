Bank Management System

Description

This project is a Bank Management System implemented in C++. It allows managing employees by storing their working hours, contract types, and calculating their salaries. The data can be saved to a file and loaded for future use.

Features

Add new employees with contract type and working hours

Display the list of employees with their calculated salaries

Save employee data to a file

Load employee data from a file

Simple console-based interface

Technologies Used

C++

File Handling (fstream)

Vectors (std::vector)

Enums and Structs

Installation & Usage

1. Clone the Repository

git clone https://github.com/your-username/your-repository.git
cd your-repository

2. Compile and Run

Using g++ (Linux/macOS)

g++ -o bank_management main.cpp
./bank_management

Using g++ (Windows)

g++ -o bank_management.exe main.cpp
bank_management.exe

Program Flow

The user is presented with a menu:

1: Add an employee

2: Show all employees

3: Save employee data to file

4: Load employee data from file

5: Exit the program

The user can input employee details, including name, surname, contract type (full-time/part-time), and weekly work hours.

Salaries are calculated based on working hours and contract type.

Data is stored in a file (punetoret.txt) for persistence.

File Structure

/
├── main.cpp           # Main program file
├── punetoret.txt      # Data file (generated after saving employees)
├── README.md          # Project documentation

Contributors
Dilon Latifaj, Eda Krasniqi, Elira Bytyqi, Art Gashi

License

This project is licensed under the MIT License.

