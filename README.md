# Flight Booking System

This **Flight Booking System** was developed to simulate the process of booking a flight from Johannesburg to Cape Town. Through this project, I was able to explore and implement core programming concepts as part of a guided assignment, focusing on user interactions, data management, and modular design.

## Project Overview

My goal for this assignment was to create a console-based application that guides a user through the flight booking process. This included selecting a flight time, choosing an available seat, and receiving a booking confirmation. The system needed to handle multiple bookings and provide a summary of all reservations at the end.

## Key Features Implemented

- **User-Friendly Interface:** Prompts the user for their name and presents a clear menu of flight departure times.
- **Flight Time Selection:** Allows users to choose from five predefined departure and arrival times, all for a fixed 2.5-hour flight duration between Johannesburg and Cape Town.
- **Dynamic Seating Arrangement:** Displays the seating layout for each flight, indicating already booked seats with "\*\*".
  - The plane has 50 seats, arranged six per row (three on each side of a walkway).
  - The first four rows are **First Class**, and the remaining rows are **Economy Class**.
  - Economy class tickests are fixed at R1600.00, while First Class tickets are 20% more.
- **Input Validation:** Ensures that user selections for flight times (1-5) and seat numbers are valid and available. If an invalid or already booked seat is chosen, a helpful message is displayed, and the user can re-enter their selection.
- **Booking Confirmation:** Upon successful seat selection, a detailed flight booking ticket is displayed, including the passenger's name, flight details, seat number, and ticket price.
- **Multiple Bookings:** Users have the option to make additional bookings for various flight times, with case-insensitive input for continuing ('Y'/'N').
- **Booking Summary:** Before exiting, the program displays the total number of bookings made for each flight time.

## Technical Implementation Details

I focused on a structured approach for this project, carefully utilizing functions and appropriate data structures to effectively manage the simulation's complexity.

### Data Structures

- To fulfil the assignment's data management requirements, I used a **two-dimensional array** to store and manage departure and arrival times for the various flight options. Additionally, **one-dimensional arrays** were employed to track seat availability for each flight and to store details of individual bookings.

### Functions

To ensure a modular and maintainable codebase, a key aspect of the assignment, I defined several functions, each with a specific responsibility:

- **`displayFlightMenu()`:** Displays the available flight times, accepts the user's choice, and performs initial validation.
- **`validateMenuOption()`:** Validates that the chosen flight time option is between 1 and 5.
- **`displaySeatingArrangementInitial()`:** Shows the seating layout for a flight when no seats have been booked yet. This function also clearly labels "First Class" and "Economy Class" sections and their respective prices.
- **`displaySeatingArrangementWithBookedSeats()`:** Updates and displays the seating arrangement, making booked seats with "\*\*". This function calls `validateSeatAvailability()` to determine which seats are taken.
- **`validateSeatAvailability()`:** Checks if a chosen seat number is already booked. (Assumes valid seat number format, only checks availability).
- **`calculateTicketPrice()`:** Determines the cost of the ticket based on the chosen travel class (First or Economy). This function ensures the First Class price is accurately calculated as 20% more than the Economy Class, using a global constant for the economy price.
- **`displayBookingTicket()`:** Generates and displays the comprehensive flight booking ticket for each successful booking, calling `calculateTicketPrice()` to get the final cost.

### Main program Flow (`main()`)

The `main()` function orchestrates the program's execution. It handles:

- Reading the user's full name.
- The primary loop for allowing multiple bookings.
- Calling the relevant functions for displaying menus, seat arrangements, and booking tickets.
- Validating seat choices and handling re-entry if a seat is already taken.
- Managing the case-insensitive "continue" prompt.
- Displaying the final booking counts before exiting.

## How to Run

```bash
# Example for C++ program:
# Compile the source code
g++ main.cpp -o flight_booking

# Run the executable
./flight_booking
```

## License / Credits

This project was developed as part of a coursework assignment for UNISA.

Copyright © 2025 Bruce R. Thagwana, UNISA. All rights reserved.
