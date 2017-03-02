#include <iostream>
#include <cstdio>
#include "Set.h"

unsigned int sanitize_user_in();

int main() {
    Set<unsigned int> set_1;
    Set<unsigned int> set_2;
    Set<unsigned int> set_3;
    int user_choice;
    unsigned int element;

    for (;;) {
        printf("\n1. Add elements to Set 1\n");
        printf("2. Add elements to Set 2\n");
        printf("3. Remove an element from Set 1\n");
        printf("4. Remove an element from Set 2\n");
        printf("5. Do a union of Set 1 and Set 2\n");
        printf("6. Do an intersection of Set 1 and Set 2\n");
        printf("7. Print Set 1, Set2, and Set 3\n");
        printf("0. Exit\n");
        printf("Choice: ");
        std::cin >> user_choice;
        switch (user_choice) {
            case 1:
                printf("Add element to Set 1: ");
                element = sanitize_user_in();
                set_1.add(element);
                printf("Added element %d to Set 1\n", element);
                break;
            case 2:
                printf("Add element to Set 2: ");
                element = sanitize_user_in();
                set_2.add(element);
                printf("Added element %d to Set 2\n", element);
                break;
            case 3:
                printf("Remove an element from Set 1: ");
                element = sanitize_user_in();
                set_1.remove(element);
                printf("Removed element %d from Set 1\n", element);
                break;
            case 4:
                printf("Remove an element from Set 2: ");
                element = sanitize_user_in();
                set_2.remove(element);
                printf("Removed element %d from Set 2\n", element);
                break;
            case 5:
                printf("Performing union of Set 1 and Set 2\n");
                set_3 = set_1 + set_2;
                break;
            case 6:
                printf("Performing intersection of Set 1 and Set 2\n");
                set_3 = set_1 - set_2;
            case 7:
                std::cout << "Set 1: " << set_1 << std::endl;
                std::cout << "Set 2: " << set_2 << std::endl;
                std::cout << "Set 3: " << set_3 << std::endl;
                break;
            case 0:
                std::exit(0);
            default:
                printf("Invalid input, try again: ");
                std::cin >> user_choice;
                break;
        }
    }
    return 0;
}

unsigned int sanitize_user_in() {
    unsigned int element;
    std::cin >> element;

    while (std::cin.fail()) {
        printf("Invalid input, try again: ");
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> element;
    }
    return element;
}
