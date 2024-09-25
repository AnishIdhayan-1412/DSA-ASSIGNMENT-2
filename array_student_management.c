/* 2. You are given a task with creating a simple student management system using arrays  that will allow the user to manage student names. Implement the following operations  on a list of student names using switch-case and arrays. After every operation,  display the current list of students. 
The operations to implement are: 
(i) Creation of the list: Allow the user to create a list of student names by entering  them one by one. 
(ii) Insertion of a new student: Insert a new student's name into a specific position  in the list. The user should provide the name and the index at which it should  be inserted. 
(iii) Deletion of a student: Delete a student's name from the list based on their  position or name. Ask the user whether they want to delete by name or by  index. 
(iv) Traversal of the list: Display all the student names in the current order. (v) Search for a student: Search for a student's name in the list and display  whether or not the student is found, along with their position if present.
*/

#include <stdio.h>
#include <string.h>

int main() {
    const int max_students = 100; // maximum number of students
    const int name_length = 50; // maximum length of a student name

    char students[max_students][name_length]; // array to hold student names
    int count = 0; // current number of students
    int choice = 0;

    while (choice != 6) {
        // display the menu
        printf("1. create the list of students\n");
        printf("2. insert a new student\n");
        printf("3. delete a student\n");
        printf("4. display student list\n");
        printf("5. search for a student\n");
        printf("6. exit\n");
        printf("enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character after entering choice

        switch (choice) {
            case 1: {
                // creation of the list
                printf("enter the number of students: ");
                scanf("%d", &count);
                getchar(); // consume newline character
                for (int i = 0; i < count; i++) {
                    printf("enter student name %d: ", i + 1);
                    fgets(students[i], name_length, stdin);
                    students[i][strcspn(students[i], "\n")] = 0; // remove newline character
                }
                break;
            }
            case 2: {
                // insertion of a new student
                if (count < max_students) {
                    char new_student[name_length];
                    int position;

                    printf("enter the student's name to insert: ");
                    fgets(new_student, name_length, stdin);
                    new_student[strcspn(new_student, "\n")] = 0; // remove newline

                    printf("enter the position (0-based index) to insert the student: ");
                    scanf("%d", &position);
                    getchar(); // consume newline

                    if (position >= 0 && position <= count) {
                        for (int i = count; i > position; i--) {
                            strcpy(students[i], students[i - 1]);
                        }
                        strcpy(students[position], new_student);
                        count++;
                    } else {
                        printf("invalid position!\n");
                    }
                } else {
                    printf("cannot insert more students, list is full.\n");
                }
                break;
            }
            case 3: {
                // deletion of a student
                char delete_option;
                printf("delete by name or position? (n/p): ");
                scanf(" %c", &delete_option);
                getchar(); // consume newline

                if (delete_option == 'n') {
                    char name_to_delete[name_length];
                    printf("enter the student's name to delete: ");
                    fgets(name_to_delete, name_length, stdin);
                    name_to_delete[strcspn(name_to_delete, "\n")] = 0; // remove newline

                    int found = 0;
                    for (int i = 0; i < count; i++) {
                        if (strcmp(students[i], name_to_delete) == 0) {
                            found = 1;
                            for (int j = i; j < count - 1; j++) {
                                strcpy(students[j], students[j + 1]);
                            }
                            count--;
                            break;
                        }
                    }
                    if (found) {
                        printf("deleted %s from the list.\n", name_to_delete);
                    } else {
                        printf("student not found.\n");
                    }
                } else if (delete_option == 'p') {
                    int position;
                    printf("enter the position (0-based index) to delete the student: ");
                    scanf("%d", &position);
                    getchar(); // consume newline

                    if (position >= 0 && position < count) {
                        for (int i = position; i < count - 1; i++) {
                            strcpy(students[i], students[i + 1]);
                        }
                        count--;
                        printf("deleted student at position %d.\n", position);
                    } else {
                        printf("invalid position!\n");
                    }
                } else {
                    printf("invalid option!\n");
                }
                break;
            }
            case 4: {
                // display student list
                printf("student list: [");
                for (int i = 0; i < count; i++) {
                    printf("%s", students[i]);
                    if (i < count - 1) {
                        printf(", ");
                    }
                }
                printf("]\n");
                break;
            }
            case 5: {
                // search for a student
                char name_to_search[name_length];
                printf("enter the student's name to search: ");
                fgets(name_to_search, name_length, stdin);
                name_to_search[strcspn(name_to_search, "\n")] = 0; // remove newline

                int found = 0;
                for (int i = 0; i < count; i++) {
                    if (strcmp(students[i], name_to_search) == 0) {
                        printf("%s found at position %d\n", name_to_search, i);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("%s not found.\n", name_to_search);
                }
                break;
            }
            case 6:
                printf("exiting the program...\n");
                break;
            default:
                printf("invalid choice! please enter a valid option.\n");
        }
    }

    return 0;
}
