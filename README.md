# 🏠 Hostel Management System

A C-based Hostel Management System developed as a group project to manage common hostel operations such as student registration, room allocation, fees, complaints, attendance, canteen services, lost & found, and laundry management.

---

## 👥 Group Members

| Name | Student ID |
|---|---|
| **MD. RAHIMUL HAQUE** | **252-35-531** |
| **MD. SIAM HOSSAN** | **252-35-262** |
| **NOSRAT JAHAN TISHA** | **252-35-289** |

---

## 📌 Project Overview

The Hostel Management System is a **menu-driven console application written in C**.

The system provides different features for students, administrators, canteen management, and warden-related management.

The main menu includes:

- Student Registration
- Student Login
- Admin Login
- Canteen Management System
- Lost & Found Management
- Laundry System
- Exit

---

## ✨ Main Features

### 👨‍🎓 Student Management

- Student Registration
- Student Login
- View Profile
- View Fee
- Pay Fee
- Payment History
- View Notice
- Add Complaint
- Leave Request
- Visitor Request
- View Attendance
- Check In
- Check Out
- Canteen
- Lost & Found
- Laundry System

---

### 🛏️ Room Management

Admin can manage hostel rooms through:

- Add Room
- View Rooms
- Allocate Room
- Remove Room
- Vacate Room
- View Students
- Update Student Fee

---

### 💰 Fee & Payment Management

The system provides:

- Student fee management
- Fee payment
- Payment history
- Food bill payment
- Paid/Pending order status

---

### 📢 Notice & Complaint Management

Admin can:

- Add Notice
- View Notice
- Delete Notice
- View Student Complaints

Students can:

- Submit Complaints
- View Notices

---

### 🕒 Attendance & Check-In / Check-Out

The system supports:

- Mark Attendance
- View Attendance
- Student Check-In
- Student Check-Out
- Late Entry Record
- Late Entry Complaint Management

---

### 🍽️ Canteen Management

The canteen module includes:

- View Food Menu
- Add Food
- Update Food Price
- Order Food
- Pay Food Bill
- View All Food Orders
- Paid/Pending Order Status

---

### 🔎 Lost & Found Management

The Lost & Found module provides:

- View Found Items
- Search Lost Item
- Claim Item
- Lost & Found Management

---

### 🧺 Laundry Management

The laundry module provides:

- Apply for Laundry
- Add Multiple Laundry Items
- Set Pickup Date
- View Laundry Status
- Update Laundry Status

Laundry status can be:

1. Received
2. Washing
3. Ready
4. Delivered

---

## 🔐 Authentication

The system provides separate login systems for:

- Student
- Admin
- Canteen Management
- Warden

Password processing uses **MD5 hashing** as part of the academic project implementation.

> **Note:** MD5 is used for this educational project. It is not recommended for modern production password storage.

---

## 💾 File Handling

The system uses file handling to store and retrieve data.

Some of the files used by the system include:

- `students.txt`
- `rooms.txt`
- `payment.txt`
- `attendance.txt`
- `leave.txt`
- `student_complaints.txt`
- `food.txt`
- `orders.txt`
- `Late_Entry.txt`
- Laundry-related data files

The program loads saved data when it starts and updates files when new information is added or modified.

---

## 🛠️ Technologies Used

- **Programming Language:** C
- **Programming Concepts:**
  - Structures
  - Arrays
  - Functions
  - Loops
  - Switch Case
  - File Handling
  - String Handling
  - Conditional Statements
- **Authentication:** MD5 Hashing
- **Data Storage:** Text Files
- **Environment:** VS Code / GCC
- **Version Control:** Git & GitHub

---

## ▶️ How to Run

### Step 1: Clone the Repository

```bash
git clone https://github.com/rahim531/Hostel-Management-System.git
