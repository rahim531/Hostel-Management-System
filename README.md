🏠 Hostel Management System

A C-based Hostel Management System developed as a group project to
manage common hostel operations such as student registration, room
allocation, fees, complaints, attendance, canteen services, lost &
found, and laundry management.

👥 Group Members

Name                     Student ID

MD. RAHIMUL HAQUE    252-35-531
MD. SIAM HOSSAN      252-35-262
NOSRAT JAHAN TISHA   252-35-289

📌 Project Overview

The Hostel Management System is a menu-driven console application
written in C. It provides separate functions for students,
administrators, canteen management, and warden-related services.

The program uses structures, arrays, functions, file handling, string
processing, menu-driven control flow, and MD5 hashing for password
storage.

✨ Main Features

👨‍🎓 Student Management

Student registration

Student login

Student profile

Fee viewing and payment

Payment history

Notice board

Complaint submission

Leave request

Visitor request

Attendance viewing

Check-in and check-out

Canteen access

Lost & Found access

Laundry application and status tracking

🛏️ Room Management

Add rooms

View room information

Allocate rooms to students

Remove rooms

Vacate rooms

Track room capacity and occupancy

💰 Fee & Payment Management

Update student fee

Student fee payment

Payment history

Food bill management

Paid/pending food order status

📢 Notice & Complaint Management

Add notices

View notices

Delete notices

Submit student complaints

View complaints

🕒 Attendance & Check-in/Check-out

Mark attendance

View attendance records

Student check-in

Student check-out

Late-entry record generation

🍽️ Canteen Management

View food menu

Add food items

Update food prices

Order food

Pay food bills

View all food orders

🔎 Lost & Found Management

View found items

Search for lost items

Claim lost items

Warden-based management

🧺 Laundry Management

Apply for laundry

Add multiple laundry items and quantities

Set pickup date

View laundry request status

Warden can update status:

Received

Washing

Ready

Delivered

🔐 Authentication

The system provides separate access for: - Student - Admin - Canteen
management - Warden-related management

Student passwords are processed using an MD5 hashing implementation
included in the C source code.

Note: MD5 is included here as part of the academic project
implementation. It is not recommended for modern production password
storage.

💾 File Handling

The program stores information in text files so that data can be loaded
again when the program starts.

Examples of files used by the program include:

students.txt

rooms.txt

notice.txt

payment.txt

attendance.txt

leave.txt

visitor.txt

student_complaints.txt

food.txt

orders.txt

lost_found.txt

laundry.txt

Late_Entry.txt

These files may be created automatically when the corresponding features
are used.

🛠️ Technologies Used

Language: C

Programming Concepts: Structures, Arrays, Functions, Loops,
Switch-Case, File Handling, String Handling

Authentication: MD5 hashing

Storage: Text files

Environment: Console/Terminal

Version Control: Git & GitHub

▶️ How to Run

1. Clone the repository

git clone https://github.com/rahim531/Hostel-Management-System.git

2. Open the project folder

cd Hostel-Management-System

3. Compile the C program

Using GCC:

gcc project.c -o hostel

4. Run the program

On Windows:

hostel.exe

Or:

.\hostel.exe

📂 Project Structure

Hostel-Management-System/
│
├── project.c
├── .vscode/
│   ├── c_cpp_properties.json
│   ├── launch.json
│   └── settings.json
│
└── README.md

Runtime data files such as students.txt, rooms.txt, payment.txt,
and others may appear in the project directory after the program is
used.

🎯 Project Objectives

Develop a practical C programming project

Apply structured programming concepts

Practice file handling and data persistence

Implement role-based menu systems

Manage hostel-related operations through a single application

Provide a simple console-based management solution

🚀 Future Improvements

Possible future improvements include:

Database integration

Graphical user interface

Stronger password hashing

Better input validation

Online hostel management

Automated email/SMS notifications

Advanced reporting and search

Improved data security

📜 License

This project is created for educational and academic purposes.

🔗 Repository

GitHub: https://github.com/rahim531/Hostel-Management-System
