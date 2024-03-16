#include <iostream>
#include <vector>
using namespace std;

// Function to display available movies
void displayMovies() {
    cout << "1. Avengers: Endgame\n";
    cout << "2. The Shawshank Redemption\n";
    cout << "3. The Dark Knight\n";
}

// Function to display seat matrix
void displaySeatMatrix(int rows, int cols, vector<vector<char>>& seatMatrix) {
    cout << "\nSeat Matrix:\n";

    // Display column letters
    cout << "  ";
    for (int j = 0; j < cols; j++) {
        cout << char('a' + j) << " ";
    }
    cout << "\n";

    // Display seat matrix with row numbers
    for (int i = 0; i < rows; i++) {
        cout << i + 1 << " "; // Display row number

        for (int j = 0; j < cols; j++) {
            cout << seatMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}

// Function to calculate total price based on the number of selected seats
int calculatePrice(int numSeats, int pricePerSeat) {
    return numSeats * pricePerSeat;
}

int main() {
    // Movie details
    int selectedMovie;
    vector<string> movies = {"Avengers: Endgame", "The Shawshank Redemption", "The Dark Knight"};

    // Seat details
    const int rows = 5;
    const int cols = 10;
    vector<vector<char>> seatMatrix(rows, vector<char>(cols, 'O'));
    vector<int> selectedSeats;
    int numSeats;

    // Booked seats information
    vector<int> bookedSeats;
    int bookedSeatsCount = 0;

    // Ticket pricing
    const int pricePerSeat = 10;

    // Main loop for the program
    while (true) {
        // Display available movies
        while (true) {
            cout << "Select a movie:\n";
            displayMovies();
            cin >> selectedMovie;

            if (selectedMovie >= 1 && selectedMovie <= 3) {
                break;
            } else {
                cout << "Invalid movie selection. Please try again.\n";
            }
        }

        selectedMovie--; // Adjust index

        // Initialize seat matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                seatMatrix[i][j] = 'O'; // 'O' represents an available seat
            }
        }

        // Display booked seats from the previous selections
        for (int seat : bookedSeats) {
            int row = seat / cols;
            int col = seat % cols;
            seatMatrix[row][col] = 'X'; // Mark booked seats as 'X'
        }

        // Display seat matrix
        displaySeatMatrix(rows, cols, seatMatrix);

        // Select seats
        cout << "\nEnter the number of seats you want to book: ";
        cin >> numSeats;

        cout << "\nEnter seat numbers (row and column, e.g., 1 a) separated by space:\n";
        for (int i = 0; i < numSeats; i++) {
            while (true) {
                int row;
                char col;
                cin >> row >> col;

                // Check if the seat is available
                if (row >= 1 && row <= rows && col >= 'a' && col < 'a' + cols && seatMatrix[row - 1][col - 'a'] == 'O') {
                    seatMatrix[row - 1][col - 'a'] = 'X'; // 'X' represents a booked seat
                    selectedSeats.push_back((row - 1) * cols + (col - 'a')); // Save seat number
                    bookedSeats.push_back(selectedSeats.back()); // Save booked seat information
                    break;
                } else {
                    cout << "Invalid seat selection. Please choose another seat.\n";
                }
            }
        }

        // Display updated seat matrix
        displaySeatMatrix(rows, cols, seatMatrix);

        // Calculate and display total price
        int totalPrice = calculatePrice(numSeats, pricePerSeat);
        cout << "\nTotal Price for " << numSeats << " seats: $" << totalPrice << "\n";

        // Option to go back to the home page or exit the program
        cout << "\nOptions:\n";
        cout << "1. Go to Home Page (Select a new movie)\n";
        cout << "2. Exit\n";

        int option;
        cin >> option;

        if (option == 2) {
            break; // Exit the program
        }
        // Otherwise, continue to the next iteration of the main loop
    }

    return 0;
}
