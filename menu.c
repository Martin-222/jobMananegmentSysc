#include <stdio.h>
#include "menu.h"
#include "job.h"

void display_menu() {
    int choice;
    do {
        printf("\nJob Management System\n");
        printf("1. Add Job\n");
        printf("2. View Jobs\n");
        printf("3. Delete Job\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_job();
                break;
            case 2:
                view_jobs();
                break;
            case 3:
                delete_job();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}
