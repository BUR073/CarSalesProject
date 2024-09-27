#include <stdio.h>

char* model(char *request, int pos) {
    char *model[]= {"BMW", "Audi"};
    if (request == "GET") {
        return model[pos];
    }
    return "works";
}


int year(char *request, int pos) {
    int year[] = {2005, 2006};
    if (request == "GET") {
        return year[pos];
    }
    return 0;
}

int amount(char *request, int pos) {
    int amount[] = {1, 2};
    if (request == "GET") {
        return amount[pos];
    }
    return 0;
}
int price(char *request, int pos) {
    int price[] = {2500, 5000};
    if (request == "GET") {
        return price[pos];
    }
    return 0;

}

void carStock() {
    for (int i = 0; i < 2; i++) {
        printf("Car %d:\n", i + 1);
        printf("Price: %d\n", price("GET", i));
        printf("Model: %s\n", model("GET", i));
        printf("Year: %d\n", year("GET", i));
        printf("Amount: %d\n", amount("GET", i));
        printf("\n");
    }
}
void menu() {
    // Looping Menu with 4 main actions:
    // View Cars Stock,
    // Buy Cars,
    // View Sales Data, and
    // Customer Feedback.
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. View Cars Stock\n");
        printf("2. Buy Cars\n");
        printf("3. View Sales Data\n");
        printf("4. Customer Feedback\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:

                // Code for Option 1
                    printf("View Cars Stock.\n");
                    carStock();
                    break;
            case 2:
                // Code for Option 2
                    printf("Buy Cars.\n");
                    break;
            case 3:
                // Code for Option 3
                    printf("View Sales Data.\n");
                    break;
            case 4:
                printf("Customer Feedback\n");
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

}

int main(void) {
    menu();
    return 0;

}