# Flight Reservation System (C++)

A console-based flight reservation system built in C++ as a Programming Fundamentals course project. The system allows passengers to search flights and make reservations, while an admin manages flight schedules and records.

---

## Overview

This was an early academic project focused on core C++ fundamentals: control structures, functions, arrays/structs, and file handling — built before introducing OOP or database-backed storage (see `airline-reservation-system` for the later, more advanced version of this concept using C#, SQL Server, and a GUI).

---

## Features

### Admin
- Add and manage flight schedules
- View and manage passenger records
- Secure login with stored credentials

### Passenger
- View flight details and destinations
- Search flights by source/destination
- Make a reservation
- View booking details

---

## Technical Details

| Aspect | Implementation |
|---|---|
| Language | C++ |
| Interface | Console (CLI) |
| Storage | Flat text files |
| Compiler used | g++ |

### Data Files
- `admin username password.txt` — admin login credentials
- `flight name.txt` — flight names
- `source.txt` / `destination.txt` — route data
- `schedule.txt` — flight schedule
- `passenger.txt` — passenger records
- `reservations.txt` — booking records
- `details.txt` — additional flight/passenger detail
- `employ.txt` — employee records
- `total flights.txt` — flight count tracker

---

## How to Run

### Prerequisites
A C++ compiler (`g++`, Code::Blocks, Dev-C++, or Visual Studio).

### Steps
1. Clone the repository:
   ```
   git clone https://github.com/salehakhuram/Flight-Reservation-System.git
   ```
2. Keep the `.cpp` file and all `.txt` data files in the same folder.
3. Compile:
   ```
   g++ "Programming Fundamentals Project.cpp" -o flight_reservation
   ```
4. Run:
   ```
   ./flight_reservation       # Linux/macOS
   flight_reservation.exe     # Windows
   ```

---

## Known Limitations

- This is an early, file-based academic project — no encryption, no concurrency handling, no input sanitization beyond basic checks.
- Several data files in this repo are duplicate/leftover copies from local testing and should be cleaned up (tracked separately).
- A precompiled `.exe` is currently committed to the repo; this will be removed and excluded going forward via `.gitignore`.

---

## Relationship to Other Projects

This was succeeded by **[airline-reservation-system](https://github.com/salehakhuram/airline-reservation-system)**, which rebuilds the same domain (flights/reservations) using C#, Windows Forms, SQL Server, and role-based access control — a more representative example of current skill level.

---

## Author

Saleha Khurram
