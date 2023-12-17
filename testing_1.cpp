#include <iostream>
#include <iomanip>
using namespace std;

// Constants for ticket categories and prices
const int NUM_SEATS = 30;
const double VVIP_PRICE = 12000.0, VIP_PRICE = 6000.0, REGULAR_PRICE = 1000.0;

// Arrays to represent seat availability
bool vvipSeats[NUM_SEATS] = { true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true};
bool vipSeats[NUM_SEATS] = { true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true };
bool regularSeats[NUM_SEATS] = { true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true };
string VVIPSEAT[NUM_SEATS] = { "O", "O", "O", "O", "O", "O", "O", "O", "O", "O", "O", "O", "O", "O", "O", "O", "O", "O", "O", "O","O", "O", "O", "O", "O", "O", "O", "O", "O", "O" };
string VIPSEAT[NUM_SEATS] = { "O", "O", "O", "O", "O", "O", "O", "O", "O", "O","O", "O", "O", "O", "O", "O", "O", "O", "O", "O","O", "O", "O", "O", "O", "O", "O", "O", "O", "O" };
string REGSEAT[NUM_SEATS] = { "O", "O", "O", "O", "O", "O", "O", "O", "O", "O", "O", "O", "O", "O", "O", "O", "O", "O", "O", "O","O", "O", "O", "O", "O", "O", "O", "O", "O", "O" };


// Function to display the ticket ordering menu
void displayMenu() {
    std::cout << "===== Concert Ticketing System =====\n";
    std::cout << "1. Order Tickets\n";
    std::cout << "2. Display Available Seats\n";
    std::cout << "3. Exit\n";
    std::cout << "====================================\n";
}

// Function to display the layout of available seats
void displaySeats() {
    std::cout << "VVIP Seats:\n";
    for (int i = 0; i < NUM_SEATS; ++i) {
        std::cout << std::setw(3) << (vvipSeats[i] ? "O" : "X");
    }
    std::cout << "\n\nVIP Seats:\n";
    for (int i = 0; i < NUM_SEATS; ++i) {
        //std::cout << std::setw(3) << (i + 1) << ". " << (vipSeats[i] ? "O" : "X") << "   ";
        std::cout << std::setw(3) << (vipSeats[i] ? "O" : "X");
    }
    std::cout << "\n\nRegular Seats:\n";
    for (int i = 0; i < NUM_SEATS; ++i) {
        //std::cout << std::setw(3) << (i + 1) << ". " << (regularSeats[i] ? "O" : "X") << "   ";
        std::cout << std::setw(3) << (regularSeats[i] ? "O" : "X");
    }
    std::cout << "\n\n";
}

// Function to calculate the total payment
double calculateTotalPayment(int category, int quantity) {
    double price;
    //(category == 1) ? price=VIP_PRICE : price=REGULAR_PRICE;
    if(category == 1)
    {
        price=VVIP_PRICE;
    }
    else if(category == 2)
    {
        price=VIP_PRICE;
    }
    else{
        price=REGULAR_PRICE;
    }
    return price * quantity;
}

// Function to order tickets
void orderTickets() {
    int category, quantity, sub_quantity;

    // Input validation for category
    do {
        std::cout << "Enter ticket category (1 for VIP, 2 for VIP, 3 for Regular): ";
        std::cin >> category;
    } while (category < 1 || category > 3);

    // Input validation for quantity
    do {
        std::cout << "Enter quantity of tickets: ";
        std::cin >> quantity;
    } while (quantity <= 0 || quantity > NUM_SEATS);

    // Check seat availability and proceed with the order
    bool* seats = (category == 1) ? vipSeats : regularSeats;
    sub_quantity = quantity;
    for (int i = 0; i < NUM_SEATS && sub_quantity > 0; ++i) {
        if (seats[i]) {
            seats[i] = false;
            --sub_quantity;
        }
    }

    if (sub_quantity == 0) {
        std::cout << "Order successful!\n";
        double totalPayment = calculateTotalPayment(category, quantity);
        std::cout << "Total Payment: $" << std::fixed << std::setprecision(2) << totalPayment << "\n";
    }
    else {
        std::cout << "Sorry, not enough available seats.\n";
    }
}

// Function to display the ticket sales report
void displayTicket() {
    int soldVip = NUM_SEATS;
    int soldVVip = NUM_SEATS;
    int soldRegular = NUM_SEATS;

    std::cout << "===== Ticket Sales Report =====\n";
    std::cout << "VIP Tickets Sold: " << soldVip << "\n";
    std::cout << "Regular Tickets Sold: " << soldRegular << "\n";
    std::cout << "================================\n";
}

int main() {
    int choice;

    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            orderTickets();
            break;
        case 2:
            displaySeats();
            break;
        case 3:
            std::cout << "Exiting the system. Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);

    
    // Additional functionalities (if any) can be added here.

    return 0;
}
