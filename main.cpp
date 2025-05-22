#include <iostream>
#include <iomanip>  //for set()
#include <string>
using namespace std;

const int NUM = 10;
const float FLIGHT = 1600.00;
const float F_TIMES[5][2] = {{7.00, 9.30}, {9.00, 11.30},
                            {11.00, 13.30}, {13.00, 15.30},
                            {15.00, 17.30}};

struct travelBooking {
    string travellerName;
    string travelClass;
    float departureTime;
    float arrivalTime;
    string seatNo;
};
bool validateTimeOption(int opt){
    if(opt == 1 || opt == 2 || opt == 3 || opt == 4 || opt == 5)
        return true;
    else
        return false;
}
bool validateSeat(travelBooking t[], string sNo, int timeChoice){
    bool notBooked = true;
    float dTime;

    dTime = F_TIMES[timeChoice - 1][0];
    int i = 0;
    // check if it is already booked
    while(i < NUM){
        if(t[i].seatNo == sNo && t[i].departureTime == dTime){
            notBooked = false;
            break;
        }
        i++;
    }
    if(notBooked == false)
        return false;
    else
        return true;
}
void timeMenu(int & timeChoice){
    cout << "The available travel times for "
         << "flights are:" << endl;
    cout << setw(16) << "   Depart"
         << setw(7) << "Arrive" << endl;
    for(int i = 0; i < 5; i++)
        cout << i + 1 << setw(3) << "." << setw(12)
             << F_TIMES[i][0] << F_TIMES[i][1] << endl;

    cout << "Choose the time by entering the "
         << "option number from the displayed list:" << endl;
        do {
            cin >> timeChoice;
            if(!validateTimeOption(timeChoice))
                cout << "Incorrect option! Please choose from 1-5.";
        }while(!validateTimeOption(timeChoice));
}
//called the very first time, for any of the listed times
void displaySeats1(){
    int seatFlag = 0;
    int divValue;
    char row = 'A';
    int col = 1;
    divValue = 3;

    cout.setf(ios::left);
    // display the seats
    cout << "First Class(";
    cout << FLIGHT + FLIGHT * 0.20;
    cout << ")" << endl;
    cout << "|";
    for(int i = 1; i <= 5; i++){
        if(i == 25){
            cout << "Economy class(";
            cout << FLIGHT;

            cout << ")" << endl;
            cout << "|";
        }
        // display seats
        cout << row << col++;

        // arranging the seats in each row

        if(i % divValue == 0){
            if(seatFlag == 0){
                cout << "|";
                cout << setw(4) << "---- ";
                seatFlag = 1;
            }
            else
            {
                cout << "|";
                cout << endl;
                row = row + 1;
                seatFlag = 0;
                col =1;
            }
        }
        cout << "|";
    }
}
// called from second time onwards, for any particular time
void displaySeats2(travelBooking t[], int timeChoice){
    int seatFlag = 0;
    // int number;
    bool notBooked;
    int divValue;
    char row = 'A';
    int col = 1;
    divValue = 3;
    // float dTime;
    string sNo;

    cout.setf(ios::left);
    // displaying the seats
    cout << "First Class(";
    cout << FLIGHT + FLIGHT + 0.20;
    cout << ")" << endl;
    cout << "|";
    for(int i = 1; i <= 50; i++){
        //cout << "Current seat no: << sNo << endl;
        sNo = ""; // very important
        notBooked = true;
        if(i == 20){
            cout << "Economy class(";
            cout << FLIGHT;
            cout << ")" << endl;
            cout << "|";
        }

        sNo += row;
        sNo += to_string(col);

        // check if it is already booked
        notBooked = validateSeat(t, sNo, timeChoice);

        // display seats
        if(notBooked == false){
            cout << "**";
            col++;
        }
        else
            cout << row << col++;
        // arranging the seats for each row

        if(i % divValue == 0){
            if(seatFlag == 0){
                cout << "|";
                cout << setw(4) << "---- ";
                seatFlag = 1;
            }
            else{
                cout << "|";
                cout << endl;
                row = row + 1;
                seatFlag = 0;
                col = 1;
            }
        }
        cout << "|";
    }
}
float calcTicketPrice(travelBooking t){
    float price = 0.0;
    if((t.seatNo.substr(0, 1)) > "D")   // economy class
        price = FLIGHT;
    else
        price = FLIGHT + FLIGHT * 0.20;
    return price;
}
void displayTicket(travelBooking t){
    cout << setw(25) << "*************************" << endl;
    if((t.seatNo.substr(0, 1)) > "D")
        t.travelClass = "Economy class";
    else
        t.travelClass = "First class";

    cout << "\nTravel ticket for " << "FLIGHT" << endl;
    cout << setw(25) << "*************************" << endl;
    cout << setw(15) << "Name" << setw(3) << ":"
         << setw(20) << t.travellerName;
    cout << setw(20) << "Travel Ticket class"
         << setw(3) << ":" << t.travelClass << endl;
    cout << setw(38) << ":" << setw(20) << "Seat No"
         << setw(3) << ":" << t.seatNo << endl;
    cout << setw(15) << "Departure" << setw(3) << ":"
         << "Johannesburg";
    cout << setw(8) << "" << setw(20) << "Departure Time"
         << setw(3) << ":" << t.departureTime << endl;

    cout << setw(15) << "Destination" << setw(3) << ":"
         << "Cape Town";
    cout << setw(11) << "" << setw(20) << "Arrival Time"
         << setw(3) << ":" << t.arrivalTime << endl;

    // display amount
    cout << "*************************" << endl;
    cout << "Amount:R" << calcTicketPrice(t);
    cout << " Thank you for booking with COS1511."
         << "Your travel agent for queries is "
         << "Annie Mathew. " << endl;
    cout << "*************************" << endl;
}


