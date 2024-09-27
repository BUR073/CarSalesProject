#include <stdio.h>

char* model(char *request, int pos) {
    char *model[]= {"BMW 116i", "Audi A3", "Citroen Berlingo", "BMW M340i"};
    if (request == "GET") {
        return model[pos];
    }
    return "works";
}

int amount(char *request, int pos) {
    int amount[] = {1, 2, 3, 1};
    if (request == "GET") {
        return amount[pos];
    }
    return 0;
}
int price(char *request, int pos) {
    int price[] = {2500, 5000, 7500, 40000};
    if (request == "GET") {
        return price[pos];
    }
    return 0;

}

int year(char *request, int pos) {
    int year[] = {2005, 2006, 2007, 2018};
    if (request == "GET") {
        return year[pos];
    }
    if (request == "len") {
        return sizeof(year) / sizeof(year[0]);
    }
    return 0;
}

int findLargestIndex(int arr[], int size) {
    int maxIndex = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void carStock() {
    int numberOfModels = year("len", 0);
    int order[numberOfModels];
    int IndexOrder[numberOfModels];
    for (int i = 0; i < numberOfModels; i++) {
        order[i] = year("GET", i);
    }
    int index;
    for (int i = 0; i < numberOfModels; i++) {
        index = findLargestIndex(order, numberOfModels);
        order[index] = 0;
        IndexOrder[i] = index;
    }


    for (int i = 0; i < numberOfModels; i++) {
        printf("Car %d:\n", i + 1);
        printf("Model: %s\n", model("GET", IndexOrder[i]));
        printf("Year: %d\n", year("GET", IndexOrder[i]));
        printf("Price: £%d\n", price("GET", IndexOrder[i]));
        printf("Amount: %d\n", amount("GET", IndexOrder[i]));
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
        printf("\n");

        switch (choice) {
            case 1:

                // Code for Option 1
                    printf("View Cars Stock\n\n");
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