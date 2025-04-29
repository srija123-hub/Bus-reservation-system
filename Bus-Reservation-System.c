#include <stdio.h>
#include <string.h>

struct Bus {
    char bus_no[10];
    char driver[50];
    char arrival[10];
    char departure[10];
    char from[20];
    char to[20];
    char seats[8][4][20]; // 8 rows, 4 seats per row
};

struct Bus buses[10];
int bus_count = 0;

void addBus() {
	int i,j;
    printf("\nEnter Bus No: ");
    scanf("%s", buses[bus_count].bus_no);

    printf("Enter Driver Name: ");
    scanf("%s", buses[bus_count].driver);

    printf("Enter Arrival Time: ");
    scanf("%s", buses[bus_count].arrival);

    printf("Enter Departure Time: ");
    scanf("%s", buses[bus_count].departure);

    printf("Enter From: ");
    scanf("%s", buses[bus_count].from);

    printf("Enter To: ");
    scanf("%s", buses[bus_count].to);

    // Initialize all seats as "Empty"
    for(i=0; i<8; i++) {
        for(j=0; j<4; j++) {
            strcpy(buses[bus_count].seats[i][j], "Empty");
        }
    }

    bus_count++;
    printf("\nBus added successfully!\n");
}

void reserveSeat() {
    char bus_no[10];
    int seat,i;
    printf("\nEnter Bus No: ");
    scanf("%s", bus_no);

    int found = -1;
    for (i=0; i<bus_count; i++) {
        if (strcmp(buses[i].bus_no, bus_no) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Bus not found!\n");
        return;
    }

    printf("Enter Seat Number (1-32): ");
    scanf("%d", &seat);

    if (seat < 1 || seat > 32) {
        printf("Invalid seat number!\n");
        return;
    }

    int row = (seat - 1) / 4;
    int col = (seat - 1) % 4;

    if (strcmp(buses[found].seats[row][col], "Empty") == 0) {
        printf("Enter Passenger Name: ");
        scanf("%s", buses[found].seats[row][col]);
        printf("Seat reserved successfully!\n");
    } else {
        printf("Seat already reserved!\n");
    }
}

void showBus() {
    char bus_no[10];
    printf("\nEnter Bus No: ");
    scanf("%s", bus_no);

    int found = -1,i,j;
    for (i=0; i<bus_count; i++) {
        if (strcmp(buses[i].bus_no, bus_no) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Bus not found!\n");
        return;
    }

    printf("\nBus No: %s\nDriver: %s\nArrival Time: %s\nDeparture Time: %s\nFrom: %s\nTo: %s\n", 
        buses[found].bus_no, buses[found].driver, buses[found].arrival, buses[found].departure,
        buses[found].from, buses[found].to);

    printf("\nSeats:\n");
    for (i=0; i<8; i++) {
        for (j=0; j<4; j++) {
            printf("%d.%s\t", (i*4)+j+1, buses[found].seats[i][j]);
        }
        printf("\n");
    }
}

void listBuses() {
	int i;
    printf("\nList of Buses:\n");
    for (i=0; i<bus_count; i++) {
        printf("%d. Bus No: %s, Driver: %s, From: %s, To: %s\n", i+1, 
                buses[i].bus_no, buses[i].driver, buses[i].from, buses[i].to);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n*** Bus Reservation System ***\n");
        printf("1. Add Bus\n2. Reserve Seat\n3. Show Bus\n4. List Buses\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addBus(); break;
            case 2: reserveSeat(); break;
            case 3: showBus(); break;
            case 4: listBuses(); break;
            case 5: return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