int main()
{
    travelBooking traveller[NUM];   // array of structs

    string fullName;
    string seatNo;
    int depTimeChoice;
    char answer;

    int timeCount1, timeCount2, timeCount3, timeCount4, timeCount5, bCount;
    timeCount1 = timeCount2 = timeCount3 = timeCount4 = timeCount5 = 0;
    int i = 0;

    do{
        cout << "Welcome to COS1511 Flight Booking system"
             << endl;
        cout << "\nEnter full name: " << endl;
        getline(cin, fullName, '\n');
        cout << endl;
        cout.setf(ios::left);
        cout.precision(2);
        cout.setf(ios::fixed);
        // call function to display time chart
        timeMenu(depTimeChoice);

        cout << "\nThe available seats for "
             << F_TIMES[depTimeChoice - 1][0]
             << " are as follows:" << endl;
        switch(depTimeChoice){
        case 1:
            bCount = timeCount1;
            break;
        case 2:
            bCount = timeCount2;
            break;
        case 3:
            bCount = timeCount3;
            break;
        case 4:
            bCount = timeCount4;
            break;
        case 5:
            bCount = timeCount5;
            break;
        }
        if(bCount == 0){
            displaySeats1(); // first time seat dispaly
            cout << "\nPlease key in a seat number "
                 << "to choose a seat(e.g:A2)" << endl;
        }
        else{
            // seat display after bookings are made
            displaySeats2(traveller, depTimeChoice);

            cout << "\n\nSeats that are already taken "
                 << "are indicated with an asterisk " << endl;
            cout << "Please key in a seat number to "
                 << "choose a seat(e.g:A2)" << endl;
        }

        // validating the chosen number
        do{
            cin >> seatNo;
            if((!validateSeat(traveller, seatNo, depTimeChoice)))
                cout << "Sorry, the seat is taken. "
                     << "Please choose a seat that is available "
                     << endl;
        }while(!validateSeat(traveller, seatNo, depTimeChoice));

        // assign the booking details to the array of structs
        traveller[i].travellerName = fullName;

        if((seatNo.substr(0, 1)) > "D")
            traveller[i].travelClass = "Economy class";
        else
            traveller[i].travelClass = "First class";
        traveller[i].departureTime = F_TIMES[depTimeChoice - 1][0];
        traveller[i].arrivalTime =F_TIMES[depTimeChoice - 1][1];
        traveller[i].seatNo = seatNo;

        // display ticket
        displayTicket(traveller[i]);
        i++;

        cout << "Do you want to make another booking(Y/N)?" << endl;
        cin >> answer;
        cin.get();
        // based on time choice increment the counts
        if(depTimeChoice == 1)
            timeCount1++;
        else if(depTimeChoice == 2)
            timeCount2++;
        else if(depTimeChoice == 3)
            timeCount3++;
        else if(depTimeChoice == 4)
            timeCount4++;
        else if(depTimeChoice == 5)
            timeCount5++;

    }while(toupper(answer) == 'Y');
    cout << endl;
    cout << "Number of bookings made for " << F_TIMES[0][0]
         << "a.m" << ":" << timeCount1 << endl;
    cout << "Number of bookings made for " << F_TIMES[1][0]
         << "a.m" << ":" << timeCount2 << endl;
    cout << "Number of bookings made for " << F_TIMES[2][0]
         << "a.m" << ":" << timeCount3 << endl;
    cout << "Number of bookings made for " << F_TIMES[3][0]
         << "a.m" << ":" << timeCount4 << endl;
    cout << "Number of bookings made for " << F_TIMES[4][0]
         << "a.m" << ":" << timeCount5 << endl;
    return 0;
}
